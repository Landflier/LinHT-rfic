// Converted from IHP SG13CMOS5L PDK (Ngspice) for VACASK

//************************************************************************
//*
//* Copyright 2023 IHP PDK Authors
//* 
//* Licensed under the Apache License, Version 2.0 (the "License");
//* you may not use this file except in compliance with the License.
//* You may obtain a copy of the License at
//* 
//*    https://www.apache.org/licenses/LICENSE-2.0
//* 
//* Unless required by applicable law or agreed to in writing, software
//* distributed under the License is distributed on an "AS IS" BASIS,
//* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//* See the License for the specific language governing permissions and
//* limitations under the License.
//*
//************************************************************************

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_a21o_1
//* View name: schematic
subckt sg13cmos5l_a21o_1(x a1 a2 b1 vdd vss)
xn0 (net1 a1 net2 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn1 (net2 a2 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn2 (net1 b1 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn3 (x net1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp2 (net1 b1 net3 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (net3 a1 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (net3 a2 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (x net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_a21o_2
//* View name: schematic
subckt sg13cmos5l_a21o_2(x a1 a2 b1 vdd vss)
xn0 (net1 a1 net2 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (net2 a2 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net1 b1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (x net1 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xp2 (net1 b1 net3 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (net3 a1 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (net3 a2 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (x net1 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_a21oi_1
//* View name: schematic
subckt sg13cmos5l_a21oi_1(y a1 a2 b1 vdd vss)
xn0 (y b1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net1 a2 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (y a1 net1 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp2 (y b1 net2 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net2 a2 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (net2 a1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_a21oi_2
//* View name: schematic
subckt sg13cmos5l_a21oi_2(y a1 a2 b1 vdd vss)
xn0 (y b1 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn2 (net2 a2 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn1 (y a1 net2 vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xp2 (y b1 net1 vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp1 (net1 a2 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp0 (net1 a1 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_a221oi_1
//* View name: schematic
subckt sg13cmos5l_a221oi_1(y a1 a2 b1 b2 c1 vdd vss)
xp2 (y c1 net3 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp4 (net3 b2 net1 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net3 b1 net1 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (net1 a2 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (net1 a1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn4 (y c1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (net4 b2 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (y b1 net4 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (net2 a2 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (y a1 net2 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_and2_1
//* View name: schematic
subckt sg13cmos5l_and2_1(x a b vdd vss)
xn0 (net4 a net2 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn2 (x net4 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (net2 b vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp0 (net4 b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp2 (x net4 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net4 a vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_and2_2
//* View name: schematic
subckt sg13cmos5l_and2_2(x a b vdd vss)
xn0 (net1 a net2 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn2 (x net1 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn1 (net2 b vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp0 (net1 b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp2 (x net1 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp1 (net1 a vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_and3_1
//* View name: schematic
subckt sg13cmos5l_and3_1(x a b c vdd vss)
xn2 (net3 c vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn3 (x net2 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (net2 a net1 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn1 (net1 b net3 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp3 (x net2 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net2 b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp2 (net2 a vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp0 (net2 c vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_and3_2
//* View name: schematic
subckt sg13cmos5l_and3_2(x a b c vdd vss)
xn2 (net3 c vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn3 (x net2 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn0 (net2 a net1 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn1 (net1 b net3 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp3 (x net2 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp1 (net2 b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp2 (net2 a vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp0 (net2 c vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_and4_1
//* View name: schematic
subckt sg13cmos5l_and4_1(x a b c d vdd vss)
xn3 (net17 d vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn2 (net16 c net17 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn1 (net15 b net16 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn0 (net1 a net15 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn4 (x net1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp3 (net1 a vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp4 (x net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (net1 d vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp1 (net1 c vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp2 (net1 b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_and4_2
//* View name: schematic
subckt sg13cmos5l_and4_2(x a b c d vdd vss)
xn3 (net17 d vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn2 (net16 c net17 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn1 (net15 b net16 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn0 (net1 a net15 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn4 (x net1 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xp3 (net1 a vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp4 (x net1 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp0 (net1 d vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp1 (net1 c vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp2 (net1 b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_antennanp
//* View name: schematic
subckt sg13cmos5l_antennanp(a vdd vss)
xd1 (vss a) dantenna  l=780n w=780n m=1
xd0 (a vdd) dpantenna  l=1.34u w=1.05u m=1
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_buf_1
//* View name: schematic
subckt sg13cmos5l_buf_1(x a vdd vss)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn1 (x net1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp1 (x net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_buf_16
//* View name: schematic
subckt sg13cmos5l_buf_16(x a vdd vss)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=4.44u l=130.00n ng=6 ad=8.436e-13 as=1.066e-12 pd=6.72e-06 ps=8.8e-06 m=1
)
xn1 (x net1 vss vss) sg13_lv_nmos (
  w=11.84u l=130.00n ng=16 ad=2.25e-12 as=2.472e-12 pd=1.792e-05 ps=2e-05 m=1
)
xp1 (x net1 vdd vdd) sg13_lv_pmos (
  w=17.92u l=130.00n ng=16 ad=3.405e-12 as=3.741e-12 pd=2.4e-05 ps=2.684e-05 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=6.72u l=130.00n ng=6 ad=1.277e-12 as=1.613e-12 pd=9e-06 ps=1.184e-05 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_buf_2
//* View name: schematic
subckt sg13cmos5l_buf_2(x a vdd vss)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn1 (x net1 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xp1 (x net1 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_buf_4
//* View name: schematic
subckt sg13cmos5l_buf_4(x a vdd vss)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (x net1 vss vss) sg13_lv_nmos (
  w=2.96u l=130.00n ng=4 ad=5.624e-13 as=7.844e-13 pd=4.48e-06 ps=6.56e-06 m=1
)
xp1 (x net1 vdd vdd) sg13_lv_pmos (
  w=4.48u l=130.00n ng=4 ad=8.512e-13 as=1.187e-12 pd=6e-06 ps=8.84e-06 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=1.68u l=130.00n ng=2 ad=3.192e-13 as=5.712e-13 pd=2.44e-06 ps=4.72e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_buf_8
//* View name: schematic
subckt sg13cmos5l_buf_8(x a vdd vss)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=2.22u l=130.00n ng=3 ad=5.328e-13 as=5.328e-13 pd=4.4e-06 ps=4.4e-06 m=1
)
xn1 (x net1 vss vss) sg13_lv_nmos (
  w=5.92u l=130.00n ng=8 ad=1.125e-12 as=1.347e-12 pd=8.96e-06 ps=1.104e-05 m=1
)
xp1 (x net1 vdd vdd) sg13_lv_pmos (
  w=8.96u l=130.00n ng=8 ad=1.702e-12 as=2.038e-12 pd=1.2e-05 ps=1.484e-05 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=3.36u l=130.00n ng=3 ad=8.064e-13 as=8.064e-13 pd=5.92e-06 ps=5.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_decap_4
//* View name: schematic
subckt sg13cmos5l_decap_4(vdd vss)
xn0 (vss vdd vss vss) sg13_lv_nmos (
  w=420.00n l=1.000u ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp0 (vdd vss vdd vdd) sg13_lv_pmos (
  w=1.000u l=1.000u ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_decap_8
//* View name: schematic
subckt sg13cmos5l_decap_8(vdd vss)
xn0 (vss vdd vss vss) sg13_lv_nmos (
  w=840.00n l=1.000u ng=2 ad=1.596e-13 as=2.856e-13 pd=1.6e-06 ps=3.04e-06 m=1
)
xp0 (vdd vss vdd vdd) sg13_lv_pmos (
  w=2.000u l=1.000u ng=2 ad=3.8e-13 as=6.8e-13 pd=2.76e-06 ps=5.36e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dfrbp_1
//* View name: schematic
subckt sg13cmos5l_dfrbp_1(q q_n clk d reset_b vdd vss)
xn11 (net12 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn10 (net5 clkneg net12 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn12 (net2 net5 net11 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn13 (net11 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn14 (q_n net5 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (db d net10 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn1 (net10 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn4 (db clkneg net6 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn5 (net6 clkpos net9 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn6 (net9 net4 net8 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (net8 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn8 (net4 net6 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (clkneg clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (net4 clkpos net5 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (clkpos clkneg vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn16 (q net1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn15 (net1 net5 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp11 (net5 clkpos net3 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp12 (net2 net5 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp13 (net2 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp14 (q_n net5 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp4 (db clkpos net6 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp0 (db reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp1 (db d vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp5 (net7 net4 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp6 (net6 clkneg net7 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (net6 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp2 (clkneg clk vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (clkpos clkneg vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp8 (net4 net6 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp9 (net4 clkneg net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp16 (q net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp10 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp15 (net1 net5 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dfrbp_2
//* View name: schematic
subckt sg13cmos5l_dfrbp_2(q q_n clk d reset_b vdd vss)
xn11 (net12 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn10 (net5 clkneg net12 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn12 (net2 net5 net11 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn13 (net11 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn14 (q_n net5 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn0 (db d net10 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn1 (net10 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn4 (db clkneg net6 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn5 (net6 clkpos net9 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn6 (net9 net4 net8 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (net8 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn8 (net4 net6 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (clkneg clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (net4 clkpos net5 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (clkpos clkneg vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn16 (q net1 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn15 (net1 net5 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp11 (net5 clkpos net3 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp12 (net2 net5 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp13 (net2 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp14 (q_n net5 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp4 (db clkpos net6 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp0 (db reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp1 (db d vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp5 (net7 net4 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp6 (net6 clkneg net7 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (net6 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp2 (clkneg clk vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (clkpos clkneg vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp8 (net4 net6 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp9 (net4 clkneg net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp16 (q net1 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp10 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp15 (net1 net5 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dlhq_1
//* View name: schematic
subckt sg13cmos5l_dlhq_1(q d gate vdd vss)
xp8 (q qint_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp6 (qint gate_bb net8 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (qint_b qint vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (db d vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp0 (gate_b gate vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp1 (gate_bb gate_b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp5 (net8 qint_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp4 (net4 gate_b qint vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (net4 db vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xn0 (gate_b gate vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (gate_bb gate_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn5 (qint gate_b net9 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn8 (q qint_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn4 (net7 db vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn6 (net9 qint_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (qint_b qint vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (qint gate_bb net7 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (db d vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dlhr_1
//* View name: schematic
subckt sg13cmos5l_dlhr_1(q q_n d gate reset_b vdd vss)
xp8 (qint_b reset_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp9 (q qint_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp6 (qint gate_bb net11 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp5 (net11 qint_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp4 (qint gate_b net2 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (net2 db vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (db d vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp0 (gate_b gate vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp11 (q_n qintn_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp7 (qint_b qint vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (gate_bb gate_b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp10 (qintn_b qint_b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xn7 (qint_b qint net9 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn8 (net9 reset_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn5 (qint gate_b net7 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn6 (net7 qint_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn9 (q qint_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (qint gate_bb net1 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn4 (net1 db vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn2 (db d vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (gate_b gate vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn11 (q_n qintn_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (gate_bb gate_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn10 (qintn_b qint_b vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dlhrq_1
//* View name: schematic
subckt sg13cmos5l_dlhrq_1(q d gate reset_b vdd vss)
xn8 (net116 reset_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (q qint_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (gate_bb gate_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn5 (qint gate_b net89 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (qint_b qint net116 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (db d vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn4 (net61 db vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn3 (qint gate_bb net61 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn6 (net89 qint_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn0 (gate_b gate vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp3 (net60 db vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp8 (qint_b reset_b vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp6 (qint gate_bb net92 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp9 (q qint_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp5 (net92 qint_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp0 (gate_b gate vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp2 (db d vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp4 (qint gate_b net60 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (gate_bb gate_b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp7 (qint_b qint vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dllr_1
//* View name: schematic
subckt sg13cmos5l_dllr_1(q q_n d gate_n reset_b vdd vss)
xn2 (db d vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (gnb gate_n vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (gnbb gnb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn6 (net89 qint_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (qint_b qint net116 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn8 (net116 reset_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn5 (qint gnbb net89 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn11 (q_n qintn_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (qint gnb net61 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn10 (qintn_b qint_b vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn4 (net61 db vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn9 (q qint_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp1 (gnbb gnb vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp4 (qint gnbb net60 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp10 (qintn_b qint_b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp11 (q_n qintn_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (net60 db vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp5 (net92 qint_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp8 (qint_b reset_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (db d vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp0 (gnb gate_n vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp9 (q qint_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp6 (qint gnb net92 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (qint_b qint vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dllrq_1
//* View name: schematic
subckt sg13cmos5l_dllrq_1(q d gate_n reset_b vdd vss)
xn5 (qint gnbb net89 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn3 (qint gnb net61 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn8 (net116 reset_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (q qint_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn4 (net61 db vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn6 (net89 qint_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (qint_b qint net116 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (db d vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (gnb gate_n vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (gnbb gnb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp3 (net59 db vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp8 (qint_b reset_b vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (gnb gate_n vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp5 (net92 qint_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (qint_b qint vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp9 (q qint_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp4 (qint gnbb net59 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (db d vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp1 (gnbb gnb vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp6 (qint gnb net92 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dlygate4sd1_1
//* View name: schematic
subckt sg13cmos5l_dlygate4sd1_1(x a vdd vss)
xp3 (x net3 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (net2 net1 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn3 (x net3 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net3 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn1 (net2 net1 vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dlygate4sd2_1
//* View name: schematic
subckt sg13cmos5l_dlygate4sd2_1(x a vdd vss)
xp3 (x net3 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=1.000u l=250.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (net2 net1 vdd vdd) sg13_lv_pmos (
  w=1.000u l=250.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn3 (x net3 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net3 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=180.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn1 (net2 net1 vss vss) sg13_lv_nmos (
  w=420.00n l=180.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dlygate4sd3_1
//* View name: schematic
subckt sg13cmos5l_dlygate4sd3_1(x a vdd vss)
xp3 (x net3 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=1.000u l=500.0n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (net2 net1 vdd vdd) sg13_lv_pmos (
  w=1.000u l=500.0n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn3 (x net3 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net3 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=500.0n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn1 (net2 net1 vss vss) sg13_lv_nmos (
  w=420.00n l=500.0n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_ebufn_2
//* View name: schematic
subckt sg13cmos5l_ebufn_2(z a te_b vdd vss)
xn3 (net4 net3 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn2 (z net1 net4 vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn1 (net3 te_b vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp2 (net2 te_b vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp3 (z net1 net2 vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp1 (net3 te_b vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_ebufn_4
//* View name: schematic
subckt sg13cmos5l_ebufn_4(z a te_b vdd vss)
xn0 (net23 a vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (net21 te_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (z net23 net22 vss) sg13_lv_nmos (
  w=2.96u l=130.00n ng=4 ad=5.624e-13 as=7.844e-13 pd=4.48e-06 ps=6.56e-06 m=1
)
xn3 (net22 net21 vss vss) sg13_lv_nmos (
  w=2.96u l=130.00n ng=4 ad=5.624e-13 as=7.844e-13 pd=4.48e-06 ps=6.56e-06 m=1
)
xp0 (net23 a vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net21 te_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (z net23 net24 vdd) sg13_lv_pmos (
  w=4.48u l=130.00n ng=4 ad=8.512e-13 as=1.187e-12 pd=6e-06 ps=8.84e-06 m=1
)
xp2 (net24 te_b vdd vdd) sg13_lv_pmos (
  w=4.48u l=130.00n ng=4 ad=8.512e-13 as=1.187e-12 pd=6e-06 ps=8.84e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_ebufn_8
//* View name: schematic
subckt sg13cmos5l_ebufn_8(z a te_b vdd vss)
xn3 (net23 net22 vss vss) sg13_lv_nmos (
  w=5.92u l=130.00n ng=8 ad=1.125e-12 as=1.347e-12 pd=8.96e-06 ps=1.104e-05 m=1
)
xn2 (z net21 net23 vss) sg13_lv_nmos (
  w=5.92u l=130.00n ng=8 ad=1.125e-12 as=1.347e-12 pd=8.96e-06 ps=1.104e-05 m=1
)
xn1 (net22 te_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (net21 a vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xp2 (net24 te_b vdd vdd) sg13_lv_pmos (
  w=8.96u l=130.00n ng=8 ad=1.702e-12 as=2.038e-12 pd=1.2e-05 ps=1.484e-05 m=1
)
xp3 (z net21 net24 vdd) sg13_lv_pmos (
  w=8.96u l=130.00n ng=8 ad=1.702e-12 as=2.038e-12 pd=1.2e-05 ps=1.484e-05 m=1
)
xp1 (net22 te_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (net21 a vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_einvn_2
//* View name: schematic
subckt sg13cmos5l_einvn_2(z a te_b vdd vss)
xn0 (te te_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn2 (net1 te vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn1 (z a net1 vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xp0 (te te_b vdd vdd) sg13_lv_pmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp1 (net2 te_b vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp2 (z a net2 vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_einvn_4
//* View name: schematic
subckt sg13cmos5l_einvn_4(z a te_b vdd vss)
xn2 (net16 te vss vss) sg13_lv_nmos (
  w=2.96u l=130.00n ng=4 ad=5.624e-13 as=7.844e-13 pd=4.48e-06 ps=6.56e-06 m=1
)
xn0 (te te_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (z a net16 vss) sg13_lv_nmos (
  w=2.96u l=130.00n ng=4 ad=5.624e-13 as=7.844e-13 pd=4.48e-06 ps=6.56e-06 m=1
)
xp0 (te te_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net17 te_b vdd vdd) sg13_lv_pmos (
  w=4.48u l=130.00n ng=4 ad=8.512e-13 as=1.187e-12 pd=6e-06 ps=8.84e-06 m=1
)
xp2 (z a net17 vdd) sg13_lv_pmos (
  w=4.48u l=130.00n ng=4 ad=8.512e-13 as=1.187e-12 pd=6e-06 ps=8.84e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_einvn_8
//* View name: schematic
subckt sg13cmos5l_einvn_8(z a te_b vdd vss)
xn1 (z a net29 vss) sg13_lv_nmos (
  w=5.92u l=130.00n ng=8 ad=1.125e-12 as=1.347e-12 pd=8.96e-06 ps=1.104e-05 m=1
)
xn0 (te te_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net29 te vss vss) sg13_lv_nmos (
  w=5.92u l=130.00n ng=8 ad=1.125e-12 as=1.347e-12 pd=8.96e-06 ps=1.104e-05 m=1
)
xp1 (net28 te_b vdd vdd) sg13_lv_pmos (
  w=8.96u l=130.00n ng=8 ad=1.702e-12 as=2.038e-12 pd=1.2e-05 ps=1.484e-05 m=1
)
xp2 (z a net28 vdd) sg13_lv_pmos (
  w=8.96u l=130.00n ng=8 ad=1.702e-12 as=2.038e-12 pd=1.2e-05 ps=1.484e-05 m=1
)
xp0 (te te_b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_inv_1
//* View name: schematic
subckt sg13cmos5l_inv_1(y a vdd vss)
xn0 (y a vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp0 (y a vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_inv_16
//* View name: schematic
subckt sg13cmos5l_inv_16(y a vdd vss)
xn0 (y a vss vss) sg13_lv_nmos (
  w=11.84u l=130.00n ng=16 ad=2.25e-12 as=2.472e-12 pd=1.792e-05 ps=2e-05 m=1
)
xp0 (y a vdd vdd) sg13_lv_pmos (
  w=17.92u l=130.00n ng=16 ad=3.405e-12 as=3.741e-12 pd=2.4e-05 ps=2.684e-05 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_inv_2
//* View name: schematic
subckt sg13cmos5l_inv_2(y a vdd vss)
xn0 (y a vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xp0 (y a vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_inv_4
//* View name: schematic
subckt sg13cmos5l_inv_4(y a vdd vss)
xp0 (y a vdd vdd) sg13_lv_pmos (
  w=4.48u l=130.00n ng=4 ad=8.512e-13 as=1.187e-12 pd=6e-06 ps=8.84e-06 m=1
)
xn0 (y a vss vss) sg13_lv_nmos (
  w=2.96u l=130.00n ng=4 ad=5.624e-13 as=7.844e-13 pd=4.48e-06 ps=6.56e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_inv_8
//* View name: schematic
subckt sg13cmos5l_inv_8(y a vdd vss)
xn0 (y a vss vss) sg13_lv_nmos (
  w=5.92u l=130.00n ng=8 ad=1.125e-12 as=1.347e-12 pd=8.96e-06 ps=1.104e-05 m=1
)
xp0 (y a vdd vdd) sg13_lv_pmos (
  w=8.96u l=130.00n ng=8 ad=1.702e-12 as=2.038e-12 pd=1.2e-05 ps=1.484e-05 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_lgcp_1
//* View name: schematic
subckt sg13cmos5l_lgcp_1(gclk clk gate vdd vss)
xp1 (clkbb clkb vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp3 (net1 clkbb net4 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp4 (int_gate net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (net4 gate vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp8 (net3 int_gate vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp9 (gclk net3 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp6 (net1 clkb net6 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp0 (clkb clk vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp7 (net3 clk vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp5 (net6 int_gate vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn9 (gclk net3 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn7 (net3 int_gate net5 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn4 (int_gate net1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (clkbb clkb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn6 (net7 int_gate vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn3 (net2 gate vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn5 (net1 clkbb net7 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn0 (clkb clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn8 (net5 clk vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn2 (net1 clkb net2 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_mux2_1
//* View name: schematic
subckt sg13cmos5l_mux2_1(x a0 a1 s vdd vss)
xp1 (net4 s vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp5 (x net6 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp4 (net6 a1 net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (sb s vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp3 (net5 sb vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (net6 a0 net4 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xn4 (net3 s vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net1 sb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn5 (x net6 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (sb s vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn3 (net6 a1 net3 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (net6 a0 net1 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_mux2_2
//* View name: schematic
subckt sg13cmos5l_mux2_2(x a0 a1 s vdd vss)
xp1 (net4 s vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp5 (x net6 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp4 (net6 a1 net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (sb s vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp3 (net5 sb vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (net6 a0 net4 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xn4 (net3 s vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net1 sb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn5 (x net6 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn0 (sb s vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn3 (net6 a1 net3 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (net6 a0 net1 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_mux4_1
//* View name: schematic
subckt sg13cmos5l_mux4_1(x a0 a1 a2 a3 s0 s1 vdd vss)
xn12 (x xb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (low s0b net7 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn3 (net7 a0 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn6 (low s1b xb vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn11 (high s1 xb vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn10 (net4 a3 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn9 (high s0 net4 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn8 (net6 a2 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn7 (high s0b net6 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn5 (net2 a1 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn4 (low s0 net2 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn1 (s1b s1 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn0 (s0b s0 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp6 (low s1 xb vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp11 (high s1b xb vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp12 (x xb vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp10 (high s0b net3 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp9 (net3 a3 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp8 (high s0 net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp7 (net5 a2 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (net8 a0 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (low s0 net8 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (s1b s1 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (s0b s0 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp5 (low s0b net1 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp4 (net1 a1 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nand2_1
//* View name: schematic
subckt sg13cmos5l_nand2_1(y a b vdd vss)
xp1 (y b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (y a vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn1 (net1 b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (y a net1 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nand2_2
//* View name: schematic
subckt sg13cmos5l_nand2_2(y a b vdd vss)
xp1 (y b vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp0 (y a vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xn1 (net1 b vss vss) sg13_lv_nmos (
  w=1.44u l=130.00n ng=2 ad=2.736e-13 as=4.896e-13 pd=2.2e-06 ps=4.24e-06 m=1
)
xn0 (y a net1 vss) sg13_lv_nmos (
  w=1.44u l=130.00n ng=2 ad=2.736e-13 as=4.896e-13 pd=2.2e-06 ps=4.24e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nand2b_1
//* View name: schematic
subckt sg13cmos5l_nand2b_1(y a_n b vdd vss)
xp2 (y net2 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net2 a_n vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp0 (y b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn1 (y net2 net1 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (net2 a_n vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn2 (net1 b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nand2b_2
//* View name: schematic
subckt sg13cmos5l_nand2b_2(y a_n b vdd vss)
xp2 (y a vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp0 (a a_n vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp1 (y b vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xn1 (y b net1 vss) sg13_lv_nmos (
  w=1.44u l=130.00n ng=2 ad=2.736e-13 as=4.896e-13 pd=2.2e-06 ps=4.24e-06 m=1
)
xn0 (a a_n vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn2 (net1 a vss vss) sg13_lv_nmos (
  w=1.44u l=130.00n ng=2 ad=2.736e-13 as=4.896e-13 pd=2.2e-06 ps=4.24e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nand3_1
//* View name: schematic
subckt sg13cmos5l_nand3_1(y a b c vdd vss)
xp0 (y a vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (y b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (y c vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn1 (net2 b net3 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net3 c vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (y a net2 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nand3b_1
//* View name: schematic
subckt sg13cmos5l_nand3b_1(y a_n b c vdd vss)
xp0 (net1 a_n vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp1 (y net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (y b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (y c vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn2 (net2 b net3 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (net3 c vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (net1 a_n vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn1 (y net1 net2 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nand4_1
//* View name: schematic
subckt sg13cmos5l_nand4_1(y a b c d vdd vss)
xp3 (y d vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (y a vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (y b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (y c vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn1 (net2 b net3 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net3 c net5 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (y a net2 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (net5 d vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nor2_1
//* View name: schematic
subckt sg13cmos5l_nor2_1(y a b vdd vss)
xn0 (y a vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (y b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (y b net1 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nor2_2
//* View name: schematic
subckt sg13cmos5l_nor2_2(y a b vdd vss)
xn0 (y a vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn1 (y b vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp1 (y b net1 vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nor2b_1
//* View name: schematic
subckt sg13cmos5l_nor2b_1(y a b_n vdd vss)
xn0 (b b_n vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn1 (y a vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (y b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp0 (b b_n vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp1 (net1 b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (y a net1 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nor2b_2
//* View name: schematic
subckt sg13cmos5l_nor2b_2(y a b_n vdd vss)
xn0 (b b_n vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn1 (y a vss vss) sg13_lv_nmos (
  w=1.44u l=130.00n ng=2 ad=2.736e-13 as=4.896e-13 pd=2.2e-06 ps=4.24e-06 m=1
)
xn2 (y b vss vss) sg13_lv_nmos (
  w=1.44u l=130.00n ng=2 ad=2.736e-13 as=4.896e-13 pd=2.2e-06 ps=4.24e-06 m=1
)
xp0 (b b_n vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (net1 b vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp2 (y a net1 vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nor3_1
//* View name: schematic
subckt sg13cmos5l_nor3_1(y a b c vdd vss)
xp2 (y c net2 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net2 b net3 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (net3 a vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn0 (y a vss vss) sg13_lv_nmos (
  w=770.00n l=130.00n ng=1 ad=2.618e-13 as=2.618e-13 pd=2.22e-06 ps=2.22e-06 m=1
)
xn1 (y b vss vss) sg13_lv_nmos (
  w=770.00n l=130.00n ng=1 ad=2.618e-13 as=2.618e-13 pd=2.22e-06 ps=2.22e-06 m=1
)
xn2 (y c vss vss) sg13_lv_nmos (
  w=770.00n l=130.00n ng=1 ad=2.618e-13 as=2.618e-13 pd=2.22e-06 ps=2.22e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nor3_2
//* View name: schematic
subckt sg13cmos5l_nor3_2(y a b c vdd vss)
xp2 (y c net2 vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp1 (net2 b net3 vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp0 (net3 a vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xn0 (y a vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn1 (y b vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn2 (y c vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nor4_1
//* View name: schematic
subckt sg13cmos5l_nor4_1(y a b c d vdd vss)
xp0 (net3 a vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net2 b net3 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (net1 c net2 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (y d net1 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn0 (y a vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (y d vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (y b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (y c vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_nor4_2
//* View name: schematic
subckt sg13cmos5l_nor4_2(y a b c d vdd vss)
xp0 (net3 a vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp1 (net2 b net3 vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp2 (net1 c net2 vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp3 (y d net1 vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xn0 (y a vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn3 (y d vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn1 (y b vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn2 (y c vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_o21ai_1
//* View name: schematic
subckt sg13cmos5l_o21ai_1(y a1 a2 b1 vdd vss)
xp0 (net14 a1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=150.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (y a2 net14 vdd) sg13_lv_pmos (
  w=1.12u l=150.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (y b1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=150.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn0 (net1 a2 vss vss) sg13_lv_nmos (
  w=740.00n l=150.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net1 a1 vss vss) sg13_lv_nmos (
  w=740.00n l=150.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (y b1 net1 vss) sg13_lv_nmos (
  w=740.00n l=150.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_or2_1
//* View name: schematic
subckt sg13cmos5l_or2_1(x a b vdd vss)
xp1 (net2 b net3 vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp0 (net3 a vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp2 (x net2 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn1 (net2 a vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (net2 b vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn2 (x net2 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_or2_2
//* View name: schematic
subckt sg13cmos5l_or2_2(x a b vdd vss)
xp1 (net2 b net3 vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp0 (net3 a vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp2 (x net2 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xn1 (net2 a vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (net2 b vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn2 (x net2 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_or3_1
//* View name: schematic
subckt sg13cmos5l_or3_1(x a b c vdd vss)
xn2 (net1 c vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn3 (x net1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (net1 b vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xp3 (x net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net9 b net12 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (net12 a vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (net1 c net9 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_or3_2
//* View name: schematic
subckt sg13cmos5l_or3_2(x a b c vdd vss)
xn2 (net1 c vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn3 (x net1 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn1 (net1 b vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xp3 (x net1 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp1 (net9 b net12 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (net12 a vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (net1 c net9 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_or4_1
//* View name: schematic
subckt sg13cmos5l_or4_1(x a b c d vdd vss)
xn4 (x net1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (net1 d vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn2 (net1 c vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn1 (net1 b vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xp0 (net4 a vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (net3 b net4 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (net2 c net3 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (net1 d net2 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp4 (x net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_or4_2
//* View name: schematic
subckt sg13cmos5l_or4_2(x a b c d vdd vss)
xn4 (x net1 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn3 (net1 d vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn2 (net1 c vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn1 (net1 b vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xp0 (net4 a vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (net3 b net4 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (net2 c net3 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (net1 d net2 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp4 (x net1 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_sdfbbp_1
//* View name: schematic
subckt sg13cmos5l_sdfbbp_1(q q_n clk d reset_b scd sce set_b vdd vss)
xp1 (resetbb reset_b vdd vdd) sg13_lv_pmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp19 (pre_q dbblatch2 net8 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp20 (pre_q set_b vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (clkbb clkb vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (sceb sce vdd vdd) sg13_lv_pmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp7 (db d net3 vdd) sg13_lv_pmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp13 (dbbtg clkb net10 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp12 (net10 dblatchm vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp6 (net3 sce vdd vdd) sg13_lv_pmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp21 (q_n pre_q vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp14 (net1 dblatchm vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp18 (net8 resetbb vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp11 (dblatchm set_b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp4 (net2 scd vdd vdd) sg13_lv_pmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp2 (clkb clk vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp10 (dblatchm dbbtg net7 vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp8 (db clkbb dbbtg vdd) sg13_lv_pmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp5 (db sceb net2 vdd) sg13_lv_pmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp22 (pre_qb pre_q vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp9 (net7 resetbb vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp16 (net6 pre_q vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp17 (dbblatch2 clkbb net6 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp15 (dbblatch2 clkb net1 vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp23 (q pre_qb vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xn4 (db sce net5 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn5 (net5 scd vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn18 (pre_q dbblatch2 net11 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn8 (db clkb dbbtg vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (net4 sceb vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn3 (clkbb clkb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (resetbb reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn17 (net14 pre_q vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn9 (dblatchm dbbtg net12 vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (sceb sce vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn10 (net12 set_b vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn13 (net15 dblatchm vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn19 (net11 set_b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn12 (dbbtg clkbb net15 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn6 (db d net4 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn22 (pre_qb pre_q vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn16 (dbblatch2 clkb net14 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn23 (q pre_qb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn15 (net13 dblatchm vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn2 (clkb clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn14 (dbblatch2 clkbb net13 vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn11 (dblatchm resetbb net12 vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn21 (q_n pre_q vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn20 (pre_q resetbb net11 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_sighold
//* View name: schematic
subckt sg13cmos5l_sighold(sh vdd vss)
xn1 (net1 sh vss vss) sg13_lv_nmos (
  w=300.0n l=130.00n ng=1 ad=1.02e-13 as=1.02e-13 pd=1.28e-06 ps=1.28e-06 m=1
)
xn0 (sh net1 vss vss) sg13_lv_nmos (
  w=300.0n l=700.0n ng=1 ad=1.02e-13 as=1.02e-13 pd=1.28e-06 ps=1.28e-06 m=1
)
xp1 (net1 sh vdd vdd) sg13_lv_pmos (
  w=450.00n l=130.00n ng=1 ad=1.53e-13 as=1.53e-13 pd=1.58e-06 ps=1.58e-06 m=1
)
xp0 (sh net1 vdd vdd) sg13_lv_pmos (
  w=300.0n l=700.0n ng=1 ad=1.02e-13 as=1.02e-13 pd=1.28e-06 ps=1.28e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_slgcp_1
//* View name: schematic
subckt sg13cmos5l_slgcp_1(gclk clk gate sce vdd vss)
xp10 (gclk net5 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp4 (net1 clkbb net6 vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp1 (clkbb clkb vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp8 (net5 int_gate vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp2 (net3 sce vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp7 (net6 clkb net4 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp5 (int_gate net6 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (clkb clk vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp9 (net5 clk vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp6 (net4 int_gate vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp3 (net1 gate net3 vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xn5 (int_gate net6 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (net2 clk vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn2 (net1 sce vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn4 (net6 clkb net1 vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn7 (net7 int_gate vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn8 (net5 int_gate net2 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn10 (gclk net5 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (clkbb clkb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (net1 gate vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn0 (clkb clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn6 (net6 clkbb net7 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_tiehi
//* View name: schematic
subckt sg13cmos5l_tiehi(l_hi vdd vss)
xn1 (net3 net2 vss vss) sg13_lv_nmos (
  w=795.00n l=130.00n ng=1 ad=2.703e-13 as=2.703e-13 pd=2.27e-06 ps=2.27e-06 m=1
)
xn0 (net1 net1 vss vss) sg13_lv_nmos (
  w=300n l=130.00n ng=1 ad=1.02e-13 as=1.02e-13 pd=1.28e-06 ps=1.28e-06 m=1
)
xp1 (l_hi net3 vdd vdd) sg13_lv_pmos (
  w=1.155u l=130.00n ng=1 ad=3.927e-13 as=3.927e-13 pd=2.99e-06 ps=2.99e-06 m=1
)
xp0 (net2 net1 vdd vdd) sg13_lv_pmos (
  w=660.0n l=130.00n ng=1 ad=2.244e-13 as=2.244e-13 pd=2e-06 ps=2e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_tielo
//* View name: schematic
subckt sg13cmos5l_tielo(l_lo vdd vss)
xn0 (net3 net2 vss vss) sg13_lv_nmos (
  w=385.00n l=130.00n ng=1 ad=1.309e-13 as=1.309e-13 pd=1.45e-06 ps=1.45e-06 m=1
)
xn1 (l_lo net1 vss vss) sg13_lv_nmos (
  w=880.0n l=130.00n ng=1 ad=2.992e-13 as=2.992e-13 pd=2.44e-06 ps=2.44e-06 m=1
)
xp0 (net2 net2 vdd vdd) sg13_lv_pmos (
  w=300n l=130.00n ng=1 ad=1.02e-13 as=1.02e-13 pd=1.28e-06 ps=1.28e-06 m=1
)
xp1 (net1 net3 vdd vdd) sg13_lv_pmos (
  w=1.045u l=130.00n ng=1 ad=3.553e-13 as=3.553e-13 pd=2.77e-06 ps=2.77e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_xnor2_1
//* View name: schematic
subckt sg13cmos5l_xnor2_1(y a b vdd vss)
xp4 (y net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (y b net4 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (net4 a vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp1 (net1 b vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp0 (net1 a vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xn3 (y net1 net3 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (net2 a vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn0 (net1 b net2 vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xn4 (net3 b vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net3 a vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_xor2_1
//* View name: schematic
subckt sg13cmos5l_xor2_1(x a b vdd vss)
xn0 (net1 a vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn3 (x b net3 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (x net1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn4 (net3 a vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (net1 b vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xp0 (net6 a vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp1 (net1 b net6 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (net5 a vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp4 (net5 b vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (x net1 net5 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_a22oi_1
//* View name: schematic
subckt sg13cmos5l_a22oi_1(y a1 a2 b1 b2 vdd vss)
xn1 (net1 b1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (y b2 net1 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (net2 a2 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (y a1 net2 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp1 (y b1 net3 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (y b2 net3 vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp2 (net3 a2 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp0 (net3 a1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_sdfrbpq_1
//* View name: schematic
subckt sg13cmos5l_sdfrbpq_1(q clk d reset_b scd sce vdd vss)
xn3 (db scd net63 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (db d net65 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (sceb sce vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn4 (net63 sce vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net65 sceb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn17 (net12 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn16 (net5 clkneg net12 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn18 (net2 net5 net11 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn19 (net11 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn20 (q net2 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn6 (dbbb dbb net10 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (net10 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn10 (dbbb clkneg net6 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn11 (net6 clkpos net9 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn12 (net9 net4 net8 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn13 (net8 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn14 (net4 net6 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn8 (clkneg clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn15 (net4 clkpos net5 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (clkpos clkneg vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn5 (dbb db vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp1 (net64 sce vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (net62 sceb vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (sceb sce vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp4 (db scd net62 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (db d net64 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp17 (net5 clkpos net3 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp18 (net2 net5 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp19 (net2 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp20 (q net2 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp10 (dbbb clkpos net6 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp6 (dbbb reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (dbbb dbb vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp11 (net7 net4 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp12 (net6 clkneg net7 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp13 (net6 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp8 (clkneg clk vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp9 (clkpos clkneg vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp14 (net4 net6 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp15 (net4 clkneg net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp5 (dbb db vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp16 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_sdfrbpq_2
//* View name: schematic
subckt sg13cmos5l_sdfrbpq_2(q clk d reset_b scd sce vdd vss)
xn3 (db scd net63 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (db d net65 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (sceb sce vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn4 (net63 sce vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net65 sceb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn5 (dbb db vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn17 (net12 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn16 (net5 clkneg net12 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn18 (net2 net5 net11 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn19 (net11 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn20 (q net2 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn6 (dbbb dbb net10 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (net10 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn10 (dbbb clkneg net6 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn11 (net6 clkpos net9 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn12 (net9 net4 net8 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn13 (net8 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn14 (net4 net6 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn8 (clkneg clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn15 (net4 clkpos net5 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (clkpos clkneg vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp1 (net64 sce vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (net62 sceb vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (sceb sce vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp4 (db scd net62 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (db d net64 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp5 (dbb db vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp17 (net5 clkpos net3 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp18 (net2 net5 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp19 (net2 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp20 (q net2 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp10 (dbbb clkpos net6 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp6 (dbbb reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (dbbb dbb vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp11 (net7 net4 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp12 (net6 clkneg net7 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp13 (net6 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp8 (clkneg clk vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp9 (clkpos clkneg vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp14 (net4 net6 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp15 (net4 clkneg net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp16 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_sdfrbp_2
//* View name: schematic
subckt sg13cmos5l_sdfrbp_2(q q_n clk d reset_b scd sce vdd vss)
xn3 (db scd net63 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (db d net65 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (sceb sce vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn4 (net63 sce vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net65 sceb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn5 (dbb db vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn17 (net12 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn16 (net5 clkneg net12 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn18 (net2 net5 net11 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn19 (net11 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn20 (q_n net5 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn6 (dbbb dbb net10 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (net10 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn10 (dbbb clkneg net6 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn11 (net6 clkpos net9 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn12 (net9 net4 net8 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn13 (net8 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn14 (net4 net6 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn8 (clkneg clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn15 (net4 clkpos net5 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (clkpos clkneg vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn22 (q net1 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn21 (net1 net5 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp1 (net64 sce vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (net62 sceb vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (sceb sce vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp4 (db scd net62 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (db d net64 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp5 (dbb db vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp17 (net5 clkpos net3 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp18 (net2 net5 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp19 (net2 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp20 (q_n net5 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp10 (dbbb clkpos net6 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp6 (dbbb reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (dbbb dbb vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp11 (net7 net4 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp12 (net6 clkneg net7 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp13 (net6 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp8 (clkneg clk vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp9 (clkpos clkneg vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp14 (net4 net6 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp15 (net4 clkneg net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp22 (q net1 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp16 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp21 (net1 net5 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_sdfrbp_1
//* View name: schematic
subckt sg13cmos5l_sdfrbp_1(q q_n clk d reset_b scd sce vdd vss)
xn3 (db scd net63 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn1 (db d net65 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn0 (sceb sce vss vss) sg13_lv_nmos (
  w=550.00n l=130.00n ng=1 ad=1.87e-13 as=1.87e-13 pd=1.78e-06 ps=1.78e-06 m=1
)
xn4 (net63 sce vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (net65 sceb vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn5 (net13 db vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn17 (net12 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn16 (net5 clkneg net12 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn18 (net2 net5 net11 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn19 (net11 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn20 (q_n net5 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn6 (dbb net13 net10 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (net10 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn10 (dbb clkneg net6 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn11 (net6 clkpos net9 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn12 (net9 net4 net8 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn13 (net8 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn14 (net4 net6 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn8 (clkneg clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn15 (net4 clkpos net5 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (clkpos clkneg vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn22 (q net1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn21 (net1 net5 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp1 (net64 sce vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp3 (net62 sceb vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp0 (sceb sce vdd vdd) sg13_lv_pmos (
  w=840.00n l=130.00n ng=1 ad=2.856e-13 as=2.856e-13 pd=2.36e-06 ps=2.36e-06 m=1
)
xp4 (db scd net62 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp2 (db d net64 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp5 (net13 db vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp17 (net5 clkpos net3 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp18 (net2 net5 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp19 (net2 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp20 (q_n net5 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp10 (dbb clkpos net6 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp6 (dbb reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (dbb net13 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp11 (net7 net4 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp12 (net6 clkneg net7 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp13 (net6 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp8 (clkneg clk vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp9 (clkpos clkneg vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp14 (net4 net6 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp15 (net4 clkneg net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp22 (q net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp16 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp21 (net1 net5 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dfrbpq_2
//* View name: schematic
subckt sg13cmos5l_dfrbpq_2(q clk d reset_b vdd vss)
xn11 (net12 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn10 (net5 clkneg net12 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn12 (net2 net5 net11 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn13 (net11 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn0 (db d net10 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn1 (net10 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn4 (db clkneg net6 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn5 (net6 clkpos net9 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn6 (net9 net4 net8 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (net8 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn8 (net4 net6 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (clkneg clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (net4 clkpos net5 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (clkpos clkneg vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn15 (q net1 vss vss) sg13_lv_nmos (
  w=1.48u l=130.00n ng=2 ad=2.812e-13 as=5.032e-13 pd=2.24e-06 ps=4.32e-06 m=1
)
xn14 (net1 net5 vss vss) sg13_lv_nmos (
  w=640.00n l=130.00n ng=1 ad=2.176e-13 as=2.176e-13 pd=1.96e-06 ps=1.96e-06 m=1
)
xp11 (net5 clkpos net3 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp12 (net2 net5 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp13 (net2 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp4 (db clkpos net6 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp0 (db reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp1 (db d vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp5 (net7 net4 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp6 (net6 clkneg net7 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (net6 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp2 (clkneg clk vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (clkpos clkneg vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp8 (net4 net6 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp9 (net4 clkneg net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp15 (q net1 vdd vdd) sg13_lv_pmos (
  w=2.24u l=130.00n ng=2 ad=4.256e-13 as=7.616e-13 pd=3e-06 ps=5.84e-06 m=1
)
xp10 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp14 (net1 net5 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_dfrbpq_1
//* View name: schematic
subckt sg13cmos5l_dfrbpq_1(q clk d reset_b vdd vss)
xn11 (net12 net2 vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn10 (net5 clkneg net12 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn12 (net2 net5 net11 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn13 (net11 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn0 (db d net10 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn1 (net10 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn4 (db clkneg net6 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn5 (net6 clkpos net9 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn6 (net9 net4 net8 vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn7 (net8 reset_b vss vss) sg13_lv_nmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xn8 (net4 net6 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn2 (clkneg clk vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn9 (net4 clkpos net5 vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn3 (clkpos clkneg vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn15 (q net1 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xn14 (net1 net5 vss vss) sg13_lv_nmos (
  w=740.00n l=130.00n ng=1 ad=2.516e-13 as=2.516e-13 pd=2.16e-06 ps=2.16e-06 m=1
)
xp11 (net5 clkpos net3 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp12 (net2 net5 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp13 (net2 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp4 (db clkpos net6 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp0 (db reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp1 (db d vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp5 (net7 net4 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp6 (net6 clkneg net7 vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp7 (net6 reset_b vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp2 (clkneg clk vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp3 (clkpos clkneg vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp8 (net4 net6 vdd vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp9 (net4 clkneg net5 vdd) sg13_lv_pmos (
  w=1.000u l=130.00n ng=1 ad=3.4e-13 as=3.4e-13 pd=2.68e-06 ps=2.68e-06 m=1
)
xp15 (q net1 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
xp10 (net3 net2 vdd vdd) sg13_lv_pmos (
  w=420.00n l=130.00n ng=1 ad=1.428e-13 as=1.428e-13 pd=1.52e-06 ps=1.52e-06 m=1
)
xp14 (net1 net5 vdd vdd) sg13_lv_pmos (
  w=1.12u l=130.00n ng=1 ad=3.808e-13 as=3.808e-13 pd=2.92e-06 ps=2.92e-06 m=1
)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_fill_1
//* View name: schematic
subckt sg13cmos5l_fill_1(vdd vss)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_fill_2
//* View name: schematic
subckt sg13cmos5l_fill_2(vdd vss)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_fill_4
//* View name: schematic
subckt sg13cmos5l_fill_4(vdd vss)
ends
//* End of subcircuit definition.

//* Library name: sg13cmos5l_stdcell
//* Cell name: sg13cmos5l_fill_8
//* View name: schematic
subckt sg13cmos5l_fill_8(vdd vss)
ends
//* End of subcircuit definition.
