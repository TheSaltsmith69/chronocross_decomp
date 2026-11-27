#!/usr/bin/env python3
"""permwatch.py FUNC MINUTES LOG [--every-compile] -- live progress for one decomp-permuter run.

Reads the permuter's output on stdin (permute_all.sh pipes it here), copies all of it to LOG
and prints to the console:
  - the base score when the permuter has compiled the starting C,
  - a line each time a compile beats the best score so far (with the compile number),
  - a status line that updates in place on every compile: compiles done and rate, the score
    of the latest compile, the best score, errors and time left,
  - a permanent progress line once a minute (so the window keeps a history),
  - with --every-compile, one permanent line per compile instead of the in-place line.
Lower scores are better; 0 is a full match.
"""
import os, re, sys, time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pauseclock import active_time      # time.time() minus paused time (control panel)

func, minutes, log_path = sys.argv[1], float(sys.argv[2]), sys.argv[3]
every = "--every-compile" in sys.argv[4:]
tty = sys.stdout.isatty()

GREEN, BOLD, DIM, RESET = ("\033[32;1m", "\033[1m", "\033[2m", "\033[0m") if tty else ("",) * 4
ITER = re.compile(r"iteration (\d+), (\d+) errors, (?:(\d+) permuter failures, )?score = (\S+)")
BASE = re.compile(r"base score = (\d+)")
BEST = re.compile(r"found new best score! \((\d+) vs (\d+)\)")
TIED = re.compile(r"tied best score! \((\d+) vs (\d+)\)")
NOISE = ("warnings.warn", "resource_tracker", "leaked semaphore")
WROTE = re.compile(r"wrote to (\S+)")
ANSI = re.compile(r"\x1b\[[0-9;]*m")

start = active_time()
deadline = start + minutes * 60
base = best = last = None
compiles = errors = 0
live = False          # an in-place status line is on screen
last_minute = start
other = []            # unrecognised output, shown at the end unless it is the Ctrl+C traceback


def clock():
    return time.strftime("%H:%M:%S")


def left():
    s = max(0, int(deadline - active_time()))
    return f"{s // 60}:{s % 60:02d}"


def rate():
    el = active_time() - start
    return compiles / el if el > 0 else 0.0


def status():
    b = f"{best}" if best is not None else "?"
    pct = f" ({100 * (base - best) / base:.1f}% better)" if base and best is not None and best < base else ""
    return (f"  {func}: compile {compiles} ({rate():.1f}/s) | this {last} | best {b}{pct}"
            f" | base {base if base is not None else '?'} | {errors} errors | {left()} left")


def say(msg):
    """Print a permanent line, clearing the in-place status line first."""
    global live
    if live:
        sys.stdout.write("\r\033[K" if tty else "\n")
        live = False
    sys.stdout.write(msg + "\n")
    sys.stdout.flush()


def show_live():
    global live
    if every or not tty:
        return
    sys.stdout.write("\r\033[K" + DIM + status() + RESET)
    sys.stdout.flush()
    live = True


def handle(line):
    global base, best, last, compiles, errors, last_minute
    line = ANSI.sub("", line).strip()
    if not line:
        return
    m = ITER.search(line)
    if m:
        compiles, errors, last = int(m.group(1)), int(m.group(2)), m.group(4)
        if every:
            say(f"{clock()} {status().strip()}")
        elif time.time() - last_minute >= 60:
            last_minute = time.time()
            say(f"{clock()} {status().strip()}")
        else:
            show_live()
        return
    m = BASE.search(line)
    if m:
        base = best = int(m.group(1))
        say(f"{clock()} {BOLD}{func}: base score {base}{RESET} (the starting C; 0 = match)")
        return
    m = BEST.search(line)
    if m:
        new, old = int(m.group(1)), int(m.group(2))
        prev = best
        best = new
        say(f"{clock()} {GREEN}{func}: IMPROVED at compile {compiles + 1}: {prev} -> {new}"
            f" (base {old}){RESET}")
        return
    m = TIED.search(line)
    if m:
        say(f"{clock()} {func}: another variant tied the best score {m.group(1)} (compile {compiles + 1})")
        return
    if any(n in line for n in NOISE):
        return
    m = WROTE.search(line)
    if m:
        say(f"           saved {m.group(1)}/source.c")
        return
    if "Found zero score" in line:
        say(f"{clock()} {GREEN}{func}: FULL MATCH (score 0){RESET}")
        return
    if line.startswith("Exiting"):
        say(f"{clock()} {func}: time is up, stopping the permuter")
        return
    if line.startswith(("Loading", "Will try", "No perm macros")) or line.endswith("base.c (" + func + ")"):
        return
    other.append(line)


with open(log_path, "w") as log:
    say(f"{clock()} {func}: compiling the starting C ({minutes:g} min budget)")
    buf = ""
    while True:
        chunk = sys.stdin.buffer.read1(4096)
        if not chunk:
            break
        text = chunk.decode("utf-8", "replace")
        log.write(text)
        log.flush()
        buf += text
        parts = re.split(r"[\r\n\b]+", buf)
        buf = parts.pop()
        for p in parts:
            handle(p)
    if buf:
        handle(buf)

if not any("KeyboardInterrupt" in l for l in other):
    for l in other[-15:]:
        say("  | " + l)
b = best if best is not None else "none"
say(f"{clock()} {func}: done after {compiles} compiles, best {b} (base {base if base is not None else '?'})")
