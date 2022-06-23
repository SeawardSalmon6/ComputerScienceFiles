#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void Imprimir_filas(fila *normal, fila *preferencial)
{
  printf("\n---- Preferencial ----\n");
  Imprimir(preferencial);

  printf("\n------- Normal -------\n");
  Imprimir(normal);
}

int main()
{
  fila *normal = (fila *)malloc(sizeof(fila));
  fila *preferencial = (fila *)malloc(sizeof(fila));

  Definir(normal);
  Definir(preferencial);

  // Realiza as inserções padrão na lista Normal
  Inserir(normal, 10);
  Inserir(normal, 5);
  Inserir(normal, 12);
  Inserir(normal, 13);

  // Realiza as inserções padrão na lista Preferencial
  Inserir(preferencial, 60);
  Inserir(preferencial, 62);
  Inserir(preferencial, 63);

  // Imprime as filas antes das chamadas das senhas
  Imprimir_filas(normal, preferencial);

  // Realiza a chamada das Senhas (1 elemento da preferencial --- se houver --- para 2 elementos da normal --- se houver)
  Chamar_senhas(normal, preferencial);

  // Imprime as filas depois das chamadas das senhas
  Imprimir_filas(normal, preferencial);

  printf("\n");
  return 0;
}