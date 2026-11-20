#!/usr/bin/env python3
"""Decomp progress report for SLUS_010.41 and its overlays.

Reads the splat configs, the built ELFs and src/*.c, and reports how many
functions / bytes of code are written in C ("matched") vs still asm.

usage: .venv/bin/python3 tools/progress.py [--json out.json]
Run `make` first so build/ is up to date.
"""
import argparse, csv, datetime, json, re, subprocess, sys
from pathlib import Path

import yaml

ROOT = Path(__file__).resolve().parent.parent
NM = "mips-linux-gnu-nm"

# (overlay name or None, splat config, segment name, built ELF, src dir).
# Main-EXE rows are categorised game/lib by file name; every row of an overlay
# gets the overlay's name as its category.
MODULES = [
    (None, ROOT / "slus_010.41.yaml", "main", ROOT / "build" / "slus_010.41.elf", ROOT / "src"),
    ("ov_field", ROOT / "ov_field.yaml", "ov_field", ROOT / "build" / "ov_field.elf", ROOT / "src" / "ov_field"),
]
OVERLAYS = [m[0] for m in MODULES if m[0]]


def load_text_files(config, segment):
    """[(vram_start, vram_end, name, type)] for a code segment's files."""
    cfg = yaml.safe_load(config.read_text())
    main = next(s for s in cfg["segments"] if isinstance(s, dict) and s.get("name") == segment)
    rom0, vram0 = main["start"], main["vram"]
    subs = []
    for s in main["subsegments"]:
        if isinstance(s, list) and len(s) >= 3 and s[1] in ("asm", "c"):
            subs.append((s[0] - rom0 + vram0, s[2], s[1]))
        elif isinstance(s, list) and len(s) >= 2 and s[1].lstrip(".") in ("data", "rodata", "bss", "bin"):
            subs.append((s[0] - rom0 + vram0, None, "end"))
    files = []
    for (a, name, t), (b, _, _) in zip(subs, subs[1:]):
        if t in ("asm", "c"):
            files.append((a, b, name, t))
    return files


def elf_functions(elf):
    out = subprocess.run([NM, "-n", str(elf)], capture_output=True, text=True, check=True).stdout
    funcs = {}
    for line in out.splitlines():
        parts = line.split()
        if len(parts) == 3 and parts[1] in "Tt":
            addr, name = int(parts[0], 16), parts[2]
            if name in ("__gnu_compiled_c", "gcc2_compiled."):
                continue  # gcc marker labels, not functions
            if not name.startswith((".", "L")) and "_TEXT_" not in name and "_ROM_" not in name:
                funcs.setdefault(addr, name)
    return funcs


def c_status(src_dir, unit):
    """(set of INCLUDE_ASM names) for <src_dir>/<unit>.c, or None if not a C file."""
    p = src_dir / f"{unit}.c"
    if not p.exists():
        return None
    names = set()
    for folder, name in re.findall(r'INCLUDE_ASM\(\s*"([^"]+)"\s*,\s*(\w+)\s*\)', p.read_text()):
        names.add(name)
        # Extra entry points inside the included asm (glabel mid-function) are still asm too.
        s = ROOT / folder / f"{name}.s"
        if s.exists():
            names.update(re.findall(r'^\s*(?:glabel|alabel)\s+(\w+)', s.read_text(), re.M))
    return names


def category(name):
    if name.startswith("lib/"):
        return "lib"
    return "game"


