"""Permuter tuning profiles (control panel) and the Auto profile's per-function weight choice.

A profile is a set of perm settings plus the full set of randomization weight overrides. The
control panel lists these built-ins next to the ones you save. "Auto" keeps Balanced's
settings, but before each function's visit permute_all.sh runs

    perm_profiles.py --auto permuter/nonmatchings/FUNC

which compiles the C the visit starts from, sorts the instructions that still differ from the
target (registers only, load/store widths, branches) and writes the weights of
the profile that fits into that function's settings.toml.
"""
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))

# the overrides every built-in keeps: these passes make C that gcc 2.8.1 rejects or that
# can never match (function/extern retyping, float literals, deleting statements)
_SAFE = {"randomize_function_type": 0, "randomize_external_type": 0, "float_literal": 0,
         "remove_ast": 0, "inline": 1, "randomize_internal_type": 20}


def _w(**kw):
    return {"perm_" + k: float(v) for k, v in dict(_SAFE, **kw).items()}


BUILTIN_PROFILES = [
    {"id": "balanced", "name": "Balanced",
     "desc": "The everyday setting: 20 min per function, gives up after 5 min without progress. "
             "Default weights minus the passes that make broken C.",
     "perm": {"minutes": 20, "threads": 8, "stall": 5, "keep_prob": 0.6, "speed": 100, "stack_diffs": False},
     "weights": _w()},
    {"id": "auto", "name": "Auto (per function)",
     "desc": "Balanced's settings, but before each function's visit the weights are picked from "
             "what still differs: mostly registers -> Register allocation, branches -> Control "
             "flow, load/store widths -> Types & casts, a mix -> Balanced. The console says "
             "which it picked and why.",
     "perm": {"minutes": 20, "threads": 8, "stall": 5, "keep_prob": 0.6, "speed": 100, "stack_diffs": False},
     "weights": _w(), "auto": True},
    {"id": "quick", "name": "Quick sweep",
     "desc": "A cheap first pass over a long queue: 5 min each, stall after 2. Finds the easy "
             "wins and shows which functions are worth a deep dive.",
     "perm": {"minutes": 5, "threads": 8, "stall": 2, "keep_prob": 0.5, "speed": 100, "stack_diffs": False},
     "weights": _w()},
    {"id": "deep", "name": "Deep dive",
     "desc": "For a function that is close (low score): 90 min, 20 min stall, and a higher "
             "keep probability so it stacks more changes on top of each other.",
     "perm": {"minutes": 90, "threads": 12, "stall": 20, "keep_prob": 0.8, "speed": 100, "stack_diffs": False},
     "weights": _w()},
    {"id": "regalloc", "name": "Register allocation",
     "desc": "Wrong registers or swapped s-registers, logic otherwise right. Leans on temporaries, "
             "declaration and statement order, split/chained assignments and operand order.",
     "perm": {"minutes": 30, "threads": 8, "stall": 8, "keep_prob": 0.7, "speed": 100, "stack_diffs": False},
     "weights": _w(temp_for_expr=120, reorder_decls=40, reorder_stmts=25, split_assignment=25,
                   commutative=20, chain_assignment=15, remove_var=15, refer_to_var=5,
                   expand_expr=10, struct_ref=5, ins_block=5, condition=0.5)},
    {"id": "flow", "name": "Control flow",
     "desc": "Branches and blocks laid out differently: reversed conditions, inequalities, "
             "inserted blocks, conditional blocks, compound assignments.",
     "perm": {"minutes": 30, "threads": 8, "stall": 8, "keep_prob": 0.6, "speed": 100, "stack_diffs": False},
     "weights": _w(condition=15, reverse_cond=15, inequalities=20, ins_block=25, var_cond_block=15,
                   empty_stmt=5, compound_assignment=10, temp_for_expr=40, reorder_stmts=15,
                   expand_expr=10)},
    {"id": "types", "name": "Types & casts",
     "desc": "Wrong load/store widths, sign extension or struct access: retypes locals, adds "
             "casts and masks, rewrites struct references and array aliases.",
     "perm": {"minutes": 30, "threads": 8, "stall": 8, "keep_prob": 0.6, "speed": 100, "stack_diffs": False},
     "weights": _w(randomize_internal_type=60, cast_simple=30, struct_ref=25, alias_array=10,
                   add_mask=5, temp_for_expr=50, factor_shift=5, factor_mult=5)},
    {"id": "stack", "name": "Stack layout",
     "desc": "Right code, wrong stack offsets. Scores stack differences too and favours "
             "declaration order, padding variables and array aliases. Those scores run higher "
             "than normal ones, so the stall timer is off (it compares with earlier runs).",
     "perm": {"minutes": 30, "threads": 8, "stall": 0, "keep_prob": 0.6, "speed": 100, "stack_diffs": True},
     "weights": _w(reorder_decls=50, pad_var_decl=15, alias_array=10, randomize_internal_type=25,
                   temp_for_expr=40, remove_var=10)},
    {"id": "light", "name": "Background (light)",
     "desc": "Keeps working while you use the PC: 3 threads at half speed (the permuter sleeps "
             "between compiles), otherwise Balanced.",
     "perm": {"minutes": 30, "threads": 3, "stall": 8, "keep_prob": 0.6, "speed": 50, "stack_diffs": False},
     "weights": _w()},
]
BY_ID = {p["id"]: p for p in BUILTIN_PROFILES}

