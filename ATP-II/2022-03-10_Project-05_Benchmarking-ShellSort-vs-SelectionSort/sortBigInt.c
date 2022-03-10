#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval end, begin;
#define NUMBERS_QUANTITY 200000

typedef struct Biggo {
    int high;
    int low;
} BigInt;

/* ============== Métodos de Ordenação */
void RunShellSort(FILE*, BigInt*);
void RunSelection(FILE*, BigInt*);
void RunBubble(FILE*, BigInt*);
void ShellSort(BigInt*);
void SelectionSort(BigInt*);
void BubbleSort(BigInt*);

/* ============== Funções Auxiliares do Programa */
void TestFile(FILE*);
void ReadData(FILE*, BigInt*);
void TrocaValorBiggos(BigInt*, BigInt*);
void WriteOnFile(FILE*, BigInt*);
void ResetToOrigin(BigInt*, BigInt*);
int pPow(int, int);

int main() {
    FILE *fr = fopen("bigint.dat", "r"); TestFile(fr);
    FILE *fShell = fopen("shell.dat", "w"); TestFile(fShell);
    FILE *fSelection = fopen("selection.dat", "w"); TestFile(fSelection);
    FILE *fBubble = fopen("bubble.dat", "w"); TestFile(fBubble);
    BigInt Original[NUMBERS_QUANTITY], VetorBiggos[NUMBERS_QUANTITY];

    ReadData(fr, Original); fclose(fr);

    ResetToOrigin(Original, VetorBiggos);
    RunShellSort(fShell, VetorBiggos);

    ResetToOrigin(Original, VetorBiggos);
    RunSelectionSort(fSelection, VetorBiggos);

    // ResetToOrigin(Original, VetorBiggos);
    // RunBubble(fBubble, VetorBiggos);

    printf("\n");

    return 0;
}

void TrocaValorBiggos(BigInt *a, BigInt *b) {
    BigInt tmp;
    tmp.high = a->high;
    tmp.low = a->low;
    a->high = b->high;
    a->low = b->low;
    b->high = tmp.high;
    b->low = tmp.low;
}

void ShellSort(BigInt *VetorBiggos) {
    int i, j, p, l, valHigh, valLow;
    int k[10] = { 1, 0 };

    p = 1;
    while(k[p - 1] < NUMBERS_QUANTITY / 2) { // --> Calculando passo inicial
        k[p] = pPow(4, p) + 3 * pPow(2, p - 1) + 1;
        p++;
    } p--; // --> diminuição do índice maior que a quantidade de items

    while(p > 0) {
        p--; // --> acertando o valor do passo para iteração atual
        for(l = 0; l < k[p]; l++) { // --> laço para executar insertion k[p] vezes
            for(i = l + k[p]; i < NUMBERS_QUANTITY; i += k[p]) { // --> algoritmo insertion ajustado
                valHigh = VetorBiggos[i].high; // --> atribuir a valor o valor da posição
                valLow = VetorBiggos[i].low; // --> atribuir a valor o valor da posição
                j = i;

                while(j - k[p] >= 0 && VetorBiggos[j - k[p]].high >= valHigh) {
                    if(VetorBiggos[j - k[p]].high > valHigh) { // --> Verifica se o high é maior, se sim troca
                        VetorBiggos[j].high = VetorBiggos[j - k[p]].high;
                        VetorBiggos[j].low = VetorBiggos[j - k[p]].low;
                        j = j - k[p];
                    } else if(VetorBiggos[j - k[p]].low > valLow) { // --> Verifica se o low é maior, se sim, troca
                        VetorBiggos[j].high = VetorBiggos[j - k[p]].high;
                        VetorBiggos[j].low = VetorBiggos[j - k[p]].low;
                        j = j - k[p];
                    } else
                        break;
                }

                VetorBiggos[j].high = valHigh;
                VetorBiggos[j].low = valLow;
            }
        }
    }
    return;
}

