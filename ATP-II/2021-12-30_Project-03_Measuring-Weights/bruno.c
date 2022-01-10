#include <stdio.h>

// Protótipos
int Balanca(int, int, int);
void OrdenarVetor(int*, int);

// Variáveis Globais
int Pesos[20], M;

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
	OrdenarVetor(Pesos, M);

	for(i = 0; i < N; i++) {
		if(Balanca(Produtos[i], M - 1, 1))
			printf("\n");
		else
	        printf("0\n"); // caso não seja encontrada solução
	}

    return 0;
}

void OrdenarVetor(int *arr, int size) {
	int i, aux, lastnum;
	for (lastnum = size - 1; lastnum >= 0; lastnum--)
		for (i = 0; i < lastnum; i++)
			if ((arr[i] > arr[i + 1])) {
				aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = aux;
			}
}

// retorna verdadeiro se existe solução, caso contrário, retorna falso
int Balanca(int produto, int M, int inverse) {
    // se for encontrada um conjunto solução, retorna verdadeiro
	// retornando o nó solução todo
    if(produto == 0)
        return (1);

    // se o índice for negativo ou o produto for negativo, retorna falso
    if(M < 0 || produto < 0)
        return (0);

    // testa o problema utilizando o Pesos[M]
	if (Balanca(produto - Pesos[M], M - 1, inverse)) {
		printf("%d ", Pesos[M] * inverse); // multiplica pela inversão de valores
		return 1;
	}
	else if (Balanca(produto, M - 1, inverse))
		return 1;
	else if ((produto - Pesos[M] < 0) && Balanca(Pesos[M] - produto, M - 1, -inverse)) {
		printf("%d ", Pesos[M] * inverse); // multiplica pela inversão de valores
		return 1;
	}

	return 0;
}
