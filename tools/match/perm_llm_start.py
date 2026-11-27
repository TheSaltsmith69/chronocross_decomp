"""perm_llm_start.py permuter/nonmatchings/FUNC -- start the permuter from the LLM's best when it's better.

permute_all.sh runs this before each visit, after it has moved base.c on to the best permuter
output. If the LLM loop has a best.c for FUNC (permuter/llm/FUNC/best.c) that this hasn't
checked yet, it is spliced into base.c in place of the function and scored the way the
permuter scores (permuter.py --debug: one compile, no permuting). When that beats what base.c
scores now, it becomes base.c (the original draft stays in base.orig.c, its score in
base.score; base.from holds the new score). The permuter has to parse the C itself (pycparser),
so LLM code it can't read is skipped with a message. Each best.c is checked once (llm.checked).
"""
import glob
import os
import re
import shutil
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, "..", ".."))
sys.path.insert(0, HERE)
PY = sys.executable
PERMUTER = os.path.join(ROOT, "tools", "decomp-permuter", "permuter.py")


def read(p, default=""):
    try:
        with open(p, errors="replace") as f:
            return f.read()
    except OSError:
        return default


def debug_score(dirpath, text):
    """The permuter's score for TEXT as the base of DIRPATH's job, or (None, why)."""
    tmp = tempfile.mkdtemp(prefix="llmstart_", dir=os.path.dirname(os.path.abspath(dirpath)))
    try:
        for n in os.listdir(dirpath):
            p = os.path.join(dirpath, n)
            if os.path.isfile(p) and not n.startswith(("base", "llm.")):
                shutil.copy(p, tmp)
        with open(os.path.join(tmp, "base.c"), "w") as f:
            f.write(text)
        r = subprocess.run(["nice", "-n", "10", PY, PERMUTER, tmp, "--debug"], cwd=ROOT,
                           capture_output=True, text=True, timeout=300)
        out = r.stdout + r.stderr
        m = re.search(r"base score = (\d+)", out)
        if m:
            return int(m.group(1)), ""
        last = [l for l in out.splitlines() if l.strip()][-3:]
        return None, " / ".join(last)[:300] or f"exit code {r.returncode}"
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
        for junk in ("debug_source.c", "debug_compiled_object.o"):   # --debug leaves these in cwd
            try:
                os.remove(os.path.join(ROOT, junk))
            except OSError:
                pass


def best_output_score(dirpath):
    s = [int(m.group(1)) for o in glob.glob(os.path.join(dirpath, "output-*"))
         for m in [re.search(r"output-(\d+)-\d+$", o)] if m]
    return min(s) if s else None


def main(dirpath):
    import gui_diff
    func = os.path.basename(dirpath.rstrip("/"))
    best = os.path.join(ROOT, "permuter", "llm", func, "best.c")
    if not os.path.exists(best):
        return
    st = os.stat(best)
    stamp = f"{st.st_mtime:.3f} {st.st_size}"
    mark = os.path.join(dirpath, "llm.checked")
    if read(mark).strip() == stamp:
        return                                  # this best.c was already looked at
    with open(mark, "w") as f:
        f.write(stamp + "\n")
    base_p = os.path.join(dirpath, "base.c")
    try:
        text = gui_diff.splice(read(base_p), read(best), func)
    except Exception as e:
        print(f"{func}: the LLM's best couldn't be put into base.c ({e}); not used")
        return
    llm, why = debug_score(dirpath, text)
    if llm is None:
        print(f"{func}: the permuter can't use the LLM's best ({why}); not used")
        return
    known = [int(x) for x in [read(os.path.join(dirpath, "base.from")).strip()] if x.isdigit()]
    known += [x for x in [best_output_score(dirpath)] if x is not None]
    cur = min(known) if known else None         # the best the permuter has, base.c or an output
    if cur is None:
        cur, _ = debug_score(dirpath, read(base_p))
    if cur is not None and llm >= cur:
        print(f"{func}: the LLM's best scores {llm}, not better than the permuter's {cur}; not used")
        return
    if not os.path.exists(os.path.join(dirpath, "base.orig.c")):
        shutil.copy(base_p, os.path.join(dirpath, "base.orig.c"))
        m = re.search(r"base score = (\d+)", read(os.path.join(ROOT, "permuter", f"{func}.log"))[:65536])
        if m and not os.path.exists(os.path.join(dirpath, "base.score")):
            with open(os.path.join(dirpath, "base.score"), "w") as f:
                f.write(m.group(1) + "\n")
    with open(base_p, "w") as f:
        f.write(text)
    with open(os.path.join(dirpath, "base.from"), "w") as f:
        f.write(f"{llm}\n")
    print(f"{func}: starting from the LLM's best (score {llm}"
          + (f", the permuter's best was {cur}" if cur is not None else "") + ")")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        sys.exit(__doc__.split("\n")[0])
    try:
        main(sys.argv[1])
    except Exception as e:                      # never stop the permuter run over this
        print(f"{os.path.basename(sys.argv[1].rstrip('/'))}: LLM best check skipped ({e})")
