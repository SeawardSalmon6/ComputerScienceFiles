#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

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

void InserirValor(int item, int pos, No *no, No *filho)
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
    InserirValor(item, pos, no, filho);
  else
    InserirValor(item, pos - mediana, *novoNo, filho);

  *pval = no->item[no->count];
  (*novoNo)->link[0] = no->link[no->count];
  no->count--;
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

int setNo(int item, int *pval, No *no, No **filho)
{
  int pos;
  if (!no)
  {
    *pval = item;
    *filho = NULL;
    return -1;
  }

  if (item < no->item[1])
    pos = 0;
  else
  {
    for (pos = no->count; (item < no->item[pos] && pos > 1); pos--)
      ;

    if (item == no->item[pos]) // Valor duplicado
      return 0;
  }

  if (setNo(item, pval, no->link[pos], filho))
  {
    if (no->count < MAX)
      InserirValor(*pval, pos, no, *filho);
    else
      divideNo(*pval, pval, pos, no, *filho, filho);

    return 1;
  }

  return 0;
}

void inserir(int item)
{
  int flag, i;
  No *filho;

  flag = setNo(item, &i, raiz, &filho);
  if (flag < 0)
    raiz = criarNo(i, filho);

  if (flag != 0)
    printf("\n--> Valor inserido com sucesso!\n\n");
  else
    printf("\n!--> Não permite valor duplicado!\n\n");
}

void clearBuf()
{
  int c;
  while (((c = getchar()) == '\n' || c == EOF))
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
      printf("\n(0) Encerrar");

      printf("\n\n--> Insira a opção desejada: ");
      r = scanf(" %d", &op);

      if (!r)
        clearBuf();

      if (!r || op < 0 || op > 2)
        printf("\n!--> Insira uma opção válida!\n\n");
    } while (!r || op < 0 || op > 2);

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

    case 0:
      printf("\n--> Obrigado por utilizar nosso programa! 😁\n\n");
    }
  } while (op != 0);

  return 0;
}