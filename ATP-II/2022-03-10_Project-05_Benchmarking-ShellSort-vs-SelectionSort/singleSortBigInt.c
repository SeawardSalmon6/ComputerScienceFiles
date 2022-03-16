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
void RunShellSort(BigInt*);
void ShellSort(BigInt*);

/* ============== Funções Auxiliares do Programa */
void TestFile(FILE*);
void ReadData(FILE*, BigInt*);
void WriteOnFile(FILE*, BigInt*);
int pPow(int, int);

int main() {
    FILE *fr = fopen("bigint.dat", "r"); TestFile(fr);
    BigInt VetorBiggos[NUMBERS_QUANTITY];

    ReadData(fr, VetorBiggos); fclose(fr);
    RunShellSort(VetorBiggos);

    printf("\n");

    return 0;
}

void RunShellSort(BigInt *VetorBiggos) {
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

void ShellSort(BigInt *VetorBiggos) {
    int i, j, p, l;
    int k[10] = { 1, 0 };
	BigInt paraInserir;

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

                while(j - k[p] >= 0 && VetorBiggos[j - k[p]].high >= paraInserir.high) {
					if((VetorBiggos[j - k[p]].high > paraInserir.high)
                    || (VetorBiggos[j - k[p]].high >= 0 && VetorBiggos[j - k[p]].low > paraInserir.low)
                    || (VetorBiggos[j - k[p]].high < 0 && VetorBiggos[j - k[p]].low < paraInserir.low))
					{
						VetorBiggos[j] = VetorBiggos[j - k[p]];
                        j = j - k[p];
					} else
                        break;
                }

                if(j != i)
					VetorBiggos[j] = paraInserir;
            }
        }
    }
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

int pPow(int a, int b) {
    int i, res = a;

    if(!a) return 0;
    if(!b) return 1;
    for(i = 1; i < b; i++)
        res *= a;

    return res;
}
