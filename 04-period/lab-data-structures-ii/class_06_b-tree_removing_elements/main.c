#include <stdio.h>
#include <stdlib.h>

#define NMAXREGS 2
#define MAX 2
#define MIN 1

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct no
{
  int ordem;
  int nregs;
  int chaves[ORDER + 1];
  struct no *filhos[ORDER + 1];
} ArvB, NoArvB;

ArvB *raiz;

void RemoveChaveEmNo(NoArvB *no, int pos)
{
  int i;
  /* desloca as chaves e filhas para trás */
  for (i = pos; i < no->nregs; i++)
  {
    no->chaves[i] = no->chaves[i + 1];
    no->filhos[i] = no->filhos[i + 1];
  }
  /* completa o deslocamento para a filha à direita da última chave */
  no->filhos[i] = no->filhos[i + 1];
  no->filhos[i + 1] = NULL;
  /* ajusta o número de registros */
  no->nregs--;
}

void TrocaChaveComAntecessora(NoArvB *no, int pos)
{
  ArvB *no_aux;
  int chave_aux;

  no_aux = no->filhos[pos];                     /* árvore filha à esquerda da chave na posição "pos" */
  while (no_aux->filhos[no_aux->nregs] != NULL) /* busca a chave mais à direira na àrvore esquerda (i.e., a antecessora da chave que está em "no" na posição "pos") */
    no_aux = no_aux->filhos[no_aux->nregs];

  /* troca a chave por sua antecessora na árvore B */
  chave_aux = no->chaves[pos];
  no->chaves[pos] = no_aux->chaves[no_aux->nregs - 1];
  no_aux->chaves[no_aux->nregs - 1] = chave_aux;
}

void TrataNoComMenosChavesQuePermitido(NoArvB **no, int pos)
{
  int chave, i, j;
  NoArvB *irma_esq = NULL, *filha = NULL, *irma_dir = NULL;

  filha = (*no)->filhos[pos];

  if (pos > 0)
  { /* existe irmã à esquerda da filha */
    irma_esq = (*no)->filhos[pos - 1];
    if (irma_esq->nregs > (((*no)->ordem) / 2))
    { /* A irmã à esquerda tem chaves para emprestar. A sua última chave sobe
para o nó pai e a chave do nó pai  desce para a filha na posição mais à esquerda. A filha à direira da chave que
subiu passa a ser filha à esquerda daquela que desceu.*/
      chave = (*no)->chaves[pos - 1];
      (*no)->chaves[pos - 1] = irma_esq->chaves[irma_esq->nregs - 1];
      NoArvB *filha_esq = irma_esq->filhos[irma_esq->nregs];
      RemoveChaveEmNo((*no)->filhos[pos - 1], (*no)->filhos[pos - 1]->nregs);
      filha->nregs++;
      filha->filhos[0] = filha_esq;
      filha->chaves[0] = chave;
      return;
    }
  }

  if (pos < (*no)->nregs)
  { /* existe irmã à direita */
    irma_dir = (*no)->filhos[pos + 1];
    if (irma_dir->nregs > (((*no)->ordem) / 2))
    { /* A irmã à direita tem chaves para
emprestar. A sua primeira chave sobe para o nó pai e a chave do nó pai desce para a filha na posição mais à
direita. A filha à esquerda da chave que subiu passa a ser filha à direita daquela que desceu. */
      chave = (*no)->chaves[pos];
      (*no)->chaves[pos] = irma_dir->chaves[0];
      NoArvB *filha_dir = irma_dir->filhos[0];
      RemoveChaveEmNo((*no)->filhos[pos + 1], 0);
      filha->nregs++;
      filha->filhos[filha->nregs] = filha_dir;
      filha->chaves[filha->nregs - 1] = chave;
      return;
    }
  }
}

BOOL NoComMaisChavesQuePossivel(NoArvB *no)
{
  return (no->nregs > ORDER);
}

BOOL NoComMenosChavesQuePermitido(NoArvB *no)
{
  return (no->nregs < MIN_KEYS);
}

BOOL BuscaChaveNoArvB(NoArvB *no, int chave, int *pos)
{
  for ((*pos) = 1; (no->chaves[*pos] < chave) && (*pos) < no->nregs; (*pos)++)
    ;

  /* "pos" contém a posição da chave no nó */
  if (((*pos) <= no->nregs) && (no->chaves[*pos] == chave))
    return (TRUE);

  /* "pos" contém a posição da árvore filha na qual a chave poderá ser encontrada */
  return (FALSE);
}

