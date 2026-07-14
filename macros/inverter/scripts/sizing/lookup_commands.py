# -*- coding: utf-8 -*-
# SPDX-FileCopyrightText: 2024 Simon Dorrer
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Description: Overview of the most important pygmid lookup commands for the
# gm/ID methodology (converted from lookup_commands.ipynb).
#
# Plain Python script (no Jupyter server needed). Run from this directory:
#   python3 lookup_commands.py
#
# The SG13G2 gm/ID lookup tables (.mat) are shared repo-wide in
# <repo>/scripts/sizing/data/.
# ============================================

# Packages
from pathlib import Path

from pygmid import Lookup as lk
import scipy.constants as sc
import scipy.io as sio
import numpy as np

# Shared SG13G2 lookup tables (generated with the pygmid techsweep flow)
DATA_DIR = Path(__file__).resolve().parents[4] / "scripts" / "sizing" / "data"

# Please select LV or HV devices
devices = ['sg13g2_lv_nmos', 'sg13g2_lv_pmos']
# devices = ['sg13g2_hv_nmos', 'sg13g2_hv_pmos']

# Please select NMOS or PMOS
choice = 0 # 0... NMOS, 1... PMOS

# Load the .mat file
data_mat = sio.loadmat(str(DATA_DIR / (devices[choice] + '.mat')))

# Extract the dictionary stored under the device name
device_data = data_mat[devices[choice]]

# Read 4-D table data
# List of parameters: VGS, VDS, VSB, VTH, VDSS, L, W, NFING, ID, GM, GMB, GDS, CGG, CGB, CGD, CGS, CDD, CSS, STH, SFL
data_lk = lk(str(DATA_DIR / (devices[choice] + '.mat')))

# The function "lookup" or "look_up" extracts a desired subset from the 4-dimensional simulation data.
# The function interpolates when the requested points lie off the simulation grid.

# If not specified: minimum L = 0.13um, VDS=max(vgs)/2=0.75V and VSB=0V.

# Note on Width W:
# The techsweep data is generated with DC sweeps (and noise simulations) with ngspice and a Xschem testbench
# in four dimensions (L, VGS, VDS and VSB) for a fixed device width W.
# While one could in principle include the device width as a fifth sweep variable, this is not necessary since the parameters
# scale (approximately) linearly with W across the typical range encountered in analog design.
# For W > 2um the error lies within about 1.5% for gm/ID, gm/gds, gm/Cgg [Jespers_Murmann_2017].
# In general, the lookup function is mostly used to extract ratios anyway.
# However, if exact single parameter look up results want to be achieved it is advised to run the techsweep testbench with the needed width.
# At least the result has to be scaled up / down with W / W_techsweep.
# The following results are computed with techsweep data where W = 5um was used in the techsweep testbench.

# Width in techsweep testbench
W = device_data["W"].item()[0][0]
print(f"Techsweep Testbench Width W = {W}um \n")

# There are three usage modes for lv_nmos.lookup() or lv_nmos.look_up(), same for lv_pmos:
# (1) Simple lookup of parameters at some given (L, VGS, VDS, VSB)

print("(1) Simple lookup of parameters at some given (L, VGS, VDS, VSB).")

# Drain current (ID)
ID = data_lk.lookup("ID", L=0.13, VGS=0.3, VDS=0.75, VSB=0)
print(f"ID(L, VGS, VDS, VSB) = {round(float(ID) * 1e6, 2)}uA at W = {W}um")

# Output conductance (gds)
gds = data_lk.lookup("GDS", L=0.13, VGS=0.3, VDS=0.75, VSB=0)
print(f"gds(L, VGS, VDS, VSB) = {round(float(gds) * 1e6, 2)}uS at W = {W}um")

# Transconductance (gm)
gm = data_lk.lookup("GM", L=0.13, VGS=0.3, VDS=0.75, VSB=0)
print(f"gm(L, VGS, VDS, VSB) = {round(float(gm) * 1e6, 2)}uS at W = {W}um")

