# SPDX-FileCopyrightText: 2026 TODO
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Description: Plots for the pll macro based on ngspice wrdata exports.
#
# The testbenches write whitespace-separated tables (one header line with the
# vector names, then one row per point) into data/ via ngspice `wrdata` with
# `set wr_vecnames` and `set wr_singlescale`. Keep design math (derived
# metrics such as cut-off frequencies) in the ngspice control block (`meas`,
# `deriv()`, ...) — this script only draws the exported results.
#
# Renders SVG + PDF into figures/ (no interactive windows). Usage (from
# scripts/plot_simulations/):
#   gnuplot plot_pll.gp
# or from the macro root:
#   make sim-view-xschem CELL=pll
#
# See macros/inverter/scripts/plot_simulations/plot_inverter.gp for a
# complete, worked example (Bode plot with extracted metrics, DC transfer).

DATA = 'data/pll_tb_tran.txt'   # TODO(pll_top): point at your export
FIG  = 'figures/pll_tb_tran'

# Common style
set grid back linetype -1 dashtype 3 linecolor rgb '#c0c0c0'
set key top right

# TODO(pll_top): axis setup + plot command, e.g. a transient plot:
# set xlabel 't (ms)'
# set ylabel 'V (V)'
# PLOT = "plot DATA skip 1 using ($1*1e3):2 with lines linewidth 2 linecolor rgb '#0c5da5' title 'v(out)'"
PLOT = "plot [][0:1] 1/0 title 'TODO(pll_top): edit plot_pll.gp'"

# Render to files
set terminal svg size 900,620 dynamic background rgb 'white'
set output FIG.'.svg'
@PLOT

set terminal pdfcairo size 9,6.2
set output FIG.'.pdf'
@PLOT

unset output
