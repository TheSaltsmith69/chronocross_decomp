#!/usr/bin/env python3
"""llm_iterate.py -- let a local LLM iterate on unmatched functions.

    llm_iterate.py --parked ov_battle [--rounds 8]      # the parked list of an overlay
    llm_iterate.py --queue permuter/queue.txt          # "CANDS.c FUNC [IDX]" lines
    llm_iterate.py func_800C91FC func_800B8AC4         # named functions

For each function it starts from a candidate (the queue's, else an m2c draft from
decomp.py), then for --rounds rounds: sends the model the target assembly, the exact
compiler setup for that object, the relevant declarations, the best C so far and its
instruction diff, takes the C function it answers with, compiles and scores it, and
keeps the best. Everything happens in a separate copy of the repo (~/chronocross-llm,
refreshed from this checkout before each function), because trycc edits source files
while it works; this checkout is never touched.

Results: permuter/llm/<func>/ (every round, best.c) and permuter/llm/summary.txt.
A MATCH there is a trycc match (relocations masked), so it still needs locking with a
full build in this checkout.

The model is reached through an OpenAI-compatible chat API:
    LLM_BASE_URL  default http://127.0.0.1:47831/v1 (Strata)
    LLM_API_KEY   or STRATA_API_KEY
    LLM_MODEL     default: the first model the server lists
From WSL, requests go through Windows' curl.exe, since a server listening on
Windows' 127.0.0.1 isn't reachable from WSL directly.
"""
import argparse, json, os, re, shutil, subprocess, sys, time

MAIN = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
WORK = os.path.expanduser(os.environ.get("LLM_WORKDIR", "~/chronocross-llm"))
OUT = os.path.join(MAIN, "permuter", "llm")
# (an empty value counts as unset: run_llm.bat passes these through WSLENV even when unset)
BASE = (os.environ.get("LLM_BASE_URL") or "http://127.0.0.1:47831/v1").rstrip("/")
KEY = os.environ.get("LLM_API_KEY") or os.environ.get("STRATA_API_KEY") or ""
CURL_EXE = "/mnt/c/Windows/System32/curl.exe"
SYNC = ["src", "include", "tools/match", "Makefile", "asm", "linker_scripts", "undefined_funcs.txt"]


def log(*a):
    print(time.strftime("%H:%M:%S"), *a, flush=True)


# ---------------------------------------------------------------- workspace

def sync_workspace():
    os.makedirs(WORK, exist_ok=True)
    if not os.path.exists(f"{WORK}/.venv"):
        os.symlink(f"{MAIN}/.venv", f"{WORK}/.venv")
    os.makedirs(f"{WORK}/tools", exist_ok=True)
    for d in os.listdir(f"{MAIN}/tools"):          # toolchains etc.: link, don't copy
        if d != "match" and not os.path.exists(f"{WORK}/tools/{d}"):
            os.symlink(f"{MAIN}/tools/{d}", f"{WORK}/tools/{d}")
    for p in SYNC:
        src = f"{MAIN}/{p}"
        if os.path.isdir(src):
            subprocess.run(["rsync", "-a", "--delete", src + "/", f"{WORK}/{p}/"], check=True)
        elif os.path.exists(src):
            shutil.copy2(src, f"{WORK}/{p}")
    for f in os.listdir(MAIN):
        if f.endswith((".yaml", ".txt")) and os.path.isfile(f"{MAIN}/{f}"):
            shutil.copy2(f"{MAIN}/{f}", f"{WORK}/{f}")


def wrun(cmd, **kw):
    return subprocess.run(cmd, cwd=WORK, capture_output=True, text=True, **kw)


# ---------------------------------------------------------------- the model

