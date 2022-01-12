/* Um arranjo bidimensional triangular inferior e uma matriz (geralmente quadrada)
na qual A[i][j]=0 se i<j. Escreva um programa em C que, dadas duas matrizes
triangulares inferiores A e B, efetua a sua multiplicacao e exibe o resultado. */

#include <stdio.h>

int main() {
	int n, i, j;

	do {
		printf("\nInsira o tamanho das matrizes quadradas: ");
		scanf(" %d", &n);

		if(n <= 0)
			printf("\n ----> Valor incorreto!\n");
	} while(n <= 0);

	// ======================= Inicializacao e leitura dos valores das matrizes
	int A[n][n], B[n][n];

	printf("\n----------- Preenchimento da Matriz A\n");
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(i >= j) {
				printf("\n  -> Valor da linha %d, coluna %d:  ", i + 1, j + 1);
				scanf(" %d", &A[i][j]);
			} else
				A[i][j] = 0;

	printf("\n\n----------- Preenchimento da Matriz B\n");
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(i >= j) {
				printf("\n  -> Valor da linha %d, coluna %d:  ", i + 1, j + 1);
				scanf(" %d", &B[i][j]);
			} else
				B[i][j] = 0;

	// ======================= Calcula a multiplicacao e apresenta os resultados
	printf("\n\n ========== RESULTADOS DA MULTIPLICACAO ========= \n");
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(i >= j)
				if(j % n == 0)
					printf("\n\t%d", (A[i][j] * B[i][j]));
				else
					printf("\t%d", (A[i][j] * B[i][j]));
			else
				printf("\t0");

	printf("\n\n");

	return 0;
}