# Gate capacitance (Cgg), Cgg = Cgs + Cgb + Cdb
cgg = data_lk.lookup("CGG", L=0.13, VGS=0.3, VDS=0.75, VSB=0)
print(f"Cgg(L, VGS, VDS, VSB) = {round(float(cgg) * 1e15, 2)}fF at W = {W}um")

# Threshold voltage (Vth)
Vth = data_lk.lookup("VTH", L=0.13, VGS=0.3, VDS=0.75, VSB=0)
print(f"Vth(L, VGS, VDS, VSB) = {round(float(Vth), 2)}V at W = {W}um")

# Drain-Source saturation voltage (vdss)
vdss = data_lk.lookup('VDSS', L=0.13, VGS=0.3, VDS=0.75, VSB=0)
print(f"Vdss(L, VGS, VDS, VSB) = {round(float(vdss), 2)} V at W = {W}um")

# Estimate Drain-Source saturation voltage (vdss)
GM_ID = data_lk.lookup("GM_ID", L=0.13, VGS=0.3, VDS=0.75, VSB=0)
Vdss_est = 2 / GM_ID
print(f"Vdss(gm/ID) = 2 / GM_ID = {round(float(Vdss_est), 2)} V (estimated)")
print("================================================================ \n")


# (2) Lookup of arbitrary ratios of parameters, e.g. GM_ID, GM_CGG at given (L, VGS, VDS, VSB)

print("(2) Lookup of arbitrary ratios of parameters, e.g. gm/ID, gm/Cgg at given (L, VGS, VDS, VSB).")

# gm/ID
GM_ID = data_lk.lookup("GM_ID", L=0.13, VGS=0.3, VDS=0.75, VSB=0)
print(f"gm/ID(L, VGS, VDS, VSB) = {round(float(GM_ID), 2)} uS/uA")

# gm/gds
GM_GDS = data_lk.lookup("GM_GDS", L=0.13, VGS=0.3, VDS=0.75, VSB=0)
print(f"gm/gds(L, VGS, VDS, VSB) = {round(float(GM_GDS), 2)}")

# gm/Cgg
GM_CGG = data_lk.lookup("GM_CGG", L=0.13, VGS=0.3, VDS=0.75, VSB=0)
print(f"gm/Cgg(L, VGS, VDS, VSB) = {round(float(GM_CGG * 1e6 * 1e-15), 2)} uS/fF")

# ID/W
ID_W = data_lk.lookup('ID_W', L=0.13, VGS=0.3, VDS=0.75, VSB=0)
print(f"ID/W(L, VGS, VDS, VSB) = {round(float(ID_W * 1e6), 2)} uA/um")
print("================================================================ \n")

# (3) Cross-lookup of one ratio against another, e.g. GM_CGG for some GM_ID

print("(3) Cross-lookup of one ratio against another, e.g. gm/Cgg for some gm/ID.")

# Drain current (ID) from gm/ID
# ID = gm / GM_ID

# Transconductance (gm) from gm/ID
ID = 20e-6
GM_ID = 10
gm = ID * GM_ID
print(f"gm = {round(float(gm) * 1e6, 2)}uS")

# Output Conductance (gds)
gm_gds = data_lk.lookup('GM_GDS', GM_ID=GM_ID, L=0.13, VDS=0.75, VSB=0)
gds = gm / gm_gds
print(f"gds(gm/ID, L, VDS, VSB) = {round(float(gds) * 1e6, 2)}uS")

# Gate capacitance (Cgg), Cgg = Cgs + Cgb + Cdb
gm_cgg = data_lk.lookup('GM_CGG', GM_ID=GM_ID, L=0.13, VDS=0.75, VSB=0)
cgg = gm / gm_cgg
print(f"Cgg(gm/ID, L, VDS, VSB) = {round(float(cgg) * 1e15, 2)}fF")

# OR get Cgg with CGG_GM
cgg_gm = data_lk.lookup('CGG_GM', GM_ID=GM_ID, L=0.13, VDS=0.75, VSB=0)
cgg = cgg_gm * gm # = Cin
print(f"Cgg(gm/ID, L, VDS, VSB) = {round(float(cgg) * 1e15, 2)}fF")