# ---------------------------------------------------------------- Auto: what kind of difference

LOADS = {"lb", "lbu", "lh", "lhu", "lw", "lwl", "lwr"}
STORES = {"sb", "sh", "sw", "swl", "swr"}
EXTEND = {"sll", "sra", "srl", "andi"}
REGS = re.compile(r"\b(?:zero|at|v[01]|a[0-3]|t\d|s[0-8]|k[01]|gp|sp|fp|ra)\b")


def _mn(i):
    return i.split(None, 1)[0] if i else ""


def _branch(m):
    return m.startswith("b") and m not in ("break",) or m in ("j", "jr", "jalr")


def classify(rows):
    """rows: [target, ours, kind] from gui_diff (kind eq/reg/diff/ins/del) -> {category: count}"""
    c = {"reg": 0, "stack": 0, "width": 0, "branch": 0, "other": 0}
    for a, b, k in rows:
        if k == "eq":
            continue
        ma, mb = _mn(a), _mn(b)
        if k == "reg":
            c["reg"] += 1
        elif _branch(ma) or _branch(mb):
            c["branch"] += 1
        elif a and b and ma == mb and REGS.sub("R", re.sub(r"-?\d+\(sp\)", "N(sp)", a)) == \
                REGS.sub("R", re.sub(r"-?\d+\(sp\)", "N(sp)", b)) and "(sp)" in a:
            c["stack"] += 1
        elif a and b and ma != mb and ({ma, mb} <= LOADS or {ma, mb} <= STORES):
            c["width"] += 1
        elif ma in EXTEND or mb in EXTEND:
            c["width"] += 1
        else:
            c["other"] += 1
    return c


def choose(c):
    """-> (profile id, reason)"""
    total = sum(c.values())
    if not total:
        return "balanced", "nothing differs"
    # stack offsets aren't scored unless the run has --stack-diffs, so they never pick weights
    order = [("reg", "regalloc", "register-only"), ("branch", "flow", "branch"),
             ("width", "types", "load/store width or extension")]
    key, pid, what = max(order, key=lambda o: c[o[0]])
    share = c[key] / total
    detail = ", ".join(f"{v} {k}" for k, v in c.items() if v)
    if share >= 0.5:
        return pid, f"{c[key]} of {total} differing instructions are {what} ({detail})"
    return "balanced", f"no single kind dominates ({detail})"


def diff_rows(dirpath, src):
    """(differing rows [target, ours, kind], target length) for SRC compiled like the function"""
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import difflib
    import gui_diff
    func = os.path.basename(dirpath.rstrip("/"))
    mine = gui_diff.compile_obj(func, open(src).read())
    target = gui_diff.disasm(os.path.join(dirpath, "target.o"), func)
    rows = []
    sm = difflib.SequenceMatcher(None, target, mine, autojunk=False)
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op == "equal":
            continue
        for k in range(max(i2 - i1, j2 - j1)):
            a = target[i1 + k] if i1 + k < i2 else None
            b = mine[j1 + k] if j1 + k < j2 else None
            rows.append([a, b, "del" if b is None else "ins" if a is None else
                         "reg" if gui_diff.regs_only(a, b) else "diff"])
    return rows, len(target)


