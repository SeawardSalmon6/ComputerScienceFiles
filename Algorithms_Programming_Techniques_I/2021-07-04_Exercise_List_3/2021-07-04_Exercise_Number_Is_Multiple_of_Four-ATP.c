#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int number;

	printf("\nInsira um número, para verificarmos se ele é divísivel por 4:\n");
	scanf("%d", &number);

	if(number % 4 == 0)
		printf("\nEste número é um múltiplo de 4!\n\n");
	else
		printf("\nNúmero inválido.\n\n");

	return 0;
}