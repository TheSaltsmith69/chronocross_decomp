#!/usr/bin/env python3
"""llm_iterate.py -- let a local LLM iterate on unmatched functions.

    llm_iterate.py --parked ov_battle [--compiles 40] [--minutes 30]   # an overlay's parked list
    llm_iterate.py --queue permuter/queue.txt          # "CANDS.c FUNC [IDX]" lines
    llm_iterate.py --permuted [FUNC...]                # functions the permuter has improved
    llm_iterate.py func_800C91FC func_800B8AC4         # named functions

For each function it starts from a candidate (the queue's, else an m2c draft from
decomp.py) and holds one conversation with the model: the first message has the target
assembly, the exact compiler setup for that object, the relevant declarations and the
best C so far with its instruction diff; each reply may carry up to --variants versions
of the function, every one is compiled and scored, and the results go back as the next
message. It stops at a match, after --compiles compiles or after --minutes minutes, and
keeps the best. When the history passes ~35% of --ctx tokens (the model's thinking needs
the rest), it restarts the conversation from the best code and the model's handoff notes.
--rounds N is the older mode: N independent single-answer rounds. Everything happens in a separate copy of the repo (~/chronocross-llm,
refreshed from this checkout before each function), because trycc edits source files
while it works; this checkout is never touched.

--permuted works through the functions under permuter/nonmatchings/ that have at least one
permuter output (not the *.matched ones), lowest permuter score first. Each starts from the
function in its best output-SCORE-N/source.c, put after the queue candidate's own declarations
(typedefs, externs); the queue candidate is scored as well, and the better one is used. The
model is told the code came from the permuter, which makes random changes that can be odd or
wrong C. With --skip-done, a function is skipped only if the LLM already started from that same
permuter output (permuter/llm/<func>/permuted_from.txt); a newer permuter result runs it again.

Each first prompt also carries up to --examples already-matched functions (default 2) whose
assembly is most like the target's (same overlay, opcode-sequence similarity >= 0.5), as
models for types, struct aliases and statement shape, and the extra tips in
tools/match/llm_tips.md (edit that file to teach the model new tricks; no code change needed).

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
import argparse, glob, json, os, re, shutil, subprocess, sys, time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pauseclock import active_time      # time.time() minus time paused from the control panel
import fnotes                             # notes/FUNC.md, shared with the control panel

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


GREY, RESET = "\033[90m", "\033[0m"
STREAM = True          # --quiet turns it off


def stream_lines(body, timeout=1800):
    """POST /chat/completions with stream=true; yield the raw SSE lines."""
    url = BASE + "/chat/completions"
    if os.path.exists(CURL_EXE):
        args = [CURL_EXE, "-s", "-N", "--max-time", str(timeout), "-X", "POST",
                "-H", "Content-Type: application/json", "--data-binary", "@-"]
        if KEY:
            args += ["-H", f"Authorization: Bearer {KEY}"]
        p = subprocess.Popen(args + [url], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                             stderr=subprocess.PIPE, text=True, encoding="utf-8", bufsize=1)
        p.stdin.write(json.dumps(body))
        p.stdin.close()
        done = False
        try:
            for line in p.stdout:
                yield line.rstrip("\r\n")
            done = True
        finally:
            if not done:                # the caller stopped reading (thinking budget): hang up
                p.kill()
                p.wait()
        p.wait()
        if p.returncode:
            raise RuntimeError(f"curl.exe failed ({p.returncode}): {p.stderr.read().strip()}")
    else:
        import urllib.request
        req = urllib.request.Request(url, method="POST", data=json.dumps(body).encode(),
                                     headers={"Content-Type": "application/json",
                                              **({"Authorization": f"Bearer {KEY}"} if KEY else {})})
        with urllib.request.urlopen(req, timeout=timeout) as f:
            for raw in f:
                yield raw.decode("utf-8", "replace").rstrip("\r\n")


def ask(model, system, user, temperature):
    return ask_messages(model, [{"role": "system", "content": system}, {"role": "user", "content": user}],
                        temperature)


NO_THINK = {"chat_template_kwargs": {"enable_thinking": False}}   # Qwen3-style templates; others ignore it
KWARGS_OK = True        # cleared once the server rejects chat_template_kwargs
KWARGS_REFUSED = re.compile(r"chat_template|kwargs|unknown (field|param)|unrecognized|not (supported|allowed)|"
                            r"extra (fields|inputs)|invalid_request", re.I)
# the engine behind the server died or isn't up (yet); the server restarts it on the next request
ENGINE_DOWN = re.compile(r"engine stopped|exit code|restarts it|server_error|loading|connection refused|"
                         r"curl\.exe failed \((7|52|56)\)", re.I)


def ask_messages(model, messages, temperature, think_budget=0, extra=None):
    """Returns (answer, thinking). With STREAM, both are printed as they arrive:
    thinking in grey, the answer in the normal colour. With THINK_BUDGET (characters), the
    request is hung up once the thinking passes it, before any answer has started; the
    answer is then "" and the caller decides what to do."""
    body = {"model": model, "temperature": temperature, "messages": messages, **(extra or {})}
    if not STREAM:
        data = http("POST", "/chat/completions", body)
        msg = data["choices"][0]["message"]
        text = msg.get("content") or ""
        think = msg.get("reasoning_content") or msg.get("reasoning") or ""
        think += "".join(re.findall(r"<think>(.*?)</think>", text, flags=re.S))
        return re.sub(r"<think>.*?</think>", "", text, flags=re.S), think

    body["stream"] = True
    content, thinking = [], []
    in_think = False            # inside <think>...</think> in the content stream
    pending = ""                # content not yet split into thinking/answer
    mode = None                 # what is being printed: "think" or "answer"

    def show(kind, s):
        nonlocal mode
        if not s:
            return
        if kind != mode:
            sys.stdout.write((GREY + "\n[thinking] " if kind == "think" else RESET + "\n[answer] "))
            mode = kind
        sys.stdout.write(s)
        sys.stdout.flush()

    lines = stream_lines(body)
    thought = 0
    for line in lines:
        if think_budget and thought > think_budget and not "".join(content).strip():
            lines.close()
            sys.stdout.write(RESET + f"\n[thinking cut off at ~{thought // 4} tokens]")
            pending = ""
            break
        if not line.startswith("data:"):
            if line.strip().startswith("{") and '"error"' in line:
                raise RuntimeError(line.strip())
            continue
        payload = line[5:].strip()
        if payload == "[DONE]":
            break
        try:
            chunk = json.loads(payload)
        except ValueError:
            continue
        if "error" in chunk:
            raise RuntimeError(str(chunk["error"]))
        for ch in chunk.get("choices", []):
            delta = ch.get("delta") or {}
            r = delta.get("reasoning_content") or delta.get("reasoning") or ""
            if r:
                thinking.append(r)
                thought += len(r)
                show("think", r)
            pending += delta.get("content") or ""
            # split <think>...</think> out of the content; a tag may arrive split across
            # chunks, so hold back a tail that could be the start of one
            while pending:
                tag = "</think>" if in_think else "<think>"
                at = pending.find(tag)
                if at >= 0:
                    part, pending = pending[:at], pending[at + len(tag):]
                else:
                    keep = next((k for k in range(len(tag) - 1, 0, -1) if pending.endswith(tag[:k])), 0)
                    part, pending = (pending[:-keep], pending[-keep:]) if keep else (pending, "")
                (thinking if in_think else content).append(part)
                if in_think:
                    thought += len(part)
                show("think" if in_think else "answer", part)
                if at >= 0:
                    in_think = not in_think
                elif keep:
                    break
    if pending:
        (thinking if in_think else content).append(pending)
        show("think" if in_think else "answer", pending)
    sys.stdout.write(RESET + "\n")
    sys.stdout.flush()
    return "".join(content), "".join(thinking)


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


HEAD = """You are an expert at matching decompilation of PlayStation 1 games: you write C that, \
compiled with the exact original compiler, produces instruction-for-instruction the given MIPS assembly.

