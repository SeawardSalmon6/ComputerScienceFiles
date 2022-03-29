#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define NUMBERS_QUANTITY 200

// ============= Métodos de Ordenação
void InsertionSort(int*, int, int);
void Merge(int*, int*, int, int);

// ============= Funções Auxiliares
void LerDados(FILE*, int*);
void TestarArquivo(FILE*);

int main(int argc, char **argv) {
	if(argc != 2) {
		printf("Usage: ./main <QTD_VETORES>\n");
		exit(1);
	}

	// --> Variáveis do programa
	int myRank, size, i, j, vizinho, qtdVetores = atoi(argv[1]);
	FILE *fr = fopen("vetor.dat", "r"); TestarArquivo(fr);
	FILE *fw = fopen("ordenado.dat", "w"); TestarArquivo(fw);

	// --> Inicialização do vetor original para a leitura dos dados
	int *VetorOriginal = (int*) malloc(sizeof(int) * NUMBERS_QUANTITY);
	LerDados(fr, VetorOriginal); fclose(fr);

	// --> Cálculo e declaração do sub vetor (armazenamento para Scatter)
	int qtdElemPorVetor = NUMBERS_QUANTITY / qtdVetores;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &size); // --> retorna a quantidade de processos
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank); // --> retorna o rank do processador atual

	// --> Declaração dos subvetores (para cada um dos processos)
	int *subVetor = (int*) malloc(sizeof(int) * qtdElemPorVetor * 2);

	// --> Envio das informações (pedaços do vet. original) para os outros processos
	MPI_Scatter(VetorOriginal, qtdElemPorVetor * 2, MPI_INT, subVetor, qtdElemPorVetor * 2, MPI_INT, 0, MPI_COMM_WORLD);

	// --> Ordenar cada um dos subvetores (de cada processo) utilizando o Insertion Sort
	InsertionSort(subVetor, 0, qtdElemPorVetor);
	InsertionSort(subVetor, qtdElemPorVetor, qtdElemPorVetor * 2);

	// --> Realiza o MergeSort em cada um dos processos
	int *tmpArray = (int*) malloc(2 * qtdElemPorVetor * sizeof(int));
	Merge(subVetor, tmpArray, 0, (qtdElemPorVetor * 2 - 1));

	for(i = 0; i < size; i++) {
		if(myRank == i) {
			if(myRank % 2) { // --> Processo ímpar
				vizinho = myRank - 1;
				MPI_Send(subVetor, qtdElemPorVetor * 2, MPI_INT, vizinho, 1, MPI_COMM_WORLD);
			} else {
				vizinho = (myRank == size - 1) ? 0 : (myRank % size + 1);
				subVetor = (int*) realloc(subVetor, qtdElemPorVetor * 4);
				MPI_Recv(subVetor, qtdElemPorVetor * 4, MPI_INT, vizinho, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				tmpArray = (int*) realloc(tmpArray, qtdElemPorVetor * 4);
				Merge(subVetor, tmpArray, 0, (qtdElemPorVetor * 4 - 1));
			}
		}
	}

	int *Sorted = NULL;
	if(myRank == 0) {
		Sorted = (int*) malloc(sizeof(int) * NUMBERS_QUANTITY);
	}

	// --> Reúne os os vetores ordenados num único vetor
	for(i = 0; i < size; i++) {
		if(myRank == i && myRank) {
			j = myRank;
			while(j > 0 && !(myRank % 2) && j != size) {
				MPI_Send(subVetor, qtdElemPorVetor * 4, MPI_INT, 0, 2, MPI_COMM_WORLD);
				j += 2;
			}
		} else if(myRank == 0) {
			MPI_Recv(Sorted, qtdElemPorVetor * 4, MPI_INT, i, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
	}

	free(tmpArray);

	// --> Realiza a chamada final do Merge Sort
	if(myRank == 0) {
		tmpArray = (int*) malloc(sizeof(int) * NUMBERS_QUANTITY);
		Merge(Sorted, tmpArray, 0, (NUMBERS_QUANTITY - 1));

		// --> Escreve os valores ordenados no novo arquivo
		for(i = 0; i < NUMBERS_QUANTITY; i++)
			fprintf(fw, "%d ", Sorted[i]);

		fclose(fw);
		free(Sorted); // --> Limpa a memória da root (proc. 00)
	}

	// --> Limpa a memória dos outros processos
	free(subVetor); free(VetorOriginal); free(tmpArray);

	MPI_Barrier(MPI_COMM_WORLD);

	MPI_Finalize();
	return 0;
}

void InsertionSort(int *Vetor, int start, int end) {
	int i, j, paraInserir;
	for(i = start; i < end; i++) {
		paraInserir = Vetor[i];
		j = i;

		while(j > 0 && Vetor[j - 1] > paraInserir) {
			Vetor[j] = Vetor[j - 1];
			j--;
		}

		Vetor[j] = paraInserir;
	}
}

void Merge(int *origin, int *aux, int i, int j) {
	int k, mid, ptrEsq, ptrDir;

	mid = (i + j) / 2;

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

void LerDados(FILE *fr, int *VetorLeitura) {
	int i;
	for(i = 0; i < NUMBERS_QUANTITY; i++)
		fscanf(fr, "%d ", &VetorLeitura[i]);
}

void TestarArquivo(FILE *fp) {
    if(!fp) {
        printf("\n--> Erro ao alocar memória. Saindo...\n\n");
        exit(1);
    }
}