def auto(dirpath):
    """Pick weights for the function in DIRPATH from its base.c; write them into its
    settings.toml. Prints one line for the console."""
    func = os.path.basename(dirpath.rstrip("/"))
    rows, _ = diff_rows(dirpath, os.path.join(dirpath, "base.c"))
    pid, why = choose(classify(rows))
    w = BY_ID[pid]["weights"]
    s = os.path.join(dirpath, "settings.toml")
    text = open(s).read() if os.path.exists(s) else ""
    text = re.sub(r"\n?\[weight_overrides\][\s\S]*$", "", text).rstrip("\n")
    text += "\n[weight_overrides]\n" + "".join(
        f"{k} = {int(v) if v == int(v) else v}\n" for k, v in w.items())
    with open(s + ".tmp", "w") as f:
        f.write(text.lstrip("\n"))
    os.replace(s + ".tmp", s)
    print(f"{func}: auto profile -> {BY_ID[pid]['name']}: {why}")
    return pid


KIND_TEXT = {"reg": "register-only", "branch": "branch/jump", "width": "load/store width or extension",
             "stack": "stack offset", "other": "other"}


def note(dirpath, why=""):
    """Rewrite the permuter's part of notes/FUNC.md: best score so far and what its best output
    still gets wrong, so the LLM (and you) start from a summary instead of re-reading the diff."""
    import glob
    import time
    import fnotes
    func = os.path.basename(dirpath.rstrip("/"))
    outs = []
    for o in glob.glob(os.path.join(dirpath, "output-*", "source.c")):
        m = re.search(r"output-(\d+)-(\d+)", o)
        if m:
            outs.append((int(m.group(1)), int(m.group(2)), o))
    if not outs:
        return
    score, _, src = min(outs)
    if score == 0:
        fnotes.set_section(func, "permuter", "")       # matched: nothing left to say
        return
    rows, total = diff_rows(dirpath, src)
    c = classify(rows)
    try:
        base = int(open(os.path.join(dirpath, "base.score")).read())
    except (OSError, ValueError):
        base = None
    kinds = ", ".join(f"{v} {KIND_TEXT[k]}" for k, v in sorted(c.items(), key=lambda kv: -kv[1]) if v)
    lines = [f"**Permuter** (written automatically, {time.strftime('%Y-%m-%d %H:%M')}{', ' + why if why else ''}):",
             f"- best score {score}" + (f" (draft {base})" if base else "")
             + f", `{os.path.relpath(os.path.abspath(src), ROOT)}`",
             f"- {len(rows)} of {total} instructions still differ: {kinds or 'none'}"]
    pid, _ = choose(c)
    if pid != "balanced":
        lines.append(f"- mostly a {BY_ID[pid]['name'].lower()} problem")
    shown = [r for r in rows if r[2] != "eq"][:6]
    if shown:
        lines.append("- first differences (target | ours):")
        lines += [f"  - `{a or '-'}` | `{b or '-'}`" for a, b, _ in shown]
    fnotes.set_section(func, "permuter", "\n".join(lines))
    print(f"{func}: permuter summary written to notes/{func}.md")


USAGE = "usage: perm_profiles.py --auto|--note permuter/nonmatchings/FUNC [WHY]"

if __name__ == "__main__":
    if len(sys.argv) >= 3 and sys.argv[1] in ("--auto", "--note"):
        name = os.path.basename(sys.argv[2].rstrip("/"))
        try:
            if sys.argv[1] == "--auto":
                auto(sys.argv[2])
            else:
                note(sys.argv[2], " ".join(sys.argv[3:]))
        except Exception as e:                # never stop the permuter run over this
            print(f"{name}: {sys.argv[1][2:]} skipped ({e})")
    else:
        sys.exit(USAGE)
