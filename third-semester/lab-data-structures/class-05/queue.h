#define QUEUE_SIZE 100
#define index int
#define boolean int
#define TRUE 1
#define FALSE 0

// Data type
// typedef struct
// {
//   char name[30];
//   //... (caso tenha mais campos)
// } DataType;
typedef int DataType;

// Tipo fila (seq. encadeada)
typedef struct
{
  DataType arr[QUEUE_SIZE];
  index start, end;
} Queue;

// ------------------------------------
// Definition (Prototypes)

// Creates an empty queue
void defineQueue(Queue *);

// Checks if the queue is empty
boolean isQueueEmpty(Queue *);

// Checks if the queue is full
boolean isQueueFull(Queue *);

// Adds a new element at the end of the queue
boolean insertInQueue(Queue *, DataType);

// Removes an element at the beginning of the queue
boolean removeFromQueue(Queue *, DataType *);

// Returns the queue size
int queueSize(Queue *);

// Shows the start of the queue without removing the element
boolean queueStart(Queue *, DataType *);