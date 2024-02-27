#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SHARED 1

// Protótipo das duas threads
void *Producer(void *);
void *Consumer(void *);

sem_t empty, full; // Quando eu posso utilizar o valor e um para escrever
int data;          // Buffer compartilhado
int numIters;

int main(int argc, char *argv[])
{
  pthread_t pid, cid;  // ID dos threads
  pthread_attr_t attr; // Atributos comuns

  numIters = argc < 2 ? 5 : atoi(argv[1]);
  pthread_attr_init(&attr);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

  sem_init(&empty, SHARED, 1); // Sem. Empty = 1
  sem_init(&full, SHARED, 0);  // Sem. Full = 0

  pthread_create(&pid, &attr, Producer, NULL);
  pthread_create(&cid, &attr, Consumer, NULL);
  pthread_join(pid, NULL);
  pthread_join(cid, NULL);
}

void *Producer(void *arg)
{
  int produced;
  for (produced = 1; produced <= numIters; produced++)
  {
    sem_wait(&empty);
    data = produced;
    sem_post(&full);
  }

  return NULL;
}

void *Consumer(void *arg)
{
  int total = 0, consumed;

  for (consumed = 1; consumed <= numIters; consumed++)
  {
    sem_wait(&full);
    total = total + data;
    sem_post(&empty);
  }

  printf("The total is %d\n", total);
  return NULL;
}