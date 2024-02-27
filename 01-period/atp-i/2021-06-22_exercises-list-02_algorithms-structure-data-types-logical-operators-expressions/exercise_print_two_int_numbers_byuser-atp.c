#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int A, B;

	printf("\nInsira um número: ");
	scanf("%d", &A);

	printf("Insira outro número: ");
	scanf("%d", &B);

	printf("\nO primeiro número é: %d", A);
	printf("\nO segundo número é: %d\n", B);
	
	return 0;
}