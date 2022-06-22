#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
  fila *normal = (fila *)malloc(sizeof(fila));
  fila *preferencial = (fila *)malloc(sizeof(fila));
  Definir(normal);
  Definir(preferencial);
  int idade;

  Inserir(normal, 10);
  Inserir(normal, 5);
  Inserir(normal, 12);
  Inserir(normal, 13);

  Inserir(preferencial, 60);
  Inserir(preferencial, 62);
  Inserir(preferencial, 63);

  printf("\n---- Preferencial ----\n");
  Imprimir(preferencial);
  printf("\n------- Normal -------\n");
  Imprimir(normal);

  printf("\n");

  Chamar_senhas(normal, preferencial);

  printf("\n");

  printf("\n---- Preferencial ----\n");
  Imprimir(preferencial);
  printf("\n------- Normal -------\n");
  Imprimir(normal);

  printf("\n\n");

  return 0;
}