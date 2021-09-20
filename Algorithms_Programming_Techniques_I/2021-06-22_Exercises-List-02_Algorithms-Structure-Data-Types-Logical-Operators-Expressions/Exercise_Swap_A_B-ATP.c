#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int A, B, aux;

	printf("\nInsira um número para a variável A: ");
	scanf("%d", &A);

	printf("\nInsira um número para a variável B: ");
	scanf("%d", &B);

	aux = B;
	B = A;
	A = aux;

	printf("\nO valor de A agora é: %d", A);
	printf("\nO valor de B agora é: %d\n", B);

	return 0;
}