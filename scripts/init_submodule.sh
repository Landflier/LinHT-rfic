#!/usr/bin/env bash
# SPDX-FileCopyrightText: 2026 Vasil Yordanov
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
#
# Initialize a submodule cell inside an existing macro from the per-cell
# files of macros/_templates/<type>.
#
# A submodule is a sub-block of a macro (e.g. a latch or an inverter inside
# a DAC). It lives in the parent macro's directory tree and is driven through
# the parent Makefile's per-cell targets (CELL=<subcell>, SIZING_CELL=<subcell>,
# TB=<subcell>_tb_<analysis>); it does not get a Makefile or a final/ handoff
# of its own -- only the macro top does.
#
# Usage:
#   scripts/init_submodule.sh <macro_name> <subcell_name> [analog|digital]
# or via the top-level Makefile:
#   make init-submodule MACRO=<macro_name> SUB=<subcell_name> [TYPE=analog|digital]
#
# When the type is omitted it is auto-detected from the parent macro
# (rtl/ -> digital; scripts/sizing/ or verification/cace/ -> analog).
#
# Scaffolded files (analog):
#   scripts/sizing/specs_<sub>.py and sizing_<sub>.py
#   scripts/plot_simulations/plot_<sub>.gp
#   verification/cace/<sub>.yaml
# Scaffolded files (digital):
#   rtl/<sub>.sv
#   testbenches/verilog/<sub>_tb.v   (per-cell testbenches use .v, see the
#                                     _TB_EXT logic in the macro Makefile)
#   testbenches/cocotb/<sub>_tb.py
#
# Placeholders substituted in file contents:
#   __CELL__ / __TOP__  subcell name (a submodule is its own DUT)
#   __NAME__            parent macro name (keeps TODO(<macro>) tags greppable)
#   __DESIGNER__        git user.name (or TODO)
#   __DATE__            today's date

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TPL_ROOT="$REPO_ROOT/macros/_templates"

usage() {
    echo "Usage: $(basename "$0") <macro_name> <subcell_name> [analog|digital]" >&2
    echo "Available templates: $(ls "$TPL_ROOT" | tr '\n' ' ')" >&2
    exit 1
}

NAME="${1:-}"
SUB="${2:-}"
TYPE="${3:-}"

[ -n "$NAME" ] && [ -n "$SUB" ] || usage

for n in "$NAME" "$SUB"; do
    if ! [[ "$n" =~ ^[a-z][a-z0-9_]*$ ]]; then
        echo "ERROR: name must match ^[a-z][a-z0-9_]*\$ (got '$n')" >&2
        exit 1
    fi
done

MACRO_DIR="$REPO_ROOT/macros/$NAME"
if [ ! -d "$MACRO_DIR" ] || [ "$NAME" = "_templates" ]; then
    echo "ERROR: macros/$NAME does not exist (create it first: make init-macro MACRO=$NAME)" >&2
    exit 1
fi

# The parent macro's core and top cells already own the per-cell collateral
CORE="${NAME%_top}"
if [ "$SUB" = "$CORE" ] || [ "$SUB" = "${CORE}_top" ]; then
    echo "ERROR: '$SUB' is the parent macro's own cell, not a submodule" >&2
    exit 1
fi

# Auto-detect the macro type unless given explicitly
if [ -z "$TYPE" ]; then
    is_digital=0
    is_analog=0
    [ -d "$MACRO_DIR/rtl" ] && is_digital=1
    { [ -d "$MACRO_DIR/scripts/sizing" ] || [ -d "$MACRO_DIR/verification/cace" ]; } && is_analog=1
    if [ "$is_digital" = 1 ] && [ "$is_analog" = 1 ]; then
        echo "ERROR: macros/$NAME looks both analog and digital, pass the type explicitly" >&2
        usage
    elif [ "$is_digital" = 1 ]; then
        TYPE=digital
    else
        TYPE=analog
    fi
fi

if [ ! -d "$TPL_ROOT/$TYPE" ]; then
    echo "ERROR: unknown macro type '$TYPE' (no template macros/_templates/$TYPE)" >&2
    usage
fi

# Template -> destination pairs (paths relative to the template/macro root)
case "$TYPE" in
analog)
    SRCS=(
        "scripts/sizing/specs___CELL__.py"
        "scripts/sizing/sizing___CELL__.py"
        "scripts/plot_simulations/plot___CELL__.gp"
        "verification/cace/__CELL__.yaml"
    )
    DSTS=(
        "scripts/sizing/specs_$SUB.py"
        "scripts/sizing/sizing_$SUB.py"
        "scripts/plot_simulations/plot_$SUB.gp"
        "verification/cace/$SUB.yaml"
    )
    ;;
