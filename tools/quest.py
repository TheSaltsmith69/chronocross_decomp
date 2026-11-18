#!/usr/bin/env python3
"""Build a quest list from a boot trace: which functions run, and are they done?

Reads a trace CSV from tools/ds_trace.py (progress/traces/<name>.csv) and the
current build, and writes progress/quest_<name>.csv with one row per traced
function: order, seconds, addr, name, category, file, bytes, matched.

usage: .venv/bin/python3 tools/quest.py boot_to_title
"""
import csv, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from progress import ROOT, load_text_files, elf_functions, c_status  # noqa: E402


def main():
    name = sys.argv[1]
    trace = ROOT / "progress" / "traces" / f"{name}.csv"
    files = load_text_files()
    funcs = elf_functions()
    addrs = sorted(funcs)

    def locate(a):
        for start, end, fname, typ in files:
            if start <= a < end:
                nxt = next((x for x in addrs if x > a), end)
                size = min(nxt, end) - a
                asm = c_status(fname) if typ == "c" else None
                matched = asm is not None and funcs.get(a) not in asm
                return fname, size, matched
        return "?", 0, False

    rows = []
    with open(trace, newline="") as fh:
        for r in csv.DictReader(fh):
            a = int(r["addr"], 16)
            fname, size, matched = locate(a)
            rows.append({
                "order": r["order"], "seconds": r["seconds"], "addr": r["addr"],
                "name": funcs.get(a, r["name"]), "category": "lib" if r["category"] == "l" else "game",
                "file": fname, "bytes": size, "matched": int(matched),
            })

    out = ROOT / "progress" / f"quest_{name}.csv"
    with open(out, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)

    for cat in ("game", "lib"):
        rs = [r for r in rows if r["category"] == cat]
        done = [r for r in rs if r["matched"]]
        print(f"{cat:4}: {len(done)}/{len(rs)} funcs, "
              f"{sum(r['bytes'] for r in done)}/{sum(r['bytes'] for r in rs)} bytes")
    print("wrote", out)


if __name__ == "__main__":
    main()
