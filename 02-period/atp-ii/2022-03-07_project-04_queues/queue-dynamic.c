#include <stdio.h>
#include <stdlib.h>

/* ======== Structs */
typedef struct Pessoa {
    int idade;
    int instante;
    int tempo;
    struct Pessoa *proxInstante;
    struct Pessoa *proxFila;
} tPessoa;


/* ======== Protótipos de Funções */
void AbrirMercadao(tPessoa**, int); // --> Função Principal
void LerPessoas(tPessoa**, int); // --> Função de Leitura
void FreeListaPessoas(tPessoa **); // --> Libera a memória alocada

// --> Tratamento da Fila Saída de Dados
void EscreverFila(tPessoa**);
void InserirNaFila(tPessoa**, tPessoa**, tPessoa*, int*);

// --> Funções do Caixa
int TemCaixaLivre(int*, int, int, int*);
int OcuparCaixa(int*, tPessoa**, tPessoa*, int*);

// --> Merge Sorting Methods
void MergeSorting(tPessoa**);
void EncontrarMeio(tPessoa*, tPessoa**, tPessoa**);
tPessoa *MergeBlocos(tPessoa*, tPessoa*);


/* ======== Funções e Conteúdo Principal */
// --> Função de Leitura
void LerPessoas(tPessoa **listHead, int qtdPessoas) {
    int i;
    tPessoa *newPerson, *auxPerson = *listHead;

    /* --> Lê o primeiro cliente */
    scanf(" %d %d %d", &auxPerson->idade, &auxPerson->instante, &auxPerson->tempo);

    for(i = 1; i < qtdPessoas; i++) {
        newPerson = (tPessoa*) malloc(sizeof(tPessoa)); // --> Aloca a memória necessária

        /* --> Lê os dados do novo cliente */
        scanf(" %d %d %d", &newPerson->idade, &newPerson->instante, &newPerson->tempo);

        /* --> Faz a conexão entre os clientes anteriores */
        auxPerson->proxInstante = newPerson;
		auxPerson->proxFila = NULL;
        auxPerson = auxPerson->proxInstante;
    }

	// --> Deixa nulo os valores do próximo cliente e valor da fila (não há)
	auxPerson->proxInstante = NULL;

    /* --> Ordenar Vetor em função dos instantes de chegada, utilizando Merge Sort */
	MergeSorting(listHead);
}

void FreeListaPessoas(tPessoa **ListaPessoas) {
	tPessoa *tmp = *ListaPessoas; // --> Ponteiro auxiliar
	while(tmp) { // --> Enquanto não for nulo...
		tmp = tmp->proxInstante; // --> Atualiza o ponteiro para o próximo da lista
		free(*ListaPessoas); // --> Remove a cabeça da lista
		*ListaPessoas = tmp; // --> Atualiza a cabeça da lista para o próximo ponteiro da lista
	}
}

int main() {
    int qtdPessoas, qtdCaixas; // --> Variáveis iniciais do programa

    // -->  Leitura da Quantidade de Pessoas e Caixas
    scanf(" %d %d", &qtdPessoas, &qtdCaixas);

	// --> Declaração da variável da Lista de Clientes
    tPessoa *ListaPessoas = (tPessoa*) malloc(sizeof(tPessoa));

    LerPessoas(&ListaPessoas, qtdPessoas); // --> Realiza a leitura dos dados e os ordenam
    AbrirMercadao(&ListaPessoas, qtdCaixas); // --> Inicia o trabalho do programa
	FreeListaPessoas(&ListaPessoas); // --> Libera a memória alocada pelos clientes

    return 0;
}

