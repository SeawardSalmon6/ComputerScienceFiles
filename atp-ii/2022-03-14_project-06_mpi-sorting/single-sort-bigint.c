#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval end, begin;
int NUMBERS_QUANTITY;

/* ============== Métodos de Ordenação */
void RunShellSort(int*);
void ShellSort(int*);

/* ============== Funções Auxiliares do Programa */
void TestFile(FILE*);
void ReadData(FILE*, int*);
void WriteOnFile(FILE*, int*);
int pPow(int, int);

int main() {
    FILE *fr = fopen("vetor.dat", "r"); TestFile(fr);
    int *VetorBiggos;

	printf("\n--> Insira a quantidade de elementos a serem ordenados: ");
	scanf(" %d", &NUMBERS_QUANTITY);

	VetorBiggos = (int*) malloc(sizeof(int) * NUMBERS_QUANTITY);

    ReadData(fr, VetorBiggos); fclose(fr);
    RunShellSort(VetorBiggos);

    printf("\n");
	free(VetorBiggos);

    return 0;
}

void RunShellSort(int *VetorBiggos) {
    FILE *fShell = fopen("shell.dat", "w"); TestFile(fShell);
	double tempoExecucao;

    gettimeofday(&begin, NULL);
    ShellSort(VetorBiggos);
    gettimeofday(&end, NULL);

	tempoExecucao = (double) (end.tv_sec - begin.tv_sec + 1E-6 * (end.tv_usec - begin.tv_usec));

    printf("\n--> [SHELL SORT] Time Elapsed: %lf\n", tempoExecucao);
    WriteOnFile(fShell, VetorBiggos);
    fclose(fShell);
}

void ShellSort(int *VetorBiggos) {
    int i, j, p, l, paraInserir;
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
                paraInserir = VetorBiggos[i]; // --> atribuir a valor o valor da posição
                j = i;

                while(j - k[p] >= 0 && VetorBiggos[j - k[p]] > paraInserir) {
					VetorBiggos[j] = VetorBiggos[j - k[p]];
					j = j - k[p];
                }

                if(j != i)
					VetorBiggos[j] = paraInserir;
            }
        }
    }
}

void WriteOnFile(FILE *fw, int *VetorBiggos) {
    int i;
    for(i = 0; i < NUMBERS_QUANTITY; i++)
        fprintf(fw, "%d ", VetorBiggos[i]);
}

void ReadData(FILE* fr, int* VetorBiggos) {
    int i;
    for(i = 0; i < NUMBERS_QUANTITY; i++)
        fscanf(fr, "%d ", &VetorBiggos[i]);
}

void TestFile(FILE *fp) {
    if(!fp) {
        printf("\n--> Erro ao alocar memória. Saindo...\n\n");
        exit(1);
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
