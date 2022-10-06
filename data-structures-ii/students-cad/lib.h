// Definitions
#define MAX_STRING_SIZE 60
#define RECORD_SIZE 128
#define FIELDS_DELIMETER ";"
#define LIST_FILENAME "turma.txt"
#define INDEX_FILENAME "index.txt"
#define RECORDS_COUNT_KEY "RECORDS"
#define FILL_RECORD_CHARACTER '#'

typedef struct
{
  int raUnesp;
  int pos;
} TIndexNode;

typedef struct node
{
  TIndexNode info;
  struct node *prox;
} Node;

typedef struct
{ // Respecting 60 + 60 + 5 + 3 (delimiters) = 128 bytes
  char nome[MAX_STRING_SIZE];
  char curso[MAX_STRING_SIZE];
  int raUnesp;
} TAluno;

// Helpers
void clearTerminalEOF();
void fillRecord(FILE *, TAluno);
Node *createNode(TIndexNode);
Node *getIndexListFromFile(FILE *, Node **);
void setIndexesBackup(FILE *, Node *);

// Program Functions
void readStudent(FILE *, Node **, Node **);
void findStudent(FILE *, Node **);
void showMenu(FILE *, Node **, Node **);