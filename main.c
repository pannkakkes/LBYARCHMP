#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void c_sdot(int n, double* vectorA, double* vectorB, double* sdot) {
	*sdot = 0.0;

	for (int i = 0; i < n; i++) {
		*sdot += vectorA[i] * vectorB[i];
	}
}
extern double asm_sdot(int n, double* vectorA, double* vectorB, double* sdot);

int main() {
	int n = 1 << 20;
	double* vectorA = (double*)malloc(n * sizeof(double));
	double* vectorB = (double*)malloc(n * sizeof(double));
	double sdot;
	double result_c;
	double result_asm;


	for (int i = 0; i < n; i++) {
		vectorA[i] = (double)(i + 1);
		vectorB[i] = (double)(i + 5);
	}

	clock_t start, end;
	double elapsedTime;

	// C
	start = clock();

	c_sdot(n, vectorA, vectorB, &sdot);

	end = clock();

	elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
	printf("sdot (C) = %f\n", sdot);
	printf("Elapsed time (C) = %fseconds\n", elapsedTime);
	result_c = sdot;

	// ASM
	start = clock();

	asm_sdot(n, vectorA, vectorB, &sdot);

	end = clock();
	elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
	result_asm = sdot;
	printf("sdot (ASM) = %f\n", result_asm);
	printf("Elapsed time (ASM) = %f seconds\n", elapsedTime);

	if (result_c == result_asm) {
		printf("Correctness check passed.\n");
	}
	else {
		printf("Correctness check failed.\n");
	}

	return 0;
}