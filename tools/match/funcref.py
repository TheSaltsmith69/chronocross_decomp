"""Function references that stay unambiguous across overlays.

Several overlays load at the same address (four at 0x801EE000, three in slot B), so
splat gives their functions the same names: ov_enct, ov_party, ov_party2 and ov_monmenu
each have a func_801EE000. A reference is either a plain name or `NAME@MODULE`, where
MODULE is the folder under src/ (ov_party2, ov_battle, game, lib, ...):

    func_801EE000@ov_party2

A plain name is fine while only one source file still has it as INCLUDE_ASM (or
defines it). When several do, `find()` stops with the qualified names to choose
from, instead of silently taking the first file. Candidate blocks (`// @@REF`),
queue lines, permuter/LLM result folders and the tools' arguments all take
either form; result folders of an ambiguous name use the qualified form.
"""
import glob, os, re

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))


class Ambiguous(SystemExit):
    pass


def split(ref):
    """'func_X@ov_party' -> ('func_X', 'ov_party'); 'func_X' -> ('func_X', None)."""
    name, _, mod = ref.partition("@")
    return name, (mod or None)


def name_of(ref):
    return split(ref)[0]


def module_of_src(path):
    """src/ov_party/party_801EE000.c -> 'ov_party' (first folder under src/)."""
    rel = os.path.relpath(os.path.abspath(path), os.path.join(ROOT, "src"))
    return rel.split(os.sep)[0]


def _inc(name):
    return re.compile(r'^INCLUDE_ASM\("([^"]+)",\s*' + re.escape(name) + r'\);', re.M)


def sources(name, texts=None, defs=False):
    """Source files that hold NAME as INCLUDE_ASM (and, with defs, as a C definition)."""
    inc = _inc(name)
    dfn = re.compile(r'^[A-Za-z_][\w \t\*]*\b' + re.escape(name) + r'\s*\([^;]*$', re.M)
    if texts is None:
        texts = {p: open(p).read() for p in sorted(glob.glob(f"{ROOT}/src/**/*.c", recursive=True))}
    out = [p for p, t in sorted(texts.items()) if inc.search(t)]
    if defs and not out:
        out = [p for p, t in sorted(texts.items()) if dfn.search(t)]
    return out


def find(ref, texts=None, defs=False):
    """The one source file REF refers to. Exits with a clear message when there is none,
    or when a plain name matches several files (listing the qualified refs to use)."""
    name, mod = split(ref)
    hits = sources(name, texts, defs)
    if mod:
        hits = [p for p in hits if module_of_src(p) == mod]
    if not hits:
        raise SystemExit(f"{ref}: not found under src/" + (" (no INCLUDE_ASM or definition)" if defs else " (no INCLUDE_ASM)"))
    if len(hits) > 1:
        raise Ambiguous(f"{ref} is in {len(hits)} source files; use one of: "
                        + ", ".join(f"{name}@{module_of_src(p)}" for p in hits))
    return hits[0]


def asm_path(ref):
    """The function's nonmatchings .s file (taken from the INCLUDE_ASM folder of its source)."""
    name, mod = split(ref)
    src = find(ref)
    m = _inc(name).search(open(src).read())
    p = os.path.join(ROOT, m.group(1), name + ".s")
    if os.path.exists(p):
        return p
    hits = glob.glob(f"{ROOT}/asm/{mod or '*'}/nonmatchings/**/{name}.s", recursive=True)
    if not hits:
        raise SystemExit(f"{ref}: no .s under asm/")
    return hits[0]


def ambiguous_names(texts=None):
    """{name: [module, ...]} for every name that is INCLUDE_ASM in more than one file."""
    if texts is None:
        texts = {p: open(p).read() for p in glob.glob(f"{ROOT}/src/**/*.c", recursive=True)}
    seen = {}
    pat = re.compile(r'^INCLUDE_ASM\("[^"]+",\s*(\w+)\);', re.M)
    for p, t in texts.items():
        for n in pat.findall(t):
            seen.setdefault(n, []).append(module_of_src(p))
    return {n: sorted(m) for n, m in seen.items() if len(m) > 1}


_ASM_MODS = None


def asm_modules(name):
    """The modules (folders under asm/) that have a NAME.s, matched or not."""
    global _ASM_MODS
    if _ASM_MODS is None:
        _ASM_MODS = {}
        base = os.path.join(ROOT, "asm")
        for dp, _, files in os.walk(base):
            mod = os.path.relpath(dp, base).split(os.sep)[0]
            for f in files:
                if f.endswith(".s"):
                    _ASM_MODS.setdefault(f[:-2], set()).add(mod)
    return _ASM_MODS.get(name, set())


def result_key(ref, texts=None):
    """Folder name for this function's permuter/LLM results (and its notes): NAME@MODULE when
    several overlays have a function of that name, even if only one of them is still asm
    (the control panel shows those twins as NAME@MODULE too), else the plain name. A qualified
    REF stays as given, so a queue line's name and its folder always agree."""
    name, mod = split(ref)
    if mod:
        return ref
    if len(asm_modules(name)) <= 1 and len(sources(name, texts)) <= 1:
        return name
    return f"{name}@{module_of_src(find(ref, texts))}"   # exits with the choices if REF is a plain twin
