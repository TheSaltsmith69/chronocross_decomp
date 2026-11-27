#!/usr/bin/env python3
"""Find which disc files with code are loaded in a RAM dump, and where.

  tools/find_overlays.py --scan <disc.bin> [--out iso/code_files_discN.txt]
      list every file in the disc's file table that looks like MIPS code (jr ra and
      stack-frame prologues), with the load address its own jal targets point to
  tools/find_overlays.py <disc.bin> <dump_ram.bin>...
      for each 2 MB RAM dump (PCSX-Redux dump("name"), see redux_ram_dumps.md):
      which of those code files are in RAM, at which address, and how much of the
      file still matches (data/BSS change after loading, code doesn't)

The scan takes a minute per disc; --out caches it (a later run with the same disc
reads the cache if it exists next to the default path).
"""
import collections, os, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import extract_files as ef

JR_RA = 0x03E00008
RAM0 = 0x80000000


def looks_like_code(data):
    n = len(data) // 4
    ws = struct.unpack_from("<%dI" % n, data)
    jr = sum(1 for w in ws if w == JR_RA)
    if jr < 8:
        return None
    pro = [i * 4 for i, w in enumerate(ws) if (w & 0xFFFF8000) == 0x27BD8000]      # addiu sp,sp,-N
    tg = [RAM0 | ((w & 0x3FFFFFF) << 2) for w in ws if w >> 26 == 3]
    votes = collections.Counter()
    for t, _ in collections.Counter(tg).most_common(60):
        for o in pro[:400]:
            b = t - o
            if b & 3 == 0 and 0x80010000 <= b < 0x80200000:
                votes[b] += 1
    base = votes.most_common(1)[0][0] if votes else 0
    inside = sum(1 for t in tg if base <= t < base + len(data)) / max(1, len(tg))
    return {"jr": jr, "prologues": len(pro), "base": base, "inside": inside}


def scan(disc):
    out = []
    with open(disc, "rb") as f:
        ents = ef.load_table(f)
        seen = set()
        for i, v in enumerate(ents):
            lba, cnt = ef.span(ents, i)
            if v & 0x800000 or lba in seen or cnt <= 0 or cnt > 400:
                continue
            seen.add(lba)
            r = looks_like_code(ef.read_sectors(f, lba, cnt))
            if r:
                out.append((i, lba, cnt, r))
    return out


def cache_path(disc):
    return os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "iso",
                        "code_files_" + os.path.basename(disc).replace(" ", "_") + ".txt")


def load_scan(disc):
    p = cache_path(disc)
    if os.path.exists(p):
        rows = []
        for l in open(p):
            i, lba, cnt, jr, pro, base, inside = l.split()
            rows.append((int(i), int(lba), int(cnt), {"jr": int(jr), "prologues": int(pro),
                                                      "base": int(base, 16), "inside": float(inside)}))
        return rows
    rows = scan(disc)
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, "w") as fh:
        for i, lba, cnt, r in rows:
            fh.write(f"{i} {lba} {cnt} {r['jr']} {r['prologues']} {r['base']:#x} {r['inside']:.3f}\n")
    return rows


def find_in(ram, data):
    """(address, fraction of the file's words equal in RAM there) or None. Anchors on a few
    distinctive 32-byte runs of the file (code survives loading unchanged)."""
    best = None
    tried = set()
    for frac in (0.1, 0.3, 0.5, 0.7, 0.9):
        o = int(len(data) * frac) & ~3
        while o + 32 <= len(data) and len(set(data[o:o + 32])) < 12:   # skip zero/padding runs
            o += 32
        chunk = data[o:o + 32]
        if len(chunk) < 32:
            continue
        p = ram.find(chunk)
        while p >= 0:
            start = p - o
            if start >= 0 and start not in tried:
                tried.add(start)
                end = min(len(ram), start + len(data))
                n = (end - start) // 4
                a = struct.unpack_from("<%dI" % n, ram, start)
                b = struct.unpack_from("<%dI" % n, data, 0)
                same = sum(1 for x, y in zip(a, b) if x == y) / max(1, len(data) // 4)
                if not best or same > best[1]:
                    best = (RAM0 + start, same)
            p = ram.find(chunk, p + 4)
    return best


def main():
    a = sys.argv[1:]
    if len(a) >= 2 and a[0] == "--scan":
        rows = scan(a[1])
        dest = a[a.index("--out") + 1] if "--out" in a else None
        for i, lba, cnt, r in rows:
            line = (f"file {i:5d}  lba {lba:7d}  {cnt * 2048:#8x} bytes  jr ra {r['jr']:4d}  "
                    f"prologues {r['prologues']:4d}  loads at ~{r['base']:#010x} ({r['inside']:.0%} of jals inside)")
            print(line)
        if dest:
            with open(dest, "w") as fh:
                for i, lba, cnt, r in rows:
                    fh.write(f"{i} {lba} {cnt} {r['jr']} {r['prologues']} {r['base']:#x} {r['inside']:.3f}\n")
        return
    if len(a) < 2:
        sys.exit(__doc__)
    disc, dumps = a[0], a[1:]
    rows = load_scan(disc)
    with open(disc, "rb") as f:
        files = {i: ef.read_sectors(f, lba, cnt) for i, lba, cnt, _ in rows}
    for d in dumps:
        ram = open(d, "rb").read()
        print(f"== {d}")
        hits = []
        for i, data in files.items():
            r = find_in(ram, data)
            if r and r[1] >= 0.5:
                hits.append((r[0], i, len(data), r[1]))
        for addr, i, size, same in sorted(hits):
            print(f"   file {i:5d}  at {addr:#010x}-{addr + size:#010x}  {same:.0%} of the file matches")
        if not hits:
            print("   no known code file found (only the EXE)")


if __name__ == "__main__":
    main()
