#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	unsigned seed;
	
	printf("\nDigite a semente: ");
	scanf("%u", &seed); // %u de unsigned
	
	srand(seed);

	for(int i = 1; i <= 7; i++) {
		for(int j = 1; j <= 3; j++)
			printf("%d. Number - %d \t\t", j, (1 + rand() % 6));
		
		printf("\n");
	}
		
	printf("\n\n");

	return 0;
}