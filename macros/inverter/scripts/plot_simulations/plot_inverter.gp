# SPDX-FileCopyrightText: 2026 Simon Dorrer and Harald Pretl
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Description: AC and DC plots for the inverter macro based on ngspice
# wrdata exports (whitespace columns, one header line with vector names).
#
# Usage (from scripts/plot_simulations/):
#   gnuplot plot_inverter.gp        # writes SVG + PDF into figures/ (headless)
# or from the macro root:
#   make sim-view-xschem CELL=inverter

DATA_AC = 'data/inverter_tb_ac_ol.txt'    # frequency  v(Aol_dB)  v(Aol_arg)
DATA_DC = 'data/inverter_tb_dc_vout.txt'  # v-sweep    v(vin)     v(vout)

FIG_AC  = 'figures/inverter_tb_ac_ol'
FIG_DC  = 'figures/inverter_tb_dc_vout'

modes = "svg pdf"

# Common style
set style textbox opaque border lc rgb '#444444' margins 1.5, 1.5
GUIDE = "nohead dashtype 3 linecolor rgb '#444444'"

# Helpers
fmt_hz(f) = f >= 1e9 ? sprintf("%.2f GHz", f/1e9) \
          : f >= 1e6 ? sprintf("%.2f MHz", f/1e6) \
          : f >= 1e3 ? sprintf("%.2f kHz", f/1e3) \
          : sprintf("%.2f Hz", f)
# crossing frequency, interpolated linearly in log(f)
xing(f1, m1, f2, m2, t) = exp(log(f1) + (log(f2) - log(f1))*(t - m1)/(m2 - m1))
lin(x1, y1, x2, y2, x)  = y1 + (y2 - y1)*(x - x1)/(x2 - x1)

# ----------------------------------------------------------------------------
# 1. Extract characteristic Bode values from the AC data in one scan pass:
#    DC gain Aol_dB (first row), -3 dB crossing (f_cu) and 0 dB crossing (f_T)
# ----------------------------------------------------------------------------
Aol_dB = NaN; f_cu = NaN; ph_cu = NaN; f_T = NaN; ph_T = NaN
pf = NaN; pm = NaN; pp = NaN
scan(f, m, p) = ( \
    (!(Aol_dB == Aol_dB)) ? (Aol_dB = m) : 0, \
    (pm == pm && pm > Aol_dB - 3.0 && m <= Aol_dB - 3.0 && !(f_cu == f_cu)) ? \
        (f_cu = xing(pf, pm, f, m, Aol_dB - 3.0), ph_cu = lin(pm, pp, m, p, Aol_dB - 3.0)) : 0, \
    (pm == pm && pm > 0  && m <= 0  && !(f_T == f_T)) ? \
        (f_T  = xing(pf, pm, f, m, 0.0), ph_T = lin(pm, pp, m, p, 0.0)) : 0, \
    pf = f, pm = m, pp = p, f)

set table $scan_dummy
plot DATA_AC skip 1 using (scan($1, $2, $3)):(0)
unset table

Aol_VV = 10.0**(Aol_dB/20.0)
CU     = Aol_dB - 3.0

print sprintf("Aol = %.1f dB (%.1f V/V), f_cu = %s (phase %.1f deg), f_T = %s (phase %.1f deg)", \
              Aol_dB, Aol_VV, fmt_hz(f_cu), ph_cu, fmt_hz(f_T), ph_T)

