#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BTREE_FILENAME "btree.idx"
#define DATA_FILENAME "turma.dat"
#define ROOT_KEY_VALUE "RAIZ"
#define MAX_STRING_SIZE 58

const int TREE_ORDER = 3;
const int MIN_NODES = (TREE_ORDER / 2 + (TREE_ORDER / 2.0 - TREE_ORDER / 2 > 0 ? 1 : 0));
const int MAX_KEYS = TREE_ORDER - 1;
const int MIN_KEYS = MIN_NODES - 1;
const int MAX_RA_DIGITS = 9;
const int MAX_RRN_DIGITS = 4;
const int INDEX_START = strlen(ROOT_KEY_VALUE) + MAX_RRN_DIGITS + 2; // Size of jump at beginning of file
const int SIZE_OF_BTREE_PAGE_RECORD = (MAX_RRN_DIGITS + MAX_RA_DIGITS) * MAX_KEYS + TREE_ORDER * MAX_RRN_DIGITS;

int ROOT_RRN;
int CURRENT_RRN;

typedef struct index
{
  int raUnesp;
  int pos;
} IndexNode;

typedef struct page
{
  int keysCount;
  IndexNode keys[MAX_KEYS];
  int children[TREE_ORDER];
} Page;

typedef struct student
{
  int raUnesp;
  char name[MAX_STRING_SIZE + 1];
  char course[MAX_STRING_SIZE + 1];
} Student;

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
  printf("\n\n!--> %s\n", text);
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
  clearEOF();
}

int getRootRRN(FILE *btree)
{
  int rrn;
  char aux[256] = {0};
  fseek(btree, 0, SEEK_SET); // Points to beginning of file
  if (fscanf(btree, "%[^=]=%d\n", aux, &rrn) <= 0 || strcasecmp(aux, ROOT_KEY_VALUE))
  {
    printError("O arquivo contém erros ou é incompatível com este programa!");
    exit(1);
  }
  return rrn;
}

FILE *openBTreeIndex(const char *filename)
{
  FILE *fp = openFile(filename, "r+");
  if (!fp)
  {                                              // If the file doesn't exist
    fp = openFile(filename, "w+");               // Create a file
    fprintf(fp, "%s=%04d\n", ROOT_KEY_VALUE, 0); // Set ROOT_RRN to 0
    ROOT_RRN = 0;
  }
  else
    ROOT_RRN = getRootRRN(fp);
  return fp;
}

void printHeader(const char *text)
{
  printf("======== %s\n", text);
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
  Page *page = createPage();

  fseek(btree, INDEX_START + pageRrn * SIZE_OF_BTREE_PAGE_RECORD, SEEK_SET);
  for (i = 0; i < TREE_ORDER; i++)
  {
    // Read children
    if (!fgets(aux, MAX_RRN_DIGITS + 1, btree))
    {
      printError("Erro ao ler dados do índice!");
      exit(1);
    }

    if (!(aux[0] == '?'))
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

      if (!(aux[0] == '?'))
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
  const char aux[MAX_STRING_SIZE] = {'?'};
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

void searchRa()
{
  FILE *btree = openBTreeIndex(BTREE_FILENAME);

  fclose(btree);
}

int isRaValid(const int ra)
{
}

void readStudent()
{
  int r, ra;
  Student newStudent;
  FILE *dataFile = openFile(DATA_FILENAME, "a+");

  printHeader("CADASTRAR NOVO ALUNO");
  printf("\n\n--> Digite o nome do aluno: ");
  readString(newStudent.name, MAX_STRING_SIZE);

  printf("\n\n--> Digite o nome do curso: ");
  readString(newStudent.course, MAX_STRING_SIZE);

  do
  {
    printf("\n\n--> Digite o RA do aluno: ");
    r = scanf(" %d", &ra);

    clearEOF();

    if (!r || isRaValid(ra)) // RA must be in this interval
      printWarning("Insira uma opção válida!");
  } while (!r || isRaValid(ra));

  newStudent.raUnesp = ra;

  // Insert into datafile
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
      printHeader("BUSCAR ALUNO");
      break;

    case 0:
      printWarning("Obrigado por utilizar nossa aplicação! :)");
      break;

    default:
      break;
    }
  } while (op != 0);
}

void printPageOnScreen(Page *page)
{
  int i;
  for (i = 0; i < TREE_ORDER; i++)
  {
    printf("%04d|", page->children[i]);
    if (i < page->keysCount)
      printf("%09d,%04d|", page->keys[i].raUnesp, page->keys[i].pos);
    else if (i < MAX_KEYS)
      printf("%09d,%04d|", -1, -1);
  }
  printf("\n");
}

int main()
{
  return 0;
}