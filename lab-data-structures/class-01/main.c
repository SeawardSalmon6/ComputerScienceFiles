#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(int argc, char *argv[])
{
  float a, b, c, d;
  Matriz *M;

  // Cria uma matriz 5x5
  M = cria(5, 5);

  // Insere valores na matriz
  atribui(M, 1, 2, 40);
  atribui(M, 2, 3, 3);
  atribui(M, 3, 0, 15);
  atribui(M, 4, 1, 21);

  // Verifica se a inserção foi feita corretamente
  a = acessa(M, 1, 2);
  b = acessa(M, 2, 3);
  c = acessa(M, 3, 0);
  d = acessa(M, 4, 1);

  printf("M[1][2]: %4.2f \n", a);
  printf("M[2][3]: %4.2f \n", b);
  printf("M[3][0]: %4.2f \n", c);
  printf("M[4][1]: %4.2f \n", d);

  return 0;
}
