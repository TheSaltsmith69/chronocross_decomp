#!/usr/bin/env python3
"""Convert trace_boot.lua raw screenshots (shot_*.raw + .txt) to PNG."""
import struct, sys, zlib
from pathlib import Path


def png(path, w, h, rgb):
    def chunk(t, d):
        return struct.pack(">I", len(d)) + t + d + struct.pack(">I", zlib.crc32(t + d) & 0xFFFFFFFF)
    rows = b"".join(b"\0" + rgb[y * w * 3:(y + 1) * w * 3] for y in range(h))
    path.write_bytes(b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0))
                     + chunk(b"IDAT", zlib.compress(rows, 6)) + chunk(b"IEND", b""))


def convert(raw):
    w, h, bpp = map(int, raw.with_suffix(".txt").read_text().split())
    data = raw.read_bytes()
    if bpp == 24:
        rgb = data[:w * h * 3]
    else:
        out = bytearray(w * h * 3)
        for i in range(w * h):
            v = data[2 * i] | (data[2 * i + 1] << 8)
            r, g, b = v & 31, (v >> 5) & 31, (v >> 10) & 31
            out[3 * i:3 * i + 3] = bytes(((r << 3) | (r >> 2), (g << 3) | (g >> 2), (b << 3) | (b >> 2)))
        rgb = bytes(out)
    dst = raw.with_suffix(".png")
    png(dst, w, h, rgb)
    return dst, w, h, bpp


if __name__ == "__main__":
    d = Path(sys.argv[1])
    for raw in sorted(d.glob("shot_*.raw")):
        dst, w, h, bpp = convert(raw)
        print(f"{dst.name}: {w}x{h} {bpp}bpp")