def http(method, path, body=None, timeout=1800):
    url = BASE + path
    if os.path.exists(CURL_EXE):
        args = [CURL_EXE, "-s", "--max-time", str(timeout), "-X", method,
                "-H", "Content-Type: application/json"]
        if KEY:
            args += ["-H", f"Authorization: Bearer {KEY}"]
        if body is not None:
            args += ["--data-binary", "@-"]
        r = subprocess.run(args + [url], input=json.dumps(body) if body is not None else None,
                           capture_output=True, text=True, encoding="utf-8")
        if r.returncode:
            raise RuntimeError(f"curl.exe failed ({r.returncode}): {r.stderr.strip()}")
        txt = r.stdout
    else:
        import urllib.request
        req = urllib.request.Request(url, method=method,
                                     data=json.dumps(body).encode() if body is not None else None,
                                     headers={"Content-Type": "application/json",
                                              **({"Authorization": f"Bearer {KEY}"} if KEY else {})})
        with urllib.request.urlopen(req, timeout=timeout) as f:
            txt = f.read().decode()
    try:
        data = json.loads(txt)
    except ValueError:
        raise RuntimeError(f"{url}: not JSON: {txt[:300]}")
    if isinstance(data, dict) and "error" in data:
        raise RuntimeError(f"{url}: {data['error']}")
    return data


def pick_model():
    if os.environ.get("LLM_MODEL"):
        return os.environ["LLM_MODEL"]
    models = [m.get("id") for m in http("GET", "/models").get("data", [])]
    if not models:
        sys.exit("the server lists no models; set LLM_MODEL")
    return models[0]


def ask(model, system, user, temperature):
    data = http("POST", "/chat/completions", {
        "model": model, "temperature": temperature,
        "messages": [{"role": "system", "content": system}, {"role": "user", "content": user}],
    })
    text = data["choices"][0]["message"].get("content") or ""
    return re.sub(r"<think>.*?</think>", "", text, flags=re.S)


# ---------------------------------------------------------------- scoring

def score(func, code, tag):
    """Compile CODE as FUNC's candidate in the workspace: (ratio, matched, feedback)."""
    os.makedirs(f"{WORK}/llm_tmp", exist_ok=True)
    path = f"{WORK}/llm_tmp/{func}_{tag}.c"
    open(path, "w").write(f"// @@{func}\n{code.strip()}\n")
    r = wrun(["bash", "tools/match/adv.sh", path, func]).stdout
    m = re.search(r"ratio ([0-9.]+) match=(\d)", r)
    show = wrun([".venv/bin/python3", "tools/match/trycc.py", path, "--show"]).stdout
    if "COMPILE FAILED" in show or not m:
        err = "\n".join(l for l in show.splitlines()
                        if ("error" in l or "parse" in l or "undeclared" in l) and "Each undeclared" not in l
                        and "for each function" not in l)
        return 0.0, False, "COMPILE FAILED:\n" + (err or show[-1500:])
    ratio, matched = float(m.group(1)), m.group(2) == "1"
    if matched:
        return 1.0, True, "MATCH"
    diff = [l for l in show.splitlines() if l.startswith(("---", "* "))]
    return ratio, False, "\n".join(diff[:90]) + ("\n[... more differing lines]" if len(diff) > 90 else "")


# ---------------------------------------------------------------- prompt

def compiler_setup(func):
    src = wrun(["grep", "-rl", f"INCLUDE_ASM(.*, {func});", "src"]).stdout.split()
    if not src:
        return None, None
    obj = "build/" + src[0][:-2] + ".o"
    dry = wrun(["make", "--always-make", "--dry-run", obj]).stdout
    line = next((l for l in dry.splitlines() if src[0] in l and " -o " in l), "")
    expand = "--expand-div" in line
    cc1 = re.search(r"cc1 ([^|]*)\|", line)
    return src[0], {"cc1": cc1.group(1).strip() if cc1 else "", "expand_div": expand,
                    "gcc": re.search(r"gcc-([\d.]+-\w+)/cc1", line).group(1) if "gcc-" in line else "?"}


def target_asm(func):
    path = wrun(["bash", "-c", f"ls asm/*/nonmatchings/*/{func}.s"]).stdout.split()[0]
    out = []
    for l in open(f"{WORK}/{path}"):
        l = re.sub(r"^\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/\s*", "    ", l.rstrip())
        if l.strip():
            out.append(l)
    return "\n".join(out)