Rules:
"""

ROUND_RULES = """- Answer with exactly ONE ```c code block holding the complete function, preceded by any \
typedef/extern/prototype lines it needs that are not already in the provided declarations. \
Keep the function's name. Briefly say what you changed before the block.
- After the code block, write a handoff for the next round, starting with a line `HANDOFF:` \
(at most 12 lines, no code blocks). The next round sees your code and its score but NOT your \
reasoning, so put in it what you changed and why, what the remaining differences are (which \
instructions/registers), what you think causes them, what you ruled out, and what to try next.
"""

SESSION_RULES = """- You have the compiler: each reply may hold up to {k} ```c code blocks, each a complete \
variant of the function (keep its name), preceded by any typedef/extern/prototype lines it needs \
that are not already in the provided declarations. Every block is compiled and scored and the \
results come back as the next message; then you continue. This goes on until a variant matches or \
the budget of compiles and time runs out, so learn from each result: when close, change one thing \
per variant so you can tell what helped; when stuck, try a bolder restructuring. Say in one line \
before each block what it changes.
- The compiler is the checker, and a compile takes about a second while your reasoning takes \
minutes. Do NOT simulate gcc's register allocator or scheduler in your head, and do not double-check \
whether a variant will match: look at the diff, form a quick hypothesis, and send variants. When \
torn between options, send each one as its own variant instead of deliberating. Keep your thinking \
short; your thinking may be cut off if it runs long.
- End every reply with a line `HANDOFF:` and at most 8 lines (no code): what still differs, what \
you think causes it, what you ruled out, what to try next. When the conversation gets long it is \
restarted to free memory, and only the best code, its result and these handoffs are carried over.
"""

SYSTEM_BODY = """- Lasting notes: a line starting with `NOTE:` (outside code blocks, one fact per line, at most 4 \
per reply) is saved to the function's notes file, which every later session on this function is \
shown. Use it only for facts worth keeping: what the function does, what an argument or struct field \
is, a type the assembly confirms, an approach that definitely fails and why. Progress belongs in \
the HANDOFF, not in notes. Notes from the user are the most reliable.
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

