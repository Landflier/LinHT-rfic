# -*- coding: utf-8 -*-
# SPDX-FileCopyrightText: 2026 Simon Dorrer and Harald Pretl
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
# Description: Analytical (gm/ID) sizing of the inverter macro.
#
# The specifications live in specs_inverter.py — edit that file, not this
# one, when they change; this script holds only the topology-specific gm/ID
# equations. Run from the macro root:
#   make sizing
# which prints the results and writes the committed Markdown report
# scripts/sizing/sizing_inverter.md (specs + computed sizing).
#
# Pass --draw (make sizing SIZING_ARGS=--draw) to additionally re-render the
# schematic drawing (requires schemdraw) into figures/. The SG13G2 gm/ID
# lookup tables (.mat) are shared repo-wide in <repo>/scripts/sizing/data/.
# ============================================

# Imports
import argparse
import sys
from pathlib import Path

import numpy as np

# Shared sizing helpers (Report, load_table, calculate_finger_options)
REPO_ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(REPO_ROOT / "scripts" / "sizing"))
from sizing_common import Report, load_table, calculate_finger_options

# Specifications (plain-Python constants module next to this script)
sys.path.insert(0, str(Path(__file__).resolve().parent))
import specs_inverter as specs

SPECS_FILE = Path(__file__).resolve().parent / "specs_inverter.py"
REPORT_FILE = Path(__file__).resolve().parent / "sizing_inverter.md"
FIGURES_DIR = Path(__file__).resolve().parent / "figures"
# ============================================


def draw_circuit():
    """Draw the inverter schematic with schemdraw and save it to figures/."""
    import matplotlib
    # Pure Matplotlib text rendering (no external LaTeX dependency)
    matplotlib.rcParams.update({
        "text.usetex": False,
        "mathtext.fontset": "cm",
        "font.family": "serif",
    })
    import schemdraw as sd
    import schemdraw.elements as elm
    sd.svgconfig.svg2 = False

    FIGURES_DIR.mkdir(parents=True, exist_ok=True)

    with sd.Drawing(show=False) as d:
        d.config(unit=2, fontsize=16)

        elm.Dot(open=True).label(r'$V_\mathrm{in}$', loc='left', ofst=0.15)
        dot_in = elm.Line().right().length(1.5).dot()
        elm.Line().up().length(1.5)
        elm.Line().right().length(0.5)
        M2 = elm.AnalogPFet(offset_gate=False).anchor('gate').label(r'$M_{2}$', ofst=-1.75).reverse()
        elm.Line().at(M2.source).up().length(0.50)
        Mdummy2 = elm.AnalogPFet(offset_gate=False).anchor('drain').theta(0).label(r'$M_\mathrm{dummy2}$', ofst=-2.75).reverse()
        elm.Line().at(Mdummy2.source).up().length(0.5)
        elm.Vdd(lead=True).label('$V_\mathrm{DD}$', loc='top', ofst=0.15)
        elm.Line().at(Mdummy2.gate).left().length(0.5).dot()
        elm.Line().up().length(1.0)
        elm.Line().right().tox(Mdummy2.source).dot()
        elm.Line().at(Mdummy2.gate).left().length(0.5)
        elm.Line().down().length(1.0)
        elm.Line().right().tox(Mdummy2.source).dot()
        elm.Line().at(M2.drain).down().toy(dot_in.end).dot()
        elm.Line().right().length(1.5)
        elm.Dot(open=True).label(r'$V_\mathrm{out}$', loc='right', ofst=0.15)

        elm.Line().at(dot_in.end).down().length(1.5)
        elm.Line().right().length(0.5)
        M1 = elm.AnalogNFet(offset_gate=False).anchor('gate').label(r'$M_{1}$', ofst=-1.75).reverse()
        elm.Line().at(M1.source).down().length(0.50)
        Mdummy1 = elm.AnalogNFet(offset_gate=False).anchor('drain').theta(0).label(r'$M_\mathrm{dummy1}$', ofst=-2.75).reverse()
        elm.Line().at(Mdummy1.source).down().length(0.5)
        elm.GroundSignal(lead=True).label('$V_\mathrm{SS}$', loc='bottom', ofst=0.15)
        elm.Line().at(Mdummy1.gate).left().length(0.5).dot()
        elm.Line().down().length(1.0)
        elm.Line().right().tox(Mdummy1.source).dot()
        elm.Line().at(Mdummy1.gate).left().length(0.5)
        elm.Line().up().length(1.0)
        elm.Line().right().tox(Mdummy1.source).dot()
        elm.Line().at(M1.drain).up().toy(dot_in.end).dot()

        # Save the schematic
        d.save(str(FIGURES_DIR / 'inverter_circuit.svg'))
        d.save(str(FIGURES_DIR / 'inverter_circuit.pdf'))

    print(f"Saved circuit drawing to {FIGURES_DIR}/inverter_circuit.{{svg,pdf}}")


