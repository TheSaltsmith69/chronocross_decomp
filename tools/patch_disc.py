#!/usr/bin/env python3
"""Write a file (e.g. the rebuilt SLUS_010.41) into a copy of a PS1 disc image.

The image must be raw MODE2/2352 (BIN/CUE). The file is located through the
ISO9660 root directory, overwritten in place (it may not grow past the
sectors it already has), and every touched sector gets fresh EDC/ECC so the
emulator / console sees valid Form 1 sectors.

usage:
  patch_disc.py --bin IN.bin --file SLUS_010.41 --data build/SLUS_010.41 --out OUT.bin
  patch_disc.py --bin IN.bin --verify SLUS_010.41      # check EDC/ECC code on the original
"""
import argparse, os, shutil, struct, sys

SECTOR = 2352
DATA_OFF = 24          # Mode 2 Form 1: 12 sync + 4 header + 8 subheader
DATA_LEN = 2048

# ---------------------------------------------------------------- EDC / ECC
EDC_LUT = []
for i in range(256):
    e = i
    for _ in range(8):
        e = (e >> 1) ^ (0xD8018001 if e & 1 else 0)
    EDC_LUT.append(e)

ECC_F = [0] * 256
ECC_B = [0] * 256
for i in range(256):
    j = ((i << 1) ^ (0x11D if i & 0x80 else 0)) & 0xFF
    ECC_F[i] = j
    ECC_B[i ^ j] = i


def edc(buf):
    e = 0
    for b in buf:
        e = (e >> 8) ^ EDC_LUT[(e ^ b) & 0xFF]
    return e


def ecc_block(src, major_count, minor_count, major_mult, minor_inc):
    size = major_count * minor_count
    out = bytearray(major_count * 2)
    for major in range(major_count):
        index = (major >> 1) * major_mult + (major & 1)
        a = b = 0
        for _ in range(minor_count):
            t = src[index]
            index += minor_inc
            if index >= size:
                index -= size
            a ^= t
            b ^= t
            a = ECC_F[a]
        a = ECC_B[ECC_F[a] ^ b]
        out[major] = a
        out[major + major_count] = a ^ b
    return out


def fix_form1(sector):
    """Recompute EDC + ECC of a Mode 2 Form 1 sector (bytearray, in place)."""
    struct.pack_into("<I", sector, 0x818, edc(sector[0x10:0x818]))
    hdr = bytes(sector[0x0C:0x10])
    sector[0x0C:0x10] = b"\0\0\0\0"            # Mode 2: address is not covered
    sector[0x81C:0x81C + 172] = ecc_block(sector[0x0C:], 86, 24, 2, 86)
    sector[0x8C8:0x8C8 + 104] = ecc_block(sector[0x0C:], 52, 43, 86, 88)
    sector[0x0C:0x10] = hdr


# ---------------------------------------------------------------- ISO9660
def read_sector(f, lba):
    f.seek(lba * SECTOR)
    return bytearray(f.read(SECTOR))


def user_data(f, lba):
    return read_sector(f, lba)[DATA_OFF:DATA_OFF + DATA_LEN]


def find_file(f, name):
    pvd = user_data(f, 16)
    assert pvd[1:6] == b"CD001", "not an ISO9660 image (or not MODE2/2352)"
    root = pvd[156:156 + 34]
    lba, size = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]
    want = name.upper()
    for s in range((size + DATA_LEN - 1) // DATA_LEN):
        d = user_data(f, lba + s)
        i = 0
        while i < DATA_LEN and d[i]:
            ln = d[i]
            ident = bytes(d[i + 33:i + 33 + d[i + 32]]).decode("ascii", "replace")
            if ident.split(";")[0].upper() == want:
                return struct.unpack_from("<I", d, i + 2)[0], struct.unpack_from("<I", d, i + 10)[0]
            i += ln
    raise SystemExit(f"{name} not found in root directory")


# ---------------------------------------------------------------- main
def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--bin", required=True)
    ap.add_argument("--file", default="SLUS_010.41")
    ap.add_argument("--data", help="new contents for --file")
    ap.add_argument("--out", help="patched image to write")
    ap.add_argument("--verify", action="store_true",
                    help="recompute EDC/ECC of the file's sectors and compare with the image")
    a = ap.parse_args()

    with open(a.bin, "rb") as f:
        lba, size = find_file(f, a.file)
        nsec = (size + DATA_LEN - 1) // DATA_LEN
        print(f"{a.file}: LBA {lba}, {size} bytes, {nsec} sectors")
        if a.verify:
            bad = 0
            for s in range(nsec):
                orig = read_sector(f, lba + s)
                test = bytearray(orig)
                fix_form1(test)
                bad += test != orig
            print("EDC/ECC check:", "OK" if not bad else f"{bad} sectors differ")
            return 1 if bad else 0

    if not (a.data and a.out):
        ap.error("--data and --out are required to patch")
    new = open(a.data, "rb").read()
    if len(new) > nsec * DATA_LEN:
        raise SystemExit(f"new file is {len(new)} bytes; only {nsec * DATA_LEN} fit in place")
    if len(new) != size:
        print(f"warning: size changes {size} -> {len(new)}; directory record not updated")

    if os.path.abspath(a.out) != os.path.abspath(a.bin):
        shutil.copyfile(a.bin, a.out)
    changed = 0
    with open(a.out, "r+b") as f:
        for s in range(nsec):
            sec = read_sector(f, lba + s)
            chunk = new[s * DATA_LEN:(s + 1) * DATA_LEN].ljust(DATA_LEN, b"\0")
            if sec[DATA_OFF:DATA_OFF + DATA_LEN] == chunk:
                continue
            sec[DATA_OFF:DATA_OFF + DATA_LEN] = chunk
            fix_form1(sec)
            f.seek((lba + s) * SECTOR)
            f.write(sec)
            changed += 1
    cue = os.path.splitext(a.out)[0] + ".cue"
    with open(cue, "w") as c:
        c.write(f'FILE "{os.path.basename(a.out)}" BINARY\n  TRACK 01 MODE2/2352\n    INDEX 01 00:00:00\n')
    print(f"wrote {a.out} ({changed} sectors changed) and {cue}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
