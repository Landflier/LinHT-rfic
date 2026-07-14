# SPDX-FileCopyrightText: 2026 __DESIGNER__
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Description: Plots for the __CELL__ macro based on ngspice wrdata exports.
#
# The testbenches write whitespace-separated tables (one header line with the
# vector names, then one row per point) into data/ via ngspice `wrdata` with
# `set wr_vecnames` and `set wr_singlescale`. Keep design math (derived
# metrics such as cut-off frequencies) in the ngspice control block (`meas`,
# `deriv()`, ...) — this script only draws the exported results.
#
# Usage (from scripts/plot_simulations/):
#   gnuplot plot___CELL__.gp                 # write SVG + PDF into figures/
#   gnuplot -p -e "view=1" plot___CELL__.gp  # also open interactive window
# or from the macro root:
#   make sim-view-xschem CELL=__CELL__
#
# See macros/inverter/scripts/plot_simulations/plot_inverter.gp for a
# complete, worked example (Bode plot with extracted metrics, DC transfer).

DATA = 'data/__CELL___tb_tran.txt'   # TODO(__NAME__): point at your export
FIG  = 'figures/__CELL___tb_tran'

# Common style
set grid back linetype -1 dashtype 3 linecolor rgb '#c0c0c0'
set key top right

# TODO(__NAME__): axis setup + plot command, e.g. a transient plot:
# set xlabel 't (ms)'
# set ylabel 'V (V)'
# PLOT = "plot DATA skip 1 using ($1*1e3):2 with lines linewidth 2 linecolor rgb '#0c5da5' title 'v(out)'"
PLOT = "plot [][0:1] 1/0 title 'TODO(__NAME__): edit plot___CELL__.gp'"

# Render to files, then optionally to an interactive window (view=1)
set terminal svg size 900,620 dynamic background rgb 'white'
set output FIG.'.svg'
@PLOT

set terminal pdfcairo size 9,6.2
set output FIG.'.pdf'
@PLOT

if (exists("view")) {
    set terminal qt size 900,620
    unset output
    @PLOT
}