def size_device(r, tag, table, vgs, vds, i_d, l, gm_id=None):
    """Size one device from its bias point and drain current.

    Passing gm_id skips the GM_ID lookup (the inverter forces the PMOS to the
    NMOS inversion level). Returns the operating-point quantities needed for
    the final-width pass.
    """
    r.section(f"{tag} sizing")
    r.value(f"Vgs_{tag}", vgs, "V")
    r.value(f"Vds_{tag}", vds, "V")

    # Transconductance (gm)
    if gm_id is None:
        gm_id = table.lookup("GM_ID", L=l, VGS=vgs, VDS=vds, VSB=0)
        r.value("gm/ID(L, VGS, VDS, VSB)", float(gm_id), "uS/uA")
    else:
        r.value("gm/ID", float(gm_id), "uS/uA", note="same inversion level as the NMOS")
    gm = i_d * gm_id
    r.value(f"gm_{tag}", float(gm) * 1e3, "mS")

    # Output conductance (gds)
    gm_gds = table.lookup("GM_GDS", L=l, VGS=vgs, VDS=vds, VSB=0)
    r.value("gm/gds(L, VGS, VDS, VSB)", float(gm_gds))
    gds = gm / gm_gds
    r.value(f"gds_{tag}", float(gds) * 1e3, "mS")

    # Gate capacitance (Cgg) and transit frequency (fT)
    gm_cgg = table.lookup("GM_CGG", L=l, VGS=vgs, VDS=vds, VSB=0)
    cgg = gm / gm_cgg
    r.value(f"Cgg_{tag}", float(cgg) * 1e15, "fF", note="Cgg = Cgs + Cgb + Cgd")
    f_t = gm_cgg / (2 * np.pi)
    r.value(f"f_T_{tag}", float(f_t) * 1e-9, "GHz", note="transit frequency @ current gain = 1")

    # Width (W)
    id_w = table.lookup("ID_W", L=l, VGS=vgs, VDS=vds, VSB=0)
    r.value("ID/W(L, VGS, VDS, VSB)", float(id_w * 1e6), "uA/um")
    w = i_d / id_w
    r.value(f"w_{tag}", float(w), "um")

    # Noise
    sth_gm = table.lookup("STH_GM", GM_ID=gm_id, L=l, VDS=vds, VSB=0)
    sth = sth_gm * gm
    r.value("STH(gm/ID, L, VDS, VSB)", float(sth) * 1e24, "pV²/Hz", note="thermal noise PSD at 1 Hz")
    fco = table.lookup("SFL_STH", GM_ID=gm_id, L=l, VDS=vds, VSB=0)
    r.value("fco(gm/ID, L, VDS, VSB)", float(fco) * 1e-6, "MHz",
            note="flicker corner frequency @ flicker noise PSD = thermal noise PSD")

    return {"gm_id": gm_id, "gm_gds": gm_gds, "id_w": id_w, "w": w}


def size_at_final_width(r, tag, dev, w):
    """Re-derive the operating point with the final (finger-quantized) width."""
    r.section(f"{tag} at final width")
    i_d = w * dev["id_w"]
    r.value("i_out", float(i_d) * 1e3, "mA", note=f"i_out = w_{tag} * ID/W")
    gm = i_d * dev["gm_id"]
    r.value(f"gm_{tag}", float(gm) * 1e3, "mS")
    gds = gm / dev["gm_gds"]
    r.value(f"gds_{tag}", float(gds) * 1e3, "mS")
    return gm, gds


