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
void AbrirMercadao(tPerson**, int);
void LerPessoas(tPerson**); // -> Função de Leitura

// --> Merge Sorting Methods
void MergeSorting(tPerson**);
void FindMiddle(tPerson*, tPerson**, tPerson**);
tPerson *MergeBoth(tPerson*, tPerson*);

// --> Tratamento da Fila Saída de Dados
void EscreverFila(tPerson*);
void InserirNaFila(tPerson**, tPerson**, tPerson*, int*);

// --> Funções do Caixa
int TemCaixaLivre(int*, int, int, int*);
int OcuparCaixa(int*, tPerson**, tPerson*, int*);


/* ======== Funções e Conteúdo Principal */
int main() {
    int i, qtdCaixas;

    /* Leitura da Quantidade de Pessoas e Caixas */
    scanf(" %d %d", &qtdPessoas, &qtdCaixas);

    tPerson *ListaPessoas;

    LerPessoas(&ListaPessoas);
    AbrirMercadao(&ListaPessoas, qtdCaixas);

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

	if(first->arrivalTime < second->arrivalTime) {
		answer = first;
		answer->nextArrival = MergeBoth(first->nextArrival, second);
	} else if(first->arrivalTime == second->arrivalTime) {
		if(first->age > 64 || second->age > 64)
			if(second->age - first->age > 0) {
				answer = second;
				answer->nextArrival = MergeBoth(first, second->nextArrival);
			} else {
				answer = first;
				answer->nextArrival = MergeBoth(first->nextArrival, second);
			}
	} else {
		answer = second;
		answer->nextArrival = MergeBoth(first, second->nextArrival);
	}

	return answer;
}


// --> Função Principal
void AbrirMercadao(tPerson **listHead, int qtdCaixas) {
    int i, daVezNaoEstaNaFila;
	int j = 0, posCaixa = 0, idxFila = 0;
	tPerson *auxPessoa = *listHead, *queueHead = NULL, *queueTail = NULL;

    /* --> Configurar vetor de caixas */
	int *Caixas = (int*) malloc(qtdCaixas * sizeof(int));
    for(i = 0; i < qtdCaixas; i++)
        Caixas[i] = 0;

    while(auxPessoa) {
        if(TemCaixaLivre(Caixas, auxPessoa->arrivalTime, qtdCaixas, &posCaixa)) {
            daVezNaoEstaNaFila = OcuparCaixa(&Caixas[posCaixa], &queueHead, auxPessoa, &idxFila);

			if(daVezNaoEstaNaFila)
                InserirNaFila(&queueHead, &queueTail, auxPessoa, &idxFila);

            while(idxFila > 0 && TemCaixaLivre(Caixas, auxPessoa->arrivalTime, qtdCaixas, &posCaixa))
                daVezNaoEstaNaFila = OcuparCaixa(&Caixas[posCaixa], &queueHead, auxPessoa, &idxFila);
        } else
            InserirNaFila(&queueHead, &queueTail, auxPessoa, &idxFila);

        if(!(auxPessoa->arrivalTime == (auxPessoa->nextArrival)->arrivalTime))
            EscreverFila(queueHead);

		auxPessoa = auxPessoa->nextArrival;
    }

	// --> Apagar os dados
	while(*listHead) {
		auxPessoa = *listHead;
		*listHead = (*listHead)->nextArrival;
		free(auxPessoa);
	}

	free(Caixas);
}


// --> Tratamento da Fila Saída de Dados
void EscreverFila(tPerson *queueHead) {
	tPerson *auxFila = NULL;

    if(queueHead) {
		auxFila = queueHead;
        while(auxFila) {
            printf("%d ", auxFila->age);
			auxFila = auxFila->nextInQueue;
		}
    } else
        printf("NULL");
    printf("\n");
}

void InserirNaFila(tPerson **queueHead, tPerson **queueTail, tPerson *nextCustomer, int *idxFila) {
    int i = 0, j;
	tPerson *lastPerson, *auxQueue = *queueHead;

    if(!*queueHead) {
        *queueHead = nextCustomer;
        *queueTail = nextCustomer;
        *idxFila = *idxFila + 1;
        return;
    }

    if(nextCustomer->age > 64) {
        /* --> Searching a place to insert the nextCustomer */
        while(auxQueue->nextInQueue && auxQueue->age > nextCustomer->age) {
            lastPerson = auxQueue;
            auxQueue = auxQueue->nextInQueue;
        }

        if(auxQueue == *queueHead) {
            nextCustomer->nextInQueue = auxQueue;
            *queueHead = nextCustomer;
        } else {
            nextCustomer->nextInQueue = auxQueue;
            lastPerson->nextInQueue = nextCustomer;
        }
    } else {
        (*queueTail)->nextInQueue = nextCustomer;
        nextCustomer->nextInQueue = NULL;
        *queueTail = nextCustomer;
    }

    *idxFila = *idxFila + 1;
}


// --> Funções do Caixa
int TemCaixaLivre(int *Caixas, int t, int qtdCaixas, int *posCaixa) {
    int i;
    for(i = 0; i < qtdCaixas; i++)
        if(t >= Caixas[i]) {
            *posCaixa = i;
            return 1;
        }

    return 0;
}

int OcuparCaixa(int *caixaLivre, tPerson **queueHead, tPerson *nextCustomer, int *idxFila) {
    int res = 0;

    /* --> Remove e reposiciona valores da fila */
    if(*idxFila > 0) {
        nextCustomer = *queueHead;
		*idxFila = *idxFila - 1;
        *queueHead = (*queueHead)->nextInQueue;
        res = 1;
    }

    /* --> Ocupa o caixa */
    if(*caixaLivre) *caixaLivre += nextCustomer->serviceTime;
    else
        *caixaLivre = nextCustomer->arrivalTime + nextCustomer->serviceTime;

    return res;
}