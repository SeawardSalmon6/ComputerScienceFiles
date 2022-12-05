#include <stdio.h>
#include <stdlib.h>

#define NMAXREGS 4
#define MAX 4
#define MIN 2

enum _bool
{
  false = 0,
  true = 1
};

typedef enum _bool bool;

typedef struct no
{
  int ordem;
  int nregs;
  int chaves[MAX + 1];
  struct no *filhos[MAX + 1];
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

bool NoComMaisChavesQuePossivel(NoArvB *no)
{
  return (no->nregs > no->ordem);
}

bool NoComMenosChavesQuePermitido(NoArvB *no)
{
  return (no->nregs < (no->ordem / 2));
}

bool BuscaChaveNoArvB(NoArvB *no, int chave, int *pos)
{
  for ((*pos) = 0; (no->chaves[*pos] < chave) && (*pos) < no->nregs; (*pos)++)
    ;

  /* "pos" contém a posição da chave no nó */
  if (((*pos) < no->nregs) && (no->chaves[*pos] == chave))
    return (true);

  /* "pos" contém a posição da árvore filha na qual a chave poderá ser encontrada */
  return (false);
}

bool RemoveArvBRec(NoArvB **no, int chave, bool *underflow)
{
  int pos;

  /* Verifica se a chave está no nó atual. Se tiver e esse nó for uma
  folha, realiza a remoção. Caso contrário, troca a chave pela
  antecessora e continua o procedimento recursivo para remoção. */

  if (BuscaChaveNoArvB(*no, chave, &pos))
  { /* a chave está no nó deste nível */
    if ((*no)->filhos[pos] != NULL)
    {
      /* O nó atual não é uma folha,
      então a chave precisa ser trocada pela antecessora, reduzindo ao caso de remoção na folha. */

      TrocaChaveComAntecessora(*no, pos); /* troca a chave pela sua antecessora -- i.e., a
           chave mais à direita na árvore à esquerda. continua o procedimento recursivo para
           reencontrar e remover a chave do nó folha */

      RemoveArvBRec(&((*no)->filhos[pos]), chave, underflow);
      /* trata underflow, se for o caso, após a remoção da chave */
      if (*underflow)
        TrataNoComMenosChavesQuePermitido(no, pos);
    }
    else
    { /* achou a chave no nó folha, então ela pode ser removida. */
      RemoveChaveEmNo(*no, pos);
    }
    /* verifica se a folha ficou em underflow */

    (*underflow) = NoComMenosChavesQuePermitido(*no);
    return (true); /* remoção bem sucedida */
  }
  else
  { /* procura a chave nos nós abaixo */
    if ((*no)->filhos[pos] != NULL)
    {
      if (RemoveArvBRec(&((*no)->filhos[pos]), chave, underflow))
      {
        /* a chave foi encontrada e removida da folha (raiz da árvore
        filha). Trata um possível underflow e verifica novamente se
        ele será propagado para cima (volta da recursão). */
        if (*underflow)
          TrataNoComMenosChavesQuePermitido(no, pos);
        (*underflow) = NoComMenosChavesQuePermitido(*no);
        return (true);
      }
      else
      {
        return (false); /* chego na folha e não achou a chave */
      }
    }
    else
    { /* estamos na raiz e a chave não está neste nível, logo ela não existe. */
      (*underflow) = false;
      return (false);
    }
  }
}

bool RemoveArvB(ArvB **arvore, int chave)
{
  if ((*arvore) == NULL)
  {
    printf("Erro em RemoveArvB: Árvore inexistente\n");
    exit(1);
  }

  bool underflow = false;

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

    return (true);
  }

  return (false);
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
  mediana = pos > MIN ? MIN + 1 : MIN;

  j = mediana + 1;
  while (j <= MAX)
  {
    (*novoNo)->chaves[j - mediana] = no->chaves[j];
    (*novoNo)->filhos[j - mediana] = no->filhos[j];
    j++;
  }

  no->nregs = mediana;
  (*novoNo)->nregs = MAX - mediana;

  if (pos <= MIN)
    InserirValor(item, pos, no, filho);
  else
    InserirValor(item, pos - mediana, *novoNo, filho);

  *pval = no->chaves[no->nregs];
  (*novoNo)->filhos[0] = no->filhos[no->nregs];
  no->nregs--;
}

int procura(ArvB *noSelecionado, int val)
{
  int i;
  if (noSelecionado)
  {
    for (i = 0; i < noSelecionado->nregs; i++)
    {
      if (procura(noSelecionado->filhos[i], val))
        return 1;

      if (noSelecionado->chaves[i + 1] == val)
        return 1;
    }

    if (procura(noSelecionado->filhos[i], val))
      return 1;
  }

  return 0;
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

    if (item == no->chaves[pos]) // Valor duplicado
      return 0;
  }

  if (setNo(item, pval, no->filhos[pos], filho))
  {
    if (no->nregs < MAX)
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
  ArvB *filho;

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
      printf("\n(3) Remover Chave na Árvore-B");
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

    case 0:
      printf("\n--> Obrigado por utilizar nosso programa! 😁\n\n");
    }
  } while (op != 0);

  return 0;
}