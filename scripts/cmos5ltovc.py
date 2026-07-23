#!/usr/bin/env python3
"""Convert the IHP SG13CMOS5L ngspice model libraries to VACASK format.

This mirrors VACASK's shipped ``sg13g2tovc.py`` recipe, reusing the same
``ng2vclib`` conversion engine, but adapted for the CMOS-only SG13CMOS5L PDK:

  * targets ``ihp-sg13cmos5l`` (MOS lv/hv, resistors, metal-fringe cap, diodes,
    parasitic PNP, ESD, bondpad, S-varicap) + standard cells;
  * reuses the PDK's already-compiled OSDI binaries under
    ``libs.tech/ngspice/osdi`` (SG13CMOS5L ships no ``verilog-a/`` source and no
    ``vacask/`` tree), so there is NO Verilog-A compile step;
  * skips xschem-symbol ``spectre_format`` patching (those symbols live in the
    read-only container PDK and belong to the later xschem-integration step);
  * writes the generated tree into the repo, because the container PDK dir
    (``/foss/pdks/ihp-sg13cmos5l``) is read-only.

Run inside the iic-osic-tools container (the ``ng2vclib`` engine ships with
VACASK):

    PDK_ROOT=/foss/pdks PDK=ihp-sg13cmos5l LINHT_ROOT=/foss/designs/LinHT_IC \\
        python3 scripts/cmos5ltovc.py

Output: ``$LINHT_ROOT/models/vacask/ihp-sg13cmos5l/{.vacaskrc.toml,models/}``.
Re-runnable (overwrites). See .llm/vacask-simulation.md for the wider plan.
"""

import os
import sys

try:
    from ng2vclib.converter import Converter
    from ng2vclib.dfl import default_config
except ImportError:
    # Fall back to the known VACASK python location in iic-osic-tools.
    sys.path.insert(0, "/foss/tools/vacask/lib/vacask/python")
    from ng2vclib.converter import Converter
    from ng2vclib.dfl import default_config

PDK_DEFAULT = "ihp-sg13cmos5l"
DEFAULT_MODEL_PREFIX = "sg13cmos5l_default_mod_"

# Technology model files: ( ngspice file, read/process depth, output depth,
# output basename ). Corner files are copied structurally (depth 0); device
# model libs are processed one level deep (depth 1), matching sg13g2tovc.py.
TECH_FILES = [
    ("cornerMOSlv.lib", 0, 0, "cornerMOSlv.lib"),
    ("cornerMOShv.lib", 0, 0, "cornerMOShv.lib"),
    ("cornerDIO.lib", 0, 0, "cornerDIO.lib"),
    ("cornerRES.lib", 0, 0, "cornerRES.lib"),
    ("cornerPNP.lib", 0, 0, "cornerPNP.lib"),          # CMOS5L-only (parasitic PNP)
    ("diodes.lib", 1, None, "diodes.lib"),
    ("resistors_mod.lib", 1, None, "resistors_mod.lib"),
    ("cap_mfringe.lib", 1, None, "cap_mfringe.lib"),   # CMOS5L-only (no MIM cap)
    ("sg13g2_bondpad.lib", 1, None, "sg13g2_bondpad.lib"),
    ("sg13g2_esd.lib", 1, None, "sg13g2_esd.lib"),
    ("sg13g2_moshv_mod.lib", 1, None, "sg13g2_moshv_mod.lib"),
    ("sg13g2_moslv_mod.lib", 1, None, "sg13g2_moslv_mod.lib"),
    ("sg13g2_svaricaphv_mod.lib", 1, None, "sg13g2_svaricaphv_mod.lib"),
    ("sg13cmos5l_pnpMPA_mod.lib", 1, None, "sg13cmos5l_pnpMPA_mod.lib"),  # CMOS5L-only
]

# Standard cells (optional; needed only for a stdcell-based digital divider).
# Converted with the same default-model prefix so cross-references resolve.
STDCELL_FILES = [
    ("sg13cmos5l_stdcell.spice", 1, None, "sg13cmos5l_stdcell.inc"),
]

