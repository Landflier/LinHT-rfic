#!/usr/bin/env bash
# SPDX-FileCopyrightText: 2026 Vasil Yordanov
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
#
# Initialize a new macro directory from macros/_templates/<type>.
#
# Usage:
#   scripts/init_macro.sh <macro_name> [analog|digital]
# or via the top-level Makefile:
#   make init-macro MACRO=<macro_name> [TYPE=analog|digital]
#
# Naming convention: the wrapper cell that produces the final GDS is
# <core>_top. If <macro_name> itself ends in _top (e.g. vco_top), the core
# cell drops the suffix (vco) and the top cell equals the macro name;
# otherwise (e.g. rx_fe) the core cell equals the macro name and the top
# cell appends _top (rx_fe_top).
#
# Placeholders substituted in template file names and contents:
#   __CELL__      core cell name
#   __TOP__       top (wrapper) cell name
#   __NAME__      macro directory name
#   __DESIGNER__  git user.name (or TODO)
#   __DATE__      today's date

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TPL_ROOT="$REPO_ROOT/macros/_templates"

usage() {
    echo "Usage: $(basename "$0") <macro_name> [analog|digital]" >&2
    echo "Available templates: $(ls "$TPL_ROOT" | tr '\n' ' ')" >&2
    exit 1
}

NAME="${1:-}"
TYPE="${2:-analog}"

[ -n "$NAME" ] || usage

if ! [[ "$NAME" =~ ^[a-z][a-z0-9_]*$ ]]; then
    echo "ERROR: macro name must match ^[a-z][a-z0-9_]*\$ (got '$NAME')" >&2
    exit 1
fi

if [ ! -d "$TPL_ROOT/$TYPE" ]; then
    echo "ERROR: unknown macro type '$TYPE' (no template macros/_templates/$TYPE)" >&2
    usage
fi

DST="$REPO_ROOT/macros/$NAME"
if [ -e "$DST" ]; then
    echo "ERROR: macros/$NAME already exists" >&2
    exit 1
fi

# Derive cell names (see naming convention above)
CELL="${NAME%_top}"
TOP="${CELL}_top"

DESIGNER="$(git -C "$REPO_ROOT" config user.name 2>/dev/null || true)"
DESIGNER="${DESIGNER:-TODO}"
DATE="$(date +'%B %-d, %Y')"

cp -r "$TPL_ROOT/$TYPE" "$DST"

# Rename files and directories containing placeholder tokens (deepest first,
# so renamed parents do not invalidate child paths)
find "$DST" -depth \( -name '*__CELL__*' -o -name '*__TOP__*' \) | while read -r p; do
    base="$(basename "$p" | sed "s/__CELL__/$CELL/g; s/__TOP__/$TOP/g")"
    mv "$p" "$(dirname "$p")/$base"
done

# Substitute placeholders in file contents
grep -rl -e '__CELL__' -e '__TOP__' -e '__NAME__' -e '__DESIGNER__' -e '__DATE__' "$DST" \
| while read -r f; do
    sed -i "s/__CELL__/$CELL/g; s/__TOP__/$TOP/g; s/__NAME__/$NAME/g; s/__DESIGNER__/$DESIGNER/g; s/__DATE__/$DATE/g" "$f"
done

echo "Initialized macros/$NAME from the '$TYPE' template."
echo "  core cell: $CELL"
echo "  top cell:  $TOP"
echo ""
echo "Next steps:"
if [ "$TYPE" = "analog" ]; then
    echo "  1. Run the sizing script:        cd macros/$NAME && make sizing"
    echo "  2. Draw $CELL.sch / $TOP.sch in  macros/$NAME/schematic/xschem/"
    echo "  3. Add testbenches under         macros/$NAME/testbenches/xschem/"
    echo "     and enable them in the sim-all target of macros/$NAME/Makefile"
    echo "  4. Fill in the CACE spec:        macros/$NAME/verification/cace/$CELL.yaml"
else
    echo "  1. Implement the RTL in          macros/$NAME/rtl/"
    echo "  2. Extend the testbenches under  macros/$NAME/testbenches/{cocotb,verilog}/"
    echo "  3. Adjust the LibreLane config:  macros/$NAME/flow/librelane/config.yaml"
fi
echo "  5. Enable the macro in the top-level Makefile (MACROS list)"
echo "  6. Fill in the TODOs in macros/$NAME/README.md"
