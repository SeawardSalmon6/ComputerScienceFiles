#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	/* este tipo de variável não condiz com os valores utilizados, que vão de 0 a 65.535; ou seja, causa overflow
		
		unsigned int n, m, x;
	*/

	unsigned long int n, x, m;
	n = 4000000000;
	m = 300000000;
	x = n + m;

	printf("\nA soma de %lu + %lu é igual a: %lu\n\n", n, m, x);

	return 0;
}