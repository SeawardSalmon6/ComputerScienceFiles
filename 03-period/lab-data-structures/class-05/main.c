#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Connection Matrix size and distances array
#define N 5

// ----------------- Main Program
// Matrix A: represents the connections between cities 0..(N - 1)
// Distances Array: dist[i] it's the distance from city C to i
int main()
{
  // Defining cities matrix
  int connections[N][N] = {
      {0, 1, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1},
      {0, 0, 1, 0, 1},
      {0, 1, 0, 0, 0}};

  int distances[N];
  int i, j, c = 4;
  Queue *queue = (Queue *)malloc(sizeof(Queue));

  for (i = 0; i < N; i++)
    distances[i] = N; // Sets distances[i] = infinite, for every i

  distances[c] = 0;
  defineQueue(queue);      // Creates an empty queue
  insertInQueue(queue, c); // Inserts the city 'c' into the queue

  // Roda até que todos os nós tenham sido checados
  // Tira da fila uma cidade i, e coloca na fila as cidades vizinhas j com distância não computadas
  while (!isQueueEmpty(queue))
  {
    removeFromQueue(queue, &i);
    for (j = 0; j < N; j++)
    {
      if (connections[i][j] == 1 && distances[j] >= N)
      {
        distances[j] = distances[i] + 1;
        insertInQueue(queue, j);
      }
    }
  }

  // Imprime o vetor
  for (i = 0; i < N; i++)
    printf("[%d] = %d\n", i, distances[i]);

  return 0;
}