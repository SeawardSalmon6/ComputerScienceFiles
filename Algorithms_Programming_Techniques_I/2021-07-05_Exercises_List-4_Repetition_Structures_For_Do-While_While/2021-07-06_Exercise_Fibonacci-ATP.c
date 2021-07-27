#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int termAntAnterior = 1, termAnterior = 0, novoTermo = 0;

	printf("\n======== SÉRIE DE FIBONACCI ========\n");

	for(int i = 1; i <= 15; i++) {
		novoTermo = termAntAnterior + termAnterior;

		printf("\n\t%dº Termo -> %d", i, novoTermo);

		if(i == 1)
		    termAntAnterior = 0;
		else
		    termAntAnterior = termAnterior;
		
		termAnterior = novoTermo;
	}

	printf("\n\n");

	return 0;
}