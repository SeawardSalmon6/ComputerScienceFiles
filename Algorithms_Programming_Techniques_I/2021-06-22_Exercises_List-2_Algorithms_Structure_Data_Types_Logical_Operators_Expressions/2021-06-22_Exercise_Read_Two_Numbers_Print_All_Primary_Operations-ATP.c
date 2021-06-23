#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int A, B, soma, subt, mult;
	float div;

	printf("\nInsira um número: ");
	scanf("%d", &A);

	printf("Insira outro número: ");
	scanf("%d", &B);

	soma = A + B;
	subt = A - B;
	mult = A * B;
	div = A / B;

	printf("\nA soma de %d + %d é: %d", A, B, soma);
	printf("\n\nA subtração de %d - %d é: %d", A, B, subt);
	printf("\n\nA multiplicação de %d * %d é: %d", A, B, mult);
	printf("\n\nA divisão de %d / %d é: %.2lf\n", A, B, div);
	
	return 0;
}