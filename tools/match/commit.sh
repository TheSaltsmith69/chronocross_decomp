#!/bin/bash
# commit.sh MSGFILE [COPYDIR] -- full build, commit everything with MSGFILE's message, refresh the quest and
# progress CSVs in a second "Update progress snapshot" commit, push. COPYDIR gets a copy of the CSVs
# (for the dashboard upload).
set -e
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
MSG=$(abspath "$1"); DEST=${2:+$(abspath "$2")}
cd "$ROOT"
make -s
git add -A
git commit -q -F "$MSG"
"$PY" tools/quest.py boot_to_title | tail -2
"$PY" tools/progress.py --files-csv progress/files.csv --funcs-csv progress/functions.csv --history progress/history.csv | tail -1
git add progress
git commit -q -m "Update progress snapshot"
git push -q
git log --oneline | head -2
[ -n "$DEST" ] && cp progress/files.csv progress/functions.csv progress/history.csv progress/quest_boot_to_title.csv "$DEST"/
true
