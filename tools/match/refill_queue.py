#!/usr/bin/env python3
"""refill_queue.py [--ov ov_battle] [--limit N] [--min-ratio R] [--dry-run] [FUNC...] -- keep the permuter queue fed.

With FUNC names it drafts exactly those (in that order, any module) instead of the parked list;
the same skip rules apply (already matched, queued or in the permuter). A name several overlays
share is given as FUNC@MODULE (funcref.py); from a parked list it is taken as that overlay's.

Goes through the overlay's parked list (tools/match/parked_OV.txt) and picks the functions that
neither loop can work on yet: still asm (INCLUDE_ASM), not in permuter/queue.txt and without a
permuter/nonmatchings/FUNC folder. For each it makes an m2c first draft (decomp.py), compiles
and scores it, and when it compiles with a ratio of at least --min-ratio (default 0.3) saves it
as permuter/cands/<address>.c and adds a line to permuter/queue.txt, best ratio first. A draft
that already matches is listed at the end: ask Claude to lock it.

Drafts that don't compile are listed with the first error, and are tried again on the next run
(after you or Claude fix the decls they need, e.g. in tools/match/m2c_extra.h).

The work happens in its own copy of the repo (~/chronocross-refill, refreshed from this checkout
first), because scoring edits source files; this checkout is never touched, so it is safe to run
while the permuter, the LLM loop or a Claude session are working here. Adding lines to the queue
while permute_all.sh runs is also safe: a run reads the queue once when it starts, so the new
functions are picked up by the next run.

Log of every run: permuter/refill.log.
"""
import argparse, glob, os, re, sys, time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import llm_iterate as li

MAIN = li.MAIN
li.WORK = os.path.expanduser(os.environ.get("REFILL_WORKDIR", "~/chronocross-refill"))
li.STREAM = False


GTE = re.compile(r"\b(cfc2|ctc2|mfc2|mtc2|lwc2|swc2|cop2)\b")



def cand_stem(func):
    """permuter/cands file stem: 801ee000_ov_party2 for func_801EE000@ov_party2, setjmp for setjmp."""
    name = func[5:] if re.fullmatch(r"func_[0-9A-Fa-f]{8}(@\w+)?", func) else func
    return name.lower().replace("@", "_")

