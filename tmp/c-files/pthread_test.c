#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10

int arr[SIZE];

void *function(void *arg) {
  int thread_id = (size_t)arg;
  int i;

  if (thread_id == 1) {
    printf("Thread 1 running...\n");
    for (i = 0; i < SIZE / 2; i++) {
      arr[i] = 1;
    }
  } else if (thread_id == 2) {
    printf("Thread 2 running...\n");
    for (i = SIZE / 2; i < SIZE; i++) {
      arr[i] = 2;
    }
  }

  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t p1, p2;
  int i;

  pthread_create(&p1, NULL, function, (void *)1);
  pthread_create(&p2, NULL, function, (void *)2);

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);

  for (i = 0; i < SIZE; i++) {
    if (i == SIZE / 2) {
      printf("\n");
    }

    printf("%d\t", arr[i]);
  }

  printf("\n");

  return 0;
}