#include "grafo.h"
#include <climits>
#include <iostream>

grafo *criaGrafo(int vertices, int arestas)
{
  grafo *G = new grafo;
  G->qtdeDeVertices = vertices;
  G->qtdeDeArestas = arestas;
  G->listaDeAdjacencias.resize(vertices);
  return G;
}

void adicionaAresta(grafo *G, int u, int v)
{
  vertice *ultimo = &G->listaDeAdjacencias[u];
  vertice *novaFolha;

  if (ultimo->folha)
  {
    novaFolha = new vertice;
    novaFolha->rotulo = -1;
    novaFolha->folha = true;
    novaFolha->adjacente = nullptr;

    ultimo->rotulo = u;
    ultimo->folha = false;
    ultimo->adjacente = novaFolha;
  }

  while (!ultimo->folha)
  {
    if (ultimo->rotulo == v)
      return;
    ultimo = ultimo->adjacente;
  }

  novaFolha = new vertice;
  novaFolha->rotulo = -1;
  novaFolha->folha = true;
  novaFolha->adjacente = nullptr;

  ultimo->rotulo = v;
  ultimo->folha = false;
  ultimo->adjacente = novaFolha;

  /////////////////----/////////////////////

  ultimo = &G->listaDeAdjacencias[v];

  if (ultimo->folha)
  {
    novaFolha = new vertice;
    novaFolha->rotulo = -1;
    novaFolha->folha = true;
    novaFolha->adjacente = nullptr;

    ultimo->rotulo = v;
    ultimo->folha = false;
    ultimo->adjacente = novaFolha;
  }

  while (!ultimo->folha)
  {
    if (ultimo->rotulo == u)
      return;
    ultimo = ultimo->adjacente;
  }

  novaFolha = new vertice;
  novaFolha->rotulo = -1;
  novaFolha->folha = true;
  novaFolha->adjacente = nullptr;

  ultimo->rotulo = u;
  ultimo->folha = false;
  ultimo->adjacente = novaFolha;
}

void imprimeGrafo(grafo *G)
{
  for (vertice v : G->listaDeAdjacencias)
  {
    std::cout << v.rotulo << " -> ";

    v = *v.adjacente;

    while (!v.folha)
    {
      std::cout << v.rotulo << " ";
      v = *v.adjacente;
    }
    std::cout << std::endl;
  }
}

void deletaGrafo(grafo *G)
{
  vertice *x, *y;
  for (int indiceDoVertice = 0; indiceDoVertice < G->qtdeDeVertices;
       indiceDoVertice++)
  {
    x = &G->listaDeAdjacencias[indiceDoVertice];
    while (x)
    {
      y = x->adjacente;
      delete x;
      x = nullptr;
      x = y;
    }
  }
  delete G;
}

int grauVertice(grafo *G, int indice)
{
  int grau = 0;

  vertice v = G->listaDeAdjacencias[indice];
  v = *v.adjacente;
  while (!v.folha)
  { // Theta(dg(v) ou O(V(G))
    grau++;
    v = *v.adjacente;
  }
  return grau;
}

int grauMaximo(grafo *G)
{
  int max = INT_MIN; // Theta(1)
  int temp;          // Theta(1)
  for (auto v : G->listaDeAdjacencias)
  {                                  // Theta(V(G)+dg(G)) ou Theta(V(G)+A(G))
    temp = grauVertice(G, v.rotulo); // O(V(G))
    if (max < temp)
      max = temp; // Theta(1)
  }

  return max; // Theta(1)
}

void imprimeMatrizDeAdjacencia(int **matriz, const int tamanho)
{
  int i, j;

  printf("\n");
  for (i = 0; i < tamanho; i++)
  {
    for (j = 0; j < tamanho; j++)
      printf("%d\t", matriz[i][j]);
    printf("\n");
  }
}

int **criarMatrizDeAdjacencia(grafo *G)
{
  int **m, i, j;
  m = (int **)malloc(G->qtdeDeVertices * sizeof(int *));

  for (i = 0; i < G->qtdeDeVertices; i++)
    m[i] = (int *)calloc(G->qtdeDeVertices, sizeof(int));

  i = 0;
  for (vertice x : G->listaDeAdjacencias)
  {
    x = *x.adjacente;

    while (!x.folha)
    {
      j = x.rotulo;
      m[i][j] = 1;
      x = *x.adjacente;
    }

    i++;
  }

  return m;
}

void removerAresta(int **mat, const int u, const int v)
{
  if (mat[u][0] < 0 || mat[v][0] < 0)
    return;

  mat[u][v] = 0;
  mat[v][u] = 0;
}

void removerVertice(int **mat, const int u, const int tamanho)
{
  int i;

  if (mat[u][0] < 0)
    return;

  for (i = 0; i < tamanho; i++)
  {
    mat[u][i] = -1;
    mat[i][u] = -1;
  }
}