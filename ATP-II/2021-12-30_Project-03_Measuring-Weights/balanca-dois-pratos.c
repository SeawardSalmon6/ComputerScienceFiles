#include <stdio.h>

// Protótipos
int Balanca(int, int, int);
void OrdenarVetor(int*, int);
void ZerarVetor(int*, int);
void EscreverSolucao();

// Variáveis Globais
int Pesos[20], Solucao[20], M;

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
		ZerarVetor(Solucao, M); // 'reinicia' o vetor Solucao

		if(Balanca(Produtos[i], M - 1, 1)) {
			OrdenarVetor(Solucao, M); // ordena o vetor em ordem decrescente antes de escrever
			EscreverSolucao();
		} else
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
	for(i = 0; i < M; i++)
		if(Solucao[i] != 0)
			printf("%d ", Solucao[i]);
	printf("\n");
}

// Algoritmo de Ordenação (bubble-sort (2 a 2))
// za identifica se o vetor será ordenado em ordem crescente ou descrecente
void OrdenarVetor(int *arr, int size) {
	int i, aux, lastnum;
	for(lastnum = size - 1; lastnum >= 0; lastnum--)
		for(i = 0; i < lastnum; i++)
			if(arr[i] < arr[i + 1]) {
				aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = aux;
			}
}

// retorna verdadeiro se existe solução, caso contrário, retorna falso
int Balanca(int produto, int M, int inverse) {
    int men_include = 0; // valor padrão do nó extra

    // se for encontrada um conjunto solução, retorna verdadeiro
	// retornando o nó solução todo
    if(produto == 0)
        return (1);

    // se o índice for negativo ou o produto for negativo, retorna falso
    if(M < 0 || produto < 0)
        return (0);

    // testa o problema utilizando o Pesos[M]
    int include = Balanca(produto - Pesos[M], M - 1, inverse);

    // caso a inserção do Pesos[M] não possuir solução, esse valor é omitido e testa-se o próximo
    int exclude = Balanca(produto, M - 1, inverse);

	/* se o men_include for iniciado, os pesos se invertem
	 - somente inicia se o próximo valor for negativo e
	os nós principais (include e exclude)não encontrarem solução */
	if(!include && !exclude && (produto - Pesos[M] < 0))
		men_include = Balanca(Pesos[M] - produto, M - 1, -inverse);

	if(include || men_include) // caso sejam encontrados valores solução
        Solucao[M] = Pesos[M] * inverse; // multiplica pela inversão de valores

	/* caso seja encontrada solução, valores paralelos
	ao nó principal não serão contabilizados */
	if(exclude)
		Solucao[M] = 0;

    // retorna true se algum caminho utilizado encontrou solução
    return include || exclude || men_include;
}
