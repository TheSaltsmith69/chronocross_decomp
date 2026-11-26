#!/bin/bash
# try.sh CANDS.c [VERSION] [--keep] -- trycc with --show, warnings dropped
. "$(dirname -- "${BASH_SOURCE[0]}")/common.sh"
C=$(abspath "$1"); shift
"$PY" "$M/trycc.py" "$C" --show "$@" 2>&1 | grep -v 'warning'
