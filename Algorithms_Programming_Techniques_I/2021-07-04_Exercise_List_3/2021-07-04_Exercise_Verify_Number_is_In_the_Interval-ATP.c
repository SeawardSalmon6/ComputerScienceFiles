#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int number;

	printf("\nInsira um número inteiro: ");
	scanf("%d", &number);

	if(number >= 20 && number <= 100)
		printf("\nEste número está entre o intervalo [20, 100] (de 20 a 100)!\n\n");
	else 
		printf("\nEste número NÃO ESTÁ entre o intervalo [20, 100] (de 20 a 100)!\n\n");

	return 0;
}