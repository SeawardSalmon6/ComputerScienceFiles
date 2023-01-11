#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

Node *raiz;
int indexRaiz = 0;

Node *
criarNo(int item, Node *filho)
{
  int i;
  Node *novoNo = (Node *)calloc(1, sizeof(Node));
  if (!novoNo)
  {
    printf("\n\n!--> Erro ao alocar memória do Node!\n");
    exit(1);
  }

  indexRaiz++;
  novoNo->keys[1] = item;
  novoNo->count = 1;
  novoNo->children[0] = raiz;
  novoNo->children[1] = filho;

  return novoNo;
}

int nodeHasChildren(Node *node)
{
  int i;
  if (node)
  {
    for (i = 0; i <= node->count; i++)
      if (node->children[i])
        return 1;
  }
  return 0;
}

void salvarNode(Node *node, int *k, FILE *fp)
{
  int i;
  if (node)
  {
    for (i = 1; i <= TREE_ORDER; i++)
    {
      if (node->children[i - 1])
        fprintf(fp, "%04d ", (*k) - (node->count + 1 - i + 1));
      else
        fprintf(fp, "%s ", NO_CHILD_KEY_VALUE);

      if (i <= node->count)
        fprintf(fp, "%04d ", node->keys[i]);
      else if (i < TREE_ORDER)
        fprintf(fp, "%s ", NO_CHILD_KEY_VALUE);
    }

    fprintf(fp, "\n");
    *k = *k + 1;
  }
}

void salvarPai(Node *node, int *k, FILE *fp)
{
  int i, j;
  if (node)
  {
    if (!nodeHasChildren(node))
      return;

    for (i = 0; i <= node->count; i++)
    {
      salvarPai(node->children[i], k, fp);
      salvarNode(node->children[i], k, fp);
    }
  }
}

void salvarArvore()
{
  int k = 0;
  FILE *fp = fopen(INDEX_FILENAME, "w");
  if (!fp)
  {
    printf("\n\n!--> Erro ao abrir o arquivo!\n");
    exit(1);
  }

  fprintf(fp, "%s=%04d\n", ROOT_RRN_KEYNAME, indexRaiz - 1);
  salvarPai(raiz, &k, fp);
  salvarNode(raiz, &k, fp);
}

void inserirValor(int item, int pos, Node *no, Node *filho)
{
  int j = no->count;
  while (j > pos)
  {
    no->keys[j + 1] = no->keys[j];
    no->children[j + 1] = no->children[j];
    j--;
  }

  no->keys[j + 1] = item;
  no->children[j + 1] = filho;
  no->count++;
}

void divideNo(int item, int *pval, int pos, Node *no, Node *filho, Node **novoNo)
{
  int mediana, j;

  *novoNo = (Node *)calloc(1, sizeof(Node));
  if (!novoNo)
  {
    printf("\n\n!--> Erro ao alocar memória para o Node!\n");
    exit(1);
  }

  indexRaiz++;
  mediana = pos > MIN_KEYS ? MIN_KEYS + 1 : MIN_KEYS;

  j = mediana + 1;
  while (j <= MAX_KEYS)
  {
    (*novoNo)->keys[j - mediana] = no->keys[j];
    (*novoNo)->children[j - mediana] = no->children[j];
    j++;
  }

  no->count = mediana;
  (*novoNo)->count = MAX_KEYS - mediana;

  if (pos <= MIN_KEYS)
    inserirValor(item, pos, no, filho);
  else
    inserirValor(item, pos - mediana, *novoNo, filho);

  *pval = no->keys[no->count];
  (*novoNo)->children[0] = no->children[no->count];
  no->count--;
}

int setNo(int item, int *pval, Node *no, Node **filho)
{
  int pos, ret;
  if (!no)
  {
    *pval = item;
    *filho = NULL;
    return 1;
  }

  // Procurar posição de inserção
  if (item < no->keys[1])
    pos = 0; // Se o item for maior que a primeira chave, faz a marcação
  else
  { // Quando o item é inserido no meio do vetor
    pos = no->count;
    while (pos > 1 && item < no->keys[pos])
      pos--;

    if (item == no->keys[pos]) // Valor duplicado
      return -1;
  }

  ret = setNo(item, pval, no->children[pos], filho);
  if (ret == -1) // Verifica se o valor foi duplicado nas recursões posteriores
    return -1;

  if (ret)
  {
    if (no->count < MAX_KEYS) // Se servir no nó, insere ali mesmo
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
  Node *filho;

  flag = setNo(item, &valRaiz, raiz, &filho);
  if (flag && flag != -1)
    raiz = criarNo(valRaiz, filho);

  if (flag != -1)
    printf("\n--> Valor inserido com sucesso!\n\n");
  else
    printf("\n!--> Não permite valor duplicado!\n\n");
}

void escreveArvB(Node *noSelecionado)
{
  int i;
  if (noSelecionado)
  {
    for (i = 0; i < noSelecionado->count; i++)
    {
      escreveArvB(noSelecionado->children[i]);
      printf("%d ", noSelecionado->keys[i + 1]);
    }

    escreveArvB(noSelecionado->children[i]);
  }
}

int getTamanhoArvB(Node *root)
{
  int height;

  if (!root)
    return -1;

  height = getTamanhoArvB(root->children[0]) + 1;

  return height;
}

void escreveNoCompleto(Node *no)
{
  int i;
  for (i = 0; i < no->count; i++)
    printf("%d ", no->keys[i + 1]);
  printf("      ");
}

void escreveNivelArvB(Node *root, int nivel)
{
  if (!root)
    return;

  if (nivel == 0)
    escreveNoCompleto(root);
  else if (nivel > 0)
    for (int i = 0; i <= root->count; i++)
      escreveNivelArvB(root->children[i], nivel - 1);
}

void escreveArvBPorNivel(Node *root)
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

int procura(Node *noSelecionado, int val)
{
  int i;
  if (noSelecionado)
  {
    for (i = 0; i < noSelecionado->count; i++)
    {
      if (procura(noSelecionado->children[i], val))
        return 1;

      if (noSelecionado->keys[i + 1] == val)
        return 1;
    }

    if (procura(noSelecionado->children[i], val))
      return 1;
  }

  return 0;
}

void clearBuf()
{
  int c;
  while (((c = getchar()) == '\n' && c == EOF))
    ;
}