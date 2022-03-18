// ============= Bibliotecas Utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// ============= Variáveis Globais
struct timeval end, begin;
const int NUMBERS_QUANTITY = 200000;

// ============= Estrutura do Tipo de Dado BigInt
typedef struct Biggo {
    int high;
    int low;
} BigInt;

// ============= Métodos de Ordenação */
void RunShellSort(BigInt*);
void RunSelectionSort(BigInt*);
void ShellSort(BigInt*);
void SelectionSort(BigInt*);

/* ============== Funções Auxiliares do Programa */
void TestFile(FILE*);
void ReadData(FILE*, BigInt*, BigInt*);
void EscreverNoArquivo(FILE*, BigInt*);
int pPow(int, int);

// ============= Início do Programa
int main() {
	// --> Declara as variáveis dos vetores utilizados e do arquivo de leitura
    FILE *fr = fopen("bigint.dat", "r"); TestFile(fr);
    BigInt Original[NUMBERS_QUANTITY], VetorBiggos[NUMBERS_QUANTITY];

	// --> Realiza a leitura dos dados do arquivo de leitura e popula os vetores
    ReadData(fr, Original, VetorBiggos); fclose(fr); // --> Fecha o arquivo

	// --> Funções que iniciam os processos de timer e ordenação
    RunShellSort(Original);
    RunSelectionSort(VetorBiggos);

    printf("\n");

    return 0;
}

// ============= Método Shell Sort
void ShellSort(BigInt *VetorBiggos) {
    int i, j, p, l; // --> Variáveis auxiliares da função
	BigInt paraInserir;

	// --> Vetor com os passos, de acordo com a sequência de Sedgewick;
	// Como a quantidade de elementos é sempre a mesma, os passos estão
	// restritos até um dado passo
    int k[10] = { 1, 8, 23, 77, 281, 1073, 4193, 16577, 65921, 262913 };

    /* ======== Passos de acordo com a Sequência de Sedgewick
		--> O cáculo dos passos pode ser implementado da seguinte forma:

		p = 1; // --> Com a primeira posição de k[] já com o valor 1 (passo inicial)
		while(k[p - 1] < NUMBERS_QUANTITY / 2) { // --> Calcula os passos
			k[p] = pow(4, p) + 3 * pow(2, p - 1) + 1;
			p++;
		} p--; // --> Diminuição do índice maior que a quantidade de item
	*/

	p = 9; // --> Começa pelo maior passo
    while(p != 1) { // --> Loop que trabalha com os passos enquanto este for != de 1
        p--; // --> Acertando o valor do passo para iteração atual
        for(l = 0; l < k[p]; l++) { // --> Laço para executar o Insertion k[p] vezes
            for(i = l + k[p]; i < NUMBERS_QUANTITY; i += k[p]) { // --> Algoritmo insertion ajustado para n posições
                paraInserir = VetorBiggos[i]; // --> Atribuir a valor da posição a ser testado
                j = i; // --> Marca o valor inicial de j para esta iteração

				// --> Realiza as comparações já fazendo as devidas inserções
				// --> Executa enquanto a posição testada possui high >= a posição testada
                while(j - k[p] >= 0 && VetorBiggos[j - k[p]].high >= paraInserir.high) {

					// --> Se alguma dessas proposições sejam verdadeiras, realiza a devida inserção
					if((VetorBiggos[j - k[p]].high > paraInserir.high)
                    || (VetorBiggos[j - k[p]].high >= 0 && VetorBiggos[j - k[p]].low > paraInserir.low)
                    || (VetorBiggos[j - k[p]].high < 0 && VetorBiggos[j - k[p]].low < paraInserir.low))
					{
						VetorBiggos[j] = VetorBiggos[j - k[p]];
                        j = j - k[p]; // --> Atualiza o índice para o próximo loop
					} else // --> Caso nenhum dos testes valha, sai do loop
                        break;
                }

                if(j != i) // --> Se houveram trocas, insere o valor testado na posição correta
					VetorBiggos[j] = paraInserir;
            }
        }
    }
}

