// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "D:/Project/Lab3/lab3_gcd/gcd.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "D:/Project/Lab3/lab3_gcd/gcd.cpp"
void gcd(int a, int b, int &c) {

#pragma HLS INTERFACE s_axilite port=a
#pragma HLS INTERFACE s_axilite port=b
#pragma HLS INTERFACE s_axilite port=c
 while(a!=b) {
  if(a>b) {
   a -= b;
  } else {
   b -= a;
  }
 }
 c = a;
}
