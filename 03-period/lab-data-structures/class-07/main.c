#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

// Exemplo
int main()
{
	// Declara��o de vari�veis
	int i;
	tree raiz;
	tipo_dado valores[6];

	Definir(raiz);

	// Preenche com vetor de elementos quaisquer
	for (i = 0; i < 6; i++)
		valores[i].valor = i * i + 2;

	// Criar_raiz(raiz, valores[0]);
	// printf("\n%d\n\n", raiz->info.valor);

	// In_ordem(raiz);

	return 0;
}
