#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int codOrigem;

	printf("\nInsira o código de origem do produto: ");
	scanf("%d", &codOrigem);

	switch(codOrigem) {
		case 1:
			printf("\nA procedência deste produto é da região Sul.\n\n");
			break;
		case 2:
			printf("\nA procedência deste produto é da região Norte.\n\n");
			break;
		case 3:
			printf("\nA procedência deste produto é da região Leste.\n\n");
			break;
		case 4:
			printf("\nA procedência deste produto é da região Oeste.\n\n");
			break;
		case 5:
		case 6:
			printf("\nA procedência deste produto é da região Nordeste.\n\n");
			break;
		case 7 ... 9:
			printf("\nA procedência deste produto é da região Sudeste.\n\n");
			break;
		case 10:
		case 11:
			printf("\nA procedência deste produto é da região Centro-Oeste.\n\n");
			break;
		case 12 ... 15:
			printf("\nA procedência deste produto é da região Nordeste.\n\n");
			break;
		default:
			printf("\nEste produto foi Importado.\n\n");
			break;
	}

	return 0;
}