# Per-file source patches (same set as sg13g2tovc.py). In the CMOS5L copies the
# ESD/varicap bug anchors are already fixed upstream, so those become harmless
# no-op replacements; the SWSOA-parameter removal IS still required.
PATCHES = {
    "sg13g2_esd.lib": [(
        ".MODEL diodevss_mod D (tnom = 27 level = 1 is=9.017E-019 rs=200   "
        "n=1.03 isr=3.776E-015   ikf=0.0001754 cj0=9.42E-016  m=0.3012  "
        "vj=0.6684 bv=11.28 ibv=1E-009 8 nbv=1.324   eg=1.17 xti=3  )",
        ".MODEL diodevss_mod D (tnom = 27 level = 1 is=9.017E-019 rs=200   "
        "n=1.03 isr=3.776E-015   ikf=0.0001754 cj0=9.42E-016  m=0.3012  "
        "vj=0.6684 bv=11.28 ibv=1E-009 nbv=1.324   eg=1.17 xti=3  )",
    )],
    "sg13g2_svaricaphv_mod.lib": [("+ stuac 40", "+ stuac=40")],
    "sg13g2_moshv_mod.lib": [(".param SWSOA = 0", "")],
    "sg13g2_moslv_mod.lib": [(".param SWSOA = 0", "")],
}

# The parasitic PNP is a plain SPICE Gummel-Poon model (.model ... pnp level=1).
# Map it to VACASK's full SPICE BJT (master sp_bjt), matching the sg13g2 recipe.
FAMILY_MAP_UPDATE = {
    ("bjt", 1, None): ("spice/full/bjt.osdi", "sp_bjt", {}),
    ("bjt", None, None): ("spice/full/bjt.osdi", "sp_bjt", {}),
}

# Curated OSDI load set for the common include. Deterministic (rather than
# introspected) so the port is stable. PDK devices (psp103/psp103_nqs/r3_cmc/
# mosvar) resolve by bare name via module_path_prefix -> the PDK ngspice/osdi;
# the spice/* masters are VACASK built-ins. Mirrors the sg13g2 common lib minus
# the HBT (vbic), which SG13CMOS5L does not have.
COMMON_LOADS = [
    "mosvar.osdi",
    "psp103.osdi",
    "psp103_nqs.osdi",
    "r3_cmc.osdi",
    "spice/capacitor.osdi",
    "spice/diode.osdi",
    "spice/full/bjt.osdi",
    "spice/inductor.osdi",
    "spice/resistor.osdi",
]
COMMON_DEFAULT_MODELS = [
    (DEFAULT_MODEL_PREFIX + "c", "sp_capacitor"),
    (DEFAULT_MODEL_PREFIX + "l", "sp_inductor"),
    (DEFAULT_MODEL_PREFIX + "r", "sp_resistor"),
]

SIGNATURE = "// Converted from IHP SG13CMOS5L PDK (Ngspice) for VACASK\n"


def build_cfg(read_depth, output_depth, sourcepath):
    cfg = default_config()
    cfg.update({
        "default_model_prefix": DEFAULT_MODEL_PREFIX,
        "sourcepath": ["."] + sourcepath,
        "read_depth": read_depth,
        "process_depth": read_depth,
        "output_depth": output_depth,
        "patch": PATCHES,
        "original_case_subckt": True,
        "original_case_model": True,
        "signature": SIGNATURE,
    })
    cfg["family_map"].update(FAMILY_MAP_UPDATE)
    return cfg


def convert_files(file_list, sourcepath, out_models, failures):
    for fname, rpd, opd, outbase in file_list:
        dest = os.path.join(out_models, outbase)
        try:
            cfg = build_cfg(rpd, opd, sourcepath)
            Converter(cfg, indent=4, debug=1).convert(fname, dest)
            print("  ok  ", fname, "->", os.path.relpath(dest))
        except Exception as exc:  # noqa: BLE001 - report and continue
            print("  FAIL", fname, ":", exc)
            failures.append((fname, str(exc)))


