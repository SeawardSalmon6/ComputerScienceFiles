#include <stdio.h>

// Protótipos
int ColocarNaBalanca(int*, int, int, int);
void PesarProdutos(int*, int);
void LerDados(int*, int);
void OrdernarVetor(int*, int);
void ZerarVetor(int*, int);
int ProcurarMenorMaior(int);
void EscreveSolucao(int*);

// Variáveis Globais
int Pesos[20] = { 0 }; // Vetor de Pesos
int M; // Quantidade de Pesos Disponíveis

int main() {
    int N; // Quantidade de Produtos

    // Leitura das quantidades de Pesos e Produtos
    scanf(" %d %d", &N, &M);

    int Produtos[N]; // Inicialização do Array de Produtos

    // Leitura e preparação dos dados
    LerDados(Produtos, N);
    OrdernarVetor(Pesos, M);

    // Início do Programa
    PesarProdutos(Produtos, N);

    return 0;
}

int ColocarNaBalanca(int *vetSolucao, int pratoEsq, int pratoDir, int troca) {
    int i;

    for(i = 0; i < M; i++) {
        // Adiciona o peso na balança
        pratoDir += Pesos[i];
        vetSolucao[i] = (!troca) ? Pesos[i] : -Pesos[i];

        // Verifica se estão em equilíbrio
        if(pratoEsq == pratoDir)
            return (1); // Encontrou uma solução

        if(pratoEsq > pratoDir) {
            if(ColocarNaBalanca(vetSolucao, pratoEsq, pratoDir, 0) == 1)
                return (1);

        } else
            if(ColocarNaBalanca(vetSolucao, pratoDir, pratoEsq, 1) == 1)
                return(1);

        pratoDir -= Pesos[i];
        vetSolucao[i] = 0;
    }

    return (0); // Caso não encontre nenhuma solução
}

void PesarProdutos(int *Produtos, int N) {
    int i;
    int vetSolucao[M];

    for(i = 0; i < N; i++) {
        // Zera o vetor para o próximo produto
        ZerarVetor(vetSolucao, M);

        // Inicia a tentativa de pesagem
        if(ColocarNaBalanca(vetSolucao, Produtos[i], 0, 0) == 1) {
            EscreveSolucao(vetSolucao);
        } else
            printf("0\n");
        
    }
}

void LerDados(int *Produtos, int N) {
    int i;
    for(i = 0; i < M; i++)
        scanf(" %d", &Pesos[i]);
    
    for(i = 0; i < N; i++)
        scanf(" %d", &Produtos[i]);
}

void OrdernarVetor(int *vet, int size) {
    int i, aux, test = 1;

    while(test == 1) {
        test = 0;

        for(i = 0; i < size - 1; i++)
            if(vet[i] < vet[i + 1]) {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                test = 1;
            }
    }
}

void ZerarVetor(int *vet, int size) {
    int i;
    for(i = 0; i < size; i++)
        vet[i] = 0;
}

int ProcurarMenorMaior(int pesoProduto) {
    int i;
    for(i = 0; i < M; i ++)
        if(Pesos[i] <= pesoProduto)
            return i;
    return 0;
}

void EscreveSolucao(int *vetSolucao) {
    for(int i = 0; i < M; i++)
        if(vetSolucao[i] > 0)
            printf("%d ", vetSolucao[i]);
    printf("\n");
}