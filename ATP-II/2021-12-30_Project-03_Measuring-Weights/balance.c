#include <stdio.h>

// Prototipos
int Balanca(int, int, int);
void ZerarVetor(int*, int);
void OrdenarVetor(int*, int);
void EscreverSolucao();

// Variaveis Globais
int Pesos[20], Solucao[20], M, K;

void LerDados(int *Produtos, int N) {
	int i;
	// Leitura vetor Pesos
	for(i = 0; i < M; i++)
		scanf(" %d", &Pesos[i]);

	// Leitura vetor Produtos
	for(i = 0; i < N; i++)
		scanf(" %d", &Produtos[i]);
}

int main() {
    int N, i;

	scanf(" %d %d", &N, &M); // le a quantidade de Produtos e Pesos, respectivamente

	int Produtos[N]; // declaracao do vetor Produtos
	LerDados(Produtos, N); // le os dados de Pesos e Produtos
	OrdenarVetor(Pesos, M); // ordena o vetor em ordem crescente

    for(i = 0; i < N; i++) { // loop para acessar cada um dos produtos
		ZerarVetor(Solucao, M); K = 0; // 'reinicia' o vetor Solucao

		if(Balanca(Produtos[i], M - 1, 1))  {// testa para buscar uma solucao
			OrdenarVetor(Solucao, K); // ordena o vetor Solucao em ordem crescente
			EscreverSolucao(); // escreve em ordem decrescente
		}
		else
	        printf("0\n"); // caso nao seja encontrada solucao, retorna 0
	}

    return 0;
}

// Zera os valores do vetor indicado
void ZerarVetor(int *arr, int size) {
	int i;
	for(i = 0; i < size; i++)
		arr[i] = 0;
}

// Ordena um vetor em ordem crescente
void OrdenarVetor(int *arr, int size) {
	int i, top, aux;
	for(top = size - 1; top >= 0; top--)
		for(i = top; i < size - 1; i++)
			if(arr[i] > arr[i + 1]) {
				aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = aux;
			}
}

// Escreve o conjunto Solucao para o produto solicitado
void EscreverSolucao() {
	int i;
	for(i = K - 1; i >= 0; i--)
		printf("%d ", Solucao[i]);
	printf("\n");
}

// retorna verdadeiro se existe solucao, caso contrario, retorna falso
int Balanca(int produto, int idx, int inverse) {
    // se for encontrado um conjunto solucao, retorna verdadeiro,
	// retornando o no solucao todo
    if(produto == 0)
        return (1);

    // se o indice for negativo ou o produto for negativo, retorna falso
    if(idx < 0 || produto < 0)
        return (0);

	// testa o problema utilizando o Pesos[M]
	if(Balanca(produto - Pesos[idx], idx - 1, inverse)) {
		Solucao[K] = Pesos[idx] * inverse; K++; // multiplica por 1 (se inverse == 1) ou -1 (quando inverse == -1)
		return (1);
	}
	else if(Balanca(produto, idx - 1, inverse))
		// caso a inserção do Pesos[M] nao possuir solucao, esse valor e omitido e testa-se o proximo
		return (1);
	else if((produto - Pesos[idx] < 0) && Balanca(Pesos[idx] - produto, idx - 1, -inverse)) {
		/* - somente inicia se o proximo valor for negativo e
		os nos principais (if's anteriores) nao encontrarem solucao */
		Solucao[K] = Pesos[idx] * inverse; K++; // multiplica por 1 (se inverse == 1) ou -1 (quando inverse == -1)
		return (1);
	}

    // retorna true se algum caminho utilizado encontrou solucao
    return (0);
}
