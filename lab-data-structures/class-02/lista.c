#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

#define MAX 100
#define TRUE 1
#define FALSE 0
#define boolean int

// Implementação: Lista sequencial

// Estruturas e tipos
// -------------------------------
// Tipo chave
typedef int TipoChave;

// Tipo registro
typedef struct
{
  char nome[30];
  // ... caso tenham mais campos
} TipoDado;

// Tipo elemento (registro + chave)
typedef struct
{
  TipoChave chave;
  TipoDado info;
} TipoElem;

// Tipo Lista (sequencial)
typedef struct
{
  int nelem; // número de elementos
  TipoElem arr[MAX + 1];
} Lista;

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

boolean Inserir_posic(TipoElem x, int pos, Lista *lista)
{
  /* Insere x, que é um novo elemento na posição pos da Lista.
    Se L = a_1, a_2, ...., a_n, então temos a_1, a_2, ...., a_{pos-1}, x, a_{pos+1}, ..., an.
    Develove true se sucesso, false c.c. (isto é: L não tem nenhuma posição pos ou Lista cheia).
  OBS: Operação para Lista NAO-ORDENADA. */
  int q;

  if (Cheia(lista) || pos > lista->nelem + 1 || pos < 1)
  {
    // Lista cheia ou posição inexistente
    return FALSE;
  }
  else
  {
    // Copia vizinho pos/ direita
    for (q = lista->nelem; q >= pos; q--)
    {
      lista->arr[q + 1] = lista->arr[q];
    }

    lista->arr[pos] = x;
    lista->nelem++;

    return TRUE; // Inserção realizada com sucesso
  }
}

boolean Buscar(TipoChave x, Lista *lista, int *pos)
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
      if (lista->arr[i].chave == x)
      {
        *pos = i;
        return TRUE;
      }
      else
      {
        i++;
      }
    }
  }

  return FALSE; // Retorna false se não encontrou (ou Lista vazia)
}

void Remover_posic(int *pos, Lista *lista)
{
  /* Só é ativada após a busca ter retornado a posição pos do elemento a ser removido */
  int i;

  for (i = *pos + 1; i < lista->nelem; i++)
  {
    lista->arr[i - 1] = lista->arr[i];
  }

  lista->nelem--;
}

void Impr_elemn(TipoElem x)
{
  printf("Chave: %d\n", x.chave);
  printf("Nome: %d\n", x.info.nome);
}

void Imprimir(Lista *lista)
{
  // Imprime os elementos na sua ordem de precendencia
  int i;
  if (!Vazia(lista))
  {
    for (i = 1; i < lista->nelem; i++)
    {
      Impr_elem(lista->arr[i]);
    }
  }
}

int Tamanho(Lista *lista)
{
  // Retorna o tamanho da Lista. se L é vazia, retorn false
  return lista->nelem;
}

boolean Inserir_ord(TipoElem x, Lista *lista)
{
  /* Insere novo elemento de form a a manter a lista ordenada (crescente).
    Devolve true (se sucesso), false c.c. */
  int i = 1;

  if (Vazia(lista))
  {
    return Inserir_posic(x, i, lista);
  }
  else
  {
    while (i <= lista->nelem) // Encontra a posição de inserção
    {
      if (x.chave < lista->arr[i].chave)
      {
        return Inserir_posic(x, i, lista);
      }
      else
      {
        i++;
      }
    }
    return Inserir_posic(x, i, lista); // Última posição
  }
}