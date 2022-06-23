#include <stdio.h>
#include <stdlib.h>
#include "queue-dynamic.h"

// Operations
// -------------------------

// Create an empty list
void createQueue(Queue *queue)
{
  queue->start = NULL;
  queue->end = NULL;
}

// Verifies if the queue is empty
boolean queueIsEmpty(Queue *queue)
{
  return (queue->start == NULL);
}

// Clear the entire queue and then creates a new one
void restartQueue(Queue *queue)
{
  ElemType *node, *nextNode;

  if (!queueIsEmpty(queue))
  {
    node = queue->start;
    while (node != NULL)
    {
      nextNode = node->next;
      free(node);
      node = nextNode;
    }
  }

  createQueue(queue);
}

// Inserts an element at the end of the queue
boolean insert(Queue *queue, DataType newInfo)
{
  ElemType *newElement = (ElemType *)malloc(sizeof(ElemType));

  if (newElement == NULL)
    return FALSE;

  newElement->info = newInfo;
  newElement->next = NULL;

  if (queueIsEmpty(queue))
    queue->start = newElement;
  else
    queue->end->next = newElement;

  queue->end = newElement;
}

// Removes an element at the start of the queue
boolean removeFromQueue(Queue *queue, DataType *info)
{
  ElemType *element;

  if (queueIsEmpty(queue))
    return FALSE;

  element = queue->start;
  *info = element->info;
  queue->start = element->next;

  if (queue->start == NULL)
    queue->end = NULL;

  free(element);
  return TRUE;
}

// Gets the size of the queue
int getQueueSize(Queue *queue)
{
  ElemType *element;
  int count = 0;

  element = queue->start;
  while (element != NULL)
  {
    count++;
    element = element->next;
  }

  return count;
}

// Shows the first element of the queue without removing it
boolean getElementAtStart(Queue *queue, DataType *info)
{
  if (queueIsEmpty(queue))
    return FALSE;

  *info = queue->start->info;
  return TRUE;
}
