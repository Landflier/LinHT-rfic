# ihp-sg13g2 __NAME__ macro (digital)

> [!IMPORTANT]
> This repository requires the [IIC-OSIC-TOOLS](https://github.com/iic-jku/IIC-OSIC-TOOLS) container with tag `2026.05` or later.

**TODO(__NAME__):** one-paragraph description of the macro (function, key specs,
pointer to the relevant section of `doc/design_plan.md`).

Cell naming convention: `__CELL__` is the core module; `__TOP__` is the
top-level wrapper hardened by LibreLane. The template RTL contains a
placeholder heartbeat register so the lint/sim/hardening flow is runnable
before the real design lands.

For a fully worked digital macro (RTL, cocotb + Verilog testbenches, FPGA
target, LibreLane hardening, XSPICE generation), see
[`macros/counter/`](../counter/).


## Directory Structure

```text
📁 __NAME__/
├─ 📁 final/                    # hardened views (make build-top -> copy-final)
├─ 📁 flow/
│  └─ 📁 librelane/             # config.yaml, SDC files, pin_order.cfg
├─ 📁 netlist/                  # nl/pnl/spice/xspice netlists
├─ 📁 render/
│  └─ 📁 img/                   # rendered layout images
├─ 📁 rtl/                      # constants.sv, __CELL__.sv, __TOP__.sv
├─ 📁 schematic/
│  └─ 📁 xschem/                # __TOP__.sym for mixed-signal (XSPICE) use
├─ 📁 scripts/                  # lay2img.py, spi2xspice.py, reorder_xspice_pins.py
├─ 📁 testbenches/
│  ├─ 📁 cocotb/                # __TOP___tb.py (RTL + gate-level)
│  ├─ 📁 verilog/               # __TOP___tb.sv (Icarus)
│  └─ 📁 xschem/                # gate-level XSPICE testbench
├─ 📁 verification/             # reports copied from the LibreLane run
├─ Makefile
└─ README.md
```


## Typical Workflow

1. **RTL** — implement the design in `rtl/` (shared constants in
   `constants.sv`, core logic in `__CELL__.sv`, hardening wrapper in
   `__TOP__.sv`), then lint:

   ```sh
   make lint-verilog-all
   ```

2. **Simulation** — extend the cocotb testbench
   (`testbenches/cocotb/__TOP___tb.py`) and the self-checking Verilog
   testbench (`testbenches/verilog/__TOP___tb.sv`):

   ```sh
   make sim-rtl-verilog
   make sim-rtl-cocotb
   ```

3. **Hardening** — adjust `flow/librelane/config.yaml` (die area, clock,
   pin order), then run LibreLane and collect results:

   ```sh
   make build-top
   ```

4. **Gate-level checks** — re-run the cocotb testbench against the hardened
   netlist, and (optionally) generate the XSPICE model for mixed-signal
   top-level simulation:

   ```sh
   make sim-gl-cocotb
   make generate-xspice
   make sim-gl-xschem
   ```

5. Enable the macro in the top-level `Makefile` (`MACROS` list) so
   `make build-macros` includes it.

Run `make` (or `make help`) for the full target list.


## Exit Criteria (doc/design_plan.md §11)

- Lint clean, RTL + gate-level cocotb testbenches green
- LibreLane run clean: STA met at all six template corners, DRC/LVS clean
- Reports collected in `verification/`
