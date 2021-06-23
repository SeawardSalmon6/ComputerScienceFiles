#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int A, B;
	
	printf("\nInsira um número: ");
	scanf("%d", &A);

	printf("Insira outro número: ");
	scanf("%d", &B);

	int mult = A * B;

	printf("\nA multiplicação de %d * %d é: %d\n", A, B, mult);
	
	return 0;
}