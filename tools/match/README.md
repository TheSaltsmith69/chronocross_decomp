# tools/match

Helpers for matching functions one batch at a time. Run them from WSL; they find the repo
from their own location, so they work from any directory. Candidate files may be given as
relative or absolute paths (for example a Windows scratch folder under `/mnt/c/...`).

## Candidate files

A candidate file holds C blocks, each headed by the name of the function it replaces:

```c
// @@func_800B5C1C
s32 func_800B5C1C(s32 a) { ... }
// @@func_800B5C1C
s32 func_800B5C1C(s32 a) { ... }   /* a second variant, tried in the next round */
```

The source file that holds the function's `INCLUDE_ASM` is found automatically.

## Everyday loop

| Step | Command |
|---|---|
| Pick candidates | `next.sh 16 all` (overlay, skips `parked_<OV>.txt` + `skip_<OV>.txt`), `libnext.sh 10`, `qdump.py 600` (boot-path quest) |
| Rank easiest-first | `rank.py ov_field` then `easy.py` |
| Compare | `try.sh CANDS.c` (`trycc.py` with `--show`), `tryd.sh` (differing lines only), `showf.sh CANDS.c FUNC` |
| Lock in | `trycc.py CANDS.c --keep` then `fullbuild.sh CANDS.c` (full `make`, reverts on mismatch); `liblock.sh` for lib functions |
| Commit | `commit.sh MSG.txt [COPYDIR]` (build, commit, progress snapshot commit, push) |

`trycc.py` compiles each object and compares instructions with relocated fields masked, so it
can't see symbol names. Two globals loaded in swapped order look like a match. Always finish
with `fullbuild.sh`, which compares the real bytes.

## First drafts with m2c

`decomp.py FUNC... [-a CANDS.c]` writes a first-draft candidate block per function with
[m2c](https://github.com/matt-kempster/m2c) (`bash tools/setup_tools.sh` fetches it;
`.venv/bin/pip install pycparser graphviz`). Append to a candidate file with `-a`, then
`try.sh` it like a hand-written block.

- The context (`m2ctx.py FUNC`) is what the function can see at its spot in its source
  file, preprocessed, with function bodies cut to prototypes and `asm("...")` aliases
  renamed to the real symbol. `m2c_extra.h` adds prototypes the sources don't declare yet
  (helpers such as `func_8009C9F4`); extend it as signatures become known.
- Output is in house style: untyped pointers are `u8 *`, fields are `*(T *)(p + off)`.
- If the file declares the function further down, m2c is given that signature, or the
  draft is defined through an asm alias when that declaration's types aren't known yet.
  Callee prototypes m2c guessed are swapped for the file's own later declaration.
- Stack slots m2c reads without declaring get `s32 spXX; /* m2c: undeclared stack slot */`;
  those are usually a local struct or array to reconstruct.

Expect a draft to compile and get the logic right, then need the usual pass for
types, temporaries and loop shape (a raw draft typically diffs at 0.3-0.8 ratio).

## Local LLM loop

`llm_iterate.py` hands unmatched functions to a local model over an OpenAI-compatible chat
API (Strata by default: `LLM_BASE_URL=http://127.0.0.1:47831/v1`, key in `STRATA_API_KEY` or
`LLM_API_KEY`, `LLM_MODEL` optional). Each round the model gets the target asm, the object's
exact compiler setup (cc1 flags, whether `--expand-div` applies), the declarations the code
uses, the best C so far and its diff. It then has the compiler: each reply may carry up to
`--variants` (3) versions of the function, each one is compiled and scored, and the results go
back as the next message, until a match or the budget runs out (`--compiles` 40, `--minutes` 30
per function, whichever comes first). Every reply ends with a HANDOFF note; when the history
passes ~35% of `--ctx` tokens the conversation restarts from the best code plus those notes.
The system prompt lists the gcc 2.8.1 patterns that matched functions here, plus the lines of
`tools/match/llm_tips.md` (add a line there when a new trick matches something). The first
prompt also shows up to `--examples` (2) already-matched functions from the same overlay whose
opcode sequence is most like the target's (similarity >= 0.5), e.g. a matched twin. `--rounds N` is the older mode (N independent single-answer rounds).
The system prompt tells it the compiler is the checker (a compile is ~1 s, so send variants
rather than reasoning about whether they'll match). `--think TOKENS` (default 4000) cuts a reply
whose thinking runs past that before any answer: the request is hung up and re-sent with the end
of the reasoning and "answer with code now" (thinking off for that call). `--no-think` asks the
server to turn thinking off throughout (`chat_template_kwargs.enable_thinking=false`).

| Command | What it does |
|---|---|
| `llm_iterate.py --parked ov_battle [--compiles 40] [--minutes 30] [--skip-done]` | The overlay's parked list (functions with a saved candidate in `permuter/queue.txt` first, others start from an m2c draft) |
| `llm_iterate.py --queue FILE` / `llm_iterate.py FUNC...` | A queue of `CANDS.c FUNC [IDX]` lines, or named functions |
| `llm_iterate.py --permuted [FUNC...]` | Functions with permuter results (`permuter/nonmatchings/`), lowest score first, each starting from its best `output-*/source.c`; the model is told the code is permuter output. With `--skip-done`, a function reruns only when the permuter has a newer best |
| `llm_iterate.py --dry-run FUNC` | Builds the first prompt into `permuter/llm/FUNC/prompt.txt` without calling the model |

It works in a separate copy of the repo (`~/chronocross-llm`, refreshed before each function)
because `trycc.py` edits source files while it compiles, so it can run alongside other work.
From WSL it sends requests through Windows' `curl.exe` (a server on Windows' 127.0.0.1 isn't
reachable from WSL). Results: `permuter/llm/FUNC/` (each turn with its thinking, every variant, `handoffs.txt`, `best.c`) and
`permuter/llm/summary.txt`. A MATCH is a trycc match: lock it with a full build as usual.

