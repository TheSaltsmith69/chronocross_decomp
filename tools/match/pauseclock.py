"""pauseclock.py -- time that doesn't count while a job is paused.

control_gui.py pauses a job by stopping its processes (SIGSTOP) and keeps a ledger file,
named by the PAUSE_LEDGER environment variable, holding two numbers:
    <seconds paused in total, finished pauses>  <epoch when the current pause began, or 0>
active_time() is time.time() minus all paused time, so budgets and stall timers measured
with it carry on where they were after a resume instead of firing at once. Without a
ledger it is just time.time().
"""
import os
import time

LEDGER = os.environ.get("PAUSE_LEDGER") or ""


def paused_total(now=None):
    if not LEDGER:
        return 0.0
    try:
        total, since = (float(x) for x in open(LEDGER).read().split()[:2])
    except (OSError, ValueError):
        return 0.0
    now = time.time() if now is None else now
    return total + (now - since if since > 0 else 0.0)


def active_time():
    now = time.time()
    return now - paused_total(now)


def write(path, total, since):
    tmp = path + ".tmp"
    with open(tmp, "w") as f:
        f.write(f"{total:.3f} {since:.3f}\n")
    os.replace(tmp, path)
