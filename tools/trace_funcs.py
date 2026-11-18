#!/usr/bin/env python3
"""Write <out>/funcs.lua: every function start in the main EXE text, for trace_boot.lua."""
import subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
out = Path(sys.argv[1])
out.mkdir(parents=True, exist_ok=True)
nm = subprocess.run(["mips-linux-gnu-nm", "-n", str(ROOT / "build/slus_010.41.elf")],
                    capture_output=True, text=True, check=True).stdout
seen = {}
for line in nm.splitlines():
    p = line.split()
    if len(p) == 3 and p[1] in "Tt":
        a = int(p[0], 16)
        name = p[2]
        if not (0x80010000 <= a < 0x80056530):
            continue
        if name in ("__gnu_compiled_c", "gcc2_compiled.") or name.startswith((".", "L")) or "_TEXT_" in name:
            continue
        seen.setdefault(a, name)
# Tag each function game ("g") or PsyQ library ("l") from the splat file layout.
sys.path.insert(0, str(ROOT / "tools"))
from progress import load_text_files  # noqa: E402
files = load_text_files()

def cat(a):
    for start, end, name, _ in files:
        if start <= a < end:
            return "l" if name.startswith("lib/") else "g"
    return "g"

lines = ["return {"] + [f'  {{0x{a:08X}, "{n}", "{cat(a)}"}},' for a, n in sorted(seen.items())] + ["}"]
(out / "funcs.lua").write_text("\n".join(lines) + "\n")
n_g = sum(1 for a in seen if cat(a) == "g")
print(f"{len(seen)} functions ({n_g} game, {len(seen) - n_g} lib) -> {out / 'funcs.lua'}")
