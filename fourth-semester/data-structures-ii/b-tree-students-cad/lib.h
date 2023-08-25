#include <stdio.h>
#include <string.h>

// Program Defs
#define BTREE_FILENAME "btree.idx"
#define DATA_FILENAME "turma.dat"
#define ROOT_KEY_VALUE "RAIZ"
/*
  58 bytes: nome do aluno
  58 bytes: nome do curso
  9 bytes : tamanho máximo do RA
  3 bytes : delimitadores (;)
 */
#define RECORD_SIZE 128
#define MAX_STRING_SIZE 58
#define FILL_RECORD_CHARACTER '#'
#define FIELDS_DELIMETER ";"

// BTree Related Defs
#define FOUND 1
#define PROMOTION 1
#define NO_PROMOTION 0
#define ERROR -1

// Constants and Program Variables
#define TREE_ORDER 5
#define MAX_KEYS (TREE_ORDER - 1)
#define MIN_NODES (TREE_ORDER / 2 + (TREE_ORDER / 2.0 - TREE_ORDER / 2 > 0 ? 1 : 0))
#define MIN_KEYS (MIN_NODES - 1)
#define MAX_RA_DIGITS 9
#define MAX_RRN_DIGITS 4
#define INDEX_START (strlen(ROOT_KEY_VALUE) + MAX_RRN_DIGITS + 2) // Size of jump at beginning of fill
#define SIZE_OF_BTREE_PAGE_RECORD ((MAX_RRN_DIGITS + MAX_RA_DIGITS) * MAX_KEYS + (TREE_ORDER * MAX_RRN_DIGITS))

extern int ROOT_RRN;
extern int CURRENT_RRN;

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

// Helpers
void clearEOF();
void fillRecord(FILE *, Student);
int isRaInRange(const int);
int isRaValid(const int);
FILE *openFile(const char *, const char *);
void printError(const char *);
void printHeader(const char *);
void printStudent(const int);
void printWarning(const char *);
void readString(char *, const size_t);

// Menu Related
void readStudent();
void searchStudent();
void showMenu();

// File Related
void insertIntoBtree(IndexNode);
void insertIntoDatafile(FILE *, Student, IndexNode *);
FILE *openBTreeIndex(const char *);

// BTree Related
Page *createPage();
int findRaInBtree(FILE *, const int, const int, int *, int *, int *);
int getRootRRN(FILE *);
int insertKey(FILE *, const int, const IndexNode, IndexNode *, int *);
void insertKeyInPage(const IndexNode, const int, const int, Page *);
Page *retrievePage(FILE *, const int);
IndexNode *searchRa(const int, int *);
void split(const IndexNode, const int, const int, Page *, IndexNode *, int *, Page **);
void updateRoot(FILE *, const IndexNode, const int);
void writePageOnFile(FILE *, Page *, const int);