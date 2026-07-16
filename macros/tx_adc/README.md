# ihp-sg13g2 tx_adc macro

> [!IMPORTANT]
> This repository requires the [IIC-OSIC-TOOLS](https://github.com/iic-jku/IIC-OSIC-TOOLS) container with tag `2026.05` or later.

A 3rd order 1-bit CT $/delta - /Sigma $ modulator, with an OSR=64 for a baseband frequency range of $\pm$ 250KHz.


Cell naming convention: `tx_adc` is the core cell; `tx_adc_top` is the wrapper
cell (with substrate/guard-ring frame) that produces the final GDS and the
views in `final/`.


## Directory Structure

```text
📁 tx_adc/
├─ 📁 final/                    # released views (make build-top)
│  ├─ 📁 gds/                   # tx_adc_top.gds
│  ├─ 📁 lef/                   # tx_adc_top.lef
│  ├─ 📁 lib/                   # tx_adc_top.lib (stub)
│  └─ 📁 vh/                    # tx_adc_top.v (pin stub for LibreLane)
├─ 📁 layout/                   # KLayout layouts (tx_adc_top.gds, *.klay.gds)
├─ 📁 netlist/
│  ├─ 📁 schematic/             # Xschem-exported netlists (LVS reference)
│  ├─ 📁 layout/                # extracted layout netlists
│  └─ 📁 pex/                   # parasitic-extracted netlists
├─ 📁 render/
│  └─ 📁 img/                   # rendered layout images
├─ 📁 schematic/
│  └─ 📁 xschem/                # tx_adc.sch/.sym, tx_adc_top.sch/.sym, xschemrc
├─ 📁 scripts/
│  ├─ 📁 plot_simulations/      # gnuplot scripts (+ data/, figures/)
│  ├─ 📁 sizing/                # specs_tx_adc.py + sizing_tx_adc.py + generated sizing_tx_adc.md report
│  ├─ lay2img.py
│  └─ reorder_spice_pins.py
├─ 📁 testbenches/
│  └─ 📁 xschem/                # tx_adc_tb_*.sch, xschemrc
├─ 📁 verification/
│  ├─ 📁 cace/                  # tx_adc.yaml + templates/, scripts/, results/
│  ├─ 📁 drc/                   # DRC reports
│  └─ 📁 lvs/                   # LVS reports
├─ Makefile
└─ README.md
```


## Typical Workflow

1. **Theoretical synthesis and simulation** - uses the python-deltasigma framework to synthesize and simulate the $\delta\Sigma$ modulator.
   The python-deltasigma script is found under `scripts/deltasigma.py`    

2. **Schematic entry** — draw `tx_adc.sch` / `tx_adc_top.sch` (+ symbols) in
   `schematic/xschem/` with Xschem.

3. **Testbenches** — add `tx_adc_tb_<analysis>.sch` under
   `testbenches/xschem/` and run them headless:

   ```sh
   make sim-xschem TB=tx_adc_tb_<analysis>
   ```

   Testbenches export plot data with ngspice `wrdata` (with `set wr_vecnames`
   and `set wr_singlescale`) into `scripts/plot_simulations/data/`. Derived
   metrics belong in the ngspice control block (`meas`, `deriv()`, ...), not in
   the plot scripts. Render the result plots with gnuplot (headless, SVG + PDF
   into `scripts/plot_simulations/figures/`):

   ```sh
   make sim-view-xschem CELL=tx_adc
   ```

4. **Characterization** — fill in `verification/cace/tx_adc.yaml` (specs =
   acceptance rubric) and the testbench templates in
   `verification/cace/templates/`, then:

   ```sh
   make sim-cace
   ```

5. **Layout** — draw the layout in KLayout (`layout/tx_adc_top.gds`), then verify
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
accept `CELL=<cellname>` (default: `tx_adc_top`), PEX targets accept
`EXT_MODE=<1|2|3>` (default: 3 = full-RC).


## Exit Criteria (doc/design_plan.md §11)

- CACE all-green at PVT + Monte Carlo
- DRC/LVS clean in **both** engines (KLayout and Magic + Netgen)
- Post-PEX re-simulation meets spec — note the margin here in this README
