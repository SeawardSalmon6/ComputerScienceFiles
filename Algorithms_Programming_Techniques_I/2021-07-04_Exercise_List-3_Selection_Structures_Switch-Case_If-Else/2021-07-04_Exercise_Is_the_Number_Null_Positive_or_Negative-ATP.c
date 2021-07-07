#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int number;

	printf("\nInsira um número inteiro: ");
	scanf("%d", &number);

	if(number > 0)
		printf("\nO número %d é POSITIVO.\n\n", number);
	else if(number < 0)
		printf("\nO número %d é NEGATIVO.\n\n", number);
	else
		printf("\nO número %d é NULO.\n\n", number);

	return 0;
}