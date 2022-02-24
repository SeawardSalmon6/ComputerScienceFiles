/* Escreva um programa, em C, de reserva de bilhetes de linha aérea.
O programa exibe um menu com as seguintes opções: reserva de bilhete, cancelamento de bilhete,
verificação se um bilhete está reservado para uma pessoa particular e exibição dos passageiros.
A informação é mantida alfabeticamente numa lista encadeada de nomes.
Em uma versão mais simples do programa, assuma que os bilhetes estão reservados para somente um voo.
Crie uma lista encadeada de voos com cada nó incluindo um ponteiro para uma lista ligada de passageiros. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

/* ======= Definição do Tipo Lista */
typedef struct ListaPassageiros {
	char nome[100];
	struct ListaPassageiros *prox;
} stListaPassageiros;

/* ======= Protótipos */
void GetInformacoesBilhete(stListaPassageiros*);
void ReservarBilhete(stListaPassageiros**);
void RemoverBilhete(stListaPassageiros**);
void VerificarBilhete(stListaPassageiros**);
void ApresentarPassageiros(stListaPassageiros*);
void Menu(int*);
void Pause();

/* ======= Função de Inicialização da Lista */
stListaPassageiros *InicializarNode(void) {
	stListaPassageiros *Node = (stListaPassageiros*) malloc(sizeof(stListaPassageiros));
	strcpy(Node->nome, "\0");
	Node->prox = NULL;
	return Node;
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int opt = 0;
	stListaPassageiros *Passageiros = InicializarNode();

	do {
		system(CLEAR);
		Menu(&opt);
		switch(opt) {
			case 1:
				system(CLEAR);
				ReservarBilhete(&Passageiros);
				Pause();
				break;

			case 2:
				system(CLEAR);
				RemoverBilhete(&Passageiros);
				Pause();
				break;

			case 3:
				system(CLEAR);
				VerificarBilhete(&Passageiros);
				Pause();
				break;

			case 4:
				system(CLEAR);
				ApresentarPassageiros(Passageiros);
				Pause();
				break;

			case 5:
				printf("\nObrigado por utilizar nosso programa!\n\n");
				break;

			default:
				free(Passageiros);
				return 0;
				break;
		}
	} while(opt != 5);

	free(Passageiros);
	return 0;
}

void GetInformacoesBilhete(stListaPassageiros *NovoPassageiro) {
	char nomeReserva[100] = { 0 };

	printf("============ Reservar Bilhete Particular\n");

	/* ---> Receber o nome do passageiro */
	printf("\n--> Insira o nome do passageiro: ");
	scanf(" %s", nomeReserva);

	strcpy(NovoPassageiro->nome, nomeReserva);
}

void ReservarBilhete(stListaPassageiros **cabeca) {
	stListaPassageiros *NovoPassageiro = InicializarNode();
	stListaPassageiros *aux, *antes = NULL;

	GetInformacoesBilhete(NovoPassageiro);

	if(!*cabeca) return;
	if(strcmp((*cabeca)->nome, "") == 0) {
		strcpy((*cabeca)->nome, NovoPassageiro->nome);
		(*cabeca)->prox = NULL;
		return;
	}

	aux = *cabeca;

	/* ---> Procura a posição correta */
	while(aux->prox && strcmp(aux->nome, NovoPassageiro->nome) < 0) {
		antes = aux;
		aux = aux->prox;
	}

	if(aux == *cabeca)
	    if(strcmp(aux->nome, NovoPassageiro->nome) < 0) {
	        NovoPassageiro->prox = aux->prox;
            (*cabeca)->prox = NovoPassageiro;
	    } else {
	        NovoPassageiro->prox = aux;
            *cabeca = NovoPassageiro;
	    }
	else {
	    NovoPassageiro->prox = aux;
	    antes->prox = NovoPassageiro;
	}

	printf("\n--> Obrigado por reservar seu bilhete, %s!\n\n", NovoPassageiro->nome);
}

void RemoverBilhete(stListaPassageiros **cabeca) {
	char chave[100] = { 0 };
	stListaPassageiros *aux, *antes = NULL;

	printf("============ Remover Bilhete Particular\n");

	if(!*cabeca || !strcmp((*cabeca)->nome, "")) {
		printf("\n**AVISO: A lista de passageiros para este voo está vazia!.\n\n");
		return;
	}

	/* ---> Receber o nome do passageiro */
	printf("\n--> Insira o nome do passageiro: ");
	scanf(" %s", chave);

	aux = *cabeca;

	/* ---> Procura bilhete para remoção */
	while(aux->prox && strcmp(aux->nome, chave)) {
		antes = aux;
		aux = aux->prox;
	}

	if(!aux->prox && strcmp(aux->nome, chave)) {
		printf("\n---> Não encontramos nenhum bilhete com este nome.\n\n");
		return;
	}

	if(aux == *cabeca) {
		if(aux->prox) {
			*cabeca = (*cabeca)->prox;
			free(aux);
		} else {
			free(*cabeca);
			*cabeca = InicializarNode();
		}
	} else {
		antes->prox = aux->prox;
		free(aux);
	}

	printf("\n--> Bilhete removido com sucesso, %s!\n\n", chave);
}

void VerificarBilhete(stListaPassageiros **cabeca) {
	char chave[100] = { 0 };
	stListaPassageiros *aux;

	printf("============ Remover Bilhete Particular\n");

	if(!*cabeca || !strcmp((*cabeca)->nome, "")) {
		printf("\n**AVISO: A lista de passageiros para este voo está vazia!.\n\n");
		return;
	}

	/* ---> Receber o nome do passageiro */
	printf("\n--> Insira o nome do passageiro: ");
	scanf(" %s", chave);

	aux = *cabeca;

	/* ---> Procura bilhete para remoção */
	while(aux->prox && strcmp(aux->nome, chave))
		aux = aux->prox;

	if(!aux->prox && strcmp(aux->nome, chave)) {
		printf("\n---> Não encontramos nenhum bilhete com este nome.\n\n");
		return;
	}

	printf("\n----> O bilhete do Passageiro %s existe e está ativo!\n\n", aux->nome);
}

void ApresentarPassageiros(stListaPassageiros *cabeca) {
	int k = 0;
	stListaPassageiros *aux = cabeca;

	printf("\n======== Lista de Passageiros do Voo ========\n");
	if(strcmp(cabeca->nome, "")) {
		while(aux) {
			printf("\n--> Passageiro %d", ++k);
			printf("\n    Nome: %s\n", aux->nome);
			aux = aux->prox;
		}
	} else
		printf("\n**AVISO: Não há passageiros neste voo!\n\n");

	printf("\n");
}

void Menu(int *opcao) {
	printf("======== MENU PRINCIPAL ========\n");
	printf("(1). Reserva de Bilhete\n");
	printf("(2). Cancelamento de Bilhete\n");
	printf("(3). Verificar Bilhete\n");
	printf("(4). Exibir Passageiros\n");
	printf("(5). Sair do Programa\n");

	do {
		printf("\n----> Escolha uma opção: ");
		scanf(" %d", opcao);

		if(*opcao < 1 || *opcao > 5)
			printf("\n**AVISO: Insira uma opção válida!\n");
	} while(*opcao < 1 || *opcao > 5);
}

void Pause() {
	printf("\n - Pressione uma tecla para continuar...");
	getchar(); scanf("c");
}
