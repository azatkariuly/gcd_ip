#include <stdio.h>
#include "gcd.h"

int main() {
	int a, b, c;
	a = 16; b = 48;

	gcd(a, b, c);

	printf("result: %d\n", c);

	return 0;
}
