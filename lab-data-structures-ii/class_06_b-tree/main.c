/* Author: Jean Rayhan Vieira Achour */

#include <stdio.h>
#include <stdlib.h>

#define TREE_ORDER 3
#define MAX TREE_ORDER - 1
#define MIN_NODES (TREE_ORDER / 2 + (TREE_ORDER / 2.0 - TREE_ORDER / 2 > 0 ? 1 : 0))
#define MIN MIN_NODES - 1

typedef struct no
{
  int item[MAX + 1];
  int count;
  struct no *link[MAX + 1];
} No;

No *raiz;

No *criarNo(int item, No *filho)
{
  No *novoNo = (No *)malloc(sizeof(No));

  novoNo->item[1] = item;
  novoNo->count = 1;
  novoNo->link[0] = raiz;
  novoNo->link[1] = filho;

  return novoNo;
}

void inserirValor(int item, int pos, No *no, No *filho)
{
  int j = no->count;
  while (j > pos)
  {
    no->item[j + 1] = no->item[j];
    no->link[j + 1] = no->link[j];
    j--;
  }

  no->item[j + 1] = item;
  no->link[j + 1] = filho;
  no->count++;
}

void divideNo(int item, int *pval, int pos, No *no, No *filho, No **novoNo)
{
  int mediana, j;

  *novoNo = (No *)malloc(sizeof(No));
  mediana = pos > MIN ? MIN + 1 : MIN;

  j = mediana + 1;
  while (j <= MAX)
  {
    (*novoNo)->item[j - mediana] = no->item[j];
    (*novoNo)->link[j - mediana] = no->link[j];
    j++;
  }

  no->count = mediana;
  (*novoNo)->count = MAX - mediana;

  if (pos <= MIN)
    inserirValor(item, pos, no, filho);
  else
    inserirValor(item, pos - mediana, *novoNo, filho);

  *pval = no->item[no->count];
  (*novoNo)->link[0] = no->link[no->count];
  no->count--;
}

int setNo(int item, int *pval, No *no, No **filho)
{
  int pos, ret;
  if (!no)
  {
    *pval = item;
    *filho = NULL;
    return 1;
  }

  // Procurar posição de inserção
  if (item < no->item[1])
    pos = 0; // Se o item for maior que a primeira chave, faz a marcação
  else
  { // Quando o item é inserido no meio do vetor
    pos = no->count;
    while (pos > 1 && item < no->item[pos])
      pos--;

    if (item == no->item[pos]) // Valor duplicado
      return -1;
  }

  ret = setNo(item, pval, no->link[pos], filho);
  if (ret == -1) // Verifica se o valor foi duplicado nas recursões posteriores
    return -1;

  if (ret)
  {
    if (no->count < MAX) // Se servir no nó, insere ali mesmo
      inserirValor(*pval, pos, no, *filho);
    else
    {
      divideNo(*pval, pval, pos, no, *filho, filho);
      return 1;
    }
  }

  return 0;
}

void inserir(int item)
{
  int flag, valRaiz;
  No *filho;

  flag = setNo(item, &valRaiz, raiz, &filho);
  if (flag && flag != -1)
    raiz = criarNo(valRaiz, filho);

  if (flag != -1)
    printf("\n--> Valor inserido com sucesso!\n\n");
  else
    printf("\n!--> Não permite valor duplicado!\n\n");
}

void escreveArvB(No *noSelecionado)
{
  int i;
  if (noSelecionado)
  {
    for (i = 0; i < noSelecionado->count; i++)
    {
      escreveArvB(noSelecionado->link[i]);
      printf("%d ", noSelecionado->item[i + 1]);
    }

    escreveArvB(noSelecionado->link[i]);
  }
}

int procura(No *noSelecionado, int val)
{
  int i;
  if (noSelecionado)
  {
    for (i = 0; i < noSelecionado->count; i++)
    {
      if (procura(noSelecionado->link[i], val))
        return 1;

      if (noSelecionado->item[i + 1] == val)
        return 1;
    }

    if (procura(noSelecionado->link[i], val))
      return 1;
  }

  return 0;
}

int getTamanhoArvB(No *root)
{
  int height;

  if (!root)
    return -1;

  height = getTamanhoArvB(root->link[0]) + 1;

  return height;
}

void escreveNoCompleto(No *no)
{
  int i;
  for (i = 0; i < no->count; i++)
    printf("%d ", no->item[i + 1]);
  printf("      ");
}

void escreveNivelArvB(No *root, int nivel)
{
  if (!root)
    return;

  if (nivel == 0)
    escreveNoCompleto(root);
  else if (nivel > 0)
    for (int i = 0; i <= root->count; i++)
      escreveNivelArvB(root->link[i], nivel - 1);
}

void escreveArvBPorNivel(No *root)
{
  int height = getTamanhoArvB(root);
  int i;

  printf("\n====> Árvore-B (Ordenada)\n");
  printf("\n--> Altura: %02d\n\n\n", height);
  for (i = 0; i <= height; i++)
  {
    if (i == 0)
      printf("RAIZ:\t\t");
    else
      printf("\n\nNÍVEL %02d:\t", i);

    escreveNivelArvB(root, i);
  }

  printf("\n\n");
}

void clearBuf()
{
  int c;
  while (((c = getchar()) == '\n' && c == EOF))
    ;
}

int main()
{
  int r, op, item;

  do
  {
    do
    {
      printf("\n==== MENU");
      printf("\n(1) Inserir na Árvore-B");
      printf("\n(2) Buscar na Árvore-B");
      printf("\n(3) Mostrar Árvore-B");
      printf("\n(0) Encerrar");

      printf("\n\n--> Insira a opção desejada: ");
      r = scanf(" %d", &op);

      if (!r)
        clearBuf();

      if (!r || op < 0 || op > 3)
        printf("\n!--> Insira uma opção válida!\n\n");
    } while (!r || op < 0 || op > 3);

    switch (op)
    {
    case 1:
      printf("\n--> Insira o valor a ser inserido: ");
      r = scanf(" %d", &item);

      if (!r)
      {
        clearBuf();
        printf("\n!--> Insira um valor válido!\n\n");
      }
      else
        inserir(item);

      break;

    case 2:
      printf("\n--> Insira o valor a ser buscado: ");
      r = scanf(" %d", &item);

      if (!r)
      {
        clearBuf();
        printf("\n!--> Insira um valor válido!\n\n");
      }
      else if (procura(raiz, item))
        printf("\n--> Valor encontrado!\n\n");
      else
        printf("\n--> O valor não foi encontado!\n\n");

      break;

    case 3:
      if (!raiz)
        printf("\n--> Árvore vazia!\n\n");
      else
        escreveArvBPorNivel(raiz);

      break;

    case 0:
      printf("\n--> Obrigado por utilizar nosso programa! 😁\n\n");
    }
  } while (op != 0);

  return 0;
}