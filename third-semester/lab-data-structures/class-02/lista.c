#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

// Implementação: Lista sequencial
// Operações
// -----------------------------------
boolean Vazia(Lista *lista)
{
	// Retorna true (1): se vazia, false (0), caso contrário
	return (lista->nelem == 0);
}

boolean Cheia(Lista *lista)
{
	// Retorna true (1): se vazia, false (0), caso contrário
	return (lista->nelem == MAX);
}

void Definir(Lista *lista)
{
	/* Cria uma Lista vazia.
		Este procedimento deve ser chamado para cada nova Lista antes de qualquer outra operação. */
	lista->nelem = 0;
	lista->arr[0].chave = 0;
}

void Apagar(Lista *lista)
{
	// Apaga "logicamente" uma Lista
	lista->nelem = 0;
}

boolean Inserir_posic(TipoElem novoElem, int pos, Lista *lista)
{
	/* Insere x, que é um novo elemento na posição pos da Lista.
		Se L = a_1, a_2, ...., a_n, então temos a_1, a_2, ...., a_{pos-1}, x, a_{pos+1}, ..., an.
		Develove true se sucesso, false c.c. (isto é: L não tem nenhuma posição pos ou Lista cheia).
	OBS: Operação para Lista NAO-ORDENADA. */
	int q;

	if (Cheia(lista) || pos > lista->nelem + 1 || pos < 1)
		// Lista cheia ou posição inexistente
		return FALSE;
	else
	{
		// Copia vizinho pos/ direita
		for (q = lista->nelem; q >= pos; q--)
			lista->arr[q + 1] = lista->arr[q];

		lista->arr[pos] = novoElem;
		lista->nelem++;

		return TRUE; // Inserção realizada com sucesso
	}
}

boolean Buscar(TipoChave chaveBuscada, Lista *lista, int *pos)
{
	/* Retorna true, se x ocorre na posição pos. Se x ocorre
		mais de uma vez, retorna a posição da primeira ocorrência.
		Se x não ocorre, retorna false.
	OBS: Lista NAO-ORDENADA */

	if (!Vazia(lista))
	{
		int i = 1;
		while (i <= lista->nelem)
		{
			if (lista->arr[i].chave == chaveBuscada)
			{
				*pos = i;
				return TRUE;
			}

			i++;
		}
	}

	return FALSE; // Retorna false se não encontrou (ou Lista vazia)
}

void Remover_posic(int *pos, Lista *lista)
{
	/* Só é ativada após a busca ter retornado a posição pos do elemento a ser removido */
	int i;

	for (i = *pos + 1; i < lista->nelem; i++)
		lista->arr[i - 1] = lista->arr[i];

	lista->nelem--;
}

void Impr_elem(TipoElem elem)
{
	printf("\nChave: %d\n", elem.chave);
	printf("Nome: %s\n", elem.info.nome);
	printf("--------------------\n");
}

void Imprimir(Lista *lista)
{
	// Imprime os elementos na sua ordem de precendencia
	int i;
	if (!Vazia(lista))
	{
		printf("\n");
		for (i = 1; i <= lista->nelem; i++)
			Impr_elem(lista->arr[i]);
	}
}

int Tamanho(Lista *lista)
{
	// Retorna o tamanho da Lista. se L é vazia, retorn false
	return lista->nelem;
}

boolean Inserir_ord(TipoElem novoElem, Lista *lista)
{
	/* Insere novo elemento de form a a manter a lista ordenada (crescente).
		Devolve true (se sucesso), false c.c. */
	int i = 1;

	if (Vazia(lista))
		return Inserir_posic(novoElem, i, lista);

	while (i <= lista->nelem) // Encontra a posição de inserção
	{
		if (novoElem.chave < lista->arr[i].chave)
			return Inserir_posic(novoElem, i, lista);

		i++;
	}

	return Inserir_posic(novoElem, i, lista); // Última posição
}

boolean Buscar_ord(TipoChave chaveBuscada, Lista *lista, int *pos)
{
	/* */

	// Implementação de busca linear simples
	if (!Vazia(lista))
	{
		int i = 1;
		while (i <= lista->nelem)
		{
			if (lista->arr[i].chave >= chaveBuscada)
			{
				if (lista->arr[i].chave == chaveBuscada)
				{
					*pos = i;
					return TRUE;
				}

				return FALSE; // Encontrou maior, então
			}

			i++;
		}
	}

	return FALSE; // Não encontrou
}

boolean Busca_bin(TipoChave chaveBuscada, Lista *lista, int *pos)
{
	/* Retorna em pos, a posição da chaveBuscada na lista ORDENADA e true.
		Se a chave não ocorre, retorna false */

	// Implementação da busca binária
	int inf = 1;			// Posição inferior
	int sup = lista->nelem; // Posição superior
	int meio;

	while (sup >= inf)
	{
		meio = (inf + sup) / 2;

		if (lista->arr[meio].chave == chaveBuscada)
		{
			*pos = meio;
			return TRUE; // Sai da busca
		}
		else
		{
			if (lista->arr[meio].chave < chaveBuscada)
				inf = meio + 1;
			else
				sup = meio - 1;
		}
	}

	return FALSE; // Não encontrou
}

boolean Remover_ch(TipoChave chaveBuscada, Lista *lista)
{
	/* Remoção dada a chave. Retorna true, se removeu, ou false caso contrário */
	int *pos;

	if (Busca_bin(chaveBuscada, lista, pos)) // Procura via busca binária
	{
		Remover_posic(pos, lista);
		return TRUE;
	}

	return FALSE;
}