# SPDX-FileCopyrightText: 2026 __DESIGNER__
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Description: cocotb testbench for the __TOP__ module (RTL and gate-level).
#
# TODO(__NAME__): replace the placeholder smoke test with real tests.

import os
import re
import logging
from pathlib import Path

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Timer, RisingEdge, ClockCycles
from cocotb_tools.runner import get_runner

sim      = os.getenv("SIM", "icarus")
pdk_root = os.getenv("PDK_ROOT", Path("~/.ciel").expanduser())
pdk      = os.getenv("PDK", "ihp-sg13g2")
scl      = os.getenv("SCL", "sg13g2_stdcell")
# GL=1 selects the gate-level netlist; anything else (unset, "0", "") stays in RTL mode.
gl       = os.getenv("GL", "0").strip().lower() in ("1", "true", "yes", "on")

hdl_toplevel = "__TOP__"

# Defaults sourced from rtl/constants.sv — single source of truth shared with the DUT.
_CONSTANTS_SV = Path(__file__).resolve().parent / "../../rtl/constants.sv"


def _read_define(name: str) -> str:
    """Extract the value of a `define <name> <value>` macro from rtl/constants.sv."""
    text = _CONSTANTS_SV.read_text()
    m = re.search(rf"^\s*`define\s+{re.escape(name)}\s+(\S+)", text, re.MULTILINE)
    if m is None:
        raise RuntimeError(f"`{name} not found in {_CONSTANTS_SV}")
    return m.group(1)


CLK_FREQ_HZ  = float(_read_define("CLK_FREQ_DEFAULT"))
CLK_FREQ_MHZ = int(CLK_FREQ_HZ / 1e6)


async def start_clock(clock, freq=CLK_FREQ_MHZ):
    """Start the clock @ freq MHz"""
    period_ns = round(1 / freq * 1000, 4)
    c = Clock(clock, period_ns, "ns")
    cocotb.start_soon(c.start())


async def reset(dut, cycles=2):
    """Pulse the active-low reset for `cycles` clock cycles."""
    cocotb.log.info("Reset asserted...")

    dut.reset_n_i.value = 0
    dut.enable_i.value  = 0
    await ClockCycles(dut.clock_i, cycles)
    dut.reset_n_i.value = 1
    await RisingEdge(dut.clock_i)

    cocotb.log.info("Reset deasserted.")


async def start_up(dut):
    """Startup sequence: clock + reset."""
    await start_clock(dut.clock_i, CLK_FREQ_MHZ)
    await reset(dut)


@cocotb.test()
async def test_smoke(dut):
    """Placeholder: after reset, tick_o toggles while enabled."""
    logger = logging.getLogger("__CELL___tb")

    logger.info("Startup sequence...")
    await start_up(dut)

    assert int(dut.tick_o.value) == 0, \
        f"tick_o not zero after reset (got {int(dut.tick_o.value)})"

    dut.enable_i.value = 1
    expected = 1
    for _ in range(4):
        await RisingEdge(dut.clock_i)
        await Timer(1, "ns")  # let combinational settle past edge
        got = int(dut.tick_o.value)
        assert got == expected, f"expected tick_o={expected}, got {got}"
        expected ^= 1

    logger.info("Done!")


def __CELL___runner():

    proj_path = Path(__file__).resolve().parent

    sources  = []
    defines  = {}
    includes = [proj_path / "../../rtl/"]

    if gl:
        # SCL models
        sources.append(Path(pdk_root) / pdk / "libs.ref" / scl / "verilog" / f"{scl}.v")
        sources.append(Path(pdk_root) / pdk / "libs.ref" / scl / "verilog" / "sg13g2_udp.v")

        # Unpowered gate-level netlist of the macro
        sources.append(proj_path / f"../../final/nl/{hdl_toplevel}.nl.v")

        # Unpowered netlist: USE_POWER_PINS must NOT be defined at all
        # (passing USE_POWER_PINS=False would still define the macro).
    else:
        sources.append(proj_path / "../../rtl/constants.sv")
        sources.append(proj_path / "../../rtl/__CELL__.sv")
        sources.append(proj_path / "../../rtl/__TOP__.sv")

    build_args = []

    if sim == "icarus":
        # -gno-specify: skip specify blocks; sg13g2_stdcell.v uses
        # `ifnone with edge-sensitive paths`, which iverilog can't parse.
        build_args = ["-DSIM", "-gno-specify"]

    if sim == "verilator":
        build_args = ["--timing", "--trace", "--trace-fst", "--trace-structs"]

    runner = get_runner(sim)
    runner.build(
        sources=sources,
        hdl_toplevel=hdl_toplevel,
        defines=defines,
        always=True,
        includes=includes,
        build_args=build_args,
        waves=True,
        timescale=("1ns", "1fs")
    )

    plusargs = []

    runner.test(
        hdl_toplevel=hdl_toplevel,
        test_module="__TOP___tb",
        plusargs=plusargs,
        waves=True,
    )


if __name__ == "__main__":
    __CELL___runner()
