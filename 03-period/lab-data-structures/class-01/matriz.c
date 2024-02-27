#include <stdlib.h> //Para usar malloc, free, exit ...
#include <stdio.h>  //Para usar printf ,...
#include "matriz.h" //Carrega o arquivo .h criado

// Implementação da strcut matriz
struct matriz
{
  int lin;
  int col;
  float *v;
};

// Implementação das funções do TAD matriz
//-------------------------------------------
void libera(Matriz *mat)
{
  free(mat->v);
  free(mat);
}

Matriz *cria(int m, int n)
{
  Matriz *mat = (Matriz *)malloc(sizeof(Matriz));

  if (mat == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(1);
  }

  mat->lin = m;
  mat->col = n;
  mat->v = (float *)malloc(m * n * sizeof(float));

  return mat;
}

float acessa(Matriz *mat, int i, int j)
{
  int k;
  if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col)
  {
    printf("Acesso inválido!\n");
    exit(1);
  }

  k = i * mat->col + j; // Conversão índice duplo em simples
  return mat->v[k];
}

void atribui(Matriz *mat, int i, int j, float v)
{
  int k;
  if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col)
  {
    printf("Atribuição inválida!\n");
    exit(1);
  }

  k = i * mat->col + j; // Conversão (i,j) --> k (índice simples)
  mat->v[k] = v;
}

int linhas(Matriz *mat)
{
  return mat->lin;
}

int colunas(Matriz *mat)
{
  return mat->col;
}
