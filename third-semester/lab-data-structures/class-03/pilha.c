#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

#define MAX 100
#define TRUE 1
#define FALSE 0
#define boolean int
#define indice int

// Implementação: Lista sequencial

// Estruturas e tipos
// -------------------------------
// Tipo chave
typedef int TipoChave;

// Tipo registro
typedef struct
{
  char nome[30];
  // .... (caso tenha mais campos)
} TipoDado;

// Tipo elemento (registro + chave)
typedef struct
{
  TipoChave chave;
  TipoDado info;
} TipoElem;

// Tipo pilha (sequencial)
typedef struct
{
  TipoElem arr[MAX + 1];
  indice topo;
} Pilha;

// Operações
// ---------------------
// Define (P): cria uma pilha P vazia
void Define(Pilha *pilha)
{
  pilha->topo = 0;
}

// Insere elem no topo P (empilhar)
boolean Push(TipoDado elem, Pilha *pilha)
{
  if (pilha->topo == MAX)
    return FALSE;

  pilha->topo++;
  pilha->arr[pilha->topo].info = elem;

  return TRUE;
}

// Teste se P é vazia
boolean Vazia(Pilha *pilha)
{
  return pilha->topo == 0;
}

// Acessa o elemento do topo da pilha (sem remover)
// OBS: testar antes se a pilha não está vazia
TipoElem Top(Pilha *pilha)
{
  if (!Vazia(pilha))
    return pilha->arr[pilha->topo];

  return;
}

// Remove o elemento no topo de P sem retornar valor (desempilha v.01)
// OBS: testar antes se a pilha não está vazia
void Pop_up(Pilha *pilha)
{
  if (!Vazia(pilha))
    pilha->topo--;
}

// Remove e retorna o elemento (todo o registro) eliminado (desempilha v.02)
// OBS: testar antes se a pilha não está vazia
TipoElem Pop_up(Pilha *pilha)
{
  if (!Vazia(pilha))
  {
    pilha->topo--;
    return pilha->arr[pilha->topo];
  }

  return;
}