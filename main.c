#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void c_sdot(int n, double* vectorA, double* vectorB, double* sdot) {
	*sdot = 0.0;

	for (int i = 0; i < n; i++) {
		*sdot += vectorA[i] * vectorB[i];
	}
}
extern double asm_sdot(int n, double* vectorA, double* vectorB);

int main() {
	int n = 4;
	double vectorA[] = { 1.0, 2.0, 3.0, 4.0 };
	double vectorB[] = { 5.0, 6.0, 7.0, 8.0 };
	double sdot;
	double result_c;
	double result_asm;

	c_sdot(n, vectorA, vectorB, &sdot);
	printf("sdot (C) = %f\n", sdot);
	result_c = sdot;

	// also pass &sdot
	// handle printing in c
	result_asm = asm_sdot(n, &vectorA, &vectorB);

	if (result_c == result_asm) {
		printf("Correctness check passed.\n");
	}
	else {
		printf("Correctness check failed.\n");
	}

	return 0;
}