Tricks that matched functions in this project (gcc 2.8.1 -O2):
- Register swaps (s0/s1, v0/v1 the other way round): gcc gives saved registers by priority \
~ uses / live length, so moving where a value is first assigned or last used flips them. Copying a \
parameter into a local at the top, or giving a reused local the job of a temp, also changes the choice.
- A temp used only inside one block should be declared in that block (gets v0/v1 instead of an s register).
- Base + index order (`addu v0,a0,v1` vs `addu v0,v1,a0`, or which lui comes first): put the scaled \
index in a temp (`o = i * 12; *(s16 *)(p + o + 0x4)`), swap the operands of +, or index the global \
directly (`D[i].f`) instead of through a pointer local (or the other way round).
- A field offset folded into the address register instead of the load (lw 0(v0) vs lw 0x20(v0)) \
means the original used a real struct field, not a cast on a byte offset.
- Taking the address of a member of a global array element (`*(s32 *)&D[k].v`) makes gcc load \
symbol+offset as one constant.
- A load the original does before a store that may alias it must also come first in the C: read it \
into a local before the store.
- abs: `(h >= 0 ? h : -h)` on a local; `if (x < 0) x = -x;` gives a different branch shape.
- One-bit tests: `u8 > 0` gives and+sltu; `!= 0` and `& 1` give other code; a 1-bit bitfield keeps lw.
- Byte results: mask where they're read (`s32 b = f() & 0xFF;`) when the original masks right after \
the call; a callee whose result is used unmasked as an index returns s32.
- sll 16/sra 16 pairs at entry mean an s16 parameter; their absence means s32 even if the value is small.
- Loops: `move s0,v0` before a loop = a separate start variable (`for (i = s; ...)`); an explicit \
counter plus pointer (`p = base + i; ... p--`) gives a strength-reduced fill; reading a global inside \
the loop instead of a local copy changes which constants are hoisted.
- `if (call()) return X;` early returns change the branch layout; switch cases are laid out in source order.
- 0x51EB851F with sra 7 is /400 (magic-number division); with --expand-div, a real `/` or `%` by a \
variable gives the break 7 / break 6 checks.
- Chained assignments (`a = b = 0`) change store order; a store ASPSX puts in a jal delay slot is \
written just before the call.
- An argument register still holding a value at a call that seems to take fewer args = a hidden \
argument: the callee takes it.
- String constants in the function's own rodata come from string literals in the C.
"""

SYSTEM = HEAD + ROUND_RULES + SYSTEM_BODY


def session_system(k):
    return HEAD + SESSION_RULES.format(k=k) + SYSTEM_BODY + extra_tips()


NOTES_MAX = 9000        # characters of earlier rounds' handoffs kept in the prompt
FNOTES_MAX = 6000       # characters of the function's notes file kept in the prompt (newest)


def save_notes(func, answer, where):
    """Store the reply's NOTE: lines in notes/FUNC.md; returns the answer without them."""
    found, rest = fnotes.from_reply(answer)
    if found:
        try:
            added = fnotes.append(func, found, "LLM")
            if added:
                log(f"{func} {where}: {len(added)} note(s) saved to notes/{func}.md")
        except OSError as e:
            log(f"{func} {where}: couldn't save notes: {e}")
    return rest


def notes_text(notes):
    """The handoff log, oldest dropped first so it fits NOTES_MAX."""
    entries = [f"Round {n} ({res}):\n{h}" for n, res, h in notes]
    while entries and sum(len(e) for e in entries) > NOTES_MAX:
        entries.pop(0)
    return "\n\n".join(entries)


# ---------------------------------------------------------------- similar matched functions

N_EXAMPLES = 2
EXAMPLE_MIN = 0.5
EXAMPLE_LINES = 70
_OPS = {}


def asm_ops(path):
    """Opcode sequence of a splat .s file (cached)."""
    if path not in _OPS:
        ops = []
        for l in open(path, errors="replace"):
            l = re.sub(r"^\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/\s*", "", l).strip()
            m = re.match(r"([a-z][a-z0-9.]*)\b", l)
            if m and not l.startswith(("glabel", "endlabel", "nonmatching", "jlabel", "dlabel")) and ":" not in m.group(1):
                ops.append(m.group(1))
        _OPS[path] = ops
    return _OPS[path]


def c_definition(func, srcs):
    """FUNC's C text in one of SRCS (with the declarations just above it in its block), or None."""
    for src in srcs:
        t = open(src).read()
        sp = func_span(t, func)
        if not sp:
            continue
        lines = t[: sp[0]].splitlines()
        k = len(lines)
        while k > 0 and lines[k - 1].strip() and not lines[k - 1].startswith(("INCLUDE_ASM", "INCLUDE_RODATA", "}")):
            k -= 1
        text = "\n".join(lines[k:]) + ("\n" if lines[k:] else "") + t[sp[0]: sp[1]]
        tl = text.splitlines()
        if len(tl) > EXAMPLE_LINES:
            return None             # too long to be a useful example
        return text.strip("\n")
    return None


_EXAMPLES = {}


def similar_examples(func):
    """[(similarity, name, C)] of the matched functions in FUNC's module most like it."""
    if func in _EXAMPLES:
        return _EXAMPLES[func]
    import difflib
    out = []
    try:
        tpath = glob.glob(f"{WORK}/asm/*/nonmatchings/*/{func}.s")[0]
        module = tpath[len(WORK) + 5:].split("/")[0]            # e.g. ov_battle, or game for main
        srcs = sorted(glob.glob(f"{WORK}/src/{module}/**/*.c", recursive=True)) or \
            sorted(glob.glob(f"{WORK}/src/**/*.c", recursive=True))
        pending = set()
        for src in srcs:
            pending |= set(re.findall(r"^INCLUDE_ASM\([^,]+, (func_\w+)\);", open(src).read(), re.M))
        target = asm_ops(tpath)
        seen = set()
        scored = []
        for path in glob.glob(f"{WORK}/asm/{module}/nonmatchings/*/func_*.s"):
            name = os.path.basename(path)[:-2]
            if name == func or name in pending or name in seen:
                continue
            seen.add(name)
            ops = asm_ops(path)
            if not ops or not 0.5 <= len(ops) / max(1, len(target)) <= 2:
                continue
            sm = difflib.SequenceMatcher(None, target, ops, autojunk=False)
            if sm.real_quick_ratio() < EXAMPLE_MIN or sm.quick_ratio() < EXAMPLE_MIN:
                continue
            r = sm.ratio()
            if r >= EXAMPLE_MIN:
                scored.append((r, name))
        scored.sort(reverse=True)
        for r, name in scored:
            if len(out) >= N_EXAMPLES:
                break
            c = c_definition(name, srcs)
            if c:
                out.append((r, name, c))
    except Exception as e:
        log(f"{func}: similar-function search failed: {e}")
    _EXAMPLES[func] = out
    if out:
        log(f"{func}: examples " + ", ".join(f"{n} ({r:.2f})" for r, n, _ in out))
    return out


