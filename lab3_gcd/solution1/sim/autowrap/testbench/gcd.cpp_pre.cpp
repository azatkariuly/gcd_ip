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