void SelectionSort(BigInt *VetorBiggos) {
	int i, j, nChave;

	// --> Seleção
	for(i = 0; i < NUMBERS_QUANTITY; i++) {
		nChave = i;
		for(j = i + 1; j < NUMBERS_QUANTITY; j++)
			if(VetorBiggos[nChave].high > VetorBiggos[j].high)
				nChave = j;
            else if(VetorBiggos[nChave].high == VetorBiggos[j].high && VetorBiggos[nChave].low > VetorBiggos[j].low)
                nChave = j;

		if(nChave != i)
            TrocaValorBiggos(&VetorBiggos[nChave], &VetorBiggos[i]);
	}
}

void BubbleSort(BigInt *VetorBiggos) {
	int i, j, troca;

	for(i = NUMBERS_QUANTITY - 1; i >= 0; i--) {
		troca = 0;
		for(j = 0; j < i; j++) {
			if(VetorBiggos[j].high >= VetorBiggos[j + 1].high) {
                TrocaValorBiggos(&VetorBiggos[j], &VetorBiggos[j + 1]);
                troca = 1;
			} else if(VetorBiggos[j].high == VetorBiggos[j + 1].high && VetorBiggos[j].low > VetorBiggos[j + 1].low) {
                TrocaValorBiggos(&VetorBiggos[j], &VetorBiggos[j + 1]);
                troca = 1;
            }
		}

		if(!troca)
			break;
	}
}

void WriteData(BigInt* VetorBiggos) {
    int i;
    for(i = 0; i < NUMBERS_QUANTITY; i++)
        printf("(%d)  %d %d\n", i + 1, VetorBiggos[i].high, VetorBiggos[i].low);
    printf("\n");
}

void WriteOnFile(FILE *fw, BigInt *VetorBiggos) {
    int i;
    for(i = 0; i < NUMBERS_QUANTITY; i++)
        fprintf(fw, "%d %d\n", VetorBiggos[i].high, VetorBiggos[i].low);
}

void ReadData(FILE* fr, BigInt* VetorBiggos) {
    int i;
    for(i = 0; i < NUMBERS_QUANTITY; i++)
        fscanf(fr, "%d %d", &VetorBiggos[i].high, &VetorBiggos[i].low);
}

void TestFile(FILE *fp) {
    if(!fp) {
        printf("\n--> Erro ao alocar memória. Saindo...\n\n");
        exit(1);
    }
}

void ResetToOrigin(BigInt *Original, BigInt *VetorBiggos) {
    for(int i = 0; i < NUMBERS_QUANTITY; i++) {
        VetorBiggos[i].high = Original[i].high;
        VetorBiggos[i].low = Original[i].low;
    }
}

int pPow(int a, int b) {
    int i, res = a;

    if(!a) return 0;
    if(!b) return 1;
    for(i = 1; i < b; i++)
        res *= a;

    return res;
}

void RunShellSort(FILE* fShell, BigInt *VetorBiggos) {
    gettimeofday(&begin, NULL);
    ShellSort(VetorBiggos);
    gettimeofday(&end, NULL);

    printf("\n--> [SHELL SORT] Time Elapsed: %lf\n", (double) (end.tv_sec - begin.tv_sec + 1E-6 * (end.tv_usec - begin.tv_usec)));
    WriteOnFile(fShell, VetorBiggos);
    fclose(fShell);
}

void RunSelectionSort(FILE* fSelection, BigInt *VetorBiggos) {
    gettimeofday(&begin, NULL);
    SelectionSort(VetorBiggos);
    gettimeofday(&end, NULL);

    printf("\n--> [SELECTION SORT] Time Elapsed: %lf\n", (double) (end.tv_sec - begin.tv_sec + 1E-6 * (end.tv_usec - begin.tv_usec)));
    WriteOnFile(fSelection, VetorBiggos);
    fclose(fSelection);
}

void RunBubble(FILE* fBubble, BigInt *VetorBiggos) {
    gettimeofday(&begin, NULL);
    BubbleSort(VetorBiggos);
    gettimeofday(&end, NULL);

    printf("\n--> [BUBBLE SORT] Time Elapsed: %lf\n", (double) (end.tv_sec - begin.tv_sec + 1E-6 * (end.tv_usec - begin.tv_usec)));
    WriteOnFile(fBubble, VetorBiggos);
    fclose(fBubble);
}