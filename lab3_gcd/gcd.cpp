void gcd(int a, int b, int &c) {
//#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE s_axilite port=return
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
