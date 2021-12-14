#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double ArredondaBaixo(double numero, int casas) {
	int i;
	for(i = 0; i < casas; i++)
		numero *= 10;

	numero = (unsigned long long) numero;
	for(i = 0; i < casas; i++)
		numero /= 10;

	return (numero);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int p = 13;
	double num = 3.141592653589793;

	printf("\n--> O número %.*lf é igual a: %.*lf\n", p, num, p, num);
	printf("\n--> (arredondado) O número %.*lf é igual a: %.*lf\n\n", p, num, p, ArredondaBaixo(num, p));

	return 0;
}
