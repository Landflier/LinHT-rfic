# ihp-sg13g2 __NAME__ macro

> [!IMPORTANT]
> This repository requires the [IIC-OSIC-TOOLS](https://github.com/iic-jku/IIC-OSIC-TOOLS) container with tag `2026.05` or later.

**TODO(__NAME__):** one-paragraph description of the macro (function, key specs,
pointer to the relevant section of `doc/design_plan.md`).

Cell naming convention: `__CELL__` is the core cell; `__TOP__` is the wrapper
cell (with substrate/guard-ring frame) that produces the final GDS and the
views in `final/`.

For a fully worked analog macro (schematics, testbenches, CACE
characterization, verified layout), see [`macros/inverter/`](../inverter/).


## Directory Structure

```text
📁 __NAME__/
├─ 📁 final/                    # released views (make build-top)
│  ├─ 📁 gds/                   # __TOP__.gds
│  ├─ 📁 lef/                   # __TOP__.lef
│  ├─ 📁 lib/                   # __TOP__.lib (stub)
│  └─ 📁 vh/                    # __TOP__.v (pin stub for LibreLane)
├─ 📁 layout/                   # KLayout layouts (__TOP__.gds, *.klay.gds)
├─ 📁 netlist/
│  ├─ 📁 schematic/             # Xschem-exported netlists (LVS reference)
│  ├─ 📁 layout/                # extracted layout netlists
│  └─ 📁 pex/                   # parasitic-extracted netlists
├─ 📁 render/
│  └─ 📁 img/                   # rendered layout images
├─ 📁 schematic/
│  └─ 📁 xschem/                # __CELL__.sch/.sym, __TOP__.sch/.sym, xschemrc
├─ 📁 scripts/
│  ├─ 📁 plot_simulations/      # gnuplot scripts (+ data/, figures/)
│  ├─ 📁 sizing/                # analytical gm/ID sizing (plain Python)
│  ├─ lay2img.py
│  └─ reorder_spice_pins.py
├─ 📁 testbenches/
│  └─ 📁 xschem/                # __CELL___tb_*.sch, xschemrc
├─ 📁 verification/
│  ├─ 📁 cace/                  # __CELL__.yaml + templates/, scripts/, results/
│  ├─ 📁 drc/                   # DRC reports
│  └─ 📁 lvs/                   # LVS reports
├─ Makefile
└─ README.md
```


## Typical Workflow

1. **Sizing** — edit `scripts/sizing/sizing___CELL__.py` (plain Python, uses the
   shared gm/ID tables in `<repo>/scripts/sizing/data/`), then run:

   ```sh
   make sizing
   ```

2. **Schematic entry** — draw `__CELL__.sch` / `__TOP__.sch` (+ symbols) in
   `schematic/xschem/` with Xschem.

3. **Testbenches** — add `__CELL___tb_<analysis>.sch` under
   `testbenches/xschem/` and run them headless:

   ```sh
   make sim-xschem TB=__CELL___tb_<analysis>
   ```

   Testbenches export plot data with ngspice `wrdata` (with `set wr_vecnames`
   and `set wr_singlescale`) into `scripts/plot_simulations/data/`. Derived
   metrics belong in the ngspice control block (`meas`, `deriv()`, ...), not in
   the plot scripts. View the results with gnuplot:

   ```sh
   make sim-view-xschem CELL=__CELL__
   ```

4. **Characterization** — fill in `verification/cace/__CELL__.yaml` (specs =
   acceptance rubric) and the testbench templates in
   `verification/cace/templates/`, then:

   ```sh
   make sim-cace
   ```

5. **Layout** — draw the layout in KLayout (`layout/__TOP__.gds`), then verify
   with both engines:

   ```sh
   make klayout-verify-all
   make magic-verify-all
   ```

6. **Release views** — export `final/` views for chip assembly:

   ```sh
   make build-top
   ```

7. Enable the macro in the top-level `Makefile` (`MACROS` list) so
   `make build-macros` includes it.

Run `make` (or `make help`) for the full target list. All cell-specific targets
accept `CELL=<cellname>` (default: `__TOP__`), PEX targets accept
`EXT_MODE=<1|2|3>` (default: 3 = full-RC).


## Exit Criteria (doc/design_plan.md §11)

- CACE all-green at PVT + Monte Carlo
- DRC/LVS clean in **both** engines (KLayout and Magic + Netgen)
- Post-PEX re-simulation meets spec — note the margin here in this README
