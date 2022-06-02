#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define boolean int
#define MAX 101

char stack[MAX - 1];
int top;

// Funções simples para manusear pilha
// --------------------------------------------
void createStack(void)
{
  top = -1;
}

void push(char caractere)
{
  top++;
  stack[top] = caractere;
}

char pop(void)
{
  char c = stack[top];
  top--;
  return c;
}

boolean isEmpty(void)
{
  return (top == -1);
}
// --------------------------------------------

// Retorna TRUE, se a string contém uma se. válida (parênteses + colchetes), FALSE caso contrário
boolean stringIsValid(char s[])
{
  char c;
  int i;
  createStack();

  for (i = 0; s[i] != '\0'; i++)
  {
    switch (s[i])
    {
    case ')':
      if (isEmpty())
        return FALSE;

      c = pop(); // Desempilha se encontrar correspondente à esquerda

      if (c != '(')
        return FALSE;

      break; // Novo correspondente entrando
    case ']':
      if (isEmpty())
        return FALSE;

      c = pop(); // Desempilha se encontrar correspondente à esquerda

      if (c != '[')
        return FALSE;

      break; // Novo correspondente entrando
    case '}':
      if (isEmpty())
        return FALSE;

      c = pop(); // Desempilha se encontrar correspondente à esquerda

      if (c != '{')
        return FALSE;

      break; // Novo correspondente entrando
    default:
      if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == ')' || s[i] == ']' || s[i] == '}')
        push(s[i]);

      break;
    }
  }

  return isEmpty();
}

// Rotina principal
int main()
{
  char str[MAX];

  printf("\n--> Digite uma string contendo parênteses, colchetes e chaves: ");
  scanf(" %s", str);

  printf("\n---> Resultado: Sequência %s\n\n", stringIsValid(str) ? "válida!" : "inválida!");

  return 0;
}