def uses_gte(func):
    """GTE (coprocessor 2) instructions only come from inline asm: no C draft can match them,
    and m2c leaves M2C_ERROR() in their place."""
    try:
        paths = [li.funcref.asm_path(func)]
    except SystemExit:
        paths = glob.glob(f"{MAIN}/asm/**/nonmatchings/**/{li.C(func)}.s", recursive=True)
    for p in paths:
        if GTE.search(re.sub(r"/\*.*?\*/", "", open(p, errors="replace").read())):
            return True
    return False


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--ov", default="ov_battle", help="overlay whose parked list to use (default ov_battle)")
    ap.add_argument("--limit", type=int, default=0, help="draft at most N functions this run (0 = all)")
    ap.add_argument("--min-ratio", type=float, default=0.3, help="lowest score ratio worth queueing (default 0.3)")
    ap.add_argument("--dry-run", action="store_true", help="draft and score, but don't change the queue")
    ap.add_argument("funcs", nargs="*", help="draft these functions (in this order) instead of the parked list")
    a = ap.parse_args()

    queue = f"{MAIN}/permuter/queue.txt"
    queued = set()
    if os.path.exists(queue):
        for l in open(queue):
            p = l.split("#")[0].split()
            if len(p) >= 2:
                queued.add(p[1])
    pending = set()             # plain names and NAME@MODULE
    for src in glob.glob(f"{MAIN}/src/**/*.c", recursive=True):
        mod = li.funcref.module_of_src(src)
        for n in re.findall(r"^INCLUDE_ASM\([^,]+, (\w+)\);", open(src).read(), re.M):
            pending |= {n, f"{n}@{mod}"}
    shared = li.funcref.ambiguous_names()
    if a.funcs:
        # a qualified name stays qualified; a plain shared one is skipped with the choices
        a.funcs = [k for k in (f if "@" in f else li.key_of(f) for f in a.funcs) if k]
        parked, label = a.funcs, "picked"
        for f in dict.fromkeys(a.funcs):
            why = ("already matched (no INCLUDE_ASM)" if f not in pending else
                   "already in permuter/queue.txt" if f in queued else
                   "already has a permuter folder" if os.path.isdir(f"{MAIN}/permuter/nonmatchings/{f}") else None)
            if why:
                print(f"{f}: skipped, {why}")
    else:
        parked = [n if "@" in n or n not in shared else f"{n}@{a.ov}"
                  for n in (l.strip() for l in open(f"{MAIN}/tools/match/parked_{a.ov}.txt")) if n]
        sp = li.funcref.special()           # needs special work: no point drafting it
        held = [n for n in parked if li.funcref.is_special(n, sp)]
        if held:
            print("skipped (tools/match/special.txt): " + ", ".join(held))
        parked = [n for n in parked if n not in held]
        label = f"{a.ov}: {len(set(parked))} parked"
    todo = [f for f in dict.fromkeys(parked)
            if f in pending and f not in queued and not os.path.isdir(f"{MAIN}/permuter/nonmatchings/{f}")]
    skipped = len(set(parked)) - len(todo)
    print(f"{label}, {skipped} already queued, matched or in the permuter; "
          f"{len(todo)} to draft" + (f" (first {a.limit})" if a.limit and a.limit < len(todo) else ""))
    if a.limit:
        todo = todo[: a.limit]
    if not todo:
        return
    print(f"refreshing {li.WORK} ...")
    li.sync_workspace()

    good, low, failed, matched = [], [], [], []
    for k, func in enumerate(todo, 1):
        t0 = time.time()
        if uses_gte(func):
            failed.append((func, "GTE (cop2) instructions: needs inline asm, not a permuter job"))
            print(f"[{k}/{len(todo)}] {func}: uses GTE (cop2) instructions, which need inline asm; not queued")
            continue
        code = li.start_code(func)
        if code is None:
            failed.append((func, "m2c could not draft it"))
            print(f"[{k}/{len(todo)}] {func}: m2c could not draft it")
            continue
        ratio, ok, fb = li.score(func, code, "refill")
        dt = time.time() - t0
        if ok:
            matched.append((func, code))
            print(f"[{k}/{len(todo)}] {func}: the m2c draft already MATCHES ({dt:.0f}s)")
        elif fb.startswith("COMPILE FAILED"):
            err = next((l for l in fb.splitlines()[1:] if l.strip()), "?")
            failed.append((func, err.strip()[:150]))
            print(f"[{k}/{len(todo)}] {func}: draft doesn't compile: {err.strip()[:110]}")
        elif ratio < a.min_ratio:
            low.append((func, ratio))
            print(f"[{k}/{len(todo)}] {func}: ratio {ratio:.4f}, below {a.min_ratio}, not queued")
        else:
            good.append((func, ratio, code))
            print(f"[{k}/{len(todo)}] {func}: ratio {ratio:.4f} ({dt:.0f}s)")

    good.sort(key=lambda x: -x[1])
    day = time.strftime("%Y-%m-%d")
    added = []
    if not a.dry_run:
        os.makedirs(f"{MAIN}/permuter/cands", exist_ok=True)
        with open(queue, "a") as q:
            for func, ratio, code in good + [(f, 1.0, c) for f, c in matched]:
                stem = cand_stem(func)
                name = f"permuter/cands/{stem}.c"
                if os.path.exists(f"{MAIN}/{name}"):
                    name = f"permuter/cands/{stem}_refill.c"
                open(f"{MAIN}/{name}", "w").write(f"// @@{func}\n{code.rstrip()}\n")
                q.write(f"{name} {func} 0 # refill {day}: m2c draft, ratio {ratio:.4f}\n")
                added.append(func)

    lines = [f"=== {time.strftime('%Y-%m-%d %H:%M')} refill {'picked' if a.funcs else a.ov}"
             + (" (dry run)" if a.dry_run else "")]
    lines += [f"queued {f} ratio {r:.4f}" for f, r, _ in good]
    lines += [f"MATCH {f} (m2c draft; lock it)" for f, _ in matched]
    lines += [f"low {f} ratio {r:.4f}" for f, r in low]
    lines += [f"failed {f}: {e}" for f, e in failed]
    with open(f"{MAIN}/permuter/refill.log", "a") as log:
        log.write("\n".join(lines) + "\n")

    print()
    print(f"queued {len(good)}" + (" (dry run: queue not changed)" if a.dry_run else "")
          + f", {len(low)} below {a.min_ratio}, {len(failed)} failed to draft or compile")
    for f, r, _ in good:
        print(f"  + {f}  {r:.4f}")
    if matched:
        print("Already matching as drafted (ask Claude to lock):")
        for f, _ in matched:
            print(f"  * {f}  permuter/cands/{cand_stem(f)}.c")
    if failed:
        print("Not queued (fix and rerun):")
        for f, e in failed:
            print(f"  - {f}: {e}")
    print("log: permuter/refill.log")


if __name__ == "__main__":
    main()
