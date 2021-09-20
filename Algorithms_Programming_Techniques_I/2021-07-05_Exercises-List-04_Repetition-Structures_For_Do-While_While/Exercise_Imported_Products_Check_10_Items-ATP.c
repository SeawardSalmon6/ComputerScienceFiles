#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int codOrigem;

    for(int i = 1; i <= 10; i++) {
		printf("\nProduto %d - Insira o código de origem do produto: ", i);
		scanf(" %d", &codOrigem);

		switch(codOrigem) {
			case 1:
				printf("\nA procedência do produto %d é da região Sul.\n\n", i);
				break;
			case 2:
				printf("\nA procedência do produto %d é da região Norte.\n\n", i);
				break;
			case 3:
				printf("\nA procedência do produto %d é da região Leste.\n\n", i);
				break;
			case 4:
				printf("\nA procedência do produto %d é da região Oeste.\n\n", i);
				break;
			case 5:
			case 6:
				printf("\nA procedência do produto %d é da região Nordeste.\n\n", i);
				break;
			case 7 ... 9:
				printf("\nA procedência do produto %d é da região Sudeste.\n\n", i);
				break;
			case 10:
			case 11:
				printf("\nA procedência do produto %d é da região Centro-Oeste.\n\n", i);
				break;
			case 12 ... 15:
				printf("\nA procedência do produto %d é da região Nordeste.\n\n", i);
				break;
			default:
				printf("\nO produto %d foi Importado.\n\n", i);
				break;
		}

		printf("-------------------------");
	}

    return 0;
}