#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5

int main() {
	setlocale(LC_ALL, "Portuguese");

	int counter = 0;
	int vetA[MAX] = { 0 },
		vetB[MAX] = { 0 },
		vetC[MAX] = { 0 };

	printf("\nValores do Vetor A:\n");

	// armazenar valores no vetA
	for(int i = 0; i < MAX; i++) {
		counter++;

		do {
			printf("\tNúmero %d - Insira um número inteiro: ", counter);
			scanf(" %d", &vetA[i]);

			if(vetA[i] <= 0)
				printf("O valor deve ser maior que 0!\n");

		} while(vetA[i] <= 0);
	}

	printf("\nValores do Vetor B:\n");

	// armazenar valores no vetB
	for(int i = 0; i < MAX; i++) {
		counter++;

		do {
			printf("\tNúmero %d - Insira um número inteiro: ", counter);
			scanf(" %d", &vetB[i]);	

			if(vetA[i] <= 0)
				printf("O valor deve ser maior que 0!\n");

		} while(vetB[i] <= 0);
	}

	// Inverte os valores
	for(int i = MAX - 1; i >= 0; i--)
		vetC[i] = vetB[i] * vetA[MAX - (i + 1)];
	
	printf("\n==================== VALORES INVERTIDOS ====================\n");
	printf("Vetor A:");			printf("\t\t\tVetor B:");		printf("\t\t\tVetor C:");
	
	// mostra as alterações
	for(int i = 0; i < MAX; i++) {
	    printf("\n  Posição %d = %d", i, vetA[i]);
	    printf("\t\t  Posição %d = %d", i, vetB[i]);
		printf("\t\t  Posição %d = %d", i, vetC[i]);
	}

	printf("\n\n");

	return 0;
}