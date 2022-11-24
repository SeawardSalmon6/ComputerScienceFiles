#ifndef GRAFO_H
#define GRAFO_H

#include <vector>

typedef struct vertice
{
  int rotulo = -1;
  bool folha = true;
  struct vertice *adjacente = nullptr;
} vertice;

typedef struct
{
  int qtdeDeVertices;
  int qtdeDearestas;
  std::vector<vertice> listaDeAdjacencias;
} grafo;

grafo *criaGrafo(int n, int m);
void adicionaAresta(grafo *G, int u, int v);
void imprimeGrafo(grafo *G);
void deletaGrafo(grafo *G);

int grauVertice(grafo *G, int u);
int grauMaximo(grafo *G);

#endif // GRAFO_H