#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// --> ============= Método Shell Sort
void shellSort(unsigned int *vetor, const int tamanho)
{
  int gap,
      indicePivoInicial,
      valorASerTrocado,
      indiceDoValorTrocado;

  for (gap = tamanho / 2; gap > 0; gap /= 2)
    for (indicePivoInicial = gap; indicePivoInicial < tamanho; indicePivoInicial++)
    {
      valorASerTrocado = vetor[indicePivoInicial]; // --> Atribuir a valor da posição a ser testado
      indiceDoValorTrocado = indicePivoInicial;    // --> Marca o valor inicial de j para esta iteração

      // --> Realiza as comparações já fazendo as devidas inserções
      // --> Executa enquanto a valor testado >= ao valor anterior testado
      while (indiceDoValorTrocado - gap >= 0 && vetor[indiceDoValorTrocado - gap] > valorASerTrocado)
      {
        vetor[indiceDoValorTrocado] = vetor[indiceDoValorTrocado - gap];
        indiceDoValorTrocado = indiceDoValorTrocado - gap; // --> Atualiza o índice para o próximo loop
      }

      if (indiceDoValorTrocado != indicePivoInicial) // --> Se houveram trocas, insere o valor testado na posição correta
        vetor[indiceDoValorTrocado] = valorASerTrocado;
    }
}

double calcularTempoDecorrido(clock_t b, clock_t e)
{
  return (double)(e - b) / CLOCKS_PER_SEC;
}

int main()
{
  clock_t comeco, fim;
  unsigned int i, numAleatorio, tamanho, *vetor;
  FILE *fp = fopen("sorted.txt", "w");
  FILE *fpe = fopen("unsorted.txt", "w");

  // --> Se não abrir o aqruivo, encerra o programa
  if (!fp || !fpe)
  {
    printf("\n!--> Erro ao abrir o arquivo!!\n\n");
    return 1;
  }

  srand(time(NULL)); // --> Seta a semente do rand()
  printf("\n--> Insira a quantidade de números a serem sorteados: ");

  // --> Se a quantidade for negativa ou não for um número, encerra o programa
  if (!scanf(" %d", &tamanho) || tamanho < 0)
  {
    printf("\n!--> Insira um valor válido!!\n\n");
    return 1;
  }

  vetor = (unsigned int *)malloc(tamanho * sizeof(unsigned int)); // --> Aloca memória para o vetor
  for (i = 0; i < tamanho; i++)
  {
    numAleatorio = rand() % RAND_MAX; // --> Preenche o vetor com números aleatórios
    vetor[i] = numAleatorio;
    fprintf(fpe, "%d\n", numAleatorio);
  }

  comeco = clock();          // --> Anota o início da ordenação
  shellSort(vetor, tamanho); // --> Ordena com o Shell-Sort
  fim = clock();             // --> Anota o ponto de fim da ordenação

  // --> Calcula o tempo total da ordenação
  printf("\n\n--> Tempo Decorrido para a Ordenação:\t%.5lf\n", calcularTempoDecorrido(comeco, fim));

  comeco = clock(); // --> Anota o início da escrita
  for (i = 0; i < tamanho; i++)
    fprintf(fp, "%d\n", vetor[i]);
  fclose(fp);
  fim = clock(); // --> Anota o fim da escrita

  // --> Apresenta o tempo total para a escrita do arquivo com os números ordenados
  printf("\n--> Tempo Decorrido para Escrita do Arquivo:\t%.5lf\n\n", calcularTempoDecorrido(comeco, fim));

  return 0;
}
