#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int somaPares = 0, counter = 0;

	printf("\n=========== SOMA DOS NÚMEROS PARES [0, 500] ===========\n");

	for(int i = 0; i <= 500; i += 2) {
		somaPares += i;
		printf("\n\t%dº = %d", counter, somaPares);

		counter++;
	}

	printf("\n\n");

	return 0;
}