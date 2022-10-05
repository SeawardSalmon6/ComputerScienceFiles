#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define boolean int

// Tipo registro
typedef struct
{
  char name[30];
  // ... (preencher outros atributos)
} DataType;

// Tipo elemento (unidade dinâmica)
typedef struct elem
{
  DataType info;
  struct elem *next;
} ElemType;

// Tipo pilha
typedef struct
{
  ElemType *top;
} Stack;

// Cria uma pilha vazia
void createStack(Stack *stack)
{
  stack->top = NULL;
}

// Insere o elemento no topo da pilha (empilha): Push(x, p)
boolean push(DataType info, Stack *stack)
{
  ElemType *aux = (ElemType *)malloc(sizeof(ElemType));

  if (aux == NULL) // Não possui memória disponível
    return FALSE;

  // Insere elem e faz as ligações necessárias
  aux->info = info;
  aux->next = stack->top;
  stack->top = aux;

  return TRUE;
}

// Testa se a pilha está vazia
boolean isEmpty(Stack *stack)
{
  return (stack->top == NULL);
}

// Acessa o elemento do topo da pilha (mas sem removê-lo)
ElemType *getTopo(Stack *stack)
{
  if (!isEmpty(stack))
    return stack->top;

  return NULL;
}

// Remove o elemento no topo da pilha sem retorna o valor (desempilhar v.01)
void popUp(Stack *stack)
{
  if (!isEmpty(stack))
  {
    ElemType *aux = stack->top;
    stack->top = stack->top->next;
    free(aux);
    return;
  }

  printf("\n==!== Warning: the stack is empty!\n");
}

// Remove o elemento no topo da pilha e devolve of valor (desempilhar v.02)
ElemType *pop(Stack *stack)
{
  if (!isEmpty(stack))
  {
    ElemType *aux = stack->top;
    stack->top = stack->top->next;
    return aux;
  }

  return NULL;
}