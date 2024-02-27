#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  double *na;
  int i, n;
  
  srand(time(NULL));
  
  printf("\n--> Insira a quantidade de elementos aleatórios: ");
  scanf(" %d", &n);
  
  na = (double*)malloc(n * sizeof(double));
  
  for(i = 0; i < n; i++)
    na[i] = 1.0 / (rand() % 100) + (rand() % 10 * 0.1);
    
  printf("\n[ ");
  
  for(i = 0; i < n; i++)
    printf("%.8lf ", na[i]);
    
  printf(" ]\n");
    
  printf("\n[ ");
  
  for(i = 0; i < n; i++)
    printf("%d ", na[i] < 0.5 ? 0 : 1);
    
  printf(" ]\n\n");

  return 0;
}
