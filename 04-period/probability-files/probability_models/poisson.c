#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
  double p, F, lambda, *na;
  int i, j, n;
  
  srand(time(NULL));
  
  printf("\n--> Insira a quantidade de variações do experimento: ");
  scanf(" %d", &n);
  
  printf("\n--> Insira o valor do lambda: ");
  scanf(" %lf", &lambda);
  
  na = (double*)malloc((n + 1) * sizeof(double));
  
  // Sets
  p = exp(-lambda);
  F = p;
  j = 0;
  
  while(j <= n) {
    na[j] = p;
    
    p = p * lambda / (j + 1);
    F += p;
    
    j++;
  }
    
  printf("\n[ ");
  
  for(i = 0; i < n; i++)
    printf("%.5lf ", na[i]);
    
  printf(" ]\n");
  printf("\n--> Soma total: %lf\n", F);

  return 0;
}