digital)
    SRCS=(
        "rtl/__CELL__.sv"
        "testbenches/verilog/__TOP___tb.sv"
        "testbenches/cocotb/__TOP___tb.py"
    )
    DSTS=(
        "rtl/$SUB.sv"
        "testbenches/verilog/${SUB}_tb.v"
        "testbenches/cocotb/${SUB}_tb.py"
    )
    ;;
esac

for d in "${DSTS[@]}"; do
    if [ -e "$MACRO_DIR/$d" ]; then
        echo "ERROR: macros/$NAME/$d already exists" >&2
        exit 1
    fi
done

DESIGNER="$(git -C "$REPO_ROOT" config user.name 2>/dev/null || true)"
DESIGNER="${DESIGNER:-TODO}"
DATE="$(LC_ALL=C date +'%B %-d, %Y')"

for i in "${!SRCS[@]}"; do
    src="$TPL_ROOT/$TYPE/${SRCS[$i]}"
    dst="$MACRO_DIR/${DSTS[$i]}"
    mkdir -p "$(dirname "$dst")"
    sed "s/__CELL__/$SUB/g; s/__TOP__/$SUB/g; s/__NAME__/$NAME/g; s/__DESIGNER__/$DESIGNER/g; s/__DATE__/$DATE/g" \
        "$src" > "$dst"
done

# The cocotb template lists rtl/__CELL__.sv and rtl/__TOP__.sv as sources;
# both map to rtl/<sub>.sv here, so drop the duplicated line.
if [ "$TYPE" = "digital" ]; then
    tb="$MACRO_DIR/testbenches/cocotb/${SUB}_tb.py"
    awk '!($0 == prev && $0 ~ /sources\.append/) { print } { prev = $0 }' "$tb" > "$tb.tmp"
    mv "$tb.tmp" "$tb"
fi

# Output directories used by the scaffolded scripts
if [ "$TYPE" = "analog" ]; then
    mkdir -p "$MACRO_DIR/scripts/sizing/figures" \
             "$MACRO_DIR/scripts/plot_simulations/data" \
             "$MACRO_DIR/scripts/plot_simulations/figures" \
             "$MACRO_DIR/verification/cace/results"
fi

echo "Initialized submodule '$SUB' ($TYPE) in macros/$NAME/:"
for d in "${DSTS[@]}"; do
    echo "  macros/$NAME/$d"
done

if [ ! -f "$MACRO_DIR/Makefile" ]; then
    echo ""
    echo "WARNING: macros/$NAME has no Makefile yet, the per-cell make targets"
    echo "         below need one (see macros/_templates/$TYPE/Makefile)."
fi

echo ""
echo "Next steps (all run from macros/$NAME/):"
if [ "$TYPE" = "analog" ]; then
    echo "  1. Fill in the specifications in scripts/sizing/specs_$SUB.py"
    echo "     and the gm/ID equations in     scripts/sizing/sizing_$SUB.py,"
    echo "     then run 'make sizing SIZING_CELL=$SUB' (writes sizing_$SUB.md)"
    echo "  2. Draw $SUB.sch / $SUB.sym in schematic/xschem/ and instantiate"
    echo "     the symbol in the parent cell's schematic"
    echo "  3. Add testbenches testbenches/xschem/${SUB}_tb_<analysis>.sch,"
    echo "     run them with 'make sim-xschem TB=${SUB}_tb_<analysis>' and"
    echo "     enable them in the sim-all target of the Makefile"
    echo "  4. Fill in the CACE spec verification/cace/$SUB.yaml"
    echo "  5. Once the layout exists, verify with"
    echo "     'make klayout-verify CELL=$SUB' / 'make magic-verify CELL=$SUB'"
    echo "     and add the cell to the *-verify-all targets of the Makefile"
else
    echo "  1. Implement the RTL in rtl/$SUB.sv"
    echo "  2. Extend the testbenches testbenches/verilog/${SUB}_tb.v and"
    echo "     testbenches/cocotb/${SUB}_tb.py, then run"
    echo "     'make sim-rtl-verilog CELL=$SUB' / 'make sim-rtl-cocotb CELL=$SUB'"
    echo "  3. Add 'lint-verilog CELL=$SUB' to the lint-verilog-all target"
    echo "     and the module to MODULES_SIM/MODULES_SYNTH in the Makefile"
fi
