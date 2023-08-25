#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include "grafo.h"

int main()
{
  int n, m, **mat;
  int u, v, r, op;
  char c;
  grafo *G;

  do
  {
    r = scanf("%d %d", &n, &m);

    while ((c = getchar()) == '\n' && c == EOF)
      ;

    if (!r || n < 0 || m < 0)
      printf("\n--> Valor inválido!\n\n");

  } while (!r || n < 0 || m < 0);

  G = criaGrafo(n, m);

  while (m--)
  {
    do
    {
      r = scanf("%d %d", &u, &v);

      while ((c = getchar()) == '\n' && c == EOF)
        ;

      if (!r || (u < 0 || u >= G->qtdeDeVertices) || (v < 0 || v >= G->qtdeDeVertices))
        printf("\n--> Valor inválido!\n\n");

    } while (!r || (u < 0 || u >= G->qtdeDeVertices) || (v < 0 || v >= G->qtdeDeVertices));
    adicionaAresta(G, u, v);
  }

  std::cout << grauVertice(G, 0) << std::endl;
  imprimeGrafo(G);
  mat = criarMatrizDeAdjacencia(G);

  do
  {
    std::cout << "\n==== MENU";
    std::cout << "\n(1) Imprimir matriz";
    std::cout << "\n(2) Remover aresta";
    std::cout << "\n(3) Remover vértice";
    std::cout << "\n(0) Encerrar";

    std::cout << "\n\nDigite a opção: ";
    r = scanf(" %d", &op);

    while ((c = getchar()) == '\n' && c == EOF)
      ;

    switch (op)
    {
    case 1:
      imprimeMatrizDeAdjacencia(mat, G->qtdeDeVertices);
      break;
    case 2:
      do
      {
        printf("\n");
        r = scanf("%d %d", &u, &v);

        while ((c = getchar()) == '\n' && c == EOF)
          ;

        if (!r || (u < 0 || u >= G->qtdeDeVertices) || (v < 0 || v >= G->qtdeDeVertices))
          printf("\n--> Valor inválido!\n\n");

      } while (!r || (u < 0 || u >= G->qtdeDeVertices) || (v < 0 || v >= G->qtdeDeVertices));

      removerAresta(mat, u, v);
      break;
    case 3:
      do
      {
        printf("\n");
        r = scanf(" %d", &u);

        while ((c = getchar()) == '\n' && c == EOF)
          ;

        if (!r || (u < 0 || u >= G->qtdeDeVertices))
          printf("\n--> Valor inválido!\n\n");

      } while (!r || (u < 0 || u >= G->qtdeDeVertices));

      removerVertice(mat, u, G->qtdeDeVertices);
      break;
    case 0:
      printf("\n--> Fim!\n\n");
      break;
    default:
      printf("\n--> Valor inválido!\n\n");
      break;
    }
  } while (op != 0);

  free(mat);
  deletaGrafo(G);

  return 0;
}