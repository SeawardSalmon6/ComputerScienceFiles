#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	printf("\nQtd. Memória dos Tipos Padrões - char, int, float, double");
	printf("\n - char: %lu", sizeof(char));
	printf("\n - int: %lu", sizeof(int));
	printf("\n - float: %lu", sizeof(float));
	printf("\n - double: %lu", sizeof(double));

	printf("\n\nQtd. Memória dos Tipos Unsigned e Long - char, int, float, double");
	printf("\nTipo char:");
	printf("\n\t - unsigned char: %lu", sizeof(unsigned char));
	printf("\nTipo int:");
	printf("\n\t - unsigned int: %lu", sizeof(unsigned int));
	printf("\n\t - long int: %lu", sizeof(long int));
	printf("\n\t - unsigned long int: %lu", sizeof(unsigned long int));
	printf("\nTipo double:");
	printf("\n\t - long double: %lu", sizeof(long double));

	printf("\n\nOBS: os tipos unsigned e long não são permitidos para o tipo float.\n\n");

	return 0;
}