def extra_tips():
    p = f"{MAIN}/tools/match/llm_tips.md"
    if not os.path.exists(p):
        return ""
    lines = [l.rstrip() for l in open(p) if l.strip() and not l.lstrip().startswith("#")]
    return ("\n\nMore project tricks (tools/match/llm_tips.md):\n" + "\n".join(lines)) if lines else ""


def build_prompt(func, setup, asm, ctx, best, best_fb, last, last_fb, notes=(), session=None):
    comp = (f"Compiler: PsyQ GCC {setup['gcc']} cc1 with `{setup['cc1']}`, output through maspsx "
            f"(ASPSX 2.79 emulation{', --expand-div: divides get the break 6/7 divide-by-zero and overflow checks' if setup['expand_div'] else ', no divide checks'}), "
            "then GNU as. MIPS R3000, little endian; load delay slots are filled with nop where needed.")
    parts = [f"Match `{func}`.", comp,
             "Declarations visible to the function in its source file (relevant ones):\n```c\n" + ctx + "\n```",
             "Target assembly:\n```\n" + asm + "\n```"]
    ex = similar_examples(func)
    if ex:
        parts.append("Already-matched functions in the same overlay whose assembly is similar (similarity in "
                     "brackets); they show the types, struct aliases and statement shapes that produce this "
                     "kind of code, so borrow from them:\n"
                     + "\n".join(f"[{r:.2f}] {n}:\n```c\n{c}\n```" for r, n, c in ex))
    parts += [
             "Best C so far:\n```c\n" + best + "\n```", "Its result:\n```\n" + best_fb + "\n```"]
    if func in START_NOTES:
        parts.append(START_NOTES[func])
    fn = fnotes.read(func).strip()
    if fn:
        if len(fn) > FNOTES_MAX:
            fn = "[... older notes cut ...]\n" + fn[-FNOTES_MAX:]
        parts.append(f"Notes on this function (notes/{func}.md, written by the user, by Claude and by "
                     "earlier sessions; lines tagged (LLM, date) came from a model):\n" + fn)
    if last is not None and last.strip() != best.strip():
        parts += ["Your previous attempt (worse than the best):\n```c\n" + last + "\n```",
                  "Its result:\n```\n" + last_fb + "\n```"]
    if notes:
        parts.append("Handoffs from earlier rounds (oldest first; the result is that round's score):\n"
                     + notes_text(notes))
    if session:
        parts.append(session + f"\nReply with up to the allowed number of variants of `{func}`, then the HANDOFF.")
    else:
        parts.append("Write an improved version of the function, then the HANDOFF.")
    return "\n\n".join(parts)


def split_handoff(text):
    """(answer without the handoff, handoff). Without a HANDOFF: line, the prose around the
    code block stands in for it."""
    m = list(re.finditer(r"^[#*_\s]*HANDOFF[*_\s]*:[*_]*", text, flags=re.M | re.I))
    if m:
        body, h = text[:m[-1].start()], text[m[-1].end():]
    else:
        body, h = text, re.sub(r"```.*?```", "", text, flags=re.S)
    h = re.sub(r"```.*?(```|$)", "", h, flags=re.S).strip()
    return body, (h[:1500] + " [...]" if len(h) > 1500 else h) or "(no handoff written)"


def extract_codes(text, func):
    """Every ```c block that holds the function, in order, without duplicates."""
    blocks = re.findall(r"```(?:c|C)?\s*\n(.*?)```", text, flags=re.S)
    return list(dict.fromkeys(b.strip() + "\n" for b in blocks if func in b))


def extract_code(text, func):
    blocks = extract_codes(text, func)
    return blocks[-1] if blocks else None


# ---------------------------------------------------------------- driver

PERMUTER_DIR = os.path.join(MAIN, "permuter", "nonmatchings")
START_NOTES = {}    # func -> extra note for the first prompt (e.g. where the start code came from)
ALT_STARTS = {}     # func -> other start code to score alongside the usual candidate


