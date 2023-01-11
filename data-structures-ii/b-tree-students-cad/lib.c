#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

// Helpers
void clearTerminalEOF()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void fillRecord(FILE *dataFile, Aluno record)
{
  int nDigits = (int)(log10(abs(record.raUnesp))) + 1;
  int nameSize = strnlen(record.name, MAX_STRING_SIZE);
  int courseSize = strnlen(record.course, MAX_STRING_SIZE);
  int i;

  for (i = 0; i < RECORD_SIZE - (nDigits + nameSize + courseSize + 3); i++)
    fprintf(dataFile, "%c", FILL_RECORD_CHARACTER);
}

BTreeNode *createNode(IndexNode info, BTreeNode *child)
{
  BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
  if (!newNode)
  {
    printf("\n\n!--> Erro ao alocar memória!\n");
    exit(EXIT_FAILURE);
  }

  newNode->count = 1;
  newNode->keys[1] = info;
  newNode->children[0] = root;
  newNode->children[1] = child;
  return newNode;
}

// Index File Access
BTreeNode *getIndexListFromFile(FILE *ind, BTreeNode **lastIndexNode)
{
  IndexNode aux;
  char key[256];

  ind = fopen(INDEX_FILENAME, "r");
  if (!ind)
  {
    *lastIndexNode = NULL;
    return NULL;
  }

  // If there is an error in the index file, set count to 0
  if (fscanf(ind, "%[^=]=%d\n", key, &recordsCount) <= 0 || strcmp(key, ROOT_ID_KEY) != 0)
  {
    recordsCount = 0;
    fclose(ind);
    *lastIndexNode = NULL;
    return NULL;
  }

  // Capture the root item
  fscanf(ind, "%d;%ld\n", &aux.raUnesp, &aux.pos);
  root = createNode(aux);
  last = root;

  for (int i = 1; i < recordsCount; i++)
  {
    fscanf(ind, "%d;%ld\n", &aux.raUnesp, &aux.pos);
    newNode = createNode(aux);
    last->prox = newNode;
    last = newNode;
  }

  fclose(ind);
  *lastIndexNode = last;
  return root;
}

void setIndexesBackup(FILE *ind, BTreeNode *indexList)
{
  BTreeNode *aux;

  ind = fopen(INDEX_FILENAME, "w");
  if (!ind)
  {
    printf("\n--> Erro ao abrir o arquivo!\n\n");
    exit(EXIT_FAILURE);
  }

  fprintf(ind, "%s=%d\n", ROOT_ID_KEY, recordsCount);
  aux = indexList;
  while (aux)
  {
    fprintf(ind, "%d;%d\n", aux->info.raUnesp, aux->info.pos);
    aux = aux->prox;
  }

  fclose(ind);
}

// Program Functions
void showMenu(FILE *dataFile)
{
  int r, op;

  dataFile = fopen(LIST_FILENAME, "a+");
  if (!dataFile)
  {
    printf("\n--> Erro ao abrir o arquivo!\n\n");
    exit(EXIT_FAILURE);
  }

  do
  {
    do
    {
      printf("\n===== MENU");
      printf("\n(1) Gravar Aluno");
      printf("\n(2) Buscar Aluno");
      printf("\n(0) Sair");

      printf("\n\n--> Digite a opção escolhida: ");
      r = scanf(" %d", &op);

      clearTerminalEOF();

      if (!r || op < 0 || op > 2)
        printf("\n\n!--> Insira uma opção válida!\n");
    } while (!r || op < 0 || op > 2);

    switch (op)
    {
    case 1:
      readStudent(dataFile, indexList, lastIndexNode);
      break;
    case 2:
      fclose(dataFile);
      findStudent(dataFile, indexList);
      break;
    case 0:
      printf("\n--> Obrigado por utilizar nossa aplicação!\n\n");
      break;
    }
  } while (op != 0);

  fclose(dataFile);
}

int isRaValid(int ra, BTreeNode *indexList)
{
  BTreeNode *aux = indexList;
  while (aux)
  {
    if (aux->info.raUnesp == ra)
    {
      printf("\n\n!--> Este RA já existe, insira um RA válido!\n");
      return 0; // If found, return false
    }
    aux = aux->prox;
  }

  if (ra <= 0 || ra > 999999999)
  {
    printf("\n\n!--> Insira um valor entre 1 e 999.999.999!\n");
    return 0;
  }

  return 1;
}

void readStudent(FILE *dataFile, BTreeNode **indexList, BTreeNode **lastIndexNode)
{
  BTreeNode *newNode;
  IndexNode indexAux;
  Aluno aux;
  int r;

  fseek(dataFile, 0, SEEK_END);
  indexAux.pos = ftell(dataFile);

  printf("\n======= GRAVAR ALUNO\n");

  printf("\n-> Insira o nome: ");
  fgets(aux.name, MAX_STRING_SIZE, stdin);
  aux.name[strcspn(aux.name, "\n")] = '\0';

  clearTerminalEOF();

  printf("\n-> Insira o nome do curso: ");
  fgets(aux.course, MAX_STRING_SIZE, stdin);
  aux.course[strcspn(aux.course, "\n")] = '\0';

  do
  {
    clearTerminalEOF();

    printf("\n-> Insira o RA UNESP: ");
    r = scanf(" %d", &aux.raUnesp);

    if (!r)
      printf("\n\n!--> Insira um valor válido!\n");
  } while (!(r && isRaValid(aux.raUnesp, *indexList)));

  fprintf(dataFile, "%d;%s;%s;", aux.raUnesp, aux.name, aux.course);
  fillRecord(dataFile, aux);

  indexAux.raUnesp = aux.raUnesp;
  newNode = createNode(indexAux);

  if (!*indexList)
    *indexList = newNode;
  else
    (*lastIndexNode)->prox = newNode;

  *lastIndexNode = newNode;
  recordsCount++;
}

void findStudent(FILE *dataFile, BTreeNode **indexList)
{
  int r, ra, found = 0;
  char *token, line[RECORD_SIZE];
  BTreeNode *aux;

  dataFile = fopen(LIST_FILENAME, "a+");
  if (!dataFile)
  {
    printf("\n--> Erro ao abrir o arquivo!\n\n");
    exit(EXIT_FAILURE);
  }

  do
  {
    printf("\n-> Insira o RA UNESP: ");
    r = scanf(" %d", &ra);

    clearTerminalEOF();

    if (!r)
      printf("\n\n!--> Insira um valor válido!\n");
  } while (!r);

  aux = *indexList;
  while (aux && !found)
  {
    if (aux->info.raUnesp == ra)
    {
      fseek(dataFile, aux->info.pos, SEEK_SET);
      if (fgets(line, RECORD_SIZE + 1, dataFile) != NULL)
      {
        token = strtok(line, FIELDS_DELIMETER);

        printf("\n--> RA do Aluno: %d", atoi(token));
        token = strtok(NULL, FIELDS_DELIMETER);

        printf("\n--> Nome do Aluno: %s", token);
        token = strtok(NULL, FIELDS_DELIMETER);

        printf("\n--> Curso: %s", token);
        printf("\n");

        found = 1;
      }
      else
      {
        printf("\n\n!--> Erro ao ler os dados do aluno!\n");
        exit(EXIT_FAILURE);
      }
    }
    else
      aux = aux->prox;
  }

  if (!found)
    printf("\n!--> O aluno especificado não foi encontrado!\n");
}