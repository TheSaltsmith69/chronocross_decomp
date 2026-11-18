#!/usr/bin/env python3
"""Boot tracer using DuckStation's GDB server.

Puts a software breakpoint on every main-EXE function, continues, and on
each hit records the function (first hit only), removes its breakpoint and
continues again. Writes <out>/ds_hits.csv as it goes.

DuckStation settings needed (settings.ini): [Main] StartPaused = true,
[Debug] EnableGDBServer = true, GDBServerPort = 2345.

usage: ds_trace.py FUNCS.lua OUT_DIR [--seconds 120] [--port 2345]
"""
import argparse, re, socket, sys, time
from pathlib import Path


class Gdb:
    def __init__(self, host, port, timeout=60):
        deadline = time.time() + timeout
        while True:
            try:
                self.s = socket.create_connection((host, port), timeout=5)
                break
            except OSError:
                if time.time() > deadline:
                    raise SystemExit(f"could not connect to GDB server on {host}:{port}")
                time.sleep(0.5)
        self.buf = b""

    def _read_byte(self, timeout):
        self.s.settimeout(timeout)
        if not self.buf:
            data = self.s.recv(4096)
            if not data:
                raise SystemExit("GDB server closed the connection")
            self.buf = data
        b, self.buf = self.buf[:1], self.buf[1:]
        return b

    def read_packet(self, timeout=10.0):
        """Next packet payload (str), or None on timeout."""
        try:
            while True:
                c = self._read_byte(timeout)
                if c == b"$":
                    break
            data = b""
            while True:
                c = self._read_byte(timeout)
                if c == b"#":
                    self._read_byte(timeout); self._read_byte(timeout)
                    break
                data += c
            self.s.sendall(b"+")
            return data.decode("latin-1")
        except socket.timeout:
            return None

    def send(self, data):
        pkt = f"${data}#{sum(data.encode()) & 0xFF:02x}".encode()
        self.s.sendall(pkt)

    def cmd(self, data, timeout=10.0):
        self.send(data)
        while True:
            r = self.read_packet(timeout)
            if r is None or not r.startswith(("O", )) or r == "OK":
                return r

    def interrupt(self):
        self.s.sendall(b"\x03")

    def pc(self):
        regs = self.cmd("g")
        if not regs or len(regs) < 38 * 8:
            r = self.cmd("p25")  # register 37 = pc
            return int.from_bytes(bytes.fromhex(r[:8]), "little") if r else None
        return int.from_bytes(bytes.fromhex(regs[37 * 8:38 * 8]), "little")


def load_funcs(path):
    out = []
    for m in re.finditer(r'\{0x([0-9A-Fa-f]{8}), "([^"]+)", "(\w)"\}', Path(path).read_text()):
        out.append((int(m.group(1), 16), m.group(2), m.group(3)))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("funcs")
    ap.add_argument("out")
    ap.add_argument("--seconds", type=float, default=120)
    ap.add_argument("--port", type=int, default=2345)
    a = ap.parse_args()

    funcs = load_funcs(a.funcs)
    by_addr = {f[0]: f for f in funcs}
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    csv_path = out / "ds_hits.csv"

    g = Gdb("127.0.0.1", a.port)
    print("connected; qSupported:", g.cmd("qSupported:swbreak+")[:80])
    print("status:", g.cmd("?"))

    armed = 0
    for addr, _, _ in funcs:
        r = g.cmd(f"Z0,{addr:x},4")
        if r == "OK":
            armed += 1
        elif armed == 0:
            raise SystemExit(f"Z0 refused: {r!r}")
    print(f"armed {armed}/{len(funcs)} breakpoints")

    hits = []
    t0 = time.time()

    def save():
        lines = ["order,seconds,addr,name,category"]
        lines += [f"{i + 1},{t:.2f},{addr:08X},{n},{c}" for i, (t, addr, n, c) in enumerate(hits)]
        csv_path.write_text("\n".join(lines) + "\n")

    last_save = time.time()
    g.send("c")
    while True:
        elapsed = time.time() - t0
        if elapsed >= a.seconds:
            g.interrupt()
            g.read_packet(10)
            break
        r = g.read_packet(timeout=max(0.5, min(5.0, a.seconds - elapsed)))
        if r is None:
            if time.time() - last_save > 5:
                save(); last_save = time.time()
            continue
        if not (r.startswith("S") or r.startswith("T")):
            continue  # console output etc.
        pc = g.pc()
        f = by_addr.get(pc)
        if f:
            hits.append((time.time() - t0, pc, f[1], f[2]))
            g.cmd(f"z0,{pc:x},4")
            if len(hits) % 50 == 0:
                print(f"{len(hits)} functions hit, t={time.time() - t0:.0f}s")
        else:
            print(f"stopped at unexpected pc {pc!r} ({r})")
        g.send("c")

    save()
    # leave the game running for the viewer
    for addr, _, _ in funcs:
        if addr not in {h[1] for h in hits}:
            g.cmd(f"z0,{addr:x},4", timeout=2)
    g.send("D")
    g.read_packet(2)
    n_g = sum(1 for h in hits if h[3] == "g")
    print(f"done: {len(hits)} functions hit ({n_g} game, {len(hits) - n_g} lib) in {a.seconds:.0f}s -> {csv_path}")


if __name__ == "__main__":
    sys.exit(main())
