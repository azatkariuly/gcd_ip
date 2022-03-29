############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab3_gcd
set_top gcd
add_files gcd.h
add_files lab3_gcd/gcd.cpp
add_files -tb tb.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog
#source "./lab3_gcd/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -wave_debug -trace_level port -tool xsim
export_design -rtl verilog -format ip_catalog
