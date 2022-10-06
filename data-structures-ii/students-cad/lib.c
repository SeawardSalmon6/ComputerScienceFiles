#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

int recordsCount;

// Helpers
void clearTerminalEOF()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void fillRecord(FILE *fp, TAluno record)
{
  int nDigits = (int)(log10(abs(record.raUnesp))) + 1;
  int nameSize = strnlen(record.nome, MAX_STRING_SIZE);
  int courseSize = strnlen(record.curso, MAX_STRING_SIZE);
  int i;

  for (i = 0; i < RECORD_SIZE - (nDigits + nameSize + courseSize + 3); i++)
    fprintf(fp, "%c", FILL_RECORD_CHARACTER);
}

Node *createNode(TIndexNode info)
{
  Node *tmp = (Node *)malloc(sizeof(Node));
  if (tmp)
  {
    tmp->info = info;
    tmp->prox = NULL;
  }
  return tmp ? tmp : NULL;
}

// Index File Access
Node *getIndexListFromFile(FILE *ind, Node **lastIndexNode)
{
  char key[MAX_STRING_SIZE];
  TIndexNode aux;
  Node *tmp = NULL, *root = NULL;

  ind = fopen(INDEX_FILENAME, "r");

  if (!ind)
  {
    *lastIndexNode = NULL;
    return NULL;
  }

  if (fscanf(ind, "%[^=]=%d\n", key, &recordsCount) <= 0 && strcmp(key, RECORDS_COUNT_KEY) != 0)
    recordsCount = 0;

  for (int i = 0; i < recordsCount; i++)
  {
    fscanf(ind, "%d;%d\n", &aux.raUnesp, &aux.pos);
    if (!root)
    {
      root = createNode(aux);
      tmp = root;
    }
    else
    {
      Node *newNode = createNode(aux);
      tmp->prox = newNode;
      tmp = newNode;
    }
  }

  fclose(ind);
  *lastIndexNode = tmp;

  return root;
}

void setIndexesBackup(FILE *ind, Node *indexList)
{
  Node *aux;
  ind = fopen(INDEX_FILENAME, "w");

  if (!ind)
  {
    printf("\n--> Erro ao abrir o arquivo!\n\n");
    exit(EXIT_FAILURE);
  }

  fprintf(ind, "%s=%d\n", RECORDS_COUNT_KEY, recordsCount);
  aux = indexList;
  while (aux)
  {
    fprintf(ind, "%d;%d\n", aux->info.raUnesp, aux->info.pos);
    aux = aux->prox;
  }

  fclose(ind);
}

// Program Functions
void showMenu(FILE *fp, Node **indexList, Node **lastIndexNode)
{
  int op;

  fp = fopen(LIST_FILENAME, "a+");

  if (!fp)
  {
    printf("\n--> Erro ao abrir o arquivo!\n\n");
    exit(EXIT_FAILURE);
  }

  do
  {
    printf("\n===== MENU");
    printf("\n(1) Gravar Aluno");
    printf("\n(2) Buscar Aluno");
    printf("\n(3) Sair");

    printf("\n\n--> Digite a opção escolhida: ");
    scanf(" %d", &op);

    switch (op)
    {
    case 1:
      readStudent(fp, indexList, lastIndexNode);
      break;
    case 2:
      fclose(fp);
      findStudent(fp, indexList);
      break;
    case 3:
      printf("\n--> Obrigado por utilizar nossa aplicação!\n\n");
      break;
    default:
      printf("\n!-> Insira uma opção válida!\n\n");
      break;
    }
  } while (op != 3);

  fclose(fp);
}

void readStudent(FILE *fp, Node **indexList, Node **lastIndexNode)
{
  TAluno aux;
  TIndexNode indexAux;
  Node *newNode;
  long pos;

  fseek(fp, 0, SEEK_END);
  pos = ftell(fp);

  clearTerminalEOF();
  printf("\n======= GRAVAR ALUNO\n");

  printf("\n-> Insira o nome: ");
  fgets(aux.nome, MAX_STRING_SIZE, stdin);
  aux.nome[strcspn(aux.nome, "\n")] = '\0';

  printf("\n-> Insira o nome do curso: ");
  fgets(aux.curso, MAX_STRING_SIZE, stdin);
  aux.curso[strcspn(aux.curso, "\n")] = '\0';

  do
  {
    printf("\n-> Insira o RA UNESP: ");
    scanf(" %d", &aux.raUnesp);

    if (aux.raUnesp <= 0 || aux.raUnesp > 99999)
      printf("\n\n!--> Insira um valor entre 1 e 99999!\n");
  } while (aux.raUnesp <= 0 || aux.raUnesp > 99999);

  fprintf(fp, "%d;%s;%s;", aux.raUnesp, aux.nome, aux.curso);
  fillRecord(fp, aux);

  indexAux.pos = pos;
  indexAux.raUnesp = aux.raUnesp;

  if (!*indexList)
  {
    newNode = createNode(indexAux);
    *indexList = newNode;
    *lastIndexNode = newNode;
  }
  else
  {
    newNode = createNode(indexAux);
    (*lastIndexNode)->prox = newNode;
    *lastIndexNode = newNode;
  }

  recordsCount++;
}

void findStudent(FILE *fp, Node **indexList)
{
  int ra, check = 0;
  char *token, line[RECORD_SIZE];
  Node *aux;

  fp = fopen(LIST_FILENAME, "a+");

  if (!fp)
  {
    printf("\n--> Erro ao abrir o arquivo!\n\n");
    exit(EXIT_FAILURE);
  }

  printf("\n======= BUSCAR ALUNO\n");
  printf("\n--> Insira o RA do aluno: ");
  scanf(" %d", &ra);

  aux = *indexList;
  while (aux && !check)
  {
    if (aux->info.raUnesp == ra)
    {
      fseek(fp, aux->info.pos, SEEK_SET);
      if (fgets(line, RECORD_SIZE + 1, fp) != NULL)
      {
        token = strtok(line, FIELDS_DELIMETER);

        printf("\n--> RA do Aluno: %d", atoi(token));
        token = strtok(NULL, FIELDS_DELIMETER);

        printf("\n--> Nome do Aluno: %s", token);
        token = strtok(NULL, FIELDS_DELIMETER);

        printf("\n--> Curso: %s", token);
        printf("\n");
      }
      check = 1;
    }

    aux = aux->prox;
  }

  if (!check)
    printf("\n!-> O aluno especificado não foi encontrado!\n");
}