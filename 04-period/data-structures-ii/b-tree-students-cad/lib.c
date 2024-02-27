#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lib.h"

int ROOT_RRN;
int CURRENT_RRN;

void clearEOF()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void printError(const char *text)
{
  printf("\n\n!--> Erro: %s\n", text);
}

void printWarning(const char *text)
{
  printf("\n\n!--> %s\n\n", text);
}

FILE *openFile(const char *filename, const char *mode)
{
  FILE *fp = fopen(filename, mode);
  if (!fp)
  {
    if (mode && mode[0] == 'r')
      return NULL;

    printError("Erro ao abrir o arquivo!\n");
    exit(1);
  }
  return fp;
}

void readString(char *str, const size_t maxLength)
{
  fgets(str, maxLength, stdin);
  str[strcspn(str, "\n")] = '\0';

  if (strnlen(str, maxLength) >= maxLength)
    clearEOF();
}

int getRootRRN(FILE *btree)
{
  int r, rrn;
  char aux[256] = {0};
  fseek(btree, 0, SEEK_SET); // Points to beginning of file
  if (fscanf(btree, "%[^=]=%d\n", aux, &rrn) <= 0)
    rrn = -1;
  return rrn;
}

FILE *openBTreeIndex(const char *filename)
{
  FILE *fp = openFile(filename, "r+");
  if (!fp)
  {                                               // If the file doesn't exist
    fp = openFile(filename, "w+");                // Create a file
    fprintf(fp, "%s=%04d\n", ROOT_KEY_VALUE, -1); // Set ROOT_RRN to -1
    ROOT_RRN = -1;
  }
  else
    ROOT_RRN = getRootRRN(fp);

  fseek(fp, 0, SEEK_END);
  CURRENT_RRN = (ftell(fp) - INDEX_START) / SIZE_OF_BTREE_PAGE_RECORD - 1;

  return fp;
}

void printHeader(const char *text)
{
  printf("\n\n======== %s\n", text);
}

Page *createPage()
{
  int i;
  Page *newPage = (Page *)malloc(sizeof(Page));
  if (!newPage)
  {
    printError("Erro ao alocar memória para a página!");
    exit(1);
  }

  // Setting standard variables
  newPage->keysCount = 0;

  for (i = 0; i < TREE_ORDER; i++)
    newPage->children[i] = -1;

  for (i = 0; i < MAX_KEYS; i++)
    newPage->keys[i].raUnesp = newPage->keys[i].pos = -1;

  return newPage;
}

Page *retrievePage(FILE *btree, const int pageRrn)
{
  int i;
  char aux[MAX_RA_DIGITS + MAX_RRN_DIGITS + 1], ra[MAX_RA_DIGITS + 1], rrn[MAX_RRN_DIGITS + 1];
  Page *page;

  if (ROOT_RRN < 0 || pageRrn < 0 || pageRrn > CURRENT_RRN) // If the tree is empty or the page RRN is invalid
    return NULL;

  page = createPage();
  fseek(btree, INDEX_START + pageRrn * SIZE_OF_BTREE_PAGE_RECORD, SEEK_SET);
  for (i = 0; i < TREE_ORDER; i++)
  {
    // Read children
    if (!fgets(aux, MAX_RRN_DIGITS + 1, btree))
    {
      printError("Erro ao ler dados do índice!");
      exit(1);
    }

    if (aux[0] != '?')
    {
      strncpy(rrn, aux, MAX_RRN_DIGITS); // Capture RRN
      rrn[MAX_RRN_DIGITS] = '\0';
      page->children[i] = atoi(rrn);
    }
    else
      page->children[i] = -1;

    if (i < MAX_KEYS)
    {
      // Read key pair (ra + rrn)
      if (!fgets(aux, MAX_RRN_DIGITS + MAX_RA_DIGITS + 1, btree))
      {
        printError("Erro ao ler dados do índice!");
        exit(1);
      }

      if (aux[0] != '?')
      { // Há chave
        page->keysCount++;
        strncpy(ra, aux, MAX_RA_DIGITS); // Capture RA
        ra[MAX_RA_DIGITS] = '\0';
        strncpy(rrn, aux + MAX_RA_DIGITS, MAX_RRN_DIGITS); // Capture RRN
        rrn[MAX_RRN_DIGITS] = '\0';
        page->keys[i].raUnesp = atoi(ra);
        page->keys[i].pos = atoi(rrn);
      }
      else
      { // Não há chave
        page->keys[i].raUnesp = -1;
        page->keys[i].pos = -1;
      }
    }
  }
  return page;
}

