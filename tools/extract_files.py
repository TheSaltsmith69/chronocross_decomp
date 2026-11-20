#!/usr/bin/env python3
"""Extract files from the Chrono Cross disc image by index.

Only SLUS_010.41 and SYSTEM.CNF are in the ISO9660 directory. Every other
file is found through the game's own table at LBA 24, one u32 per file:
  bits 0-22  start LBA
  bit  23    set on placeholder entries (they repeat the next file's LBA)
  bits 24-31 unknown (not a plain size)
A file is taken to span from its LBA up to the next distinct LBA in the
table (whole 2048-byte sectors, trailing zeros included).

Usage:
  tools/extract_files.py <disc1.bin> <out_dir> <index> [<index> ...]
  tools/extract_files.py <disc1.bin> --list
"""
import os
import struct
import sys

RAW = 2352      # raw Mode 2 sector size in the .bin
HDR = 24        # sync + header + subheader before the 2048 user bytes
TABLE_LBA = 24


def read_sectors(f, lba, count):
    out = bytearray()
    for i in range(count):
        f.seek((lba + i) * RAW + HDR)
        out += f.read(2048)
    return bytes(out)


def load_table(f):
    """Return the list of raw u32 entries."""
    # The table starts at LBA 24, +4 (after a small header word) and runs
    # until an entry falls outside the plausible LBA range.
    raw = read_sectors(f, TABLE_LBA, 16)
    ents = []
    for o in range(4, len(raw), 4):
        v = struct.unpack_from('<I', raw, o)[0]
        lba = v & 0x7FFFFF
        if not (300 <= lba < 400000) or (ents and lba < (ents[-1] & 0x7FFFFF)):
            break
        ents.append(v)
    return ents


def span(ents, i):
    lba = ents[i] & 0x7FFFFF
    for v in ents[i + 1:]:
        if (v & 0x7FFFFF) != lba:
            return lba, (v & 0x7FFFFF) - lba
    return lba, 0


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    with open(sys.argv[1], 'rb') as f:
        ents = load_table(f)
        if sys.argv[2] == '--list':
            for i, v in enumerate(ents):
                lba, n = span(ents, i)
                flag = ' (placeholder)' if v & 0x800000 else ''
                print('%5d  %08x  lba %7d  %5d sectors%s' % (i, v, lba, n, flag))
            return
        out_dir = sys.argv[2]
        os.makedirs(out_dir, exist_ok=True)
        for arg in sys.argv[3:]:
            i = int(arg, 0)
            lba, n = span(ents, i)
            data = read_sectors(f, lba, n)
            path = os.path.join(out_dir, '%04d.bin' % i)
            with open(path, 'wb') as o:
                o.write(data)
            print('file %d: lba %d, %d sectors -> %s (%#x bytes)' % (i, lba, n, path, len(data)))


if __name__ == '__main__':
    main()
