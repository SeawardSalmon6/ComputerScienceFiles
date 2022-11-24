#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include "grafo.h"

int **criarMatrizDeAdjacencia(grafo *G)
{
  vertice *x;
  int **m, i, j;
  m = (int **)malloc(G->qtdeDeVertices * sizeof(int *));

  for (i = 0; i < G->qtdeDeVertices; i++)
    m[i] = (int *)calloc(G->qtdeDeVertices, sizeof(int));

  for (i = 0; i < G->qtdeDeVertices; i++)
  {
    x = &G->listaDeAdjacencias[i]; // Linha da matriz
    x = x->adjacente;

    while (!x->folha)
    {
      j = x->rotulo;
      m[i][j] = 1;
      x = x->adjacente;
    }
  }

  for (i = 0; i < G->qtdeDeVertices; i++)
  {
    for (j = 0; j < G->qtdeDeVertices; j++)
      printf("%d ", m[i][j]);
    printf("\n");
  }

  return m;
}

int main()
{
  int n, m;
  int u, v;
  grafo *G;

  scanf("%d %d", &n, &m);
  G = criaGrafo(n, m);

  while (m--)
  {
    scanf("%d %d", &u, &v);
    adicionaAresta(G, u, v);
  }

  std::cout << grauVertice(G, 0) << std::endl;
  imprimeGrafo(G);
  criarMatrizDeAdjacencia(G);
  // deletaGrafo(G);

  return 0;
}