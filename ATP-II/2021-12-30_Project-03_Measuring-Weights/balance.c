#include <stdio.h>

/* Validações
	- Se algum dos produtos tiverem peso INFERIOR ao menor peso, retorna 0
	- Se algum dos produtos tiverem peso SUPERIOR a soma dos pesos, retorna 0
*/

void LerDados(int *prod, int nprod, int *pesos, int npesos) {
	int i;
	for(i = 0; i < npesos; i++)
		scanf(" %d", &pesos[i]);

	for(i = 0; i < nprod; i++)
		scanf(" %d", &prod[i]);
}

void OrdenarVetor(int *vet, int n) {
	int i = 0, test = 1, aux;

	while(test) {
		test = 0;

		for(i = 0; i < n - 1; i++)
			if(vet[i + 1] > vet[i]) {
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
				test = 1;
			}
	}
}

void ZerarVetor(int *vet, int n) {
	for(int i = 0; i < n; i++)
		vet[i] = 0;
}

void PesarBalanca(int *prod, int nprod, int *pesos, int npesos) {
	int i, j, k, p, auxProd;

	// Vetor Auxiliar
	int Solucao[npesos];

	for(i = 0; i < nprod; i++) {
		ZerarVetor(Solucao, npesos); k = 0;
		auxProd = prod[i];

		for(j = 0; j < npesos; j++) {
			if(auxProd / pesos[j] == 1) {
				auxProd %= pesos[j];
				Solucao[k] = pesos[j]; k++;
			}

			if(auxProd == 0) {
				for(p = 0; p < k; p++)
					printf("%d ", Solucao[p]);
			    break;
			} else if(j == npesos - 1)
			    printf("0");
		}
		printf("\n");
	}
}

int main() {
	// N = quantidade de produtos
	// M = quantidade de pesos
	int N, M, i;

	scanf(" %d %d", &N, &M);

	// Declaração dos vetores de Pesos e Produtos
	int Produtos[N], Pesos[M];
	LerDados(Produtos, N, Pesos, M);

	// Início do programa
	OrdenarVetor(Pesos, M);
	PesarBalanca(Produtos, N, Pesos, M);

	return 0;
}
