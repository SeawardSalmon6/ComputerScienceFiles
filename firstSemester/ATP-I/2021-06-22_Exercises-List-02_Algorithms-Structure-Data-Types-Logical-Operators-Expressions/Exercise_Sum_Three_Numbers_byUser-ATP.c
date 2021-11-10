#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int A, B, C;
	
	printf("\nInsira um número: ");
	scanf("%d", &A);

	printf("Insira outro número: ");
	scanf("%d", &B);

	printf("Insira mais um número: ");
	scanf("%d", &C);

	int soma = A + B + C;

	printf("\nA soma de %d + %d + %d é: %d\n", A, B, C, soma);
	
	return 0;
}