## Permuter (register-allocation near-misses)

For functions whose logic matches but registers or instruction order don't, run
[decomp-permuter](https://github.com/simonlindholm/decomp-permuter) (`bash tools/setup_tools.sh`
fetches it; `.venv/bin/pip install toml Levenshtein`).

| Command | What it does |
|---|---|
| `permute.py CANDS.c FUNC [IDX]` | Imports one candidate variant into `permuter/nonmatchings/FUNC/` (gitignored). `compile.sh` is the object's real Makefile recipe, so per-object flags such as `--expand-div` apply |
| `permuter.py permuter/nonmatchings/FUNC -j16` | Runs it interactively (from `tools/decomp-permuter/`) |
| `permute_all.sh QUEUE [MINUTES] [JOBS] [all] [fresh] [draft] [stall=M]` | Runs a queue of `CANDS.c FUNC [IDX]` lines unattended, MINUTES each; best scores go to `permuter/summary.txt`. Each visit starts from the function's best output so far: it is copied over `base.c`, with the original draft kept in `base.orig.c` and its score in `base.score` (`draft` starts from the original again). A function that goes M minutes (default 5) without beating its best is stopped and moved to the back of the line with the rest of its time. `permuter/resume.txt` lets a stopped run restart on the function it was on (`fresh` ignores it). The console shows each function's base score, every improvement (with the compile that found it) and a status line updated on every compile (count, rate, latest and best score, errors, time left), plus a permanent line each minute; `all` prints one line per compile instead (`permwatch.py`) |

Results are in `output-SCORE-N/source.c` (score 0 = full match). The randomizer often finds
odd-looking code that only fixes registers by accident; turn it into something sensible, then
check it with `try.sh` and lock it as usual. Settings are in `tools/permuter_settings.toml`;
`tools/match/permuter_weights.toml` sets the randomization weights (copied into each job's
`settings.toml` before every run) and switches off the changes that produce wrong C (function and
global types, float literals, deleted statements).

`refill_queue.py [--ov ov_battle] [--limit N] [--min-ratio 0.3] [--dry-run]` keeps the queue fed:
it drafts the parked functions that have no saved C yet with `decomp.py`, scores them in its own
copy of the repo (`~/chronocross-refill`) and appends the ones that compile to
`permuter/queue.txt`, best first (log: `permuter/refill.log`).

## When a function won't match

| Tool | What it does |
|---|---|
| `findmis.sh CANDS.c` | Full build, then names the first functions whose overlay bytes differ |
| `fcount.sh A.c B.c ...` | Differing-byte count of the overlay for each candidate file |
| `cmpat.sh CANDS.c ADDR` | Disassembly of ours vs the original around one address |
| `bdiff.sh CANDS.c` | Differing byte ranges of the main EXE |
| `builderr.sh CANDS.c` | Real compile errors (trycc only says COMPILE FAILED) |
| `adiff.py OUT [CTX]` / `adv.sh CANDS.c FUNC` | Alignment diff of saved `--show` output / per-variant diff size |
| `realdiff.sh OUT [SKIP...]` | Drops scratchpad-literal relocation noise from saved `--show` output |
| `dump.sh CANDS.c SRCFILE OUTDIR` | cc1 RTL dumps (`.lreg`/`.greg` show register allocation) |
| `libcmp.py` / `libcmp_cdk.py CANDS.c REF.o` | Compile lib C under several toolchains and compare with an object built from the original asm |
| `cdkscan.py DIR [NAME...]` | Runs parked lib drafts in `DIR/lib*.c` through `libcmp_cdk.py` |
| `magic.py MAGIC SHIFT` | Finds the divisor behind a magic-number division |

## Editing candidate files and sources

`join.py base.c out.c func=file:k ...` (merge picks, `func=-:0` drops one), `mkpick.py src dst func=k ...`,
`pick.py SRC IDX DST`, `pickblk.py OUT DIR name:idx ...`, `adddecl.py CANDS.c func "decl"`,
`hoist.py [--file SRC.c] "decl line"` (moves a decl to the top of the file), `addro.py SRC.c func sym...` (INCLUDE_RODATA lines).
`subst.py CANDS.c` puts blocks into `src/` without building. `verify.py` checks another checkout's
field-overlay C, function by function, against this repo.

## Overlays

The byte-level tools default to `OV=ov_field`. Set `OV=ov_battle` (any entry of `OVERLAYS` in the
Makefile) to point them at another overlay.

## Lists

- `parked_<OV>.txt`, `parked_main.txt`, `libskip.txt`: functions tried and parked, with their notes in the commit history.
- `skip_<OV>.txt`: skipped for now in candidate lists, but not tried in depth yet.
