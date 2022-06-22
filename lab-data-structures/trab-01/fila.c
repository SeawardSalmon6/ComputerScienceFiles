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

void Imprimir_elem(fila *q, int elem)
{
  printf("\n\t------ Sua Senha: %02d", elem);
}

void Imprimir(fila *q)
{
  int i = q->inicio;
  while (i != q->fim)
  {
    Imprimir_elem(q, q->A[i]);
    i = (i + 1) % tam_fila;
  }
}

void Chamar_senhas(fila *norm, fila *pref)
{
  int elem;

  if (!Vazia(pref))
  {
    Remover(pref, &elem);
    Imprimir_elem(pref, elem);
  }

  if (!Vazia(norm))
  {
    Remover(norm, &elem);
    Imprimir_elem(norm, elem);

    if (!Vazia(norm))
    {
      Remover(norm, &elem);
      Imprimir_elem(norm, elem);
    }
  }
}