BOOL RemoveArvBRec(NoArvB **no, int chave, BOOL *underflow)
{
  int pos;

  /* Verifica se a chave está no nó atual. Se tiver e esse nó for uma
  folha, realiza a remoção. Caso contrário, troca a chave pela
  antecessora e continua o procedimento recursivo para remoção. */

  if (BuscaChaveNoArvB(*no, chave, &pos))
  { /* a chave está no nó deste nível */
    if ((*no)->filhos[pos - 1] != NULL)
    {
      /* O nó atual não é uma folha,
      então a chave precisa ser trocada pela antecessora, reduzindo ao caso de remoção na folha. */

      TrocaChaveComAntecessora(*no, pos - 1); /* troca a chave pela sua antecessora -- i.e., a
           chave mais à direita na árvore à esquerda. continua o procedimento recursivo para
           reencontrar e remover a chave do nó folha */

      RemoveArvBRec(&((*no)->filhos[pos]), chave, underflow);
      /* trata underflow, se for o caso, após a remoção da chave */
      if (*underflow)
        TrataNoComMenosChavesQuePermitido(no, pos);
    }
    else
    { /* achou a chave no nó folha, então ela pode ser removida. */
      RemoveChaveEmNo(*no, pos - 1);
    }
    /* verifica se a folha ficou em underflow */

    (*underflow) = NoComMenosChavesQuePermitido(*no);
    return (TRUE); /* remoção bem sucedida */
  }
  else
  { /* procura a chave nos nós abaixo */
    if ((*no)->filhos[pos - 1] != NULL)
    {
      if (RemoveArvBRec(&((*no)->filhos[pos - 1]), chave, underflow))
      {
        /* a chave foi encontrada e removida da folha (raiz da árvore
        filha). Trata um possível underflow e verifica novamente se
        ele será propagado para cima (volta da recursão). */
        if (*underflow)
          TrataNoComMenosChavesQuePermitido(no, pos - 2);
        (*underflow) = NoComMenosChavesQuePermitido(*no);
        return (TRUE);
      }
      else
        return (FALSE); /* chego na folha e não achou a chave */
    }
    else
    { /* estamos na raiz e a chave não está neste nível, logo ela não existe. */
      (*underflow) = FALSE;
      return (FALSE);
    }
  }
}

BOOL RemoveArvB(ArvB **arvore, int chave)
{
  BOOL underflow = FALSE;

  if ((*arvore) == NULL)
  {
    printf("\n!--> Erro em RemoveArvB: Árvore inexistente\n\n");
    exit(1);
  }

  if (RemoveArvBRec(arvore, chave, &underflow))
  { /* A chave foi removida */

    /* Se o underflow chegou até a raiz da arvore, entao a raiz antiga
       deve ser eliminada e a nova será a sua única filha, reduzindo
       assim a altura da arvore em 1.
    */

    if (underflow)
    {
      NoArvB *no = *arvore;
      *arvore = (*arvore)->filhos[0];
      free(no);
    }

    return (TRUE);
  }

  return (FALSE);
}

ArvB *criarNo(int item, ArvB *filho)
{
  ArvB *novoNo = (ArvB *)malloc(sizeof(ArvB));

  novoNo->chaves[1] = item;
  novoNo->nregs = 1;
  novoNo->filhos[0] = raiz;
  novoNo->filhos[1] = filho;

  return novoNo;
}

void InserirValor(int item, int pos, ArvB *no, ArvB *filho)
{
  int j = no->nregs;
  while (j > pos)
  {
    no->chaves[j + 1] = no->chaves[j];
    no->filhos[j + 1] = no->filhos[j];
    j--;
  }

  no->chaves[j + 1] = item;
  no->filhos[j + 1] = filho;
  no->nregs++;
}

void divideNo(int item, int *pval, int pos, ArvB *no, ArvB *filho, ArvB **novoNo)
{
  int mediana, j;

  *novoNo = (ArvB *)malloc(sizeof(ArvB));
  mediana = pos > MIN_KEYS ? MIN_KEYS + 1 : MIN_KEYS;

  j = mediana + 1;
  while (j <= ORDER)
  {
    (*novoNo)->chaves[j - mediana] = no->chaves[j];
    (*novoNo)->filhos[j - mediana] = no->filhos[j];
    j++;
  }

  no->nregs = mediana;
  (*novoNo)->nregs = ORDER - mediana;

  if (pos <= MIN_KEYS)
    InserirValor(item, pos, no, filho);
  else
    InserirValor(item, pos - mediana, *novoNo, filho);

  *pval = no->chaves[no->nregs];
  (*novoNo)->filhos[0] = no->filhos[no->nregs];
  no->nregs--;
}

