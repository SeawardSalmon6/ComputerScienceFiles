#include <stdio.h>
#include <stdlib.h>

/* ======== Structs */
typedef struct Pessoa {
    int idade;
    int instante;
    int tempo;
} tPessoa;

typedef struct Fila {
	int idade;
	int posicao;
} tFila;


/* ======== Variáveis Globais */
int qtdPessoas;


/* ======== Protótipos de Funções */
// --> Função Principal
void AbrirMercadao(tPessoa*, int);
void LerPessoas(tPessoa*); // -> Função de Leitura

// --> Tratamento da Fila Saída de Dados
int OrdenarInstantes(const void*, const void*);
void EscreverFila(tFila*, int);
void InserirNaFila(tPessoa*, tFila*, int*, int, int*);

// --> Funções do Caixa
int TemCaixaLivre(int*, int, int *, int );
int OcuparCaixa(int*, tPessoa*, tFila*, int*, int, int*);


/* ======== Funções e Conteúdo Principal */
int main() {
    int i, qtdCaixas;

    /* Leitura da Quantidade de Pessoas e Caixas */
    scanf(" %d %d", &qtdPessoas, &qtdCaixas);

    tPessoa ListaPessoas[qtdPessoas];

    LerPessoas(ListaPessoas);
    AbrirMercadao(ListaPessoas, qtdCaixas);

    return 0;
}


// --> Função Principal
void AbrirMercadao(tPessoa *ListaPessoas, int qtdCaixas) {
    int i, daVezNaoEstaNaFila;
	int idxFila = 0, posCabeca = 0, posCaixa = 0, j = 0;

	/* --> Configurar Fila */
	tFila Fila[qtdPessoas];
    for(i = 0; i < qtdPessoas; i++)
        Fila[i].idade = Fila[i].posicao = -1;

    /* --> Configurar vetor de caixas */
	int Caixas[qtdCaixas];
    for(i = 0; i < qtdCaixas; i++)
        Caixas[i] = 0;

    for(i = 0; i < qtdPessoas; i++) {
        if(TemCaixaLivre(Caixas, ListaPessoas[i].instante, &posCaixa, qtdCaixas)) {
            daVezNaoEstaNaFila = OcuparCaixa(&Caixas[posCaixa], ListaPessoas, Fila, &posCabeca, i, &idxFila);

			if(daVezNaoEstaNaFila)
                InserirNaFila(ListaPessoas, Fila, &posCabeca, i, &idxFila);

            while(idxFila > 0 && TemCaixaLivre(Caixas, ListaPessoas[i].instante, &posCaixa, qtdCaixas))
                daVezNaoEstaNaFila = OcuparCaixa(&Caixas[posCaixa], ListaPessoas, Fila, &posCabeca, i, &idxFila);
        } else
            InserirNaFila(ListaPessoas, Fila, &posCabeca, i, &idxFila);

        if(!(ListaPessoas[i].instante == ListaPessoas[i + 1].instante))
            EscreverFila(Fila, idxFila);
    }
}

// --> Função de Leitura
void LerPessoas(tPessoa *vet) {
    int i;
    for(i = 0; i < qtdPessoas; i++)
        scanf(" %d %d %d", &vet[i].idade, &vet[i].instante, &vet[i].tempo);

    /* Ordenar Vetor em função dos instantes de chegada */
    qsort(vet, qtdPessoas, sizeof(tPessoa), OrdenarInstantes);
}

int OrdenarInstantes(const void *a, const void *b) {
    tPessoa varA = *(tPessoa*)a, varB = *(tPessoa*)b;
    if(varA.instante < varB.instante) return -1;
    else if(varA.instante == varB.instante) {
        if(varA.idade > 64 || varB.idade > 64)
            return varB.idade - varA.idade;
        return 0;
    }
    else return 1;
}


// --> Tratamento da Fila Saída de Dados
void EscreverFila(tFila *Fila, int idxFila) {
    int i;
    if(Fila[0].idade > 0) {
        for(i = 0; i < idxFila; i++)
            printf("%d ", Fila[i].idade);
    } else
        printf("NULL");
    printf("\n");
}

void InserirNaFila(tPessoa *ListaPessoas, tFila *Fila, int *posCabeca, int idxPessoa, int *idxFila) {
    int i = 0, j;

	if(!*idxFila)
		*posCabeca = idxPessoa;

    if(ListaPessoas[idxPessoa].idade > 64) {
        while(Fila[i].idade > ListaPessoas[idxPessoa].idade)
            i++;

		if(!i) *posCabeca = idxPessoa;
        for(j = *idxFila; j > i; j--) {
            Fila[j].idade = Fila[j - 1].idade;
			Fila[j].posicao = Fila[j - 1].posicao;
		}

        Fila[i].idade = ListaPessoas[idxPessoa].idade;
        Fila[i].posicao = idxPessoa;
    } else {
        Fila[*idxFila].idade = ListaPessoas[idxPessoa].idade;
        Fila[*idxFila].posicao = idxPessoa;
	}

    *idxFila = *idxFila + 1;
}


// --> Funções do Caixa
int TemCaixaLivre(int *vetCaixas, int t, int *posCaixa, int qtdCaixas) {
    int i;
    for(i = 0; i < qtdCaixas; i++)
        if(t >= vetCaixas[i]) {
            *posCaixa = i;
            return 1;
        }

    return 0;
}

int OcuparCaixa(int *caixaLivre, tPessoa *ListaPessoas, tFila *Fila, int *posCabeca, int idxPessoa, int *idxFila) {
    int i, res = 0;

    /* --> Remove e reposiciona valores da fila */
    if(*idxFila > 0) {
        idxPessoa = *posCabeca;

        for(i = 0; i < *idxFila - 1; i++) {
            Fila[i].idade = Fila[i + 1].idade;
            Fila[i].posicao = Fila[i + 1].posicao;
		}

		*posCabeca = Fila[0].posicao;
        Fila[i].idade = -1; *idxFila = *idxFila - 1;
        res = 1;
    }

    /* --> Ocupa o caixa */
    if(*caixaLivre) *caixaLivre += ListaPessoas[idxPessoa].tempo;
    else
        *caixaLivre = ListaPessoas[idxPessoa].instante + ListaPessoas[idxPessoa].tempo;

    return res;
}