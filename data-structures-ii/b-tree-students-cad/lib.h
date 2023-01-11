// Definitions
#define MAX_STRING_SIZE 58
#define RECORD_SIZE 128
#define FIELDS_DELIMETER ";"
#define LIST_FILENAME "turma.dat"
#define INDEX_FILENAME "index.txt"
#define ROOT_ID_KEY "ROOT_ID"
#define FILL_RECORD_CHARACTER '#'

// B-Tree Definitions
#define TREE_ORDER 3
#define MAX TREE_ORDER - 1
#define MIN_NODES (TREE_ORDER / 2 + (TREE_ORDER / 2.0 - TREE_ORDER / 2 > 0 ? 1 : 0))
#define MIN MIN_NODES - 1

typedef struct
{ // Respecting 58 + 58 + 9 + 3 (delimiters) = 128 bytes
  char name[MAX_STRING_SIZE];
  char course[MAX_STRING_SIZE];
  int raUnesp;
} Aluno;

typedef struct
{
  int raUnesp;
  long pos;
} IndexNode;

typedef struct node
{
  int pageId;
  int count;
  IndexNode keys[MAX + 1];
  struct node *children[TREE_ORDER];
} BTreeNode;

// Global Variables
BTreeNode *root;
int pageIdCounter;

// Helpers
void clearTerminalEOF();
void fillRecord(FILE *, Aluno);
BTreeNode *createNode(IndexNode info, BTreeNode *child);
BTreeNode *getIndexListFromFile(FILE *, BTreeNode **);
void setIndexesBackup(FILE *, BTreeNode *);
int isRaValid(int, BTreeNode *);

// Program Functions
void readStudent(FILE *, BTreeNode **, BTreeNode **);
void findStudent(FILE *, BTreeNode **);
void showMenu(FILE *, BTreeNode **, BTreeNode **);