def module_files(ov, config, segment, elf, src_dir):
    """Report rows for every code file of one module (main EXE or an overlay)."""
    files = load_text_files(config, segment)
    funcs = elf_functions(elf)
    addrs = sorted(funcs)
    report_files = []
    for start, end, name, typ in files:
        fa = [a for a in addrs if start <= a < end]
        if not fa or fa[0] != start:
            fa = [start] + fa  # file starts mid-symbol; count it as one function
        asm_names = c_status(src_dir, name) if typ == "c" else None
        entries = []
        for i, a in enumerate(fa):
            size = (fa[i + 1] if i + 1 < len(fa) else end) - a
            fname = funcs.get(a, f"func_{a:08X}")
            matched = asm_names is not None and fname not in asm_names
            entries.append((fname, size, matched))
        report_files.append({
            "file": f"{ov}/{name}" if ov else name,
            "category": ov or category(name),
            "start": f"{start:08X}",
            "funcs": len(entries),
            "funcs_matched": sum(1 for e in entries if e[2]),
            "bytes": sum(e[1] for e in entries),
            "bytes_matched": sum(e[1] for e in entries if e[2]),
            "matched": [e[0] for e in entries if e[2]],
        })
    return report_files


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--json", help="write report JSON here")
    ap.add_argument("--files-csv", help="write one row per code file here")
    ap.add_argument("--history", help="add this commit's totals to this history CSV")
    args = ap.parse_args()

    report_files = []
    for ov, config, segment, elf, src_dir in MODULES:
        if not elf.exists():
            print(f"skipping {segment}: {elf.relative_to(ROOT)} not built")
            continue
        report_files += module_files(ov, config, segment, elf, src_dir)

    def total(cat=None):
        fs = [f for f in report_files if cat is None or f["category"] == cat]
        return {
            "files": len(fs),
            "funcs": sum(f["funcs"] for f in fs),
            "funcs_matched": sum(f["funcs_matched"] for f in fs),
            "bytes": sum(f["bytes"] for f in fs),
            "bytes_matched": sum(f["bytes_matched"] for f in fs),
        }

    commit = subprocess.run(["git", "-C", str(ROOT), "rev-parse", "--short", "HEAD"],
                            capture_output=True, text=True).stdout.strip()
    report = {
        "generated": datetime.datetime.now(datetime.timezone.utc).isoformat(timespec="seconds"),
        "commit": commit,
        "total": total(),
        "game": total("game"),
        "lib": total("lib"),
        **{ov: total(ov) for ov in OVERLAYS},
        "blob_8008E488_bytes": 0x15378,  # second module, not disassembled yet
        "files": report_files,
    }

    for key in ("game", "lib", *OVERLAYS, "total"):
        t = report[key]
        pct = 100 * t["bytes_matched"] / t["bytes"] if t["bytes"] else 0
        print(f"{key:8}: {t['funcs_matched']:4}/{t['funcs']:4} funcs, "
              f"{t['bytes_matched']:6}/{t['bytes']:6} bytes ({pct:.2f}%)")
    if args.json:
        Path(args.json).write_text(json.dumps(report, indent=1))
        print("wrote", args.json)
    if args.files_csv:
        with open(args.files_csv, "w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(["file", "category", "start", "funcs", "funcs_matched", "bytes", "bytes_matched"])
            for f in report_files:
                w.writerow([f["file"], f["category"], f["start"], f["funcs"], f["funcs_matched"],
                            f["bytes"], f["bytes_matched"]])
        print("wrote", args.files_csv)
    if args.history:
        update_history(Path(args.history), report)


HISTORY_STATS = ("funcs_matched", "funcs", "bytes_matched", "bytes")
HISTORY_COLS = ["date", "commit"] + [f"{k}_{c}" for k in ("game", "lib", *OVERLAYS) for c in HISTORY_STATS]


def update_history(path, report):
    """Add (or replace) this commit's row in the history CSV."""
    rows = []
    if path.exists():
        with open(path, newline="") as fh:
            rows = [r for r in csv.DictReader(fh) if r["commit"] != report["commit"]]
    row = {"date": report["generated"][:10], "commit": report["commit"]}
    for k in ("game", "lib", *OVERLAYS):
        if not report[k]["files"]:
            continue  # module not built here (e.g. overlay not extracted): leave it empty
        for c in HISTORY_STATS:
            row[f"{k}_{c}"] = report[k][c]
    rows.append(row)
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", newline="") as fh:
        # Rows from before a module was tracked keep its columns empty.
        w = csv.DictWriter(fh, fieldnames=HISTORY_COLS, restval="")
        w.writeheader()
        w.writerows(rows)
    print("updated", path)


if __name__ == "__main__":
    sys.exit(main())
