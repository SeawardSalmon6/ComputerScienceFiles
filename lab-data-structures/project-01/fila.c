#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Operações --------------------
void Definir(fila *q)
{
  q->inicio = 0;
  q->fim = 0;
}

boolean Vazia(fila *q)
{
  return (q->inicio == q->fim);
}

boolean Cheia(fila *q)
{
  return (q->inicio == ((q->fim + 1) % tam_fila));
}

boolean Inserir(fila *q, int elem)
{
  if (Cheia(q))
    return FALSE;

  q->fim = (q->fim + 1) % tam_fila;
  q->A[q->fim] = elem;
  return TRUE;
}

boolean Remover(fila *q, int *elem)
{
  if (Vazia(q))
    return FALSE;

  q->inicio = (q->inicio + 1) % tam_fila;
  *elem = q->A[q->inicio];

  return TRUE;
}

int Tamanho(fila *q)
{
  if (q->inicio <= q->fim)
    return (q->fim - q->inicio);

  return (tam_fila - (q->inicio - q->fim));
}

boolean Inicio_fila(fila *q, int elem)
{
  if (Vazia(q))
    return FALSE;

  elem = q->A[(q->inicio + 1) % tam_fila];

  return TRUE;
}

void Imprimir_elem(int elem)
{
  printf("%02d ", elem);
}

void Imprimir(fila *q)
{
  if (!Vazia(q))
  {
    int i = q->inicio + 1;

    printf("| ");
    while (i != q->fim + 1)
    {
      Imprimir_elem(q->A[i]);
      printf("| ");

      i = (i + 1) % tam_fila;
    }
  }
  else
    printf("--> Lista Vazia");

  printf("\n");
}

void Chamar_senhas(fila *norm, fila *pref)
{
  int elem;

  if (!Vazia(pref))
  {
    Remover(pref, &elem);
    printf("\n--> Elemento removido da Lista Preferencial: ");
    Imprimir_elem(elem);
  }
  else
    printf("\n--> A Lista Preferencial está vazia!");

  if (!Vazia(norm))
  {
    Remover(pref, &elem);
    printf("\n--> Elemento removido da Lista Normal: ");
    Imprimir_elem(elem);

    if (!Vazia(norm))
    {
      Remover(pref, &elem);
      printf("\n--> Elemento removido da Lista Normal: ");
      Imprimir_elem(elem);
    }
    else
      printf("\n--> A Lista Normal está vazia!");
  }
  else
    printf("\n--> A Lista Normal está vazia!");

  printf("\n");
}