def relevant_context(func, code):
    sys.path.insert(0, f"{WORK}/tools/match")
    import importlib, m2ctx
    importlib.reload(m2ctx)
    m2ctx.ROOT = WORK
    items = [t.strip() for k, t in m2ctx.toplevel(m2ctx.context(func, keep_aliases=True)) if k == "decl"]
    names = set(re.findall(r"[A-Za-z_]\w*", code))
    keep = [t for t in items if re.match(r"typedef (un)?signed \w+ \w+;$|typedef \w+ \w+;$", t)]
    # declarations of names the code uses, then the typedefs those declarations use
    for _ in range(2):
        for t in items:
            n = m2ctx.declared_name(m2ctx.ASM_LABEL.sub("", t)[:-1])
            if n and n in names and t not in keep:
                keep.append(t)
        names |= set(re.findall(r"[A-Za-z_]\w*", "\n".join(keep)))
    return "\n".join(keep[:400])


SYSTEM = """You are an expert at matching decompilation of PlayStation 1 games: you write C that, \
compiled with the exact original compiler, produces instruction-for-instruction the given MIPS assembly.

Rules:
- Answer with exactly ONE ```c code block holding the complete function, preceded by any \
typedef/extern/prototype lines it needs that are not already in the provided declarations. \
Keep the function's name. Briefly say what you changed before the block.
- C89 only: declarations at the start of a block, no // comments inside code, no C99 features.
- Project style: untyped pointers are u8 *, struct fields are *(T *)(p + 0xOFF) or a small typedef \
struct; types u8/s8/u16/s16/u32/s32 exist. If a prototype elsewhere has different parameter types, \
define the function under another C name with an asm label: `s32 f_m(u8 *a) asm("func_X"); s32 f_m(u8 *a) {...}`.
- The diff shows lines as `ours | original`; `*` marks differing instructions. Relocated fields \
(addresses of globals) are masked, so symbol names never show as differences.
- Typical fixes for gcc 2.8.1: reorder statements; introduce or remove a local (keeps a value in a \
saved register vs reloading); change a local's type (s16 vs s32 changes sll/sra pairs; u16 gives lhu); \
compute an address once in a pointer vs inline per access; for/while/do-while loop shape; \
`if (x) y = a; else y = b;` vs ternary; split or merge expressions; operand order of + and *.
"""


def build_prompt(func, setup, asm, ctx, best, best_fb, last, last_fb):
    comp = (f"Compiler: PsyQ GCC {setup['gcc']} cc1 with `{setup['cc1']}`, output through maspsx "
            f"(ASPSX 2.79 emulation{', --expand-div: divides get the break 6/7 divide-by-zero and overflow checks' if setup['expand_div'] else ', no divide checks'}), "
            "then GNU as. MIPS R3000, little endian; load delay slots are filled with nop where needed.")
    parts = [f"Match `{func}`.", comp,
             "Declarations visible to the function in its source file (relevant ones):\n```c\n" + ctx + "\n```",
             "Target assembly:\n```\n" + asm + "\n```",
             "Best C so far:\n```c\n" + best + "\n```", "Its result:\n```\n" + best_fb + "\n```"]
    if last is not None and last.strip() != best.strip():
        parts += ["Your previous attempt (worse than the best):\n```c\n" + last + "\n```",
                  "Its result:\n```\n" + last_fb + "\n```"]
    parts.append("Write an improved version of the function.")
    return "\n\n".join(parts)


def extract_code(text, func):
    blocks = re.findall(r"```(?:c|C)?\s*\n(.*?)```", text, flags=re.S)
    blocks = [b for b in blocks if func in b]
    return blocks[-1].strip() + "\n" if blocks else None


# ---------------------------------------------------------------- driver

def start_code(func, cands=None, idx=0):
    if cands:
        t = open(cands if os.path.isabs(cands) else f"{MAIN}/{cands}").read()
        vs = t.split(f"// @@{func}\n")[1:]
        if len(vs) > idx:
            return vs[idx].split("\n// @@")[0].strip() + "\n"
    r = wrun([".venv/bin/python3", "tools/match/decomp.py", func])
    if r.returncode or f"// @@{func}" not in r.stdout:
        return None
    return r.stdout.split(f"// @@{func}\n", 1)[1]


