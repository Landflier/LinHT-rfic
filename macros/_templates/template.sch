v {xschem version=3.4.8RC file_version=1.3
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
F {}
E {}
L 4 192.5 0 1715 0 {}
L 4 0 0 32.5 0 {}
L 4 2095 -1215 2095 0 {}
L 4 0 -1215 1715 -1215 {}
L 4 0 -1215 0 0 {}
L 4 1435 -80 1435 0 {}
L 4 1435 -80 2095 -80 {}
L 4 1435 -40 2095 -40 {}
L 4 1750 -40 1750 0 {}
L 4 1750 -80 1750 -40 {}
L 4 1605 -40 1605 0 {}
L 4 1715 -0 2095 -0 {}
L 4 1710 -1215 2095 -1215 {}
P 5 19 70 -7.5 67.5 -5 62.5 0 67.5 5 73.75 11.25 77.5 15 73.75 15 70 15 67.5 15 65 12.5 62.5 10 57.5 5 52.5 10 50 12.5 47.5 15 45 15 41.25 15 37.5 15 41.25 11.25 {fill=true
bezier=1}
T {@time_last_modified} 1755 -30 0 0 0.4 0.4 {}
T {@author} 1440 -70 0 0 0.4 0.4 {}
T {Page @page of @pages} 1440 -30 0 0 0.4 0.4 {}
T {@title} 1755 -60 0 0 0.3 0.3 {vcenter=true}
T {Rev. @rev} 1610 -30 0 0 0.4 0.4 {}
T {SCHEM} 77.5 -12.5 0 0 0.5 0.5 {}
T {Desription

A short description of the circuit } 1525 -1205 0 0 0.4 0.4 {}
C {code.sym} 10 -130 0 0 {name=Libs_Xyce
simulator=xyce
only_toplevel=false
value="tcleval(
.lib $::SG13G2_MODELS_XYCE/cornerMOSlv.lib mos_tt
.lib $::SG13G2_MODELS_XYCE/cornerMOShv.lib mos_tt
.lib $::SG13G2_MODELS_XYCE/cornerHBT.lib hbt_typ
.lib $::SG13G2_MODELS_XYCE/cornerRES.lib res_typ
.lib $::SG13G2_MODELS_XYCE/cornerDIO.lib dio_typ
)"}
C {code.sym} 1350 -1180 0 0 {name=SPICE only_toplevel=false 
value="
.temp 27
.param vin=0
"}
C {code.sym} 130 -130 0 0 {name=Libs_Ngspice
simulator=ngspice
only_toplevel=false
value="
.lib cornerMOSlv.lib mos_tt
.lib cornerMOShv.lib mos_tt
.lib cornerHBT.lib hbt_typ
.lib cornerRES.lib res_typ
.lib cornerDIO.lib dio_tt
"}
C {devices/launcher.sym} 1490 -215 0 0 {name=h3
descr="OP annotate" 
tclcommand="xschem annotate_op"
}
C {devices/launcher.sym} 1490 -165 0 0 {name=h4
descr="Load waves" 
tclcommand="
xschem raw_read $netlist_dir/[file rootname [file tail [xschem get current_name]]].raw dc
xschem setprop rect 2 0 fullxzoom
"
}
C {launcher.sym} 1490 -315 0 0 {name=h5
descr=SimulateNGSPICE
tclcommand="
# Setup the default simulation commands if not already set up
# for example by already launched simulations.
set_sim_defaults
puts $sim(spice,1,cmd) 

# Change the Xyce command. In the spice category there are currently
# 5 commands (0, 1, 2, 3, 4). Command 3 is the Xyce batch
# you can get the number by querying $sim(spice,n)
set sim(spice,1,cmd) \{ngspice  \\"$N\\" -a\}

# change the simulator to be used (Xyce)
set sim(spice,default) 0

# Create FET and BIP .save file
file mkdir $netlist_dir
write_data [save_params] $netlist_dir/[file rootname [file tail [xschem get current_name]]].save

# run netlist and simulation
xschem netlist
simulate
"}
C {launcher.sym} 1490 -265 0 0 {name=h6
descr=SimulateXyce
tclcommand="
# Setup the default simulation commands if not already set up
# for example by already launched simulations.
set_sim_defaults

# Change the Xyce command. In the spice category there are currently
# 5 commands (0, 1, 2, 3, 4). Command 3 is the Xyce batch
# you can get the number by querying $sim(spice,n)
set sim(spice,3,cmd) \{Xyce -plugin $env(PDK_ROOT)/$env(PDK)/libs.tech/xyce/plugins/Xyce_Plugin_PSP103_VA.so \\"$N\\"\}

# change the simulator to be used (Xyce)
set sim(spice,default) 3

# run netlist and simulation
xschem netlist
simulate
"}
C {code.sym} 1230 -1180 0 0 {name=XYCE only_toplevel=false 
value="
.preprocess replaceground true
.option temp=27
.op
"}
