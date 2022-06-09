#include <stdio.h>
#include "queue.h"

// Queue operations
// -----------------------

// Creates an empty queue
void defineQueue(Queue *queue)
{
  queue->start = 0;
  queue->end = 0;
}

// Checks if the queue is empty
boolean isQueueEmpty(Queue *queue)
{
  return (queue->start == queue->end);
}

// Checks if the queue is full
boolean isQueueFull(Queue *queue)
{
  return (queue->start == ((queue->end + 1) % QUEUE_SIZE));
  // OBS: both pointers differ one position
}

// Adds a new element at the end of the queue
boolean insertInQueue(Queue *queue, DataType newElem)
{
  if (isQueueEmpty(queue))
    return FALSE;

  queue->end = (queue->end + 1) % QUEUE_SIZE;
  queue->arr[queue->end] = newElem;
  return TRUE;
}

// Removes an element at the beginning of the queue
boolean removeFromQueue(Queue *queue, DataType *elem)
{
  if (isQueueEmpty(queue))
    return FALSE;

  queue->start = (queue->start + 1) % QUEUE_SIZE;
  *elem = queue->arr[queue->start];
  return TRUE;
}

// Returns the queue size
int queueSize(Queue *queue)
{
  if (queue->start <= queue->end)
    return (queue->end - queue->start);

  return (QUEUE_SIZE - ((queue->start - queue->end)));
}

// Shows the start of the queue without removing the element
boolean queueStart(Queue *queue, DataType *elem)
{
  if (isQueueEmpty(queue))
    return FALSE;

  *elem = queue->arr[(queue->start + 1) % QUEUE_SIZE];
  return TRUE;
}