def iterate(model, func, cands, idx, rounds, temperature):
    sync_workspace()
    src, setup = compiler_setup(func)
    if not src:
        log(f"{func}: already matched (no INCLUDE_ASM)")
        return
    d = f"{OUT}/{func}"
    os.makedirs(d, exist_ok=True)
    code = start_code(func, cands, idx)
    if code is None:
        log(f"{func}: no starting candidate (m2c failed)")
        return
    asm = target_asm(func)
    best, (best_r, best_m, best_fb) = code, score(func, code, "start")
    open(f"{d}/start.c", "w").write(f"// @@{func}\n{code}")
    log(f"{func}: start ratio {best_r:.4f}")
    last, last_fb = None, None
    for i in range(1, rounds + 1):
        if best_m:
            break
        prompt = build_prompt(func, setup, asm, relevant_context(func, best), best, best_fb, last, last_fb)
        if model is None:                       # --dry-run
            open(f"{d}/prompt.txt", "w").write(SYSTEM + "\n=====\n" + prompt)
            log(f"{func}: dry run, prompt ({len(SYSTEM) + len(prompt)} chars) in permuter/llm/{func}/prompt.txt")
            return
        try:
            answer = ask(model, SYSTEM, prompt, temperature)
        except Exception as e:
            log(f"{func} round {i}: request failed: {e}")
            time.sleep(10)
            continue
        open(f"{d}/round{i:02d}.txt", "w").write(answer)
        new = extract_code(answer, func)
        if new is None:
            log(f"{func} round {i}: no C block with {func} in the answer")
            last, last_fb = None, None
            continue
        r, m, fb = score(func, new, f"r{i}")
        open(f"{d}/round{i:02d}.c", "w").write(f"// @@{func}\n{new}")
        log(f"{func} round {i}: {'MATCH' if m else f'ratio {r:.4f}'} (best {best_r:.4f})")
        if m or r > best_r:
            best, best_r, best_m, best_fb = new, r, m, fb
            last, last_fb = None, None
        else:
            last, last_fb = new, fb
    open(f"{d}/best.c", "w").write(f"// @@{func}\n{best}")
    line = f"{time.strftime('%Y-%m-%d %H:%M')} {func}: {'MATCH' if best_m else f'best {best_r:.4f}'} -> permuter/llm/{func}/best.c"
    with open(f"{OUT}/summary.txt", "a") as f:
        f.write(line + "\n")
    log(line)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("funcs", nargs="*")
    ap.add_argument("--parked", metavar="OV", help="work through tools/match/parked_OV.txt")
    ap.add_argument("--queue", help='file of "CANDS.c FUNC [IDX]" lines')
    ap.add_argument("--rounds", type=int, default=8)
    ap.add_argument("--temperature", type=float, default=0.6)
    ap.add_argument("--skip-done", action="store_true", help="skip functions already in summary.txt")
    ap.add_argument("--dry-run", action="store_true", help="build and save the first prompt only; no model")
    a = ap.parse_args()

    jobs = []
    starts = {}
    q = a.queue or f"{MAIN}/permuter/queue.txt"
    if os.path.exists(q):
        for l in open(q):
            p = l.split("#")[0].split()
            if len(p) >= 2:
                starts[p[1]] = (p[0], int(p[2]) if len(p) > 2 else 0)
    if a.queue:
        jobs = list(starts)
    if a.parked:
        jobs += [l.strip() for l in open(f"{MAIN}/tools/match/parked_{a.parked}.txt") if l.strip()]
        jobs.sort(key=lambda f: f not in starts)      # ones with a saved candidate first
    jobs += a.funcs
    if a.skip_done and os.path.exists(f"{OUT}/summary.txt"):
        done = set(re.findall(r" (func_\w+): ", open(f"{OUT}/summary.txt").read()))
        jobs = [j for j in jobs if j not in done]
    if not jobs:
        sys.exit("nothing to do (give functions, --parked or --queue)")
    os.makedirs(OUT, exist_ok=True)
    try:
        model = None if a.dry_run else pick_model()
    except RuntimeError as e:
        sys.exit(f"can't reach the model server: {e}\n"
                 f"(LLM_BASE_URL={BASE}; key {'set' if KEY else 'NOT set: STRATA_API_KEY / LLM_API_KEY'})")
    log(f"model {model} at {BASE}; {len(jobs)} function(s), {a.rounds} rounds each")
    for f in dict.fromkeys(jobs):
        try:
            cands, idx = starts.get(f, (None, 0))
            iterate(model, f, cands, idx, a.rounds, a.temperature)
        except KeyboardInterrupt:
            raise
        except Exception as e:
            log(f"{f}: error: {e}")


if __name__ == "__main__":
    main()
