#include <stdio.h>
#include <stdlib.h>

struct graph
{
  int id;
  int vertexes;
  int **adjMatrix;
};

typedef struct graph *Graph;

Graph cGraph(const int id)
{
  int i;
  Graph g = (Graph)malloc(sizeof(struct graph));

  if (!g)
  {
    printf("\n!--> Erro ao alocar memória!\n\n");
    exit(1);
  }

  g->id = id;
  g->vertexes = 0;
  g->adjMatrix = NULL;
  return g;
}

void initAdjMatrix(Graph g)
{
  int i, j;

  if (!g || g->vertexes <= 0)
  {
    printf("\n!--> Grafo nulo ou quantidade de vértices inválida!\n\n");
    exit(1);
  }

  g->adjMatrix = (int **)calloc(g->vertexes, sizeof(int *));

  if (!g->adjMatrix)
  {
    printf("\n!--> Erro ao alocar memória para a matriz!\n\n");
    exit(1);
  }

  for (i = 0; i < g->vertexes; i++)
  {
    g->adjMatrix[i] = (int *)calloc(g->vertexes, sizeof(int));

    if (!g->adjMatrix[i])
    {
      printf("\n!--> Erro ao alocar memória para a matriz!\n\n");
      exit(1);
    }
  }
}

int main()
{
  Graph myGraph;

  myGraph = cGraph(1);
  myGraph->vertexes = 5;

  initAdjMatrix(myGraph);

  for (int i = 0; i < myGraph->vertexes; i++)
  {
    for (int j = 0; j < myGraph->vertexes; j++)
      printf("%d ", myGraph->adjMatrix[i][j]);
    printf("\n");
  }

  return 0;
}