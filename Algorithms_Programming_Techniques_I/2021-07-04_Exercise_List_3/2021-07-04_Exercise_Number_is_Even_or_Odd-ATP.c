#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int number;

	printf("\nInsira um número inteiro: ");
	scanf("%d", &number);

	if(number % 2 == 0)
		printf("\nO número %d é PAR.\n\n", number);
	else
		printf("\nO número %d é ÍMPAR.\n\n", number);

	return 0;
}