// ============= Metódo Selection Sort
void SelectionSort(BigInt *VetorBiggos) {
	int i, j, nChave; // --> Variáveis auxiliares da função
	BigInt aux;

	// --> Loop exterior
	for(i = 0; i < NUMBERS_QUANTITY - 1; i++) {
		nChave = i; // --> Indica a primeira posição não ordenada
		for(j = i + 1; j < NUMBERS_QUANTITY; j++) { // --> Realiza os testes a partir da posição
			if(VetorBiggos[nChave].high >= VetorBiggos[j].high) { // --> Testa as possibilidades
				if((VetorBiggos[nChave].high > VetorBiggos[j].high)
				|| (VetorBiggos[nChave].high >= 0 && VetorBiggos[nChave].low > VetorBiggos[j].low)
				|| (VetorBiggos[nChave].high < 0 && VetorBiggos[nChave].low < VetorBiggos[j].low))
				{
					nChave = j; // --> Se alguma delas for verdadeira, anota a posição do menor valor atual
				}
			}
		}

		if(nChave != i) { // --> Se encontrou alguma posição de troca, realiza a troca de posição
			aux = VetorBiggos[nChave];
			VetorBiggos[nChave] = VetorBiggos[i];
			VetorBiggos[i] = aux;
		}
	}
}

// --> Escreve os resultados no arquivo especificado
void EscreverNoArquivo(FILE *fw, BigInt *VetorBiggos) {
    int i;
    for(i = 0; i < NUMBERS_QUANTITY; i++)
        fprintf(fw, "%d %d\n", VetorBiggos[i].high, VetorBiggos[i].low);
}

// --> Realiza a leitura dos dados, do arquivo especificado
void ReadData(FILE* fr, BigInt* VetorBiggos, BigInt* Copy) {
    int i;
    for(i = 0; i < NUMBERS_QUANTITY; i++) // --> Lê os dados e armazena
        fscanf(fr, "%d %d", &VetorBiggos[i].high, &VetorBiggos[i].low);

	// --> Realiza a cópia dos dados em um outro vetor (passado para o Selection)
	for(i = 0; i < NUMBERS_QUANTITY; i++)
		Copy[i] = VetorBiggos[i];
}

// --> Testa se o arquivo especificado foi devidamente aberto por fopen()
void TestFile(FILE *fp) {
    if(!fp) {
        printf("\n--> Erro ao alocar memória. Saindo...\n\n");
        exit(1);
    }
}

// --> Função auxiliar que agrupa as operações a serem realizadas pelo Shell Sort
void RunShellSort(BigInt *VetorBiggos) {
    FILE *fShell = fopen("shell.dat", "w"); TestFile(fShell); // --> Abre e testa o arquivo

    gettimeofday(&begin, NULL); // --> Marca o início da execução
    ShellSort(VetorBiggos); // --> Realiza a ordenação
    gettimeofday(&end, NULL); // --> Marca o fim da execução

	// --> Realiza o print do tempo corrido
    printf("\n--> [SHELL SORT] Time Elapsed: %lf\n", (double) (end.tv_sec - begin.tv_sec + 1E-6 * (end.tv_usec - begin.tv_usec)));
    EscreverNoArquivo(fShell, VetorBiggos); // --> Escreve o vetor ordenado no arquivo
    fclose(fShell); // --> Fecha o arquivo e salva
}

// --> Função auxiliar que agrupa as operações a serem realizadas pelo Selection Sort
void RunSelectionSort(BigInt *VetorBiggos) {
    gettimeofday(&begin, NULL); // --> Marca o início da execução
    SelectionSort(VetorBiggos); // --> Realiza a ordenação
    gettimeofday(&end, NULL); // --> Marca o fim da execução

	// --> Realiza o print do tempo corrido
    printf("\n--> [SELECTION SORT] Time Elapsed: %lf\n", (double) (end.tv_sec - begin.tv_sec + 1E-6 * (end.tv_usec - begin.tv_usec)));
}