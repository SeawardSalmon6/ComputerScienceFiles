/* Escreva um programa, em C, de reserva de bilhetes de linha aérea.
O programa exibe um menu com as seguintes opções: reserva de bilhete, cancelamento de bilhete,
verificação se um bilhete está reservado para uma pessoa particular e exibição dos passageiros.
A informação é mantida alfabeticamente numa lista encadeada de nomes.
Em uma versão mais simples do programa, assuma que os bilhetes estão reservados para somente um voo.
Crie uma lista encadeada de voos com cada nó incluindo um ponteiro para uma lista ligada de passageiros. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Pause() {
	puts(" - Pressione uma tecla para continuar...");
	getchar(); scanf("c");
}

typedef struct ListaPassageiros {
	char nome[100];
	struct ListaPassageiros *prox;
} stListaPassageiros;

void ReservarBilhete(stListaPassageiros **cabeca, stListaPassageiros *NovoPassageiro) {
	stListaPassageiros *aux, *antes = NULL;

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

		if(*opcao < 1 || *opcao < 5)
			printf("\n**AVISO: Insira uma opção válida!\n");
	} while(*opcao < 1 || *opcao < 5);
}

int main() {
	stListaPassageiros *Passageiros, teste, novoTeste, outroTeste;
	char nomeReserva[100], outro[100], outroNome[100] = { 0 };

	Passageiros = malloc(sizeof(stListaPassageiros));

	/* ---> Receber o nome do passageiro */
	printf("\n--> Insira o nome do passageiro: ");
	scanf(" %s", nomeReserva);

	strcpy(teste.nome, nomeReserva);

	ReservarBilhete(&Passageiros, &teste);

	/* ---> Receber o nome do passageiro */
	printf("\n\n--> Insira o nome do passageiro: ");
	scanf(" %s", outro);

	strcpy(novoTeste.nome, outro);
	ReservarBilhete(&Passageiros, &novoTeste);

	/* ---> Receber o nome do passageiro */
	printf("\n\n--> Insira o nome do passageiro: ");
	scanf(" %s", outroNome);

	strcpy(novoTeste.nome, outroNome);
	ReservarBilhete(&Passageiros, &outroTeste);

	printf("%s\n", Passageiros->nome);
	printf("%s\n", Passageiros->prox->nome);
	printf("%s\n", Passageiros->prox->prox->nome);

	return 0;
}