void writePageOnFile(FILE *btree, Page *page, const int pageRrn)
{
  const char *aux = "?????????";
  int i;

  fseek(btree, INDEX_START + pageRrn * SIZE_OF_BTREE_PAGE_RECORD, SEEK_SET);
  for (i = 0; i < TREE_ORDER; i++)
  {
    if (page->children[i] >= 0)
      fprintf(btree, "%04d", page->children[i]);
    else
      fprintf(btree, "%.4s", aux);

    if (i < page->keysCount && page->keys[i].raUnesp >= 0)
      fprintf(btree, "%09d%04d", page->keys[i].raUnesp, page->keys[i].pos);
    else if (i < MAX_KEYS)
      fprintf(btree, "%.9s%.4s", aux, aux);
  }
}

int findRaInBtree(FILE *btree, const int rrn, const int ra, int *foundRrn, int *keyPosition, int *seeks)
{
  int pos;
  Page *page = retrievePage(btree, rrn);

  if (!page)
  {
    free(page);
    page = NULL;
    return !FOUND;
  }

  if (seeks)
    *seeks = *seeks + 1; // Seeks counter

  pos = 0;
  while (pos < page->keysCount && page->keys[pos].raUnesp < ra)
    pos++;

  if (pos < MAX_KEYS && page->keys[pos].raUnesp == ra)
  { // Key found
    *foundRrn = rrn;
    *keyPosition = pos;

    free(page);
    page = NULL;

    return FOUND;
  }

  return findRaInBtree(btree, page->children[pos], ra, foundRrn, keyPosition, seeks);
}

IndexNode *searchRa(const int ra, int *seeks)
{
  int found, foundRrn, keyPosition;
  IndexNode *foundNode;
  Page *page;
  FILE *btree = openBTreeIndex(BTREE_FILENAME);

  if (ROOT_RRN < 0) // If the three is empty, return NULL
    return NULL;

  found = findRaInBtree(btree, ROOT_RRN, ra, &foundRrn, &keyPosition, seeks);
  if (!found)
    return NULL;

  page = retrievePage(btree, foundRrn);
  fclose(btree);

  foundNode = &page->keys[keyPosition];

  free(page);
  page = NULL;

  return foundNode;
}

int isRaInRange(const int ra)
{
  return ra >= 0 && ra < 1000000000;
}

int isRaValid(const int ra)
{
  IndexNode *key;
  if (isRaInRange(ra))
  {
    key = searchRa(ra, NULL);
    if (key)
      return -1; // Key duplicated
    return 1;    // Key is valid
  }
  return 0; // Key is not in range
}

void insertKeyInPage(const IndexNode key, const int rightChild, const int pos, Page *page)
{
  int i = pos;
  while (i < page->keysCount)
  {
    page->keys[i + 1] = page->keys[i];
    page->children[i + 1 + 1] = page->children[i + 1];
    i++;
  }

  page->keysCount++;
  page->keys[pos] = key;
  page->children[pos + 1] = rightChild;
}