def main():
    r = Report("inverter", generator=Path(__file__).name)
    r.specs(SPECS_FILE)

    # ============================================
    # Load SG13G2 data tables
    # ============================================
    lv_nmos = load_table("sg13g2_lv_nmos")
    lv_pmos = load_table("sg13g2_lv_pmos")

    # ============================================
    # Device sizing at the specified bias point
    # ============================================
    nmos = size_device(r, "NMOS", lv_nmos,
                       vgs=specs.VCM_IN, vds=specs.VCM_OUT,
                       i_d=specs.I_OUT, l=specs.L)
    pmos = size_device(r, "PMOS", lv_pmos,
                       vgs=specs.VDD - specs.VCM_IN, vds=specs.VDD - specs.VCM_OUT,
                       i_d=specs.I_OUT, l=specs.L, gm_id=nmos["gm_id"])

    # ============================================
    # Finger configuration
    # ============================================
    r.section("Finger configuration options")
    w_ratio = pmos["w"] / nmos["w"]
    r.value("Target w_PMOS", float(pmos["w"]), "um")
    r.value("Target w_NMOS", float(nmos["w"]), "um")
    r.value("Target ratio (PMOS/NMOS)", float(w_ratio))

    options = calculate_finger_options(
        round(float(pmos["w"]), 2),
        round(float(nmos["w"]), 2),
        float(w_ratio),
        min_finger_width=1.0,
        max_finger_width=20.0,
        max_options=10,
        finger_width_step=1.0,
    )

    r.table(
        ["Option", "Fingers", "PMOS fw (um)", "PMOS W (um)", "NMOS fw (um)", "NMOS W (um)", "Ratio", "Error (%)"],
        [(i, nf, f"{fw_p:g}", f"{nf * fw_p:g}", f"{fw_n:g}", f"{nf * fw_n:g}", f"{ratio:.2f}", f"{err:.2f}")
         for i, (nf, fw_p, fw_n, ratio, err) in enumerate(options[:5], 1)],
    )

    if not options:
        r.text("No suitable finger configuration found!")
        r.write(REPORT_FILE)
        return

    r.section("Final widths")
    nf, fw_p, fw_n, _, _ = options[specs.FINGER_OPTION - 1]
    w_pmos = fw_p * nf
    w_nmos = fw_n * nf
    r.value("Chosen option", specs.FINGER_OPTION, fmt=".0f",
            note="FINGER_OPTION in specs_inverter.py")
    r.value("w_PMOS", w_pmos, "um", note=f"{nf} fingers × {fw_p:g} um")
    r.value("w_NMOS", w_nmos, "um", note=f"{nf} fingers × {fw_n:g} um")
    r.value("L", specs.L, "um", note="both devices")

    # ============================================
    # Sizing with the final widths
    # ============================================
    gm_n, gds_n = size_at_final_width(r, "NMOS", nmos, w_nmos)
    gm_p, gds_p = size_at_final_width(r, "PMOS", pmos, w_pmos)

    # ============================================
    # Inverter small-signal summary
    # ============================================
    r.section("Inverter small-signal summary")
    gm_a = gm_n + gm_p
    r.value("gm_A", float(gm_a) * 1e3, "mS", note="gm_A = gm_NMOS + gm_PMOS")
    gds_a = gds_n + gds_p
    r.value("gds_A", float(gds_a) * 1e3, "mS", note="gds_A = gds_NMOS + gds_PMOS")
    aol_a = -gm_a / gds_a
    r.value("Aol_A", float(aol_a), note=f"= {20 * np.log10(float(abs(aol_a))):.2f} dB")
    rout_a = 1 / gds_a if gds_a != 0 else float("inf")
    r.value("Rout_A", float(rout_a), "Ohm", note="Rout_A = 1 / gds_A")
    fcu_a = 1 / (2 * np.pi * rout_a * specs.C_LOAD)
    r.value("fcu_A", float(fcu_a) * 1e-6, "MHz", note="open-loop cut-off, 1 / (2π Rout_A C_load)")
    ft_a = gm_a / (2 * np.pi * specs.C_LOAD)
    r.value("fT_A", float(ft_a) * 1e-6, "MHz", note="unity-gain frequency, gm_A / (2π C_load)")

    # ============================================
    # Area estimation
    # ============================================
    r.section("Area estimation")
    area_inverter = w_pmos * specs.L + w_nmos * specs.L
    r.value("area_inverter", float(area_inverter), "um²", note="w_PMOS·L + w_NMOS·L")

    r.write(REPORT_FILE)


# Main Execution
if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Analytical (gm/ID) sizing of the inverter macro.")
    parser.add_argument('--draw', action='store_true',
                        help="re-render the schematic drawing into figures/ (requires schemdraw)")
    args = parser.parse_args()

    if args.draw:
        draw_circuit()
    main()
