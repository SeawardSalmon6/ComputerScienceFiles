#include <stdlib.h>
#include <stdio.h>

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