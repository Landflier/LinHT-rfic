# SPDX-FileCopyrightText: 2026 Simon Dorrer and Harald Pretl
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Description: Transient plots for the inverter top macro based on ngspice
# wrdata exports (whitespace columns, one header line with vector names).
#
# Usage (from scripts/plot_simulations/):
#   gnuplot plot_inverter_top.gp    # writes SVG + PDF into figures/ (headless)
# or from the macro root:
#   make sim-view-xschem CELL=inverter_top

DATA = 'data/inverter_top_tb_tran.txt'  # time  v(vin)  v(vout1..4)
FIG  = 'figures/inverter_top_tb_tran'

modes = "svg pdf"

set title "Inverter Top - Transient Response"
set xlabel 't (ms)'
set ylabel 'V (V)'
set grid xtics ytics back dashtype 3 linecolor rgb '#c0c0c0'
set key top right

do for [mode in modes] {
    if (mode eq "svg")  { set terminal svg size 900,620 dynamic background rgb 'white'; set output FIG.'.svg' }
    if (mode eq "pdf")  { set terminal pdfcairo size 9,6.2; set output FIG.'.pdf' }

    plot DATA skip 1 using ($1*1e3):2 with lines linewidth 2.4             linecolor rgb '#0c5da5' title 'V_{in}', \
         ''   skip 1 using ($1*1e3):3 with lines linewidth 2.0             linecolor rgb '#ff6b35' title 'V_{out1}', \
         ''   skip 1 using ($1*1e3):4 with lines linewidth 2.0 dashtype 2  linecolor rgb '#2f855a' title 'V_{out2}', \
         ''   skip 1 using ($1*1e3):5 with lines linewidth 2.0 dashtype 4  linecolor rgb '#805ad5' title 'V_{out3}', \
         ''   skip 1 using ($1*1e3):6 with lines linewidth 2.0 dashtype 3  linecolor rgb '#c05621' title 'V_{out4}'

    unset output
}
