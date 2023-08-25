#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SHARED 1
#define MAXSIZE 2000 // Tamanho máximo da matriz
#define MAXWORKERS 4 // Número máximo de workers

pthread_mutex_t barrier; // Lock para a barreira
pthread_cond_t go;       // Variável condicional
int numWorkers;          // Número de worker threads
int numArrived = 0;      // Quantos estão na barreira

void *Worker(void *);
void Barrier(void);

int size, stripSize;
int sums[MAXWORKERS];
int matrix[MAXSIZE][MAXSIZE]; // Soma de cada workers

int main(int argc, char *argv[])
{
  int i, j;
  pthread_attr_t attr;
  pthread_t workerId[MAXWORKERS];

  pthread_attr_init(&attr);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

  pthread_mutex_init(&barrier, NULL);
  pthread_cond_init(&go, NULL);

  size = argc < 3 ? 10 : atoi(argv[1]);
  numWorkers = argc < 3 ? 2 : atoi(argv[2]);
  stripSize = size / numWorkers;

  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
      matrix[i][j] = 1;

  for (i = 0; i < numWorkers; i++)
    pthread_create(&workerId[i], &attr, Worker, (void *)(__intptr_t)i);

  pthread_exit(NULL);
}

void *Worker(void *arg)
{
  int myId = (__intptr_t)arg;
  int total, i, j, first, last;

  first = myId * stripSize;
  last = first + stripSize - 1;

  total = 0;
  for (i = first; i <= last; i++)
    for (j = 0; j < size; j++)
      total += matrix[i][j];
  sums[myId] = total;

  Barrier();

  if (myId == 0)
  {
    total = 0;
    for (i = 0; i < numWorkers; i++)
      total += sums[i];

    printf("\nThe total sum is %d\n\n", total);
  }

  return NULL;
}

void Barrier(void)
{
  pthread_mutex_lock(&barrier);
  numArrived++;

  if (numArrived < numWorkers)
    pthread_cond_wait(&go, &barrier);
  else
  {
    numArrived = 0;
    pthread_cond_broadcast(&go);
  }

  pthread_mutex_unlock(&barrier);
}