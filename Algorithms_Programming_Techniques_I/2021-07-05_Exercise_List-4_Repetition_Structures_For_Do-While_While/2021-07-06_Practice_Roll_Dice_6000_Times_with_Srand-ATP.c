#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	unsigned seed;
	int faceDado;
	int face1 = 0,
		face2 = 0,
		face3 = 0,
		face4 = 0,
		face5 = 0,
		face6 = 0;
	
	srand(time(NULL));

	for(int i = 1; i <= 6000; i++) {
		faceDado = 1 + rand() % 6;

		switch(faceDado) {
			case 1:
				face1++;
				break;
			case 2:
				face2++;
				break;
			case 3:
				face3++;
				break;
			case 4:
				face4++;
				break;
			case 5:
				face5++;
				break;
			case 6:
				face6++;
				break;
		}
	}
		
	printf("\n========== RESULTADOS ==========\n");
	printf("Quantidade de Vezes para Cada Face:");
	printf("\n\t- Face nº1:   %d vez(es)", face1);
	printf("\n\t- Face nº2:   %d vez(es)", face2);
	printf("\n\t- Face nº3:   %d vez(es)", face3);
	printf("\n\t- Face nº4:   %d vez(es)", face4);
	printf("\n\t- Face nº5:   %d vez(es)", face5);
	printf("\n\t- Face nº6:   %d vez(es)\n\n", face6);

	return 0;
}