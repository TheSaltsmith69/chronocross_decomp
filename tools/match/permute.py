#!/usr/bin/env python3
"""permute.py CANDS.c FUNC [IDX] -- import a trycc candidate block into decomp-permuter.

Puts variant IDX (default 0) of FUNC's "// @@FUNC" block from CANDS.c in place of
the function's INCLUDE_ASM line, runs tools/decomp-permuter/import.py on that
source file and the function's .s, then restores the source file. The permuter
directory is created under permuter/ (gitignored):

    .venv/bin/python3 tools/decomp-permuter/permuter.py permuter/nonmatchings/FUNC -j8
"""
import glob, os, re, subprocess, sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
cands, func = sys.argv[1], sys.argv[2]
idx = int(sys.argv[3]) if len(sys.argv) > 3 else 0
text = open(cands).read()
blocks = text.split("// @@" + func + "\n")[1:]
if idx >= len(blocks):
    sys.exit(f"{cands}: no variant {idx} of {func}")
block = blocks[idx].split("\n// @@")[0].rstrip() + "\n"

pat = re.compile(r'^INCLUDE_ASM\("([^"]+)", ' + re.escape(func) + r'\);$', re.M)
for src in glob.glob(f"{ROOT}/src/**/*.c", recursive=True):
    orig = open(src).read()
    m = pat.search(orig)
    if m:
        break
else:
    sys.exit(f"no INCLUDE_ASM for {func} under src/")
asm = os.path.join(ROOT, m.group(1), func + ".s")
os.makedirs(f"{ROOT}/permuter", exist_ok=True)
try:
    open(src, "w").write(orig[: m.start()] + block + orig[m.end() :])
    r = subprocess.run([sys.executable, f"{ROOT}/tools/decomp-permuter/import.py", src, asm],
                       cwd=f"{ROOT}/permuter")
finally:
    open(src, "w").write(orig)
if r.returncode:
    sys.exit(r.returncode)

# compile.sh: the object's real recipe from the Makefile, reading "$1" and writing "$3"
rel = os.path.relpath(src, ROOT)
obj = "build/" + rel[:-2] + ".o"
dry = subprocess.run(["make", "--always-make", "--dry-run", obj], cwd=ROOT,
                     capture_output=True, text=True).stdout.splitlines()
line = next(l for l in dry if rel in l and " -o " in l)
line = line.replace(rel, '"$INPUT"', 1)
line = line[: line.rindex(" -o ")] + ' -o "$OUTPUT"'
jobs = sorted(glob.glob(f"{ROOT}/permuter/nonmatchings/{func}*"), key=os.path.getmtime)
job = jobs[-1]

# Top-level __asm__("...") statements (e.g. the ".section .rodata / .align 3" jump-table
# alignment lines in the field overlay) are not C the permuter's parser can read; they only
# move other functions' rodata, which the permuter never compares, so drop them from base.c.
base = f"{job}/base.c"
text = open(base).read()
fixed, n = re.subn(r'^[ \t]*(?:_permuter_ignore_line[ \t]+)?(?:__asm__|asm)[ \t]*\((?:[^;"]|"(?:\\.|[^"\\])*")*\)[ \t]*;[ \t]*$',
                   "", text, flags=re.M)
if n:
    open(base, "w").write(fixed)
    print(f"base.c: dropped {n} top-level asm statement(s)")
with open(f"{job}/compile.sh", "w") as f:
    f.write("#!/usr/bin/env bash\nset -euo pipefail\n")
    f.write('INPUT="$(realpath "$1")"\nOUTPUT="$(realpath "$3")"\n')
    f.write(f"cd {ROOT}\n{line}\n")
os.chmod(f"{job}/compile.sh", 0o755)
print(f"compile.sh <- {obj} recipe")
print(f"run: .venv/bin/python3 tools/decomp-permuter/permuter.py {os.path.relpath(job, ROOT)} -j8")
