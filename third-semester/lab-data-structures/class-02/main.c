#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Definição do comando limpa_tela
#ifdef _WIN32
#define LIMPA_TELA "cls"
#else
#define LIMPA_TELA "clear"
#endif

void pause()
{
	puts("\n\nPressione uma tecla para continuar...\n");
	getchar();
	scanf("c\n");
}

int main()
{
	int posicao, opMenu = 0;
	Lista *minhaLista;

	// Inicializa a lista
	Definir(minhaLista);

	do
	{
		system(LIMPA_TELA);

		printf("\n========== MENU PRINCIPAL");
		printf("\n(1) Inserir Elemento de Maneira Ordenada");
		printf("\n(2) Remover o Elemento na Posição N");
		printf("\n(3) Apresentar um Elemento na Posição N");
		printf("\n(4) Encontrar um Elemento com Busca Simples");
		printf("\n(5) Apresentar a Lista Inteira");
		printf("\n(6) Apagar a Lista");
		printf("\n(9) Sair");

		printf("\n\n--> Digite a opção desejada: ");
		scanf(" %d", &opMenu);

		switch (opMenu)
		{
		case 1:
			system(LIMPA_TELA);

			TipoElem novoElemento;

			printf("\n========== INSERIR ORDENADAMENTE");
			printf("\n\n--> Digite o valor do elemento: ");
			scanf(" %d", &novoElemento.chave);

			printf("\n--> Digite o nome da informação: ");
			scanf(" %s", novoElemento.info.nome);

			Inserir_ord(novoElemento, minhaLista);
			printf("\n--> Elemento inserido com sucesso!");

			pause();
			break;
		case 2:
			system(LIMPA_TELA);

			printf("\n========== REMOVER ELEMENTO NA POSIÇÃO N");

			do
			{
				printf("\n\n--> Insira a posição do elemento a ser removido: ");
				scanf(" %d", &posicao);

				if (posicao <= 0)
					printf("\n\n==!== Insira um valor válido maior que 0 e menor que a quantidade de elementos da lista (no momento: %d)!\n", minhaLista->nelem);

			} while (posicao <= 0 && posicao > minhaLista->nelem);

			Impr_elem(minhaLista->arr[posicao]);
			Remover_posic(&posicao, minhaLista);
			printf("\n--> Elemento removido com sucesso!");

			pause();
			break;
		case 3:
			system(LIMPA_TELA);

			printf("\n========== APRESENTAR ELEMENTO NA POSIÇÃO N");

			do
			{
				printf("\n\n--> Insira a posição do elemento a ser apresentado: ");
				scanf(" %d", &posicao);

				if (posicao <= 0)
					printf("\n\n==!== Insira um valor válido maior que 0 e menor que a quantidade de elementos da lista (no momento: %d)!\n", minhaLista->nelem);

			} while (posicao <= 0 && posicao > minhaLista->nelem);

			Impr_elem(minhaLista->arr[posicao]);

			pause();
			break;
		case 4:
			system(LIMPA_TELA);

			TipoChave chave;
			posicao = -1;

			printf("\n========== BUSCA SIMPLES");

			printf("\n\n--> Insira o valor da chave do elemento a ser encontrado: ");
			scanf(" %d", &chave);

			Buscar(chave, minhaLista, &posicao);

			if (posicao == -1)
				printf("\n--> O elemento não foi encontrado!");
			else
			{
				printf("\n--> Elemento encontrado com sucesso!");
				Impr_elem(minhaLista->arr[posicao]);
			}

			pause();
			break;
		case 5:
			system(LIMPA_TELA);

			printf("\n========== LISTA COMPLETA");
			Imprimir(minhaLista);

			pause();
			break;
		case 6:
			system(LIMPA_TELA);
			Apagar(minhaLista);

			printf("\n\n--> Lista apagada com sucesso!");

			pause();
			break;
		case 9:
			break;
		default:
			printf("\n\n==!== Insira uma opção válida!\n");
			break;
		}
	} while (opMenu != 9);

	return 0;
}