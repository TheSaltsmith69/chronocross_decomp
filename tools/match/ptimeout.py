#!/usr/bin/env python3
"""ptimeout.py SECONDS [--used-file F] -- CMD... : like `timeout --signal=INT --kill-after=30s`,
but paused time (see pauseclock.py) doesn't count, so a job paused from the control panel
gets its whole budget after it resumes. Exit status: CMD's, or 124 when the budget ran out.
--used-file F: write the active seconds used to F at the end.
A SIGINT/SIGTERM to this process is passed on to CMD (if CMD didn't get it already), and CMD is
killed 30 s later if it is still running (the permuter can hang on exit).
"""
import os, signal, subprocess, sys, time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pauseclock import active_time

args = sys.argv[1:]
secs = float(args.pop(0))
used_file = None
if args and args[0] == "--used-file":
    args.pop(0)
    used_file = args.pop(0)
if args and args[0] == "--":
    args.pop(0)

start = active_time()
p = subprocess.Popen(args)
kill_at = None
timed_out = False


def on_signal(sig, _):
    global kill_at
    try:
        p.send_signal(signal.SIGINT if sig == signal.SIGINT else signal.SIGTERM)
    except ProcessLookupError:
        pass
    if kill_at is None:
        kill_at = time.monotonic() + 30


signal.signal(signal.SIGINT, on_signal)
signal.signal(signal.SIGTERM, on_signal)
while p.poll() is None:
    time.sleep(0.5)
    if not timed_out and active_time() - start >= secs:
        timed_out = True
        try:
            p.send_signal(signal.SIGINT)
        except ProcessLookupError:
            pass
        kill_at = time.monotonic() + 30
    if kill_at is not None and time.monotonic() >= kill_at:
        try:
            p.kill()
        except ProcessLookupError:
            pass
        kill_at = float("inf")
code = p.wait()
if used_file:
    with open(used_file, "w") as f:
        f.write(f"{int(active_time() - start)}\n")
sys.exit(124 if timed_out else code)
