#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main()
{
  int r, op, keys;

  do
  {
    do
    {
      printf("\n==== MENU");
      printf("\n(1) Inserir na Árvore-B");
      printf("\n(2) Buscar na Árvore-B");
      printf("\n(3) Mostrar Árvore-B");
      printf("\n(0) Encerrar");

      printf("\n\n--> Insira a opção desejada: ");
      r = scanf(" %d", &op);

      clearBuf();

      if (!r || op < 0 || op > 3)
        printf("\n!--> Insira uma opção válida!\n\n");
    } while (!r || op < 0 || op > 3);

    switch (op)
    {
    case 1:
      printf("\n--> Insira o valor a ser inserido: ");
      r = scanf(" %d", &keys);

      if (!r)
      {
        clearBuf();
        printf("\n!--> Insira um valor válido!\n\n");
      }
      else
        inserir(keys);

      break;

    case 2:
      printf("\n--> Insira o valor a ser buscado: ");
      r = scanf(" %d", &keys);

      if (!r)
      {
        clearBuf();
        printf("\n!--> Insira um valor válido!\n\n");
      }
      else if (procura(raiz, keys))
        printf("\n--> Valor encontrado!\n\n");
      else
        printf("\n--> O valor não foi encontado!\n\n");

      break;

    case 3:
      if (!raiz)
        printf("\n--> Árvore vazia!\n\n");
      else
        escreveArvBPorNivel(raiz);

      break;

    case 0:
      salvarArvore();
      printf("\n--> Obrigado por utilizar nosso programa! 😁\n\n");
      break;
    }
  } while (op != 0);

  return 0;
}