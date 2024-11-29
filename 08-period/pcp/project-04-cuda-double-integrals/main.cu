#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define THREADS_PER_BLOCK 512

__global__ void add(int *a, int *b, int *result) {
  const int idx = threadIdx.x;
  result[idx] = a[idx] + b[idx];
}

int main() {
  int *a, *b, *result;
  int *dev_a, *dev_b, *dev_result;
  int size = THREADS_PER_BLOCK * sizeof(int);

  // Aloca os arrays no Device
  cudaMalloc((void **)&dev_a, size);
  cudaMalloc((void **)&dev_b, size);
  cudaMalloc((void **)&dev_result, size);

  a = (int *)malloc(size);
  b = (int *)malloc(size);
  result = (int *)malloc(size);

  srand(time(NULL));
  for (int i = 0; i < THREADS_PER_BLOCK; i++) {
    a[i] = i + 1;
    b[i] = i + 1;
  }

  cudaMemcpy(dev_a, a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(dev_b, b, size, cudaMemcpyHostToDevice);

  add << <1, THREADS_PER_BLOCK >> > (dev_a, dev_b, dev_result);

  cudaMemcpy(result, dev_result, size, cudaMemcpyDeviceToHost);

  printf("[");
  for (int i = 0; i < THREADS_PER_BLOCK; i++) {
    printf("%d, ", a[i]);
  }
  printf("]\n");

  printf("[");
  for (int i = 0; i < THREADS_PER_BLOCK; i++) {
    printf("%d, ", b[i]);
  }
  printf("]\n");

  printf("[");
  for (int i = 0; i < THREADS_PER_BLOCK; i++) {
    printf("%d, ", result[i]);
  }
  printf("]\n");

  free(a);
  free(b);
  free(result);

  cudaFree(dev_a);
  cudaFree(dev_b);
  cudaFree(dev_result);

  return 0;
}
