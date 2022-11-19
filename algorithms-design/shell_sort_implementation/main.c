#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t comeco, fim;

// --> ============= Método Shell Sort
void shellSort(int *vetor, const int tamanho)
{
  int valorASerTrocado,
      vetorGaps[tamanho / 2],
      indiceGap,
      indiceValorInicial,
      posicaoDoValorTrocado,
      indiceValorTestado;

  indiceGap = 1;
  while (indiceGap < tamanho / 2)
  { // Calcula e armazena o valor do gap em relação a equação floor(N / 2^k)
    vetorGaps[indiceGap - 1] = (int)(tamanho / pow(2, indiceGap));

    if (vetorGaps[indiceGap - 1] == 0)
      break;

    indiceGap++;
  }
  indiceGap--; // --> Ajusta o início do vetor para não utilizar o gap 0

  while (indiceGap > 0)
  {
    indiceGap--; // --> Ajusta o passo da iteração atual
    for (indiceValorInicial = 0; indiceValorInicial < vetorGaps[indiceGap]; indiceValorInicial++)
    { // --> Percorre o vetor desde o início até o tamanho do gap
      for (indiceValorTestado = indiceValorInicial + vetorGaps[indiceGap]; indiceValorTestado < tamanho; indiceValorTestado += vetorGaps[indiceGap])
      {                                               // --> Acessa os valores de acordo com o gap atual
        valorASerTrocado = vetor[indiceValorTestado]; // --> Atribuir a valor da posição a ser testado
        posicaoDoValorTrocado = indiceValorTestado;   // --> Marca o valor inicial de j para esta iteração

        // --> Realiza as comparações já fazendo as devidas inserções
        // --> Executa enquanto a valor testado >= ao valor anterior testado
        while (posicaoDoValorTrocado - vetorGaps[indiceGap] > 0 && vetor[posicaoDoValorTrocado - vetorGaps[indiceGap]] >= valorASerTrocado)
        {
          vetor[posicaoDoValorTrocado] = vetor[posicaoDoValorTrocado - vetorGaps[indiceGap]];
          posicaoDoValorTrocado = posicaoDoValorTrocado - vetorGaps[indiceGap]; // --> Atualiza o índice para o próximo loop
        }

        if (posicaoDoValorTrocado != indiceValorTestado) // --> Se houveram trocas, insere o valor testado na posição correta
          vetor[posicaoDoValorTrocado] = valorASerTrocado;
      }
    }
  }
}

double calcularTempoDecorrido(clock_t b, clock_t e)
{
  return (double)(e - b) / CLOCKS_PER_SEC;
}

int main()
{
  FILE *fp = fopen("sorted.txt", "w");
  int i, numAleatorio, tamanho, *vetor;

  if (!fp)
  { // --> Se não abrir o aqruivo, encerra o programa
    printf("\n!--> Erro ao abrir o arquivo!!\n\n");
    return 1;
  }

  srand(time(NULL)); // --> Seta a semente do rand()

  printf("\n--> Insira a quantidade de números a serem sorteados: ");
  if (!scanf(" %d", &tamanho) || tamanho < 0)
  { // --> Se a quantidade for negativa ou não for um número, encerra o programa
    printf("\n!--> Insira um valor válido!!\n\n");
    return 1;
  }

  vetor = (int *)malloc(tamanho * sizeof(int)); // --> Aloca memória para o vetor
  for (i = 0; i < tamanho; i++)
  {
    numAleatorio = rand() % RAND_MAX; // --> Preenche o vetor com números aleatórios
    vetor[i] = numAleatorio;
    // --> printf("%d\n", r_num);
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
