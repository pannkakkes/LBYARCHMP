#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void c_kernel_dot_product(int n, double* vectorA, double* vectorB, double* sdot);
extern void asmhello(int n, double* vectorA, double* vectorB, double* sdot);

int main() {
	int n = 4;
	double vectorA[] = { 1.0, 2.0, 3.0, 4.0 };
	double vectorB[] = { 5.0, 6.0, 7.0, 8.0 };
	double sdot;

	asmhello();
	return 0;
}