#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int soma = 5 + 10;

	printf("A soma de 5 + 10 é: %d\n", soma);
	
	return 0;
}