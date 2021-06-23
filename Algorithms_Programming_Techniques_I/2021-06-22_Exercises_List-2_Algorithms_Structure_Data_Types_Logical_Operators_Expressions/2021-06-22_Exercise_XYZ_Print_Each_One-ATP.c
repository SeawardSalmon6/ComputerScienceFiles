#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int num, X, Y, Z;

	printf("\nInsira um número de 3 algarismos: ");
	scanf("%d", &num);

	X = num / 100;
	Y = num / 10 - (X * 10);
	Z = num - (X * 100) - (Y * 10);

	printf("\nO valor de X é: %d", X);
	printf("\nO valor de Y é: %d", Y);
	printf("\nO valor de Z é: %d\n", Z);

	return 0;
}