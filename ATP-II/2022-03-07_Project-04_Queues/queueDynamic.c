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

/* ======== Variáveis Globais */
int qtdPessoas;

/* ======== Protótipos de Funções */
// --> Função Principal
void AbrirMercadao(tPerson*, int*, int, int);
void LerPessoas(tPerson**); // -> Função de Leitura

// --> Merge Sorting Methods
void MergeSorting(tPerson**);
void FindMiddle(tPerson*, tPerson**, tPerson**);
tPerson *MergeBoth(tPerson*, tPerson*);

// --> Tratamento da Fila Saída de Dados
void EscreverFila(int*, int);
void InserirNaFila(tPerson*, int*, int*, int, int*);

// --> Funções do Caixa
int TemCaixaLivre(int*, int, int *, int );
int OcuparCaixa(int*, tPerson*, int*, int*, int, int*);


/* ======== Funções e Conteúdo Principal */
int main() {
    int i, qtdCaixas;

    /* Leitura da Quantidade de Pessoas e Caixas */
    scanf(" %d %d", &qtdPessoas, &qtdCaixas);

    tPerson *ListaPessoas;

    LerPessoas(&ListaPessoas);
    // AbrirMercadao(ListaPessoas, Fila, 0, qtdCaixas);

	free(ListaPessoas);

    return 0;
}


// --> Função de Leitura
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
	MergeSorting(listHead);
}


/* ========= Merge Sorting */
void MergeSorting(tPerson** head) {
    tPerson *cur = *head;
    tPerson *first;
    tPerson *second;

    if(!cur || !cur->nextArrival) return;

    FindMiddle(cur, &first, &second);

    MergeSorting(&first);
    MergeSorting(&second);
    *head = MergeBoth(first, second);
}

void FindMiddle(tPerson *cur, tPerson **first, tPerson** second) {
    tPerson *fast;
    tPerson *slow;
    slow = cur;
    fast = cur->nextArrival;

    while(fast != NULL) {
        fast = fast->nextArrival;
        if(fast != NULL) {
            slow = slow->nextArrival;
            fast = fast->nextArrival;
        }
    }

    *first = cur;
    *second = slow->nextArrival;
    slow->nextArrival = NULL;
}

tPerson *MergeBoth(tPerson *first, tPerson *second) {
    tPerson *answer = NULL;

    if(!first)
        return second;
    else if(!second)
        return first;

       if(first->arrivalTime <= second->arrivalTime) {
           answer = first;
           answer->nextArrival = MergeBoth(first->nextArrival, second);
       } else {
           answer = second;
           answer->nextArrival = MergeBoth(first, second->nextArrival);
       }

       return answer;
}


// // --> Função Principal
// void AbrirMercadao(tPerson *ListaPessoas, int *Fila, int idxFila, int qtdCaixas) {
//     int i, daVezNaoEstaNaFila, posCabeca = 0, j = 0, posCaixa = 0;
//     int Caixas[qtdCaixas];

//     /* --> Configurar vetor de caixas */
//     for(i = 0; i < qtdCaixas; i++)
//         Caixas[i] = 0;

//     for(i = 0; i < qtdPessoas; i++) {
//         if(TemCaixaLivre(Caixas, ListaPessoas[i].instante, &posCaixa, qtdCaixas)) {
//             daVezNaoEstaNaFila = OcuparCaixa(&Caixas[posCaixa], ListaPessoas, Fila, &posCabeca, i, &idxFila);

// 			if(daVezNaoEstaNaFila)
//                 InserirNaFila(ListaPessoas, Fila, &posCabeca, i, &idxFila);

//             while(idxFila > 0 && TemCaixaLivre(Caixas, ListaPessoas[i].instante, &posCaixa, qtdCaixas))
//                 daVezNaoEstaNaFila = OcuparCaixa(&Caixas[posCaixa], ListaPessoas, Fila, &posCabeca, i, &idxFila);
//         } else
//             InserirNaFila(ListaPessoas, Fila, &posCabeca, i, &idxFila);

//         if(!(ListaPessoas[i].instante == ListaPessoas[i + 1].instante))
//             EscreverFila(Fila, idxFila);
//     }
// }

int OrdenarInstantes(const void *a, const void *b) {
    tPerson varA = *(tPerson*)a, varB = *(tPerson*)b;
    if(varA.arrivalTime < varB.arrivalTime) return -1;
    else if(varA.arrivalTime == varB.arrivalTime) {
        if(varA.age > 64 || varB.age > 64)
            return varB.age - varA.age;
        return 0;
    }
    else return 1;
}


// // --> Tratamento da Fila Saída de Dados
// void EscreverFila(int *Fila, int idxFila) {
//     int i;
//     if(Fila[0] > 0) {
//         for(i = 0; i < idxFila; i++)
//             printf("%d ", Fila[i]);
//     } else
//         printf("NULL");
//     printf("\n");
// }

// void InserirNaFila(tPerson *ListaPessoas, int *Fila, int *posCabeca, int idxPessoa, int *idxFila) {
//     int i = 0, j;

//     if(ListaPessoas[idxPessoa].idade > 64) {
//         while(Fila[i] > ListaPessoas[idxPessoa].idade)
//             i++;

//         for(j = *idxFila; j > i; j--)
//             Fila[j] = Fila[j - 1];
//         *posCabeca = (!i) ? idxPessoa : *posCabeca;

//         Fila[i] = ListaPessoas[idxPessoa].idade;
//     } else
//         Fila[*idxFila] = ListaPessoas[idxPessoa].idade;

//     *idxFila = *idxFila + 1;
// }


// // --> Funções do Caixa
// int TemCaixaLivre(int *vetCaixas, int t, int *posCaixa, int qtdCaixas) {
//     int i;
//     for(i = 0; i < qtdCaixas; i++)
//         if(t >= vetCaixas[i]) {
//             *posCaixa = i;
//             return 1;
//         }

//     return 0;
// }

// int OcuparCaixa(int *caixaLivre, tPerson *ListaPessoas, int *Fila, int *posCabeca, int idxPessoa, int *idxFila) {
//     int i, res = 0;

//     /* --> Remove e reposiciona valores da fila */
//     if(*idxFila > 0) {
//         idxPessoa = *posCabeca;
//         for(i = 0; i < *idxFila - 1; i++)
//             Fila[i] = Fila[i + 1];

//         Fila[i] = -1; *idxFila = *idxFila - 1;
//         *posCabeca = idxPessoa + 1;
//         res = 1;
//     }

//     /* --> Ocupa o caixa */
//     if(*caixaLivre) *caixaLivre += ListaPessoas[idxPessoa].tempo;
//     else
//         *caixaLivre = ListaPessoas[idxPessoa].instante + ListaPessoas[idxPessoa].tempo;

//     return res;
// }