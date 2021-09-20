#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	float A, B, sum;

	printf("Insira dois valores reais ou inteiros abaixo e lhe daremos a somas dos valores:\n");
	scanf("%f %f", &A, &B);

	sum = A + B;

	printf("\nA soma de %.2f + %.2f é de: %.2f\n", A, B, sum);

	return 0;
}