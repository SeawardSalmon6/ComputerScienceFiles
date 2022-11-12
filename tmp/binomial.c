#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
  double r, p, pr, F, num, *na;
  int i, j, n;
  
  srand(time(NULL));
  
  printf("\n--> Insira a quantidade de elementos aleatórios: ");
  scanf(" %d", &n);
  
  printf("\n--> Insira a probabilidade: ");
  scanf(" %lf", &p);
  
  na = (double*)malloc((n + 1) * sizeof(double));
  
  // Sets
  r = p / (1.0 - p);
  pr = pow(1.0 - p, n);
  F = pr;
  j = 0;
  
  while(j <= n) {
    na[j] = pr;
    
    pr = r * ((n - j) / (j + 1.0)) * pr;
    F += pr;
    
    j++;
  }
    
  printf("\n[ ");
  
  for(i = 0; i < n; i++)
    printf("%.8lf ", na[i]);
    
  printf(" ]\n");
  printf("\n--> Soma total: %lf\n", F);

  return 0;
}