// --> Função Principal
void AbrirMercadao(tPessoa **listHead, int qtdCaixas) {
    int i, posCaixa = 0, idxFila = 0; // --> Índices auxiliares do programa
	int daVezNaoEstaNaFila; // --> Verifica a segunda restrição do projeto
	tPessoa *auxPessoa = *listHead; // --> Ponteiro auxiliar para caminhar pela lista
	tPessoa *cabecaFila = NULL, *tailFila = NULL; // --> Ponteiros auxiliares indicando o início e fim da Fila

    /* --> Configurar vetor de caixas */
	int *Caixas = (int*) malloc(qtdCaixas * sizeof(int)); // --> Aloca a memória para os Caixas
    for(i = 0; i < qtdCaixas; i++)
        Caixas[i] = 0; // --> Atualiza os próximos instantes disponíveis para atendimento

    while(auxPessoa) { // --> Enquanto o ponteiro auxiliar não for nulo...
		// --> Verifica se há disponibilidade de atendimento no instante atual
        if(TemCaixaLivre(Caixas, auxPessoa->instante, qtdCaixas, &posCaixa)) {
			// --> Ocupa um dos caixas livres (se houver) e retorna true ou false para a segunda restrição
            daVezNaoEstaNaFila = OcuparCaixa(&Caixas[posCaixa], &cabecaFila, auxPessoa, &idxFila);

			if(daVezNaoEstaNaFila) // --> Se a segunda restrição acontecer, insere a pessoa que chega na fila
                InserirNaFila(&cabecaFila, &tailFila, auxPessoa, &idxFila);

			// --> Verifica se há disponibilidade de atendimento no instante atual para as pessoas na Fila
            while(idxFila > 0 && TemCaixaLivre(Caixas, auxPessoa->instante, qtdCaixas, &posCaixa))
				// --> Ocupa o caixa disponível
                daVezNaoEstaNaFila = OcuparCaixa(&Caixas[posCaixa], &cabecaFila, auxPessoa, &idxFila);
        } else
			// --> Se não houverem caixas disponíveis o cliente é inserido na fila
            InserirNaFila(&cabecaFila, &tailFila, auxPessoa, &idxFila);

		if(auxPessoa->proxInstante) // --> Verifica se está no último cliente da lista (evitar seg. fault)
			// --> Se duas pessoas chegarem ao mesmo tempo, printa somente na próxima execução (primeira restrição do projeto)
			if(!(auxPessoa->instante == (auxPessoa->proxInstante)->instante))
				EscreverFila(&cabecaFila); // --> Escreve a fila

		auxPessoa = auxPessoa->proxInstante; // --> Atualiza o ponteiro auxiliar para o próximo cliente da fila
    }

	EscreverFila(&cabecaFila);
	free(Caixas); // --> Libera a memória utilizada nos Caixas
}


// --> Tratamento da Fila Saída de Dados
void EscreverFila(tPessoa **cabecaFila) {
	tPessoa *auxFila = NULL;

    if(*cabecaFila) { // --> Se a cabeça da fila não for nula...
		auxFila = *cabecaFila; // --> Atribui ao ponteiro auxiliar o teste inicial
        while(auxFila) { // --> Enquanto não chegar ao fim da fila
            printf("%d ", auxFila->idade); // --> Print a idade de quem está na fila
			auxFila = auxFila->proxFila;
		}
    } else
        printf("NULL"); // --> Caso não haja ninguém na fila print NULL
    printf("\n");
}

void InserirNaFila(tPessoa **cabecaFila, tPessoa **tailFila, tPessoa *nextCustomer, int *idxFila) {
	tPessoa *ultimaPessoa, *auxQueue = *cabecaFila; // --> Ponteiros auxiliares para caminhar pela fila

    if(!*cabecaFila) { // --> Se a fila estiver vazia...
		// --> Atribui valores da cabeça e cauda para o cliente que vai entrar na fila
        *cabecaFila = *tailFila = nextCustomer;
		(*tailFila)->proxFila = NULL; // --> Deixa o próximo da fila nulo para evitar seg. fault em testes
        *idxFila = *idxFila + 1; // --> Atualiza a quantidade de pessoas na fila
        return;
    }

    if(nextCustomer->idade > 64) { // --> Se o cliente tiver mais que 64 anos...
        // --> Procura a posição de inserção dentro da fila (prioridade)
        while(auxQueue->proxFila && auxQueue->idade > nextCustomer->idade) {
            ultimaPessoa = auxQueue;
            auxQueue = auxQueue->proxFila;
        }

        if(auxQueue == *cabecaFila) { // --> Caso entre no início da fila...
            nextCustomer->proxFila = auxQueue; // --> O cliente aponta para o cliente apontado pelo auxiliar
            *cabecaFila = nextCustomer; // --> Atualiza a cabeça da fila como o novo cliente
        } else { // --> Caso entre no meio da fila
            nextCustomer->proxFila = auxQueue;
            ultimaPessoa->proxFila = nextCustomer; // --> Faz o cliente anterior apontar para o novo cliente
        }
    } else { // --> Caso entre no fim da fila
        (*tailFila)->proxFila = nextCustomer; // --> Faz a cauda apontar para o novo cliente
        nextCustomer->proxFila = NULL; // --> Faz o cliente apontar para NULL
        *tailFila = nextCustomer; // --> Atualiza o valor da cauda para o novo cliente (último da fila)
    }

    *idxFila = *idxFila + 1; // --> Atualiza a quantidade de pessoas na fila
}


