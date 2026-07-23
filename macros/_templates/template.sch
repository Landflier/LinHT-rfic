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
K {}
V {}
S {}
F {}
E {}
C {frame.sym} 0 0 0 0 {name=l1
author="Vasil Yordanov"
rev=1.0
title="untitled"
page=1
pages=1
description="A short description of the circuit"
lock=true}
C {simulator_commands.sym} 10 -130 0 0 {name=Libs_Xyce
simulator=xyce
only_toplevel=false
value="tcleval(
.lib $::SG13G2_MODELS_XYCE/cornerMOSlv.lib mos_tt
.lib $::SG13G2_MODELS_XYCE/cornerMOShv.lib mos_tt
.lib $::SG13G2_MODELS_XYCE/cornerRES.lib res_typ
.lib $::SG13G2_MODELS_XYCE/cornerDIO.lib dio_typ
)"}
C {simulator_commands.sym} 1230 -1150 0 0 {name=SPICE
simulator=ngspice
only_toplevel=false
value="
.temp 27
.param vin=0
"}
C {simulator_commands.sym} 130 -130 0 0 {name=Libs_Ngspice
simulator=ngspice
only_toplevel=false
value="
.lib cornerMOSlv.lib mos_tt
.lib cornerMOShv.lib mos_tt
.lib cornerRES.lib res_typ
.lib cornerDIO.lib dio_tt
"}
C {simulator_commands.sym} 250 -130 0 0 {name=Libs_Vacask
simulator=vacask
only_toplevel=false
value="
include \\"sg13cmos5l_vacask_common.lib\\"
include \\"cornerMOSlv.lib\\" section=mos_tt
include \\"cornerMOShv.lib\\" section=mos_tt
include \\"cornerRES.lib\\" section=res_typ
include \\"cornerDIO.lib\\" section=dio_tt
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

# ngspice uses the spice netlist format (update internal state, not just the Tcl var)
xschem set netlist_type spice

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

# Xyce uses the spice netlist format (update internal state, not just the Tcl var)
xschem set netlist_type spice

# run netlist and simulation
xschem netlist
simulate
"}
C {launcher.sym} 1490 -365 0 0 {name=h7
descr=SimulateVACASK
tclcommand="
# Setup the default simulation commands if not already set up
# for example by already launched simulations.
set_sim_defaults

# In the spectre netlist category, command #0 is VACASK. --extra-tomlfile adds
# the repo's SG13CMOS5L .vacaskrc.toml (include=ported models, module=PDK OSDI)
# so 'include sg13cmos5l_vacask_common.lib' resolves. LINHT_ROOT is exported by
# the xschemrc; PDK_ROOT comes from sak-pdk.
set sim(spectre,0,cmd) \{vacask --extra-tomlfile \\"$env(LINHT_ROOT)/models/vacask/ihp-sg13cmos5l/.vacaskrc.toml\\" \\"$N\\"\}
set sim(spectre,default) 0

# Switch the *internal* netlist type. simulate reads [xschem get netlist_type]
# (not the Tcl var), so 'set netlist_type' alone would netlist as spectre but
# still run ngspice. 'xschem set' updates both. NGSPICE/Xyce switch it back.
xschem set netlist_type spectre

# Create FET/BIP .save file for operating-point annotation
file mkdir $netlist_dir
write_data [save_params] $netlist_dir/[file rootname [file tail [xschem get current_name]]].save

# run netlist and simulation
xschem netlist
simulate
"}
C {simulator_commands.sym} 1110 -1150 0 0 {name=XYCE
simulator=xyce
only_toplevel=false
value="
.preprocess replaceground true
.option temp=27
.op
"}
C {simulator_commands.sym} 1350 -1150 0 0 {name=Script_VACASK
simulator=vacask
only_toplevel=false
value="
control
  options temp=27
  save default
  analysis op1 op
endc
"}
