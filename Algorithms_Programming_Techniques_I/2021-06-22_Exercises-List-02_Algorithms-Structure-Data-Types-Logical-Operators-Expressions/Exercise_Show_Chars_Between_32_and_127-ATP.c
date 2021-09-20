#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i, counter = 0;
	char showChar;

	printf("\n ================ LISTA DE CARACTERES ASCII (32-127) ================\n");

	for(i = 32; i < 127; i++) {
		showChar = i;

		if(counter % 10 == 0)
			printf("\n");

		printf(" | %c |", showChar);
		counter++;
	}

	printf("\n\n");

	return 0;
}