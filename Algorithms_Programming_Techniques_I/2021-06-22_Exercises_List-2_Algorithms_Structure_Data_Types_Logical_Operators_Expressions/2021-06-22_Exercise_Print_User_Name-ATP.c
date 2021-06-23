#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	char nome[40];
	
	printf("\nInsira seu nome: ");
	scanf("%s", nome);

	printf("\nOlá %s, tudo bom?\n", nome);
	
	return 0;
}