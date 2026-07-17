# ihp-sg13g2 pll_top macro

> [!IMPORTANT]
> This repository requires the [IIC-OSIC-TOOLS](https://github.com/iic-jku/IIC-OSIC-TOOLS) container with tag `2026.05` or later.

**TODO(pll_top):** one-paragraph description of the macro (function, key specs,
pointer to the relevant section of `doc/design_plan.md`).

Cell naming convention: `pll` is the core cell; `pll_top` is the wrapper
cell (with substrate/guard-ring frame) that produces the final GDS and the
views in `final/`.

For a fully worked analog macro (schematics, testbenches, CACE
characterization, verified layout), see [`macros/inverter/`](../inverter/).


## Directory Structure

```text
📁 pll_top/
├─ 📁 final/                    # released views (make build-top)
│  ├─ 📁 gds/                   # pll_top.gds
│  ├─ 📁 lef/                   # pll_top.lef
│  ├─ 📁 lib/                   # pll_top.lib (stub)
│  └─ 📁 vh/                    # pll_top.v (pin stub for LibreLane)
├─ 📁 layout/                   # KLayout layouts (pll_top.gds, *.klay.gds)
├─ 📁 netlist/
│  ├─ 📁 schematic/             # Xschem-exported netlists (LVS reference)
│  ├─ 📁 layout/                # extracted layout netlists
│  └─ 📁 pex/                   # parasitic-extracted netlists
├─ 📁 render/
│  └─ 📁 img/                   # rendered layout images
├─ 📁 schematic/
│  └─ 📁 xschem/                # pll.sch/.sym, pll_top.sch/.sym, xschemrc
├─ 📁 scripts/
│  ├─ 📁 plot_simulations/      # gnuplot scripts (+ data/, figures/)
│  ├─ 📁 sizing/                # specs_pll.py + sizing_pll.py + generated sizing_pll.md report
│  ├─ lay2img.py
│  └─ reorder_spice_pins.py
├─ 📁 testbenches/
│  └─ 📁 xschem/                # pll_tb_*.sch, xschemrc
├─ 📁 verification/
│  ├─ 📁 cace/                  # pll.yaml + templates/, scripts/, results/
│  ├─ 📁 drc/                   # DRC reports
│  └─ 📁 lvs/                   # LVS reports
├─ Makefile
└─ README.md
```


## Typical Workflow

1. **Sizing** — fill in the specifications in `scripts/sizing/specs_pll.py`
   (plain-Python constants; derived values like `VCM = VDD / 2` are fine) and
   the topology equations in `scripts/sizing/sizing_pll.py` (uses the
   shared gm/ID tables in `<repo>/scripts/sizing/data/` and the helpers in
   `<repo>/scripts/sizing/sizing_common.py`), then run:

   ```sh
   make sizing
   ```

   This prints the results and (re)writes the committed report
   `scripts/sizing/sizing_pll.md`, so the given specs and the resulting
   gm/ID sizing stay visible to anyone browsing or copying the macro. Iterate
   by editing `specs_pll.py` and re-running `make sizing`.

2. **Schematic entry** — draw `pll.sch` / `pll_top.sch` (+ symbols) in
   `schematic/xschem/` with Xschem.

3. **Testbenches** — add `pll_tb_<analysis>.sch` under
   `testbenches/xschem/` and run them headless:

   ```sh
   make sim-xschem TB=pll_tb_<analysis>
   ```

   Testbenches export plot data with ngspice `wrdata` (with `set wr_vecnames`
   and `set wr_singlescale`) into `scripts/plot_simulations/data/`. Derived
   metrics belong in the ngspice control block (`meas`, `deriv()`, ...), not in
   the plot scripts. Render the result plots with gnuplot (headless, SVG + PDF
   into `scripts/plot_simulations/figures/`):

   ```sh
   make sim-view-xschem CELL=pll
   ```

4. **Characterization** — fill in `verification/cace/pll.yaml` (specs =
   acceptance rubric) and the testbench templates in
   `verification/cace/templates/`, then:

   ```sh
   make sim-cace
   ```

5. **Layout** — draw the layout in KLayout (`layout/pll_top.gds`), then verify
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
accept `CELL=<cellname>` (default: `pll_top`), PEX targets accept
`EXT_MODE=<1|2|3>` (default: 3 = full-RC).


## Exit Criteria (doc/design_plan.md §11)

- CACE all-green at PVT + Monte Carlo
- DRC/LVS clean in **both** engines (KLayout and Magic + Netgen)
- Post-PEX re-simulation meets spec — note the margin here in this README
