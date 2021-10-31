#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int codProduto, i = 0;
	char resp;

	do {
		i++;

		printf("\nProduto %d - Insira o código de origem do produto: ", i);
		scanf("%d", &codProduto);

		switch(codProduto) {
			case 1:
				printf("\n ==> Categoria: Alimento não perecível.\n\n");
				break;
			case 2 ... 4:
				printf("\n ==> Categoria: Alimento Perecível\n\n");
				break;
			case 5:
			case 6:
				printf("\n ==> Categoria: Vestuário\n\n");
				break;
			case 7:
				printf("\n ==> Categoria: Higiene Pessoal\n\n");
				break;
			case 8 ... 13:
				printf("\n ==> Categoria: Limpeza e Utensílios Domésticos\n\n");
				break;
			default:
				printf("\n ==> Código inválido, esta categoria não existe!\n\n");
				break;
		}

		printf("Deseja buscar por outro produto (S/N)?\n");
		scanf(" %c", &resp);

		printf("\n-----------------------");

	} while(toupper(resp) == 'S');

	printf("\n\n");
    
	return 0;
}