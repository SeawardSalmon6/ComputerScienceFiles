#include <stdio.h>

// Protótipos
int Balanca(int, int, int);
void ZerarVetor(int*, int);
void EscreverSolucao();

// Variáveis Globais
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

	scanf(" %d %d", &N, &M); // lê a quantidade de Produtos e Pesos, respectivamente

	int Produtos[N];
	LerDados(Produtos, N); // Lê os dados de Pesos e Produtos

    for(i = 0; i < N; i++) {
		ZerarVetor(Solucao, M); K = 0; // 'reinicia' o vetor Solucao

		if(Balanca(Produtos[i], M - 1, 1))
			EscreverSolucao();
		else
	        printf("0\n"); // caso não seja encontrada solução
	}

    return 0;
}

// Zera os valores do vetor indicado
void ZerarVetor(int *arr, int size) {
	int i;
	for(i = 0; i < size; i++)
		arr[i] = 0;
}

// Escreve o conjunto Solução para o produto solicitado
void EscreverSolucao() {
	int i;
	for(i = M - 1; i >= 0; i--)
		if(Solucao[i] != 0)
			printf("%d ", Solucao[i]);
	printf("\n");
}

// retorna verdadeiro se existe solução, caso contrário, retorna falso
int Balanca(int produto, int idx, int inverse) {
    // se for encontrada um conjunto solução, retorna verdadeiro
	// retornando o nó solução todo
    if(produto == 0)
        return (1);

    // se o índice for negativo ou o produto for negativo, retorna falso
    if(idx < 0 || produto < 0)
        return (0);

	// testa o problema utilizando o Pesos[M]
	if(Balanca(produto - Pesos[idx], idx - 1, inverse)) {
		Solucao[K] = Pesos[idx] * inverse; K++; // multiplica pela inversão de valores
		return (1);
	}
	else if(Balanca(produto, idx - 1, inverse))
		// caso a inserção do Pesos[M] não possuir solução, esse valor é omitido e testa-se o próximo
		return (1);
	else if((produto - Pesos[idx] < 0) && Balanca(Pesos[idx] - produto, idx - 1, -inverse)) {
		/* - somente inicia se o próximo valor for negativo e
		os nós principais (include e exclude) não encontrarem solução */
		Solucao[K] = Pesos[idx] * inverse; K++; // multiplica pela inversão de valores
		return (1);
	}

    // retorna true se algum caminho utilizado encontrou solução
    return (0);
}
