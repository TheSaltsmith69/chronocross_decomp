#!/usr/bin/env python3
"""Dump PS1 RAM from a running DuckStation through its GDB server.

Play to the moment you want (nothing needs to run while you do), then:

    python tools/ds_dump.py NAME [--out DIR] [--port 2345]

It connects, pauses the game, reads main RAM (2 MB at 0x80000000) and the
scratchpad (1 KB at 0x1F800000), writes DIR/NAME_ram.bin and DIR/NAME_scratch.bin
(the same files PCSX-Redux's dump() makes, see tools/find_overlays.py), then
detaches so the game carries on. Takes a few seconds.

DuckStation needs [Debug] EnableGDBServer = true (port 2345 here). Run it on the
machine DuckStation runs on (Windows python; WSL can't reach Windows localhost).
"""
import argparse, os, socket, sys, time

RAM, RAM_SIZE = 0x80000000, 0x200000
SCRATCH, SCRATCH_SIZE = 0x1F800000, 0x400


class Gdb:
    def __init__(self, host, port, timeout=5.0):
        try:
            self.s = socket.create_connection((host, port), timeout=timeout)
        except OSError as e:
            raise SystemExit(f"can't connect to DuckStation's GDB server on {host}:{port} ({e}).\n"
                             "Is DuckStation running with the game started, and EnableGDBServer = true?")
        self.buf = b""

    def _byte(self, timeout):
        self.s.settimeout(timeout)
        if not self.buf:
            data = self.s.recv(65536)
            if not data:
                raise SystemExit("DuckStation closed the connection")
            self.buf = data
        b, self.buf = self.buf[:1], self.buf[1:]
        return b

    def packet(self, timeout=10.0):
        """Next packet payload, or None on timeout. Acks it."""
        try:
            while self._byte(timeout) != b"$":
                pass
            data = bytearray()
            while True:
                c = self._byte(timeout)
                if c == b"#":
                    self._byte(timeout), self._byte(timeout)
                    break
                if c == b"}":                               # escaped byte
                    c = bytes([self._byte(timeout)[0] ^ 0x20])
                data += c
            self.s.sendall(b"+")
            return data.decode("latin-1")
        except socket.timeout:
            return None

    def send(self, data):
        self.s.sendall(f"${data}#{sum(data.encode()) & 0xFF:02x}".encode())

    def cmd(self, data, timeout=10.0):
        self.send(data)
        while True:
            r = self.packet(timeout)
            if r is None or not r.startswith("O") or r == "OK":    # skip console output packets
                return r

    def read(self, addr, size, chunk):
        out = bytearray()
        while len(out) < size:
            n = min(chunk, size - len(out))
            r = self.cmd(f"m{addr + len(out):x},{n:x}")
            if not r or r.startswith("E") or len(r) % 2:
                raise IOError(f"read at {addr + len(out):#x} failed: {r!r}")
            got = bytes.fromhex(r)
            if not got:
                raise IOError(f"empty read at {addr + len(out):#x}")
            out += got                                      # a server may return less than asked
        return bytes(out)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name", help="dump name, e.g. status (writes status_ram.bin)")
    ap.add_argument("--out", default=os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "dumps"),
                    help="folder for the .bin files")
    ap.add_argument("--port", type=int, default=2345)
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--chunk", type=int, default=0x800, help="bytes per memory read")
    a = ap.parse_args()

    os.makedirs(a.out, exist_ok=True)
    t0 = time.time()
    g = Gdb(a.host, a.port)
    sup = g.cmd("qSupported:swbreak+") or ""
    for f in sup.split(";"):                               # respect the server's packet size
        if f.startswith("PacketSize="):
            a.chunk = max(0x40, min(a.chunk, (int(f.split("=")[1], 16) - 16) // 2))
    g.s.sendall(b"\x03")                                   # pause, if it isn't already
    g.packet(2.0)
    try:
        ram = g.read(RAM, RAM_SIZE, a.chunk)
        try:
            scratch = g.read(SCRATCH, SCRATCH_SIZE, a.chunk)
        except IOError:
            scratch = None
    finally:
        g.send("D")                                        # detach: the game carries on
        g.packet(2.0)
    rp = os.path.join(a.out, f"{a.name}_ram.bin")
    open(rp, "wb").write(ram)
    print(f"wrote {os.path.abspath(rp)} ({len(ram):#x} bytes)")
    if scratch is not None:
        sp = os.path.join(a.out, f"{a.name}_scratch.bin")
        open(sp, "wb").write(scratch)
        print(f"wrote {os.path.abspath(sp)}")
    else:
        print("(scratchpad not readable through this server; main RAM is what matters)")
    print(f"done in {time.time() - t0:.1f}s, game resumed")


if __name__ == "__main__":
    sys.exit(main())
