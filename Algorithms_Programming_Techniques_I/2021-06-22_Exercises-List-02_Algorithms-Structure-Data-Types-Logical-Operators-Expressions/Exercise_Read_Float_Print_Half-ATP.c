#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	float metade, A;

	printf("\nInsira um número: ");
	scanf("%f", &A);

	metade = A / 2;

	printf("\nA metade de %.2lf é: %.2lf\n", A, metade);
	
	return 0;
}