def func_span(text, func):
    """(start, end) of FUNC's definition in TEXT (start of its line .. its closing brace), or None."""
    m = re.search(r"^[^\n;{}#]*\b" + func + r"\s*\([^;{]*\)\s*\{", text, re.M)
    if not m:
        return None
    depth, i = 0, m.end() - 1
    while i < len(text):
        c = text[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return m.start(), i + 1
        i += 1
    return None


def cand_prelude(func, cands, idx):
    """The declarations (typedefs, externs, prototypes) in front of FUNC in its queue candidate."""
    if not cands:
        return ""
    try:
        t = open(cands if os.path.isabs(cands) else f"{MAIN}/{cands}").read()
    except OSError:
        return ""
    vs = t.split(f"// @@{func}\n")[1:]
    if len(vs) <= idx:
        return ""
    block = vs[idx].split("\n// @@")[0]
    sp = func_span(block, func)
    return block[: sp[0]] if sp else ""


def permuted_best(func):
    """(score, output dir name, source.c path) of FUNC's best permuter output, or None."""
    best = None
    for src in glob.glob(f"{PERMUTER_DIR}/{func}/output-*-*/source.c"):
        m = re.search(r"output-(\d+)-(\d+)$", os.path.dirname(src))
        if m:
            k = (int(m.group(1)), int(m.group(2)))
            if best is None or k < best[0]:
                best = (k, os.path.basename(os.path.dirname(src)), src)
    return (best[0][0], best[1], best[2]) if best else None


def permuted_code(func, src, cands, idx):
    """FUNC as the permuter left it: the candidate's prelude, any helper the permuter added in
    front of the function (e.g. inline_fn), then the function. None if it can't be found."""
    t = open(src).read()
    sp = func_span(t, func)
    if not sp:
        return None
    start = sp[0]
    # what the permuter started from: base.orig.c once permute_all.sh has moved base.c on to
    # the best output (helpers it added since the draft must count as new)
    d = os.path.dirname(os.path.dirname(src))
    base_p = os.path.join(d, "base.orig.c")
    if not os.path.exists(base_p):
        base_p = os.path.join(d, "base.c")
    if os.path.exists(base_p):
        import difflib
        base = open(base_p).read()
        bsp = func_span(base, func)
        a = base[: bsp[0]].splitlines(True) if bsp else base.splitlines(True)
        b = t[: sp[0]].splitlines(True)
        new = [j1 for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes()
               if tag in ("insert", "replace") and "".join(b[j1:j2]).strip()]
        if new:
            # back up to the start of the top-level item holding the first new line
            j = min(new)
            while j > 0 and b[j - 1].strip() and not b[j - 1].rstrip().endswith((";", "}")):
                j -= 1
            start = sum(len(x) for x in b[:j])
    code = cand_prelude(func, cands, idx) + t[start: sp[1]].strip("\n") + "\n"
    return code


def permuted_jobs(starts):
    """[(func, score, output name, code)] for every function with a permuter output, best first."""
    out = []
    for d in sorted(glob.glob(f"{PERMUTER_DIR}/func_*")):
        func = os.path.basename(d)
        if not re.fullmatch(r"func_[0-9A-Fa-f]+", func):      # e.g. func_800C598C.matched
            continue
        pb = permuted_best(func)
        if not pb:
            continue
        cands, idx = starts.get(func, (None, 0))
        code = permuted_code(func, pb[2], cands, idx)
        if code is None:
            log(f"{func}: can't find the function in {pb[2]}, skipped")
            continue
        out.append((func, pb[0], pb[1], code))
    out.sort(key=lambda x: x[1])
    return out


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


def saved_code(d, func):
    """Code an earlier, interrupted run left: best.c, or (from before best.c was kept up to
    date) every round/turn file."""
    files = ([f"{d}/best.c"] if os.path.exists(f"{d}/best.c")
             else sorted(glob.glob(f"{d}/round*.c") + glob.glob(f"{d}/turn*.c")))
    out = []
    for p in files:
        t = open(p).read()
        if t.startswith(f"// @@{func}\n"):
            out.append(t.split("\n", 1)[1])
    return list(dict.fromkeys(out))


def last_index(d):
    """Highest round/turn number already on disk, so a restart doesn't overwrite them."""
    ns = [int(m.group(1)) for f in os.listdir(d) for m in [re.match(r"(?:round|turn)(\d+)", f)] if m]
    return max(ns, default=0)


def saved_notes(d):
    p = f"{d}/handoffs.txt"
    if not os.path.exists(p):
        return []
    found = re.findall(r"^=== (?:round|turn) (\d+) \((.*?)\)\n(.*?)(?=^=== |\Z)", open(p).read(), re.M | re.S)
    return [(int(n), res, h.strip()) for n, res, h in found]


def save_best(d, func, code):
    open(f"{d}/best.c", "w").write(f"// @@{func}\n{code}")


def starting_point(func, d, cands, idx):
    """(code, (ratio, matched, feedback)) to start from: the best of the queue candidate / m2c
    draft and whatever an earlier run of this function saved. None if there is nothing."""
    first = start_code(func, cands, idx)
    if first is not None and not os.path.exists(f"{d}/start.c"):
        open(f"{d}/start.c", "w").write(f"// @@{func}\n{first}")
    saved = saved_code(d, func)
    alt = [ALT_STARTS[func]] if func in ALT_STARTS else []
    best = None
    for k, code in enumerate(alt + ([first] if first is not None else []) + saved):
        s = score(func, code, f"start{k}")
        if best is None or s[1] or s[0] > best[1][0]:
            best = (code, s)
        if s[1]:
            break
    if best is None:
        return None
    if alt:
        how = ("from the permuter output" if best[0] in alt else
               "from the saved best" if best[0] in saved else "from the queue candidate")
        log(f"{func}: starting {how}: ratio {best[1][0]:.4f}")
        if best[0] not in alt:
            START_NOTES.pop(func, None)    # the permuter's code isn't what the model will see
        save_best(d, func, best[0])
    elif saved:
        how = "from the saved best" if best[0] in saved else f"from the start candidate ({len(saved)} saved scored lower)"
        log(f"{func}: resuming {how}: ratio {best[1][0]:.4f}")
        save_best(d, func, best[0])
    else:
        log(f"{func}: start ratio {best[1][0]:.4f}")
    return best


def iterate(model, func, cands, idx, rounds, temperature):
    sync_workspace()
    src, setup = compiler_setup(func)
    if not src:
        log(f"{func}: already matched (no INCLUDE_ASM)")
        return
    d = f"{OUT}/{func}"
    os.makedirs(d, exist_ok=True)
    sp = starting_point(func, d, cands, idx)
    if sp is None:
        log(f"{func}: no starting candidate (m2c failed)")
        return
    asm = target_asm(func)
    best, (best_r, best_m, best_fb) = sp
    last, last_fb = None, None
    notes = saved_notes(d)                      # (round, result, handoff)
    base = last_index(d)
    for i in range(base + 1, base + rounds + 1):
        if best_m:
            break
        prompt = build_prompt(func, setup, asm, relevant_context(func, best), best, best_fb, last, last_fb,
                              notes)
        if model is None:                       # --dry-run
            open(f"{d}/prompt.txt", "w").write(SYSTEM + "\n=====\n" + prompt)
            log(f"{func}: dry run, prompt ({len(SYSTEM) + len(prompt)} chars) in permuter/llm/{func}/prompt.txt")
            return
        log(f"{func} round {i}: asking the model")
        try:
            answer, thinking = ask(model, SYSTEM, prompt, temperature)
        except Exception as e:
            log(f"{func} round {i}: request failed: {e}")
            time.sleep(10)
            continue
        open(f"{d}/round{i:02d}.txt", "w").write(
            (f"<think>\n{thinking}\n</think>\n" if thinking else "") + answer)
        body, handoff = split_handoff(save_notes(func, answer, f"round {i}"))
        new = extract_code(body, func) or extract_code(answer, func)
        if new is None:
            log(f"{func} round {i}: no C block with {func} in the answer")
            notes.append((i, "no code block found", handoff))
            last, last_fb = None, None
            continue
        r, m, fb = score(func, new, f"r{i}")
        open(f"{d}/round{i:02d}.c", "w").write(f"// @@{func}\n{new}")
        res = ("MATCH" if m else "did not compile" if fb.startswith("COMPILE FAILED")
               else f"ratio {r:.4f}, {'new best' if r > best_r else f'best stays {best_r:.4f}'}")
        notes.append((i, res, handoff))
        with open(f"{d}/handoffs.txt", "a") as f:
            f.write(f"=== round {i} ({res})\n{handoff}\n\n")
        log(f"{func} round {i}: {'MATCH' if m else f'ratio {r:.4f}'} (best {best_r:.4f})")
        if m or r > best_r:
            best, best_r, best_m, best_fb = new, r, m, fb
            save_best(d, func, best)
            last, last_fb = None, None
        else:
            last, last_fb = new, fb
    finish(func, d, best, best_r, best_m)


def finish(func, d, best, best_r, best_m, extra=""):
    open(f"{d}/best.c", "w").write(f"// @@{func}\n{best}")
    line = (f"{time.strftime('%Y-%m-%d %H:%M')} {func}: {'MATCH' if best_m else f'best {best_r:.4f}'}"
            f"{extra} -> permuter/llm/{func}/best.c")
    with open(f"{OUT}/summary.txt", "a") as f:
        f.write(line + "\n")
    log(line)


def get_reply(model, msgs, temperature, think_tokens, no_think, func):
    """One session turn: (answer, thinking, cut). If the thinking passes THINK_TOKENS before an
    answer starts, the request is hung up and re-sent with the tail of that reasoning and an
    instruction to answer with code now (thinking switched off where the server supports it)."""
    budget = think_tokens * 4                   # ~4 characters per token

    def call(m, extra):
        global KWARGS_OK
        if not KWARGS_OK:
            extra = None
        for attempt in range(1, 4):
            try:
                return ask_messages(model, m, temperature, budget, extra)
            except RuntimeError as e:
                msg = str(e)
                if extra and KWARGS_REFUSED.search(msg) and not ENGINE_DOWN.search(msg):
                    log(f"the server refused chat_template_kwargs ({msg[:160]}); not sending it again")
                    KWARGS_OK, extra = False, None
                    continue
                if ENGINE_DOWN.search(msg) and attempt < 3:
                    # Strata restarts its engine on the next request (the model reloads, which
                    # can take a minute), so send the same request again rather than lose the turn
                    log(f"the server's engine stopped ({msg[:160]}); retrying (attempt {attempt + 1}/3, "
                        "the first one reloads the model)")
                    time.sleep(5)
                    continue
                raise
        return ask_messages(model, m, temperature, budget, None)

    answer, thinking = call(msgs, NO_THINK if no_think else None)
    if answer.strip() or not budget:
        return answer, thinking, False
    # we hung up mid-generation: give the server a moment to cancel it before the next request
    # (sending at once is the likeliest trigger for an engine crash)
    time.sleep(3)
    nudge = ("Your thinking budget for this turn ran out before you answered. The end of your "
             "reasoning was:\n\"\"\"\n" + thinking[-2000:].strip() + "\n\"\"\"\n"
             f"Stop reasoning and reply now with up to the allowed number of ```c variants of `{func}` "
             "built on that, then the HANDOFF. The compiler will check them. /no_think")
    answer, more = call(msgs + [{"role": "user", "content": nudge}], NO_THINK)
    return answer, thinking + "\n[thinking cut off; asked for code]\n" + more, True


def est_tokens(msgs):
    return sum(len(m["content"]) for m in msgs) // 3


def iterate_session(model, func, cands, idx, compiles, minutes, temperature, variants, ctx_tokens,
                    think_tokens=4000, no_think=False):
    """One conversation per function: the model sends variants, gets each one's score and
    diff back, and carries on until a match, COMPILES compiles or MINUTES minutes. When the
    history gets long (the model's thinking needs room too), the conversation restarts from
    the best code and the handoff log."""
    sync_workspace()
    src, setup = compiler_setup(func)
    if not src:
        log(f"{func}: already matched (no INCLUDE_ASM)")
        return
    d = f"{OUT}/{func}"
    os.makedirs(d, exist_ok=True)
    sp = starting_point(func, d, cands, idx)
    if sp is None:
        log(f"{func}: no starting candidate (m2c failed)")
        return
    asm = target_asm(func)
    best, (best_r, best_m, best_fb) = sp
    log(f"{func}: budget {compiles} compiles, {minutes:g} min")
    t0 = active_time()
    t_end = t0 + minutes * 60
    turn = last_index(d)
    used, fails, restarts, turns, cuts = 0, 0, 0, 0, 0
    notes, msgs = saved_notes(d), None
    system = session_system(variants)

    def budget():
        return (f"Budget left: {compiles - used} compiles, {max(0, round((t_end - active_time()) / 60))} "
                f"minutes; up to {variants} variants per reply.")

    while not best_m and used < compiles and active_time() < t_end:
        if msgs is None or est_tokens(msgs) > ctx_tokens * 0.35:
            if msgs is not None:
                restarts += 1
                log(f"{func}: conversation at ~{est_tokens(msgs)} tokens, restarting from the best code")
            prompt = build_prompt(func, setup, asm, relevant_context(func, best), best, best_fb, None, None,
                                  notes, session=budget())
            msgs = [{"role": "system", "content": system}, {"role": "user", "content": prompt}]
            if model is None:                   # --dry-run
                open(f"{d}/prompt.txt", "w").write(system + "\n=====\n" + prompt)
                log(f"{func}: dry run, prompt ({len(system) + len(prompt)} chars) in permuter/llm/{func}/prompt.txt")
                return
        turn += 1
        turns += 1
        log(f"{func} turn {turn}: asking the model ({budget()[13:]})")
        try:
            answer, thinking, cut = get_reply(model, msgs, temperature, think_tokens, no_think, func)
            cuts += cut
            fails = 0
        except Exception as e:
            log(f"{func} turn {turn}: request failed: {e}")
            fails += 1
            if fails >= 3:
                log(f"{func}: 3 failed requests in a row, moving on")
                break
            time.sleep(10)
            msgs = None                         # maybe the context was too long: start fresh
            continue
        open(f"{d}/turn{turn:02d}.txt", "w").write(
            (f"<think>\n{thinking}\n</think>\n" if thinking else "") + answer)
        msgs.append({"role": "assistant", "content": answer})
        body, handoff = split_handoff(save_notes(func, answer, f"turn {turn}"))
        blocks =(extract_codes(body, func) or extract_codes(answer, func))[:variants]
        if not blocks:
            log(f"{func} turn {turn}: no C block with {func} in the answer")
            notes.append((turn, "no code block found", handoff))
            msgs.append({"role": "user", "content": f"No ```c block containing `{func}` was found in your "
                         f"reply, so nothing was compiled. {budget()}"})
            continue
        results, tags = [], []
        for j, new in enumerate(blocks, 1):
            if used >= compiles:
                break
            used += 1
            r, m, fb = score(func, new, f"t{turn}v{j}")
            open(f"{d}/turn{turn:02d}_v{j}.c", "w").write(f"// @@{func}\n{new}")
            tag = ("MATCH" if m else "did not compile" if fb.startswith("COMPILE FAILED")
                   else f"ratio {r:.4f}" + (" (new best)" if r > best_r else f" (best is {best_r:.4f})"))
            if m or r > best_r:
                best, best_r, best_m, best_fb = new, r, m, fb
                save_best(d, func, best)
            lines = fb.splitlines()
            fb = "\n".join(lines[:60]) + ("\n[... more differing lines]" if len(lines) > 60 else "")
            results.append(f"Variant {j}: {tag}\n```\n{fb}\n```")
            tags.append(f"v{j} {tag}")
            if m:
                break
        notes.append((turn, "; ".join(tags), handoff))
        with open(f"{d}/handoffs.txt", "a") as f:
            f.write(f"=== turn {turn} ({'; '.join(tags)})\n{handoff}\n\n")
        log(f"{func} turn {turn}: " + "; ".join(tags))
        msgs.append({"role": "user", "content": "\n\n".join(results) + "\n\n" + budget()})
    why = ("" if best_m else "compile budget used" if used >= compiles
           else "time up" if active_time() >= t_end else "requests failing")
    finish(func, d, best, best_r, best_m,
           f" ({used} compiles, {turns} turns, {int((active_time() - t0) / 60)} min"
           + (f", {restarts} restarts" if restarts else "") + (f", thinking cut {cuts}x" if cuts else "")
           + (f"; {why}" if why else "") + ")")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("funcs", nargs="*")
    ap.add_argument("--parked", metavar="OV", help="work through tools/match/parked_OV.txt")
    ap.add_argument("--queue", help='file of "CANDS.c FUNC [IDX]" lines')
    ap.add_argument("--permuted", action="store_true",
                    help="work through the functions the permuter has outputs for, starting from its best code")
    ap.add_argument("--compiles", type=int, default=40, help="compiles per function (default 40)")
    ap.add_argument("--minutes", type=float, default=30, help="minutes per function (default 30)")
    ap.add_argument("--variants", type=int, default=3, help="variants the model may send per reply (default 3)")
    ap.add_argument("--ctx", type=int, default=131072,
                    help="the model's context in tokens; the conversation restarts at ~35%% of it (default 131072)")
    ap.add_argument("--think", type=int, default=4000, metavar="TOKENS",
                    help="thinking budget per reply: past it the reply is cut off and the model is told "
                         "to send code now (default 4000; 0 = unlimited)")
    ap.add_argument("--no-think", action="store_true",
                    help="ask the server to switch thinking off (Qwen3-style enable_thinking=false)")
    ap.add_argument("--rounds", type=int,
                    help="old mode instead: N independent rounds, a fresh prompt each time")
    ap.add_argument("--temperature", type=float, default=0.6)
    ap.add_argument("--skip-done", action="store_true", help="skip functions already in summary.txt")
    ap.add_argument("--dry-run", action="store_true", help="build and save the first prompt only; no model")
    ap.add_argument("--quiet", action="store_true", help="don't stream the model's thinking and answer to the window")
    ap.add_argument("--examples", type=int, default=2,
                    help="similar matched functions shown in the first prompt (default 2, 0 = none)")
    a = ap.parse_args()
    global N_EXAMPLES
    N_EXAMPLES = a.examples
    global STREAM
    STREAM = not a.quiet

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
    permuted_from = {}

    def use_permuter(func, sc, name, code):
        """offer FUNC's best permuter output as a starting point (scored with the others)"""
        ALT_STARTS[func] = code
        permuted_from[func] = f"{name}\n"
        START_NOTES[func] = (
            f"Note: the best C above came from decomp-permuter ({name}/source.c, permuter score {sc}; "
            "lower is better, 0 = match). The permuter makes random changes to find better codegen, so it "
            "can contain odd or wrong C: unused or uninitialised variables, a strange return type such as "
            "`volatile unsigned long long`, identity helpers like inline_fn, reordered or merged statements. "
            "Keep the changes that make the assembly closer, but send real, equivalent C: undo the ones "
            "that change what the function does.")

    if a.permuted:
        pj = permuted_jobs(starts)
        if a.funcs:                       # --permuted FUNC...: only those
            pj = [x for x in pj if x[0] in a.funcs]
            a.funcs = []
        for x in pj:
            use_permuter(*x)
        jobs += [f for f, *_ in pj]
        log(f"permuter outputs: " + ", ".join(f"{f} ({sc})" for f, sc, *_ in pj) if pj else "no permuter outputs")
    jobs += a.funcs
    # every other function with a permuter output gets it as a starting point too (selection,
    # lists, --queue, --parked), not only --permuted runs
    for f in dict.fromkeys(jobs):
        if f in ALT_STARTS:
            continue
        pb = permuted_best(f)
        if pb:
            cands, idx = starts.get(f, (None, 0))
            code = permuted_code(f, pb[2], cands, idx)
            if code is not None:
                use_permuter(f, pb[0], pb[1], code)
    if a.skip_done and os.path.exists(f"{OUT}/summary.txt"):
        done = set(re.findall(r" (func_\w+): ", open(f"{OUT}/summary.txt").read()))

        def already(j):
            if j not in done:
                return False
            if j not in permuted_from:
                return True
            p = f"{OUT}/{j}/permuted_from.txt"     # skip only if it already ran from this same output
            return os.path.exists(p) and open(p).read() == permuted_from[j]
        jobs = [j for j in jobs if not already(j)]
    if not jobs:
        sys.exit("nothing to do (give functions, --parked, --queue or --permuted)")
    os.makedirs(OUT, exist_ok=True)
    try:
        model = None if a.dry_run else pick_model()
    except RuntimeError as e:
        sys.exit(f"can't reach the model server: {e}\n"
                 f"(LLM_BASE_URL={BASE}; key {'set' if KEY else 'NOT set: STRATA_API_KEY / LLM_API_KEY'})")
    log(f"model {model} at {BASE}; {len(jobs)} function(s), "
        + (f"{a.rounds} rounds each" if a.rounds else
           f"up to {a.compiles} compiles / {a.minutes:g} min each, {a.variants} variants per reply, "
           + ("thinking off" if a.no_think else f"thinking cut at {a.think} tokens" if a.think
              else "thinking unlimited")))
    for f in dict.fromkeys(jobs):
        try:
            cands, idx = starts.get(f, (None, 0))
            if f in permuted_from and not a.dry_run:
                os.makedirs(f"{OUT}/{f}", exist_ok=True)
                open(f"{OUT}/{f}/permuted_from.txt", "w").write(permuted_from[f])
            if a.rounds:
                iterate(model, f, cands, idx, a.rounds, a.temperature)
            else:
                iterate_session(model, f, cands, idx, a.compiles, a.minutes, a.temperature, a.variants, a.ctx,
                                a.think, a.no_think)
        except KeyboardInterrupt:
            raise
        except Exception as e:
            log(f"{f}: error: {e}")


if __name__ == "__main__":
    main()
