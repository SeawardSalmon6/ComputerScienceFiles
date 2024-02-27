#include <stdio.h>

#define ARRAY_SIZE 5

int main()
{
  int i;
  float soma = 0, vet[ARRAY_SIZE];

  // Leitura dos elementos do vetor
  printf("\n--> Informe %02d elementos em ponto flutuante:\n", ARRAY_SIZE);
  for (i = 0; i < ARRAY_SIZE; i++)
  {
    printf("\n -) Digite o elemento %02d: ", i + 1);
    scanf(" %f", &vet[i]);
    soma += vet[i];
  }

  // Impressão da soma dos elementos do vetor
  printf("\n\n-> A somatória dos elementos lidos do vetor é: %02.2f: ", soma);

  // Impressão dos elementos do vetor
  printf("\n\n-> Os elementos lidos (inversamente) do vetor são: ");
  for (i = ARRAY_SIZE - 1; i >= 0; i--)
    printf("%02.2f ", vet[i]);

  puts("\n");
  return 0;
}