void split(const IndexNode promoKey, const int rightChild, const int pos, Page *page, IndexNode *refPromoKey, int *refRightChild, Page **newPage)
{
  const int median = (MAX_KEYS + 1) / 2;
  IndexNode keys[MAX_KEYS + 1];
  int i, children[TREE_ORDER + 1];

  // Copy values from page.keys to the auxililary vector
  for (i = 0; i < page->keysCount; i++)
  {
    keys[i] = page->keys[i];
    children[i] = page->children[i];
  }
  children[i] = page->children[i]; // Copy last children

  // Inserts promoKey at the correct position
  for (i = page->keysCount; i > pos; i--)
  {
    keys[i] = keys[i - 1];
    children[i + 1] = children[i];
  }

  keys[pos] = promoKey;
  children[pos + 1] = rightChild;

  // Create newpage
  *newPage = createPage();
  CURRENT_RRN++; // Updates the RRN

  *refPromoKey = keys[median];
  *refRightChild = CURRENT_RRN;

  // Copy values from page.keys that are less than median
  for (i = median - 1; i >= 0; i--)
  {
    page->keys[i] = keys[i];
    page->children[i] = children[i];
  }
  page->children[median] = children[median];

  // Clears copied values to newpage
  for (i = median; i < page->keysCount; i++)
  {
    page->keys[i].raUnesp = page->keys[i].pos = -1;
    page->children[i + 1] = -1;
  }

  // Copy values from page.keys that are bigger than median
  for (i = median + 1; i <= page->keysCount; i++)
  {
    (*newPage)->keys[i - (median + 1)] = keys[i];
    (*newPage)->children[i - (median + 1)] = children[i];
  }
  (*newPage)->children[i - (median + 1)] = children[i];

  page->keysCount = median;
  (*newPage)->keysCount = MAX_KEYS - median;
}

int insertKey(FILE *btree, const int pageRrn, const IndexNode key, IndexNode *promoKey, int *rightChild)
{
  int pos, returnValue;
  Page *page, *newPage;

  if (pageRrn < 0)
  {
    *promoKey = key;
    *rightChild = -1;
    return PROMOTION;
  }

  page = retrievePage(btree, pageRrn);

  pos = 0;
  while (pos < page->keysCount && page->keys[pos].raUnesp < key.raUnesp)
    pos++;

  if (pos < MAX_KEYS && page->keys[pos].raUnesp == key.raUnesp)
  {
    printError("Chave duplicada!");
    return ERROR; // Duplicated key
  }

  returnValue = insertKey(btree, page->children[pos], key, promoKey, rightChild);
  if (returnValue == NO_PROMOTION || returnValue == ERROR)
  {
    free(page);
    page = NULL;
    return returnValue;
  }

  // Checks if page can contain the new key
  if (page->keysCount < MAX_KEYS)
  { // Key can be inserted into page
    insertKeyInPage(*promoKey, *rightChild, pos, page);
    writePageOnFile(btree, page, pageRrn);

    free(page);
    page = NULL;
    return NO_PROMOTION;
  }

  // Realizes split and promotion logic
  split(*promoKey, *rightChild, pos, page, promoKey, rightChild, &newPage);
  writePageOnFile(btree, page, pageRrn);
  writePageOnFile(btree, newPage, CURRENT_RRN);

  free(page);
  page = NULL;
  free(newPage);
  newPage = NULL;
  return PROMOTION;
}

void updateRoot(FILE *btree, const IndexNode promoKey, const int rightChild)
{
  Page *newRoot = createPage();

  newRoot->keysCount = 1;
  newRoot->keys[0] = promoKey;
  newRoot->children[0] = ROOT_RRN;
  newRoot->children[1] = rightChild;

  CURRENT_RRN++;
  fseek(btree, 0, SEEK_SET);                                // Position W/R head at the header
  fprintf(btree, "%s=%04d\n", ROOT_KEY_VALUE, CURRENT_RRN); // Updates header
  ROOT_RRN = CURRENT_RRN;                                   // Updates the new ROOT_RRN value

  writePageOnFile(btree, newRoot, CURRENT_RRN);

  free(newRoot);
  newRoot = NULL;
}

void insertIntoBtree(IndexNode node)
{
  int rightChild;
  IndexNode promoKey;
  FILE *btree = openBTreeIndex(BTREE_FILENAME);

  if (insertKey(btree, ROOT_RRN, node, &promoKey, &rightChild) == PROMOTION)
    updateRoot(btree, promoKey, rightChild);

  fclose(btree);
}

void fillRecord(FILE *dataFile, Student record)
{
  int i;
  int nDigits = (int)(log10(abs(record.raUnesp))) + 1;
  int nameSize = strnlen(record.name, MAX_STRING_SIZE);
  int courseSize = strnlen(record.course, MAX_STRING_SIZE);

  fprintf(dataFile, "%d;%s;%s;", record.raUnesp, record.name, record.course);

  for (i = 0; i < RECORD_SIZE - (nDigits + nameSize + courseSize + 3); i++)
    fprintf(dataFile, "%c", FILL_RECORD_CHARACTER);
}

