#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10

int counter = 0, vetPilha[MAX] = { 0 };

void adicionaValor(void) {
	int valPilha = 0;

	printf("\nInsira um valor inteiro para adicionarmos à pilha: ");
	scanf(" %d", &valPilha);
				
	vetPilha[counter] = valPilha;
	counter++;
}

void removeValor(void) {
	counter--;
	
	for(int i = 0; i < MAX - 1; i++) {
		if(counter == 0)
		    vetPilha[0] = 0;
		else if(i + 1 >= counter)
			vetPilha[i + 1] = 0;
		else
		    vetPilha[i] = vetPilha[i + 1];
	}
}

void printPilha(void) {
	printf("\n==== PILHA ATUAL ====");
	
	for(int i = MAX - 1; i >= 0; i--)
		printf("\n| %d |", vetPilha[i]);
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int opcao;

	do {
		system("clear");

		printf("\n======== MENU ========");
		printf("\n1- Adicionar Valor à Pilha");
		printf("\n2- Remover Valor da Pilha");
		printf("\n3- Encerrar");

		printf("\n\nEscolha uma opção: ");
		scanf(" %d", &opcao);

		switch(opcao) {
			case 1:
				if(counter < MAX)
					adicionaValor();
				else
					printf("\n\nAVISO: A pilha está cheia! Remova um valor para continuar!\n");
				
				printPilha();
				break;
			case 2:
				if(counter >= 1)
					removeValor();
				else
					printf("\n\nAVISO: A pilha está vazia! Adicione um valor para continuar!\n");

				printPilha();
				break;
			case 3:
				printPilha();
				printf("\n\nFim da execução\n\n");
				break;
			default:
				printf("\nAVISO: Escolha uma opção válida!");
				break;
		}

		// equivalente a system("pause")
		if(opcao != 3) {
			puts("\n\nPressione uma tecla para continuar...");
			getchar(); scanf("c\n");
		}

	} while(opcao != 3);

	return 0;
}