#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void c_sdot(int n, double* vectorA, double* vectorB, double* sdot);
extern void asm_sdot(int n, double* vectorA, double* vectorB, double* sdot);

int main() {
	int n = 4;
	double vectorA[] = { 1.0, 2.0, 3.0, 4.0 };
	double vectorB[] = { 5.0, 6.0, 7.0, 8.0 };
	double sdot = 0.0;
	double result_c;
	double result_asm;

	c_sdot(n, vectorA, vectorB, &sdot);
	printf("sdot (C) = %f\n", sdot);
	result_c = sdot;

	sdot = 0.0;
	asm_sdot(n, vectorA, vectorB, &sdot);
	printf("sdot (x86-64) = %f\n", sdot);
	result_asm = sdot;

	if (result_c == result_asm) {
		printf("Correctness Check Passed.\n");
	}
	else {
		printf("Correctness Check Failed.\n");
	}

	return 0;
}