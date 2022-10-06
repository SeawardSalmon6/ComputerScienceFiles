#include <stdio.h>

#define ARRAY_SIZE 5

int main()
{
  int i, vet[ARRAY_SIZE];

  // Leitura dos elementos do vetor
  printf("\n--> Informe %d elementos inteiros:\n", ARRAY_SIZE);
  for (i = 0; i < ARRAY_SIZE; i++)
  {
    printf("\n -) Digite o elemento %.0d: ", i + 1);
    scanf(" %d", &vet[i]);
  }

  // Impressão dos elementos do vetor
  printf("\n\n-> Os elementos lidos do vetor são: ");
  for (i = 0; i < ARRAY_SIZE; i++)
    printf("%d ", vet[i]);

  puts("\n");
  return 0;
}