void insertIntoDatafile(FILE *dataFile, Student student, IndexNode *node)
{
  // Position W/R head to the end of file
  fseek(dataFile, 0, SEEK_END);

  node->raUnesp = student.raUnesp;
  node->pos = ftell(dataFile);
  fillRecord(dataFile, student);
}

void readStudent()
{
  int r, raValid, ra;
  Student newStudent;
  IndexNode newNode;
  FILE *dataFile = openFile(DATA_FILENAME, "a+");

  printHeader("CADASTRAR NOVO ALUNO");
  printf("\n--> Digite o nome do aluno: ");
  readString(newStudent.name, MAX_STRING_SIZE);

  printf("\n--> Digite o nome do curso: ");
  readString(newStudent.course, MAX_STRING_SIZE);

  do
  {
    printf("\n--> Digite o RA do aluno: ");
    r = scanf(" %d", &ra);

    clearEOF();

    raValid = isRaValid(ra);
    if (r && raValid < 0)
      printWarning("O RA inserido já existe na base de dados!");
    else if (!r || !raValid)
      printWarning("Insira uma valor válido!");
  } while (!r || raValid != 1);

  newStudent.raUnesp = ra;

  // Insert into Datafile
  insertIntoDatafile(dataFile, newStudent, &newNode);
  fclose(dataFile);

  // Insert into BTree
  insertIntoBtree(newNode);

  printf("\n\n--> Aluno inserido com sucesso!\n");
}

void printStudent(const int pos)
{
  char *token, record[RECORD_SIZE + 1];
  FILE *dataFile = openFile(DATA_FILENAME, "r");

  if (!dataFile)
  {
    printError("O arquivo especificado não existe!");
    exit(1);
  }

  fseek(dataFile, pos, SEEK_SET);
  if (fgets(record, RECORD_SIZE + 1, dataFile))
  {
    token = strtok(record, FIELDS_DELIMETER);

    printf("\n--> RA do Aluno: %d", atoi(token));
    token = strtok(NULL, FIELDS_DELIMETER);

    printf("\n--> Nome do Aluno: %s", token);
    token = strtok(NULL, FIELDS_DELIMETER);

    printf("\n--> Curso: %s\n", token);
  }
  else
  {
    printError("Erro ao ler os dados do aluno!");
    exit(-1);
  }
}

void searchStudent()
{
  int r, ra, seeks = 0;
  IndexNode *node;

  printHeader("BUSCAR ALUNO");

  if (ROOT_RRN < 0)
  { // The tree is empty
    printWarning("A lista de alunos está vazia!");
    return;
  }

  do
  {
    printf("\n\n--> Digite o RA do aluno: ");
    r = scanf(" %d", &ra);

    clearEOF();

    if (!r)
      printWarning("Insira uma valor válido!");
  } while (!r);

  if (!isRaInRange(ra))
  {
    printWarning("Aluno não encontrado!");
    return;
  }

  node = searchRa(ra, &seeks);
  printf("\n\n*** Quantidade de Seeks necessários: %d\n", seeks);

  if (!node)
    printWarning("Aluno não encontrado!");
  else
    printStudent(node->pos);
}

void showMenu()
{
  int r, op;

  do
  {
    do
    {
      printHeader("MENU PRINCIPAL");
      printf("\n(1) Inserir Aluno");
      printf("\n(2) Buscar Aluno");
      printf("\n(0) Encerrar");

      printf("\n\n--> Digite uma opção: ");
      r = scanf(" %d", &op);

      clearEOF();

      if (!r || op < 0 || op > 2)
        printWarning("Insira uma opção válida!");
    } while (!r || op < 0 || op > 2);

    switch (op)
    {
    case 1:
      readStudent();
      break;

    case 2:
      searchStudent();
      break;

    case 0:
      printWarning("Obrigado por utilizar nossa aplicação! :)");
      break;

    default:
      break;
    }
  } while (op != 0);
}