# ----------------------------------------------------------------------------
# 2. Bode Plot (AC): magnitude + phase
# ----------------------------------------------------------------------------
do for [mode in modes] {
    if (mode eq "svg")  { set terminal svg size 900,700 dynamic background rgb 'white'; set output FIG_AC.'.svg' }
    if (mode eq "pdf")  { set terminal pdfcairo size 9,7; set output FIG_AC.'.pdf' }

    set multiplot layout 2,1 title "Inverter - AC Open-Loop Response"
    set logscale x
    set xrange [1:1e9]
    set xlabel 'f (Hz)'
    set grid xtics ytics mxtics back dashtype 3 linecolor rgb '#c0c0c0'
    set key off

    # Magnitude
    set yrange [-20:40]
    set ytics 10
    set ylabel '|A_{ol}(f)| (dB)'
    unset arrow; unset label
    if (f_cu == f_cu) { set arrow 1 from first f_cu, graph 0 to first f_cu, graph 1 @GUIDE }
    if (f_T  == f_T ) { set arrow 2 from first f_T,  graph 0 to first f_T,  graph 1 @GUIDE }
    set arrow 3 from graph 0, first Aol_dB to graph 1, first Aol_dB @GUIDE
    set label 1 sprintf("A_{ol} = %.1f dB (%.1f V/V)\nf_{cu} = %s\nf_T = %s", \
                        Aol_dB, Aol_VV, fmt_hz(f_cu), fmt_hz(f_T)) \
        at graph 0.03, graph 0.16 front boxed
    plot DATA_AC skip 1 using 1:2 with lines linewidth 2.4 linecolor rgb '#0c5da5', \
         '+' every ::0::0 using (f_cu):(CU) with points pointtype 7 pointsize 0.7 linecolor rgb '#444444', \
         '+' every ::0::0 using (f_T):(0.0) with points pointtype 7 pointsize 0.7 linecolor rgb '#444444'

    # Phase
    set yrange [45:185]
    set ytics 45
    set ylabel 'arg A_{ol}(f) (deg)'
    unset arrow; unset label
    if (f_cu == f_cu) { set arrow 1 from first f_cu, graph 0 to first f_cu, graph 1 @GUIDE }
    if (f_T  == f_T ) { set arrow 2 from first f_T,  graph 0 to first f_T,  graph 1 @GUIDE }
    set label 1 sprintf("arg A_{ol}(f_{cu}) = %.1f deg\narg A_{ol}(f_T) = %.1f deg", ph_cu, ph_T) \
        at graph 0.03, graph 0.16 front boxed
    plot DATA_AC skip 1 using 1:3 with lines linewidth 2.4 linecolor rgb '#ff6b35', \
         '+' every ::0::0 using (f_cu):(ph_cu) with points pointtype 7 pointsize 0.7 linecolor rgb '#444444', \
         '+' every ::0::0 using (f_T):(ph_T)   with points pointtype 7 pointsize 0.7 linecolor rgb '#444444'

    unset multiplot
    unset arrow; unset label
    unset output
}

# ----------------------------------------------------------------------------
# 3. Transfer Plot (DC): Vout(Vin) + local slope dVout/dVin (y2 axis)
# ----------------------------------------------------------------------------
unset logscale x
set xrange [0:1.5]
set xlabel 'V_{in} (V)'
set yrange [0:1.5]
set ytics 0.25 nomirror
set ylabel 'V_{out} (V)'
set y2range [-50:0]
set y2tics 10
set y2label 'dV_{out}/dV_{in}'
set key center left
set grid xtics ytics back dashtype 3 linecolor rgb '#c0c0c0'

# local slope between neighboring sweep points
dpx = NaN; dpy = NaN
dydx(x, y) = (res = (dpx == dpx && x != dpx) ? (y - dpy)/(x - dpx) : NaN, \
              dpx = x, dpy = y, res)

do for [mode in modes] {
    if (mode eq "svg")  { set terminal svg size 900,620 dynamic background rgb 'white'; set output FIG_DC.'.svg' }
    if (mode eq "pdf")  { set terminal pdfcairo size 9,6.2; set output FIG_DC.'.pdf' }

    set title "Inverter - DC Transfer Characteristic"
    dpx = NaN; dpy = NaN
    plot DATA_DC skip 1 using 2:3 with lines linewidth 2.6 linecolor rgb '#0c5da5' title 'V_{out}(V_{in})', \
         x with lines linewidth 1.5 dashtype 4 linecolor rgb '#2f855a' title 'V_{out}=V_{in}', \
         DATA_DC skip 1 using 2:(dydx($2, $3)) axes x1y2 with lines linewidth 1.8 dashtype 2 linecolor rgb '#ff6b35' title 'dV_{out}/dV_{in}'

    unset output
}
