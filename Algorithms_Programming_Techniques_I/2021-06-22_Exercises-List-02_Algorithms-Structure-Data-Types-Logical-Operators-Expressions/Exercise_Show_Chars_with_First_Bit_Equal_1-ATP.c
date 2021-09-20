#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i, counter = 0;
	unsigned char showChar;

	printf("\n ================ LISTA DE CARACTERES ASCII (com o primeiro bit = 1) ================\n");

	for(i = 0; i < 127; i++) {
		showChar = i;

		if(i % 2 != 0) {
			if(counter % 10 == 0)
				printf("\n");
			
			printf(" | %c |", showChar);
			counter++;
		}
	}

	printf("\n\n");

	return 0;
}