#include <stdio.h>
#include <stdlib.h>

/* ======== Structs */
typedef struct Person {
    int age;
    int arrivalTime;
    int serviceTime;
    struct Person *nextArrival;
    struct Person *nextInQueue;
} tPerson;

typedef struct Cashier {
    int available;
    int nextAvailableTime;
    struct Cashier *nextCashier;
} tCashier;

/* ======== Variáveis Globais */
int qtdPessoas;

/* ======== Protótipos de Funções */
void AbrirMercadao(tPerson*, int*, int, int);
void LerPessoas(tPerson*);
int OrdenarInstantes(const void*, const void*);
void EscreverFila(int*, int);
int TemCaixaLivre(tCaixa*, int, int *, int );
int OcuparCaixa(tCaixa*, tPerson*, int*, int*, int, int*);
void InserirNaFila(tPerson*, int*, int*, int, int*);

int main() {
    int i, qtdCaixas;

    /* Leitura da Quantidade de Pessoas e Caixas */
    scanf(" %d %d", &qtdPessoas, &qtdCaixas);

    tPerson *ListaPessoas = (tPerson*) malloc(sizeof(tPerson));

    LerPessoas(&ListaPessoas);
    AbrirMercadao(ListaPessoas, Fila, 0, qtdCaixas);

    return 0;
}

void AbrirMercadao(tPerson *ListaPessoas, int *Fila, int idxFila, int qtdCaixas) {
    int i, daVezNaoEstaNaFila, posCabeca = 0, j = 0, posCaixa = 0;
    tCaixa Caixas[qtdCaixas];

    /* --> Configurar vetor de caixas */
    for(i = 0; i < qtdCaixas; i++) {
        Caixas[i].disponivel = 1;
        Caixas[i].proxDisponivel = 0;
    }

    for(i = 0; i < qtdPessoas; i++) {
        if(TemCaixaLivre(Caixas, ListaPessoas[i].instante, &posCaixa, qtdCaixas)) {
            daVezNaoEstaNaFila = OcuparCaixa(&Caixas[posCaixa], ListaPessoas, Fila, &posCabeca, i, &idxFila);

            while(idxFila > 0 && TemCaixaLivre(Caixas, ListaPessoas[i].instante, &posCaixa, qtdCaixas))
                daVezNaoEstaNaFila = OcuparCaixa(&Caixas[posCaixa], ListaPessoas, Fila, &posCabeca, i, &idxFila);

			if(daVezNaoEstaNaFila)
                InserirNaFila(Fila, ListaPessoas, &posCabeca, i, &idxFila);
        } else
            InserirNaFila(Fila, ListaPessoas, &posCabeca, i, &idxFila);

        if(!(ListaPessoas[i].instante == ListaPessoas[i + 1].instante))
            EscreverFila(Fila, idxFila);
    }
}

void LerPessoas(tPerson **listHead) {
    int i;
    tPerson *newPerson, *auxPerson = *listHead;

    /* --> Reading first person */
    scanf(" %d %d %d", &auxPerson->age, &auxPerson->arrivalTime, &auxPerson->serviceTime);

    for(i = 1; i < qtdPessoas; i++) {
        newPerson = (tPerson*) malloc(sizeof(tPerson));

        /* --> Data reading */
        scanf(" %d %d %d", &newPerson->age, &newPerson->arrivalTime, &newPerson->serviceTime);

        /* --> Setting default values for pointers */
        auxPerson->nextArrival = newPerson;
        auxPerson = auxPerson->nextArrival;
    }

    /* --> Ordenar Vetor em função dos instantes de chegada */
    qsort(vet, qtdPessoas, sizeof(tPerson), OrdenarInstantes);
}

int OrdenarInstantes(const void *a, const void *b) {
    tPerson varA = *(tPerson*)a, varB = *(tPerson*)b;
    if(varA.instante < varB.instante) return -1;
    else if(varA.instante == varB.instante) {
        if(varA.idade > 64 || varB.idade > 64)
            return varB.idade - varA.idade;
        return 0;
    }
    else return 1;
}

void EscreverFila(int *Fila, int idxFila) {
    int i;
    if(Fila[0] > 0) {
        for(i = 0; i < idxFila; i++)
            printf("%d ", Fila[i]);
    } else
        printf("NULL");
    printf("\n");
}

int TemCaixaLivre(tCaixa *vetCaixas, int t, int *posCaixa, int qtdCaixas) {
    int i;
    for(i = 0; i < qtdCaixas; i++)
        if(vetCaixas[i].disponivel || t >= vetCaixas[i].proxDisponivel) {
            *posCaixa = i;
            return 1;
        }

    return 0;
}

int OcuparCaixa(tCaixa *caixaLivre, tPerson *ListaPessoas, int *Fila, int *posCabeca, int idxPessoa, int *idxFila) {
    int i, res = 0;

    /* --> Remove e reposiciona valores da fila */
    if(*idxFila > 0) {
        idxPessoa = *posCabeca;
        for(i = 0; i < *idxFila - 1; i++)
            Fila[i] = Fila[i + 1];

        Fila[i] = -1; *idxFila = *idxFila - 1;
        *posCabeca = idxPessoa + 1;
        res = 1;
    }

    /* --> Ocupa o caixa */
    caixaLivre->disponivel = 0;
    if(!caixaLivre->proxDisponivel)
        caixaLivre->proxDisponivel = ListaPessoas[idxPessoa].instante + ListaPessoas[idxPessoa].tempo;
    else
        caixaLivre->proxDisponivel += ListaPessoas[idxPessoa].tempo;

    return res;
}

void InserirNaFila(tPerson *ListaPessoas, int *Fila, int *posCabeca, int idxPessoa, int *idxFila) {
    int i = 0, j;

    if(ListaPessoas[idxPessoa].idade > 64) {
        while(Fila[i] > ListaPessoas[idxPessoa].idade)
            i++;

        for(j = *idxFila; j > i; j--)
            Fila[j] = Fila[j - 1];
        *posCabeca = (!i) ? idxPessoa : *posCabeca;

        Fila[i] = ListaPessoas[idxPessoa].idade;
    } else
        Fila[*idxFila] = ListaPessoas[idxPessoa].idade;

    *idxFila = *idxFila + 1;
}