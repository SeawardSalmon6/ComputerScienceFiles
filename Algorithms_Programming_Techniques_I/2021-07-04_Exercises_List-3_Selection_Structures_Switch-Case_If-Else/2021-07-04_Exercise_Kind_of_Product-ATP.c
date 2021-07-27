#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int codProduto;

	printf("\nInsira o código de origem do produto: ");
	scanf("%d", &codProduto);

	switch(codProduto) {
		case 1:
			printf("\nCategoria: Alimento não perecível.\n\n");
			break;
		case 2 ... 4:
			printf("\nCategoria: Alimento Perecível\n\n");
			break;
		case 5:
		case 6:
			printf("\nCategoria: Vestuário\n\n");
			break;
		case 7:
			printf("\nCategoria: Higiene Pessoal\n\n");
			break;
		case 8 ... 13:
			printf("\nCategoria: Limpeza e Utensílios Domésticos\n\n");
			break;
		default:
			printf("\nCódigo inválido, esta categoria não existe!\n\n");
			break;
	}

	return 0;
}