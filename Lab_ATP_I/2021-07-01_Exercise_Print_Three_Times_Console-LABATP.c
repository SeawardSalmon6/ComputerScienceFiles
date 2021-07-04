#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese"); // configura o arquivo com alguns caracteres do Português
	
	int num, i;

	printf("\nInsira um número inteiro: ");
	scanf("%d", &num);
	printf("\n");

	for(i = 1; i <= 3; i++) {
		printf("%dª repetição ==> %d\n", i, num);
	}

	/* Outra Solução - Imprimir 'manualmente'
		printf("1ª repetição ==> %d\n", num);
		printf("2ª repetição ==> %d\n", num);
		printf("3ª repetição ==> %d\n", num);
	*/

	return 0;
}