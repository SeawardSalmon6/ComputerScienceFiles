#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int A = 15, B = 36;
	int mult = A * B;

	printf("\nA multiplicação de %d * %d é: %d\n", A, B, mult);
	
	return 0;
}