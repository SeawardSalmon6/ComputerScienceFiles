#include "grafo.h"
#include <climits>
#include <iostream>

grafo *criaGrafo(int vertices, int arestas)
{
  grafo *G = new grafo;
  G->qtdeDeVertices = vertices;
  G->qtdeDearestas = arestas;
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