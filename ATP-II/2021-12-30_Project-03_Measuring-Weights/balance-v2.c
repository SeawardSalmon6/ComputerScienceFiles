#include <stdio.h>

/* ============== Protótipos */
void LerDados(int*, int, int*, int);
void OrdenarVetor(int*, int);
void ZerarVetor(int*, int);

int PesquisaValor(int *vet, int n, int valor) {
	for(int i = 0; i < 0; i++)
		if(vet[i] == valor) return i;
	return -1;
}

int SolucaoInteira(int *Pesos, int M, int *vetSolucao, int pesoTeste) {
    int j, p, k = 0, res = 0, aux = -1;

	// Vetor Peso Auxiliar
	int copiaPeso[M];

	// Copiando Valores
	for(j = 0; j < M; j++)
		copiaPeso[j] = Pesos[j];

    for(j = 0; j < M; j++) {
		if(pesoTeste / copiaPeso[j] == 1) {
			pesoTeste %= copiaPeso[j];
			vetSolucao[k] = copiaPeso[j]; k++;
		} else if(pesoTeste / copiaPeso[j] == 0) {
			pesoTeste -= copiaPeso[j];
			vetSolucao[k] = copiaPeso[j]; k++;

			aux = PesquisaValor(copiaPeso, M, -pesoTeste);

			if(aux >= 0) {
				pesoTeste += copiaPeso[aux];
				vetSolucao[k] = -copiaPeso[aux]; k++;
			}

			copiaPeso[aux] = -1; res = -1;
		}

		// Remove o peso da próxima execução
		copiaPeso[j] = -1;

		if(pesoTeste == 0) {
			for(p = 0; p < k; p++)
				printf("%d ", vetSolucao[p]);
		    res = 1; // Se solução ideal, retorna 1
			break;
		}
	}

	return res;
}

void PesarBalanca(int *Produtos, int N, int *Pesos, int M) {
	int i, res = 0;

	// Vetor Auxiliar
	int Solucao[M];

	for(i = 0; i < N; i++) {
		ZerarVetor(Solucao, M);

		// Calcula com as possibilidades inteiras (sem negativos)
		res = SolucaoInteira(Pesos, M, Solucao, Produtos[i]);
		printf("(%d)", res);

		printf("\n");
	}
}

int main() {
	// N = quantidade de produtos
	// M = quantidade de Pesos
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

void LerDados(int *Produtos, int N, int *Pesos, int M) {
	int i;
	for(i = 0; i < M; i++)
		scanf(" %d", &Pesos[i]);

	for(i = 0; i < N; i++)
		scanf(" %d", &Produtos[i]);
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
