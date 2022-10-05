// Definitions
#define MAX_STRING_SIZE 60
#define RECORD_SIZE 128
#define FIELDS_QUANTITY 3
#define FIELDS_DELIMETER ";"
#define LIST_FILENAME "turma.txt"
#define INDEX_FILENAME "index.txt"

typedef struct
{ // Respecting 60 + 60 + 5 + 3 (delimiters) = 128 bytes
  char nome[MAX_STRING_SIZE];
  char curso[MAX_STRING_SIZE];
  int raUnesp;
} TAluno;

// Helpers
void clearTerminalEOF();
void fillRecord(FILE *, TAluno);

// Program Functions
void readStudent(FILE *, FILE *);
void findStudent(FILE *, FILE *);
void showMenu(FILE *, FILE *);