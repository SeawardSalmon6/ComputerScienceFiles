/* 2) Escreva um programa em C que insere 25 inteiros aleatórios de 1 a 10000 em ordem em uma lista encadeada.
O programa deve calcular a soma dos elementos, a média dos elementos, o maior e o menor elemento, e mostrar
a lista construída. Se esses números inseridos forem pesquisados em uma lista simplesmente encadeada e em
uma lista duplamente encadeada, o resultado será o mesmo? Justifique. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ====== Valor constante com a quantidade de números */
const int QTD_NUMEROS = 25;

/* ======= Struct da Lista */
typedef struct Lista {
	int num;
	int prox;
} stLista;

/* ======= Protótipos das Funções */
void InsereOrdenada(stLista[QTD_NUMEROS], int*, int);
void CriarListaEncadeada(stLista[QTD_NUMEROS], int*);
void PrintDadosLista(stLista[QTD_NUMEROS], int*);
int GerarNumero();

/* ======= Função Main */
int main() {
	/* ---> Seed para o Rand(); aleatória */
	srand(time(NULL));

	int cabeca = 0; /* ---> Primeira Posição da lista */
	stLista minhaLista[QTD_NUMEROS]; /* ---> Lista Estática */

	/* ---> Criar e Apresentar a Lista */
	CriarListaEncadeada(minhaLista, &cabeca);
	PrintDadosLista(minhaLista, &cabeca);

	return 0;
}

/* ========== Insere um novo número, na posição correta do vetor */
void InsereOrdenada(stLista numLista[QTD_NUMEROS], int *cabeca, int pos) {
	int i, chave, antes;

	i = *cabeca; // ---> Posição inicial
	chave = numLista[pos].num; // ---> Valor de teste
	while(i >= 0 && chave > numLista[i].num) { // ---> Loop para encontrar a posição correta
		antes = i;
		i = numLista[i].prox;
	}

	if(i == *cabeca) { // ---> Insere no início da lista
		numLista[pos].prox = i;
		*cabeca = pos;
	} else { // ---> Insere nas outras posições da lista
		numLista[pos].prox = i;
		numLista[antes].prox = pos;
	}
}

/* ======== Gera um número aleatório no intervalo 0 - 10000 */
int GerarNumero() {
	return (rand() % 10000 + 1);
}

/* ======== Função de Controle para a criação da lista */
void CriarListaEncadeada(stLista numLista[QTD_NUMEROS], int *cabeca) {
	int i = 0;

	/* --> Insere valores iniciais na primeira posição */
	numLista[0].num = GerarNumero();
	numLista[0].prox = -1;

	/* --> Insere novo número ordenado */
	for(i = 1; i < QTD_NUMEROS; i++) {
		numLista[i].num = GerarNumero();
		InsereOrdenada(numLista, cabeca, i);
	}
}

/* ======= Apresenta a lista ordenada */
void PrintDadosLista(stLista numLista[QTD_NUMEROS], int *cabeca) {
	int i = *cabeca, k = 0;
	int somaTotal = 0, maiorElem = 0;
	float mediaGeral = 0;

	printf("\n======> Lista Completa\n");
	while(i >= 0) {
		printf("\n%d:  [%d]", ++k, numLista[i].num);

		somaTotal += numLista[i].num;

		if(numLista[i].num > maiorElem)
			maiorElem = numLista[i].num;

		i = numLista[i].prox;
	}

	mediaGeral = (float) somaTotal / QTD_NUMEROS;

	printf("\n\n======> Informações da Lista Gerada\n");
	printf("\n --> Soma dos Elementos:  %d\n", somaTotal);
	printf("\n --> Média dos Elementos:  %.2f\n", mediaGeral);
	printf("\n --> Menor Elemento:  %d\n", numLista[*cabeca].num);
	printf("\n --> Maior Elemento:  %d\n", maiorElem);

	printf("\n");
}

/* Comentário da Questão:
	--> Como a lista simples já está ordenada, a utilização de lista encadeada, não afetaria a busca por informações, como soma, média, maior e menor elemento. A diferença entre as duas listas somente se daria (neste caso) na inserção de novos números, pois haveria necessidade de indicar a posição do vetor (número) que antecede o elemento de análise. Porém, como na lista encadeada dupla, podemos seguir pelo vetor em ambas as direções, o processo de busca de informações será mais eficiente, pois podemos iniciar a pesquisar de qualquer ponto do vetor.
*/