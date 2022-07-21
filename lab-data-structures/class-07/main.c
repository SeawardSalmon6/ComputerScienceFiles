#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

//Exemplo
int main()
{
   //Declaração de variáveis
   int i;
   tree raiz;
   tipo_dado valores[6];
   
   //Preenche com vetor de elementos quaisquer
   for (i=0; i<6; i++)
      valores[i].valor = i*i+2;

   //...
 
   system("PAUSE");	
   return 0;
}
