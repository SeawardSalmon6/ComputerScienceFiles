#include <stdio.h>

// Protótipos
void OrdenarVetor(int*, int, int);
void EscreverSolucao(int*, int);
void ZerarVetor(int*, int);
int subsetSum(int*, int, int, int, int*);

void LerDados(int *Pesos, int M, int *Produtos, int N) {
	int i;
	for(i = 0; i < M; i++)
		scanf(" %d", &Pesos[i]);
		
	for(i = 0; i < N; i++)
		scanf(" %d", &Produtos[i]);
}
 
// Subset Sum Problem
int main() {
    int M, produto, N, i;
	
	scanf(" %d %d", &N, &M);
	
	int Pesos[M], Solucao[M], Produtos[N];
	LerDados(Pesos, M, Produtos, N);
	OrdenarVetor(Pesos, M, 0);
 
    for(i = 0; i < N; i++) {
		ZerarVetor(Solucao, M);

		if(subsetSum(Pesos, M - 1, 1, Produtos[i], Solucao)) {
			OrdenarVetor(Solucao, M, 1);
			EscreverSolucao(Solucao, M);
		}
	    else
	        printf("0\n");
	}

    return 0;
}

void ZerarVetor(int *arr, int size) {
	int i;
	for(i = 0; i < size; i++)
		arr[i] = 0;
}

void EscreverSolucao(int *arr, int size) {
	int i;
	for(i = 0; i < size; i++)
		if(arr[i] != 0)
			printf("%d ", arr[i]);
	printf("\n");
}

void OrdenarVetor(int *arr, int size, int az) {
	int i, aux, test = 1;
	while(test == 1) {
		test = 0;

		for(i = 0; i < size - 1; i++)
			if((!az) ? (arr[i] > arr[i + 1]) : (arr[i] < arr[i + 1])) {
				aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = aux;
				test = 1;
			}
	}
}

// Returns true if there exists a subsequence of `A[0…n]` with the given sum
int subsetSum(int *Pesos, int M, int init, int produto, int *Solucao) {
    int men_include = 0;
    
    // return true if the sum becomes 0 (subset found)
    if(produto == 0)
        return (1);
 
    // base case: no items left, or sum becomes negative
    if(M < 0 || produto < 0)
        return (0);
        
    // Case 1. Include the current item `A[M]` in the subset and recur
    // for the remaining items `M-1` with the remaining total `produto - A[M]`
    int include = subsetSum(Pesos, M - 1, init, produto - Pesos[M], Solucao);
    
    // Case 2. Exclude the current item `A[M]` from the subset and recur for
    // the remaining items `M-1`
    int exclude = subsetSum(Pesos, M - 1, init, produto, Solucao);

	if(!include && !exclude && (produto - Pesos[M] < 0))
		men_include = subsetSum(Pesos, M - 1, -init, -produto + Pesos[M], Solucao);

    if(include)
        Solucao[M] = Pesos[M] * init;
	
	if(men_include)
		Solucao[M] = Pesos[M] * init;
	
	if(exclude)
		Solucao[M] = 0;
        
    // return true if we can get subset by including or excluding the
    // current item
    return include || men_include || exclude;
}