# Transit Frequency (fT) @ current gain = 1
f_T = gm_cgg / (2 * np.pi)
print(f"fT(gm/ID, L, VDS, VSB) = {round(float(f_T) * 1e-9, 2)}GHz")

# Gate-Source Capacitance (Cgs)
gm_cgs = data_lk.lookup('GM_CGS', GM_ID=GM_ID, L=0.13, VDS=0.75, VSB=0)
cgs = gm / gm_cgs
print(f"Cgs(gm/ID, L, VDS, VSB) = {round(float(cgs) * 1e15, 2)}fF")

# Width (W)
ID_W = data_lk.lookup('ID_W', GM_ID=GM_ID, L=0.13, VDS=0.75, VSB=0)
W = ID / ID_W
print(f"W(gm/ID, L, VDS, VSB) = {round(float(W), 2)}um")

# STH thermal noise psd at 1 Hz
sth_gm = data_lk.lookup('STH_GM', GM_ID=GM_ID, L=0.13, VDS=0.75, VSB=0)
sth = sth_gm * gm
print(f"STH(gm/ID, L, VDS, VSB) = {round(float(sth * 1e24), 2)} pV²/Hz (thermal noise psd at 1 Hz)")

# Gamma
T = 300 # in Kelvin
gamma = sth / (4 * sc.k * T * gm)
print(f"gamma = {round(float(gamma), 2)}")

# SFL flicker noise drain current psd at 1 Hz
sfl_gm = data_lk.lookup('SFL_GM', GM_ID=GM_ID, L=0.13, VDS=0.75, VSB=0)
sfl = sfl_gm * gm
print(f"SFL(gm/ID, L, VDS, VSB) = {round(float(sfl * 1e18), 2)} nV²/Hz (flicker noise drain current psd at 1 Hz)")

# Flicker corner frequency (fco)
fco = data_lk.lookup('SFL_STH', GM_ID=GM_ID, L=0.13, VDS=0.75, VSB=0)
print(f"fco(gm/ID, L, VDS, VSB) = {round(float(fco * 1e-6), 2)} MHz (flicker corner frequency @ flicker noise PSD = thermal noise PSD)")
print("================================================================")

# There are two usage modes for lv_nmos.lookupVGS() or lv_nmos.look_upVGS(), same for lv_pmos:
# (1) Lookup VGS with known voltage at the source terminal.
# The inputs to the function are GM_ID (or ID/W), L, VDS and VSB.

print("(1) Lookup VGS with known voltage at the source terminal.")

# vgs(gm/ID, L, VDS, VSB)
vgs = data_lk.lookupVGS(GM_ID=10, L=0.13, VDS=0.75, VSB=0)
print(f"vgs(gm/ID, L, VDS, VSB) = {round(float(vgs), 2)}V")

# vgs(ID/W, L, VDS, VSB)
ID_W = data_lk.lookup('ID_W', GM_ID=10, L=0.13, VDS=0.75, VSB=0)
vgs = data_lk.lookupVGS(ID_W=ID_W, L=0.13, VDS=0.75, VSB=0)
print(f"vgs(ID/W, L, VDS, VSB) = {round(float(vgs), 2)}V")
print("================================================================ \n")


# (2) Lookup VGS with unknown source voltage, e.g. when the source of the transistor is the tail node of a differential pair
# The inputs to the function are GM_ID (or ID/W), L, VDB and VGB.

print("(2) Lookup VGS with unknown source voltage.")

# vgs(gm/ID, L, VDB, VGB)
vgs = data_lk.lookupVGS(GM_ID=10, L=0.13, VDB=0.6, VGB=1)
print(f"vgs(gm/ID, L, VDB, VGB) = {round(float(vgs), 2)}V")

# vgs(ID/W, L, VDB, VGB)
ID_W = data_lk.lookup('ID_W', GM_ID=10, L=0.13, VDB=0.6, VGB=1)
vgs = data_lk.lookupVGS(ID_W=ID_W, L=0.13, VDB=0.6, VGB=1)
print(f"vgs(ID/W, L, VDB, VGB) = {round(float(vgs), 2)}V")
print("================================================================")
