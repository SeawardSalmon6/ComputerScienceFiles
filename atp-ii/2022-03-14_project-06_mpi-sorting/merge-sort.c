#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval end, begin;

int NUMBERS_QUANTITY;

void RecvArray(int*);
void WriteArray(int*);
void MergeSort(int, int, int*, int*);

int main() {
	int *OriginalArray, *tmpArray;
	double tempoExecucao;

	printf("\n--> Insira a quantidade de elementos a serem ordenados: ");
	scanf(" %d", &NUMBERS_QUANTITY);

	OriginalArray = (int*) malloc(sizeof(int) * NUMBERS_QUANTITY);
	tmpArray = (int*) malloc(sizeof(int) * NUMBERS_QUANTITY);

	RecvArray(OriginalArray);

	gettimeofday(&begin, NULL);
    MergeSort(0, NUMBERS_QUANTITY - 1, OriginalArray, tmpArray);
    gettimeofday(&end, NULL);

	tempoExecucao = (double) (end.tv_sec - begin.tv_sec + 1E-6 * (end.tv_usec - begin.tv_usec));

    printf("\n--> [MERGE SORT] Time Elapsed: %lf\n", tempoExecucao);
	WriteArray(OriginalArray);

	printf("\n");
	free(OriginalArray); free(tmpArray);

	return 0;
}

void MergeSort(int i, int j, int *origin, int *aux) {
	int k, mid, ptrEsq, ptrDir;

	if(j <= i) // --> Termina a recursão se vetor vazio/unitário
		return;

	mid = (i + j) / 2;
	MergeSort(i, mid, origin, aux); // --> Recursão da parte inferior
	MergeSort(mid + 1, j, origin, aux); // --> Recursão da parte superior

	// ======== Fase Recursiva
	// --> Inicializa ponteiros das partes a serem juntadas
	ptrEsq = i; ptrDir = mid + 1; k = 0;

	// --> Laço para juntar as partes do vetor
	while(ptrEsq <= mid && ptrDir <= j) {
		if(origin[ptrEsq] < origin[ptrDir]) { // --> Menor valor no vetor anterior
			aux[k] = origin[ptrEsq];
			ptrEsq++;
		} else { // --> Caso contrário, no vetor posterior
			aux[k] = origin[ptrDir];
			ptrDir++;
		}

		k++;
	}

	// --> Terminou a junção de um dos vetores, agora faz o próximo
	if(ptrEsq > mid) {
		while(ptrDir <= j) { // --> Se terminou o vetor anterior
			aux[k] = origin[ptrDir];
			ptrDir++; k++;
		}
	} else { // --> Caso terminou o vetor posterior
		while(ptrEsq <= mid) {
			aux[k] = origin[ptrEsq];
			ptrEsq++; k++;
		}
	}

	// ======= Fase Final: Copiar valores ao original
	// --> Laço de cópia para o vetor original
	for(k = i; k <= j; k++)
		origin[k] = aux[k - i];
}

void RecvArray(int *arr) {
	FILE *fp = fopen("vetor.dat", "r");

	if(!fp) {
		printf("\n--> Allocation memory error. Exiting...\n\n");
		exit(1);
	}

	int i;
	for(i = 0; i < NUMBERS_QUANTITY; i++)
		fscanf(fp, "%d ", &arr[i]);

	fclose(fp);
}

void WriteArray(int *arr) {
	FILE *fp = fopen("merge.dat", "w");

	if(!fp) {
		printf("\n--> Allocation memory error. Exiting...\n\n");
		exit(1);
	}

	int i;
	for(i = 0; i < NUMBERS_QUANTITY; i++)
		fprintf(fp, "%d ", arr[i]);

	fclose(fp);
}