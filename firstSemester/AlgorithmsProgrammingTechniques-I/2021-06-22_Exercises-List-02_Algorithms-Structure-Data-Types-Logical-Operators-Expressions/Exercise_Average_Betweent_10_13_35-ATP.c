#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int A = 10, B = 13, C = 35;
	float average = (A + B + C) / 3.00;

	printf("\nA média entre %d, %d e %d é: %.2lf\n", A, B, C, average);
	
	return 0;
}