BOOL procura(NoArvB *noSelecionado, int val)
{
  int i;
  if (noSelecionado)
  {
    for (i = 0; i < noSelecionado->nregs; i++)
    {
      if (procura(noSelecionado->filhos[i], val))
        return TRUE;

      if (noSelecionado->chaves[i + 1] == val)
        return TRUE;
    }

    if (procura(noSelecionado->filhos[i], val))
      return TRUE;
  }

  return FALSE;
}

void escreveArvB(ArvB *noSelecionado)
{
  int i;
  if (noSelecionado)
  {
    for (i = 0; i < noSelecionado->nregs; i++)
    {
      escreveArvB(noSelecionado->filhos[i]);
      printf("%d ", noSelecionado->chaves[i + 1]);
    }

    escreveArvB(noSelecionado->filhos[i]);
  }
}

void escreveNoCompleto(NoArvB *no)
{
  int i;
  for (i = 0; i < no->nregs; i++)
    printf("%d ", no->chaves[i + 1]);
}

int getTamanhoArvB(ArvB *root)
{
  int esq, dir;

  if (!root)
    return -1;

  esq = getTamanhoArvB(root->filhos[0]) + 1;
  dir = getTamanhoArvB(root->filhos[root->nregs]) + 1;

  return esq > dir ? esq : dir;
}

void escreveNivelArvB(NoArvB *root, int nivel)
{
  if (!root)
    return;

  if (nivel == 1)
    escreveNoCompleto(root);
  else if (nivel > 1)
  {
    escreveNivelArvB(root->filhos[0], nivel - 1);
    escreveNivelArvB(root->filhos[root->nregs], nivel - 1);
  }
}

void escreveArvBPorNivel(ArvB *root)
{
  int height;
  int i;
  for (i = 1; i <= height; i++)
    escreveNivelArvB(root, i);
}

int setNo(int item, int *pval, ArvB *no, ArvB **filho)
{
  int pos;
  if (!no)
  {
    *pval = item;
    *filho = NULL;
    return -1;
  }

  if (item < no->chaves[1])
    pos = 0;
  else
  {
    for (pos = no->nregs; (item < no->chaves[pos] && pos > 1); pos--)
      ;

    if (item == no->chaves[pos])
      return -2;
  }

  if (setNo(item, pval, no->filhos[pos], filho))
  {
    if (no->nregs < ORDER)
      InserirValor(*pval, pos, no, *filho);
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
  int flag, i;
  ArvB *filho;

  flag = setNo(item, &i, raiz, &filho);
  if (flag && flag != -2)
    raiz = criarNo(i, filho);

  if (flag == -2)
    printf("\n!--> Não permite valor duplicado!\n\n");
  else
    printf("\n--> Valor inserido com sucesso!\n\n");
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
      printf("\n(3) Remover Chave na Árvore-B");
      printf("\n(4) Mostrar Árvore-B");
      printf("\n(0) Encerrar");

      printf("\n\n--> Insira a opção desejada: ");
      r = scanf(" %d", &op);

      if (!r)
        clearBuf();

      if (!r || op < 0 || op > 4)
        printf("\n!--> Insira uma opção válida!\n\n");
    } while (!r || op < 0 || op > 4);

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
      printf("\n--> Insira o valor a ser removido: ");
      r = scanf(" %d", &item);

      if (!r)
      {
        clearBuf();
        printf("\n!--> Insira um valor válido!\n\n");
      }
      else if (RemoveArvB(&raiz, item))
        printf("\n--> Valor removido com sucesso!\n\n");
      else
        printf("\n--> A chave não foi encontrada e logo não foi removida!\n\n");

      break;

    case 4:
      if (!raiz)
        printf("\n--> Árvore vazia!\n\n");
      else
      {
        printf("\n====> Árvore-B (Ordenada h-%d)\n\n", getTamanhoArvB(raiz));
        escreveArvB(raiz);
        printf("\n\n");
      }
      break;

    case 0:
      printf("\n--> Obrigado por utilizar nosso programa! 😁\n\n");
    }
  } while (op != 0);

  return 0;
}