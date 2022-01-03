#include <stdio.h>

/* Protótipos */
void LerDados(int*, int, int*, int);
void OrdenarVetor(int*, int);
void ZerarVetor(int*, int);
void Pesagem(int*, int, int*, int);
int PesquisaMenorValor(int*, int, int, int);
void printSolucao(int*, int);

void PesarBalanca(int *PesosRestantes, const int M, const int init, int prEsq, int prDir, int *vetSolucao, int k, int i, int troca) {
	int pos = -1;

	if(prEsq == prDir) {
		printSolucao(vetSolucao, M);
		return;
	}

	if(troca >= 2 || i > M) {
		printf("0\n");
		return;
	}

	pos = PesquisaMenorValor(PesosRestantes, M, prEsq - prDir, i);

	prDir += PesosRestantes[i];
	vetSolucao[k] = (troca) ? -PesosRestantes[i] : PesosRestantes[i];

	if(prEsq >= prDir) {
		k++;
		PesarBalanca(PesosRestantes, M, init, prEsq, prDir, vetSolucao, k, i + 1, troca);
	} else if(prEsq <= prDir && troca == 1 && i == M) {
		ZerarVetor(vetSolucao, M);
		pos = PesquisaMenorValor(PesosRestantes, M, init, 0) + 1;

		PesarBalanca(PesosRestantes, M, init, init, 0, vetSolucao, 0, pos, ++troca);
	} else {
		if(pos >= 0) {
			vetSolucao[k] = 0;
			prDir -= PesosRestantes[i];
			PesarBalanca(PesosRestantes, M, init, prEsq, prDir, vetSolucao, k, pos, troca);
		} else if(i == M)
			printf("0\n");
		else {
			k++;
			PesarBalanca(PesosRestantes, M, init, prDir, prEsq, vetSolucao, k, i + 1, ++troca);
		}
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
	Pesagem(Produtos, N, Pesos, M);

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

void Pesagem(int *Produtos, int N, int *Pesos, int M) {
	int i, j, start;
	int vetSolucao[M];

	OrdenarVetor(Pesos, M);

	for(i = 0; i < N; i++) {
		ZerarVetor(vetSolucao, M);

		start = PesquisaMenorValor(Pesos, M, Produtos[i], 0);
		if(start == -1)
			printf("0\n");
		else
			PesarBalanca(Pesos, M, Produtos[i], Produtos[i], 0, vetSolucao, 0, start, 0);
	}
}

int PesquisaMenorValor(int *Pesos, int M, int val, int s) {
	for(int i = s; i < M; i++)
		if(val / Pesos[i] == 1)
			return i;
	return -1;
}

void printSolucao(int *vetSolucao, int M) {
	for(int p = 0; p < M; p++)
		if(vetSolucao[p] != 0)
			printf("%d ", vetSolucao[p]);
	printf("\n");
}
