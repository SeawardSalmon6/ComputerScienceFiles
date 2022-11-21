#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// --> ============= Método Shell Sort
void shellSort(unsigned int *vetor, const int tamanho)
{
  int valorASerTrocado,
      indiceGap,
      posicaoDoValorTrocado,
      indiceValorTestado;

  for (indiceGap = tamanho / 2; indiceGap > 0; indiceGap /= 2)
    for (indiceValorTestado = indiceGap; indiceValorTestado < tamanho; indiceValorTestado++)
    {
      valorASerTrocado = vetor[indiceValorTestado]; // --> Atribuir a valor da posição a ser testado
      posicaoDoValorTrocado = indiceValorTestado;   // --> Marca o valor inicial de j para esta iteração

      // --> Realiza as comparações já fazendo as devidas inserções
      // --> Executa enquanto a valor testado >= ao valor anterior testado
      while (posicaoDoValorTrocado - indiceGap >= 0 && vetor[posicaoDoValorTrocado - indiceGap] > valorASerTrocado)
      {
        vetor[posicaoDoValorTrocado] = vetor[posicaoDoValorTrocado - indiceGap];
        posicaoDoValorTrocado = posicaoDoValorTrocado - indiceGap; // --> Atualiza o índice para o próximo loop
      }

      if (posicaoDoValorTrocado != indiceValorTestado) // --> Se houveram trocas, insere o valor testado na posição correta
        vetor[posicaoDoValorTrocado] = valorASerTrocado;
    }
}

double calcularTempoDecorrido(clock_t b, clock_t e)
{
  return (double)(e - b) / CLOCKS_PER_SEC;
}

int main()
{
  clock_t comeco, fim;
  unsigned int i, j, num, exp, tamanho, *vetor;
  FILE *fp = fopen("sorted.txt", "w");
  FILE *fpe = fopen("unsorted.txt", "w");

  if (!fp || !fpe)
  { // --> Se não abrir o aqruivo, encerra o programa
    printf("\n!--> Erro ao abrir o arquivo!!\n\n");
    return 1;
  }

  srand(time(NULL)); // --> Seta a semente do rand()

  printf("\n--> Insira a um número menor que 30: \t");
  if (!scanf(" %d", &exp) || exp < 0 || exp > 30)
  { // --> Se a quantidade for negativa ou não for um número, encerra o programa
    printf("\n!--> Insira um valor válido!!\n\n");
    return 1;
  }

  tamanho = pow(2, exp);

  printf("\n--> Quantidade de Elementos Totais:\t%02d", tamanho);

  vetor = (unsigned int *)malloc(tamanho * sizeof(unsigned int)); // --> Aloca memória para o vetor
  for (i = 1, j = 1; i <= tamanho; i++)
  {
    num = (i % 2) ? pow(2, exp - 1) + j : j++;
    vetor[i - 1] = num;
    fprintf(fpe, "%d\n", num);
  }
  // --> printf("\n\n");

  comeco = clock();          // --> Anota o início da ordenação
  shellSort(vetor, tamanho); // --> Ordena com o Shell-Sort
  fim = clock();             // --> Anota o ponto de fim da ordenação

  // --> Calcula o tempo total da ordenação
  printf("\n\n--> Tempo Decorrido para a Ordenação:\t%.5lf\n", calcularTempoDecorrido(comeco, fim));

  // --> printf("\n--> Sorted: \n");
  comeco = clock(); // --> Anota o início da escrita
  for (i = 0; i < tamanho; i++)
  {
    fprintf(fp, "%d\n", vetor[i]);
    // --> printf("%d\n", vet[i]);
  }
  fclose(fp);
  fim = clock(); // --> Anota o fim da escrita
  // --> printf("\n\n");

  // --> Apresenta o tempo total para a escrita do arquivo com os números ordenados
  printf("\n--> Tempo Decorrido para Escrita do Arquivo:\t%.5lf\n\n", calcularTempoDecorrido(comeco, fim));

  return 0;
}
