#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int A, B, sum;

	printf("Insira dois valores inteiros abaixo e lhe daremos a somas dos valores:\n");
	scanf("%d %d", &A, &B);

	sum = A + B;

	printf("\nA soma de %d + %d é de: %d\n", A, B, sum);

	return 0;
}