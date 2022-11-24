#include <stdio.h>
#include <stdlib.h>

struct graph
{
  int vertexes;
  int **adjMatrix;
};

typedef struct graph *Graph;

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

Graph cGraph(const int vertexes)
{
  int i;
  Graph g = (Graph)malloc(sizeof(struct graph));

  if (!g)
  {
    printf("\n!--> Erro ao alocar memória!\n\n");
    exit(1);
  }

  g->vertexes = vertexes;
  initAdjMatrix(g);
  return g;
}

void printAdjMatrix(Graph g)
{
  int i, j;

  printf("\n\n====== Matriz de Adjacência\n");

  for (i = 0; i < g->vertexes; i++)
  {
    for (j = 0; j < g->vertexes; j++)
      printf("%d ", g->adjMatrix[i][j]);
    printf("\n");
  }
}

int main()
{
  int i, j, r, vertexes;
  char resp;
  Graph myGraph;

  printf("\n--> Insira a quantidade de vértices do grafo:\t");
  r = scanf(" %d", &vertexes);

  if (!r || vertexes < 0)
  {
    printf("\n!--> Insira um valor válido!\n\n");
    exit(1);
  }

  myGraph = cGraph(vertexes); // Cria o grafo

  for (i = 0; i < vertexes; i++)
  {
    printf("\n--> Ligações do Vértice %02d:\n", i + 1);

    for (j = 0; j < vertexes; j++)
    {
      do
      {
        printf("\n\t--> Liga-se com o vértice %02d (s/n)?\t", j + 1);
        r = scanf(" %c", &resp);

        if (!r || (resp != 's' && resp != 'n'))
          printf("\n!--> Digite uma opção válida!\n\n");
      } while (!r || (resp != 's' && resp != 'n'));

      myGraph->adjMatrix[i][j] = (resp == 's') ? 1 : 0;
    }
  }

  printAdjMatrix(myGraph);

  return 0;
}