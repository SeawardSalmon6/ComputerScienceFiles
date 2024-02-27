#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
  int id;
  struct list *next;
} List;

List *ls_create(const int id)
{
  List *n = (List *)malloc(sizeof(List));
  if (!n)
  {
    printf("\nError allocating memory!\n");
    exit(1);
  }

  n->id = (int)id;
  n->next = NULL;

  return n;
}

void freeList(List **list)
{
  if (*list)
  {
    List *aux = *list;
    while (aux)
    {
      (*list) = aux->next;
      free(aux);
      aux = *list;
    }
    *list = NULL;
  }
}

int main(int argc, char *argv[])
{
  List *head = ls_create(1);
  List *l2 = ls_create(2);
  List *l3 = ls_create(3);

  head->next = l2;
  head->next->next = l3;

  printf("%p\n", head);

  freeList(&head);

  printf("%p\n", head);

  return 0;
}