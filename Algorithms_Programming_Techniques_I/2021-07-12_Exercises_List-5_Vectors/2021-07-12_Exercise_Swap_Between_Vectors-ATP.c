#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5

int main() {
	setlocale(LC_ALL, "Portuguese");

	int counter = 0, aux = 0;
	int vetA[MAX] = { 0 },
		vetB[MAX] = { 0 };

	printf("\nValores do Vetor A:\n");

	// armazenar valores no vetA
	for(int i = 0; i < MAX; i++) {
		printf("\tNúmero %d - Insira um número inteiro: ", (counter++) + 1);
		scanf(" %d", &vetA[i]);
	}

	printf("\nValores do Vetor B:\n");

	// armazenar valores no vetB
	for(int i = 0; i < MAX; i++) {
		printf("\tNúmero %d - Insira um número inteiro: ", (counter++) + 1);
		scanf(" %d", &vetB[i]);
	}

	// Inverte os valores
	for(int i = 0; i < MAX; i++) {
		aux = vetA[MAX - (i + 1)];
		vetA[MAX - (i + 1)] = vetB[i];
		vetB[i] = aux;
	}
	
	printf("\n======== VALORES INVERTIDOS ========\n");
	printf("Vetor A:");			printf("\t\t\tVetor B:");
	
	// mostra as alterações
	for(int i = 0; i < MAX; i++) {
	    printf("\n  Posição %d = %d", i, vetA[i]);
	    printf("\t\t  Posição %d = %d", i, vetB[i]);
	}

	printf("\n\n");

	return 0;
}