// --> Funções do Caixa
int TemCaixaLivre(int *Caixas, int t, int qtdCaixas, int *posCaixa) {
    int i;
    for(i = 0; i < qtdCaixas; i++) // --> Percorre todos os caixas
        if(t >= Caixas[i]) { // --> Verifica se o caixa está livre (testando o instante de liberação)
            *posCaixa = i; // --> Caso esteja livre, atualiza a posição do caixa disponível
            return 1; // --> Retorna true caso encontre disponibilidade
        }

    return 0; // --> Retorna false caso não encontre disponibilidade
}

int OcuparCaixa(int *caixaLivre, tPessoa **cabecaFila, tPessoa *nextCustomer, int *idxFila) {
    int res = 0; // --> Retorna false caso não se aplique a segunda restrição

    // --> Remove e reposiciona valores da fila
    if(*idxFila > 0) { // --> Se houverem pessoas na fila...
        nextCustomer = *cabecaFila; // --> O cliente a ser atendido será o primeiro da fila
		*idxFila = *idxFila - 1; // --> Atualiza a quantidade de pessoas na fila
        *cabecaFila = (*cabecaFila)->proxFila; // --> Torna a cabeça da fila o segundo cliente da fila
        res = 1; // --> Retorna true caso se aplique a segunda restrição
    }

    // --> Ocupa o caixa
	// --> Se o caixa já estiver em atividade, adiciona-se o tempo de atendimento do cliente
    if(*caixaLivre) *caixaLivre += nextCustomer->tempo;
    else // --> Se o caixa não estiver em atividade, adiciona-se os tempos de chegada e de atendimento do cliente
        *caixaLivre = nextCustomer->instante + nextCustomer->tempo;

    return res;
}


/* ========= Merge Sorting */
void MergeSorting(tPessoa** cabecaLista) {
    tPessoa *atual = *cabecaLista;
    tPessoa *firstElem;
    tPessoa *secondElem;

    if(!atual || !atual->proxInstante) return;

    EncontrarMeio(atual, &firstElem, &secondElem);

    MergeSorting(&firstElem);
    MergeSorting(&secondElem);
    *cabecaLista = MergeBlocos(firstElem, secondElem);
}

void EncontrarMeio(tPessoa *atual, tPessoa **firstElem, tPessoa** secondElem) {
    tPessoa *fast;
    tPessoa *slow;
    slow = atual;
    fast = atual->proxInstante;

    while(fast != NULL) {
        fast = fast->proxInstante;
        if(fast != NULL) {
            slow = slow->proxInstante;
            fast = fast->proxInstante;
        }
    }

    *firstElem = atual;
    *secondElem = slow->proxInstante;
    slow->proxInstante = NULL;
}

tPessoa *MergeBlocos(tPessoa *firstElem, tPessoa *secondElem) {
    tPessoa *res = NULL;

    if(!firstElem) // --> Se o primeiro bloco não possuir elementos
        return secondElem; // --> Retorna o segundo bloco
    else if(!secondElem) // --> Se o segundo bloco não possuir elementos
        return firstElem; // --> Retorna o primeiro bloco

	// --> Realiza o posicionamento correto dos elementos, em relação ao instante de chegada
	if(firstElem->instante < secondElem->instante) {
		res = firstElem;
		res->proxInstante = MergeBlocos(firstElem->proxInstante, secondElem);
	} else if(firstElem->instante == secondElem->instante) {
		if(firstElem->idade > 64 || secondElem->idade > 64)
			// --> Já realiza a ordenação por ordem de prioridade
			if(secondElem->idade - firstElem->idade > 0) {
				res = secondElem;
				res->proxInstante = MergeBlocos(firstElem, secondElem->proxInstante);
			} else {
				res = firstElem;
				res->proxInstante = MergeBlocos(firstElem->proxInstante, secondElem);
			}
	} else {
		res = secondElem;
		res->proxInstante = MergeBlocos(firstElem, secondElem->proxInstante);
	}

	return res;
}
