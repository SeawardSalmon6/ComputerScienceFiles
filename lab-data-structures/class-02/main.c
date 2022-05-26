#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
  Lista *minhaLista;
  TipoElem elem01 = {12, {"Hello"}};
  Definir(minhaLista);

  Impr_elem(elem01);

  return 0;
}