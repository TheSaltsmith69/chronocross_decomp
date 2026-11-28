#!/usr/bin/env python3
"""permute.py CANDS.c FUNC[@MODULE] [IDX] -- import a trycc candidate block into decomp-permuter.

For a name several overlays share, give FUNC@MODULE (funcref.py); the folder is then
permuter/nonmatchings/FUNC@MODULE.

Puts variant IDX (default 0) of FUNC's "// @@FUNC" block from CANDS.c in place of
the function's INCLUDE_ASM line, runs tools/decomp-permuter/import.py on that
source file and the function's .s, then restores the source file. The permuter
directory is created under permuter/ (gitignored):

    .venv/bin/python3 tools/decomp-permuter/permuter.py permuter/nonmatchings/FUNC -j8
"""
import glob, os, re, shutil, subprocess, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import funcref

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
cands, ref = sys.argv[1], sys.argv[2]
idx = int(sys.argv[3]) if len(sys.argv) > 3 else 0
func = funcref.name_of(ref)                    # plain C name
# folder name: NAME@MODULE for a shared name or a qualified REF (the queue line's name, which
# permute_all.sh looks for)
key = funcref.result_key(ref)
text = open(cands).read()
# (blocks headed with the plain name count too: candidate files from before NAME@MODULE)
blocks = next((v for v in (text.split(f"// @@{h}\n")[1:] for h in dict.fromkeys((ref, key, func))) if v), [])
if idx >= len(blocks):
    sys.exit(f"{cands}: no variant {idx} of {ref}")
block = blocks[idx].split("\n// @@")[0].rstrip() + "\n"

src = funcref.find(ref)
orig = open(src).read()
m = re.compile(r'^INCLUDE_ASM\("([^"]+)", ' + re.escape(func) + r'\);$', re.M).search(orig)
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
if key != func and os.path.basename(job) != key:
    # import.py names the folder after the plain function; a shared name gets NAME@MODULE
    # so its twins' results never mix (the control panel and permute_all.sh look there)
    dest = f"{ROOT}/permuter/nonmatchings/{key}"
    if os.path.exists(dest):
        shutil.rmtree(dest)
    os.rename(job, dest)
    job = dest

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