def write_common_lib(out_models):
    path = os.path.join(out_models, "sg13cmos5l_vacask_common.lib")
    lines = [SIGNATURE, "// Disable SOA checks\n", "parameters swsoa=0\n",
             "// OSDI files\n"]
    lines += ['load "%s"\n' % f for f in COMMON_LOADS]
    lines += ["\n// Default models\n"]
    lines += ["model %s %s\n" % (name, master) for name, master in COMMON_DEFAULT_MODELS]
    with open(path, "w") as f:
        f.writelines(lines)
    print("  wrote", os.path.relpath(path))


def write_vacaskrc(out_base, pdk):
    path = os.path.join(out_base, ".vacaskrc.toml")
    # include_path -> repo models (via $(LINHT_ROOT)); module_path -> the PDK's
    # existing OSDI (read-only is fine). "ihp-sg13cmos5l" is hardcoded rather
    # than $(PDK) so this works regardless of a stale PDK env var.
    txt = (
        "# VACASK configuration for IHP SG13CMOS5L (ported from ngspice models).\n"
        "# Requires env vars: LINHT_ROOT (repo root), PDK_ROOT (dir with ihp-sg13cmos5l).\n"
        "# Copy to $HOME or the VACASK run dir, or point VACASK at it.\n"
        "[Paths]\n"
        'include_path_prefix = [ "$(LINHT_ROOT)/models/vacask/%s/models" ]\n'
        'module_path_prefix = [ "$(PDK_ROOT)/ihp-sg13cmos5l/libs.tech/ngspice/osdi" ]\n'
        % pdk
    )
    with open(path, "w") as f:
        f.write(txt)
    print("  wrote", os.path.relpath(path))


def main():
    pdkroot = os.getenv("PDK_ROOT")
    if not pdkroot:
        sys.exit("error: PDK_ROOT must point to the directory containing the PDKs")
    pdk = os.getenv("PDK") or PDK_DEFAULT
    if pdk != PDK_DEFAULT:
        print("warning: PDK=%s, expected %s; proceeding" % (pdk, PDK_DEFAULT))
        pdk = PDK_DEFAULT
    linht = os.getenv("LINHT_ROOT")
    if not linht:
        sys.exit("error: LINHT_ROOT must point to the repo root")

    tech_src = os.path.realpath(os.path.join(pdkroot, pdk, "libs.tech", "ngspice", "models"))
    stdcell_src = os.path.realpath(os.path.join(pdkroot, pdk, "libs.ref", "sg13cmos5l_stdcell", "spice"))
    if not os.path.isdir(tech_src):
        sys.exit("error: ngspice models not found at %s" % tech_src)

    out_base = os.path.join(linht, "models", "vacask", pdk)
    out_models = os.path.join(out_base, "models")
    os.makedirs(out_models, exist_ok=True)
    print("Output:", out_base)

    failures = []
    print("Converting technology model files")
    convert_files(TECH_FILES, [tech_src], out_models, failures)

    print("Converting standard cells")
    if os.path.isdir(stdcell_src):
        convert_files(STDCELL_FILES, [tech_src, stdcell_src], out_models, failures)
    else:
        print("  skip (stdcell spice dir not found:", stdcell_src, ")")

    print("Writing common include + .vacaskrc.toml")
    write_common_lib(out_models)
    write_vacaskrc(out_base, pdk)

    if failures:
        print("\n%d file(s) failed:" % len(failures))
        for fname, err in failures:
            print("  -", fname, ":", err)
        sys.exit(1)
    print("\nDone. Set LINHT_ROOT + PDK_ROOT and include sg13cmos5l_vacask_common.lib")
    print("plus the corner libs in your VACASK netlist.")


if __name__ == "__main__":
    main()
