v {xschem version=3.4.6 file_version=1.2
*
* This file is part of XSCHEM,
* a schematic capture and Spice/Vhdl/Verilog netlisting tool for circuit
* simulation.
* Copyright (C) 1998-2024 Stefan Frederik Schippers
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
}
G {}
K {type=logo
template="name=l1 author=\\"Vasil Yordanov\\" rev=1.0 lock=false"
verilog_ignore=true
vhdl_ignore=true
spice_ignore=true
tedax_ignore=true
}
V {}
S {}
E {}
L 4 192.5 0 1715 0 {}
L 4 0 0 32.5 0 {}
L 4 1715 -1215 1715 0 {}
L 4 0 -1215 1715 -1215 {}
L 4 0 -1215 0 0 {}
L 4 1055 -80 1055 0 {}
L 4 1055 -80 1715 -80 {}
L 4 1055 -40 1715 -40 {}
L 4 1370 -40 1370 0 {}
L 4 1370 -80 1370 -40 {}
L 4 1225 -40 1225 0 {}
P 5 19 70 -7.5 67.5 -5 62.5 0 67.5 5 73.75 11.25 77.5 15 73.75 15 70 15 67.5 15 65 12.5 62.5 10 57.5 5 52.5 10 50 12.5 47.5 15 45 15 41.25 15 37.5 15 41.25 11.25 {fill=true
bezier=1}
T {@time_last_modified} 1375 -30 0 0 0.4 0.4 {}
T {@author} 1060 -70 0 0 0.4 0.4 {}
T {Page @page of @pages} 1060 -30 0 0 0.4 0.4 {}
T {@title} 1375 -60 0 0 0.3 0.3 {vcenter=true}
T {Rev. @rev} 1230 -30 0 0 0.4 0.4 {}
T {SCHEM} 77.5 -12.5 0 0 0.5 0.5 {}
T {Desription

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa} 1150 -1210 0 0 0.4 0.4 {}
C {code.sym} 10 -130 0 0 {name="Models, Libraries" only_toplevel=false 
value="
.lib cornerMOSlv.lib mos_tt
.lib cornerMOShv.lib mos_tt
.lib cornerRES.lib res_typ
.include /home/vasil/CAD_VLSI/IHP-Open-PDK/ihp-sg13g2/libs.ref/sg13g2_stdcell/spice/sg13g2_stdcell.spice
"}
C {code.sym} 975 -1185 0 0 {name=SPICE only_toplevel=false 
value="
.temp 27
.param vin=0
"}
C {devices/launcher.sym} 1117.5 -157.5 0 0 {name=h2
descr="simulate" 
tclcommand="xschem save; xschem netlist; xschem simulate"
}
C {devices/launcher.sym} 1120 -120 0 0 {name=h1
descr="load waves" 
tclcommand="xschem raw_read $netlist_dir/circuit_14_tran.raw tran"
}
