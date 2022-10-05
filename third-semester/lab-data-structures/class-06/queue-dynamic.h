#define boolean int
#define TRUE 1
#define FALSE 0

// Structures and Other Types
// Data Type
typedef struct
{
  char name[30];
  // .....
} DataType;

// Element Type (type of element for dynamic implementation)
typedef struct elem
{
  DataType info;
  struct elem *next;
} ElemType;

// Queue Type
typedef struct
{
  ElemType *start;
  ElemType *end;
} Queue;

// Operations Prototypes
// -------------------------------

// Create an empty list
void createQueue(Queue *);

// Verifies if the queue is empty
boolean queueIsEmpty(Queue *);

// Clear the entire queue and then creates a new one
void restartQueue(Queue *);

// Inserts an element at the end of the queue
boolean insert(Queue *, DataType);

// Gets the size of the queue
int getQueueSize(Queue *);

// Shows the first element of the queue without removing it
boolean getElementAtStart(Queue *, DataType *);

// Removes an element at the start of the queue
boolean removeFromQueue(Queue *, DataType *);