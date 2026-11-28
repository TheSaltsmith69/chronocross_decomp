"""Per-function notes: notes/FUNC.md at the repo root, one Markdown file per function.

Written by you (the control panel's function window, or any editor), by the LLM loop (lines a
model starts with NOTE:, appended with a "(LLM, date)" tag) and by Claude. The LLM loop puts
the file in every prompt for that function, so anything learned about it (what it does,
struct layouts, what was tried and failed) carries over to later sessions.
"""
import os
import re
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
DIR = os.path.join(ROOT, "notes")
NAME = re.compile(r"[A-Za-z_]\w{0,80}(@\w{1,40})?")      # FUNC or FUNC@MODULE (funcref.py)
MAX = 200_000


def path(func):
    if not NAME.fullmatch(func or ""):
        raise ValueError(f"bad function name {func!r}")
    return os.path.join(DIR, func + ".md")


def read(func):
    try:
        with open(path(func), encoding="utf-8", errors="replace") as f:
            return f.read()
    except OSError:
        return ""


def mtime(func):
    try:
        return os.path.getmtime(path(func))
    except OSError:
        return 0


def write(func, text):
    """Replace the notes; empty text deletes the file."""
    p = path(func)
    text = (text or "")[:MAX]
    if not text.strip():
        if os.path.exists(p):
            os.remove(p)
        return
    os.makedirs(DIR, exist_ok=True)
    with open(p + ".tmp", "w", encoding="utf-8") as f:
        f.write(text.rstrip() + "\n")
    os.replace(p + ".tmp", p)


def append(func, lines, who="LLM"):
    """Add LINES as bullet points tagged with WHO and the time; skips ones already there.
    Returns the lines added."""
    cur = read(func)
    have = {re.sub(r"^- \([^)]*\) ", "", l).strip() for l in cur.splitlines()}
    new = [l.strip() for l in lines if l.strip() and l.strip() not in have]
    new = list(dict.fromkeys(new))
    if not new:
        return []
    stamp = time.strftime("%Y-%m-%d %H:%M")
    add = "".join(f"- ({who}, {stamp}) {l}\n" for l in new)
    write(func, (cur.rstrip() + "\n\n" if cur.strip() else f"# {func}\n\n") + add)
    return new


def set_section(func, name, body):
    """Replace (or add, at the end) the block between <!-- NAME --> and <!-- /NAME -->: a part
    of the notes a tool rewrites each time instead of appending to. Empty BODY removes it."""
    cur = read(func)
    start, end = f"<!-- {name} -->", f"<!-- /{name} -->"
    block = f"{start}\n{body.strip()}\n{end}\n" if body.strip() else ""
    pat = re.compile(re.escape(start) + r"[\s\S]*?" + re.escape(end) + r"\n?")
    if pat.search(cur):
        new = pat.sub(lambda m: block, cur, count=1)
    elif block:
        new = (cur.rstrip() + "\n\n" if cur.strip() else f"# {func}\n\n") + block
    else:
        return
    write(func, new)


def listing():
    """{func: mtime} of every function with notes"""
    out = {}
    try:
        for n in os.listdir(DIR):
            if n.endswith(".md"):
                out[n[:-3]] = os.path.getmtime(os.path.join(DIR, n))
    except OSError:
        pass
    return out


NOTE_LINE = re.compile(r"^[ \t>*_-]*NOTE[*_ \t]*:[*_]*[ \t]*(.+)$", re.M | re.I)


def from_reply(text, limit=4):
    """(NOTE: lines a model wrote, text without them). Lines inside code blocks don't count."""
    outside = re.sub(r"```.*?(```|$)", "", text, flags=re.S)
    found = [m.group(1).strip() for m in NOTE_LINE.finditer(outside)]
    found = [f[:400] for f in found if len(f) > 3][:limit]
    return found, NOTE_LINE.sub("", text) if found else text
