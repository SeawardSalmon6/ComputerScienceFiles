#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	float hipotenusa, A, B;

	printf("\nInsira o valor do primeiro cateto: ");
	scanf("%f", &A);

	printf("\nInsira o valor do primeiro cateto: ");
	scanf("%f", &B);

	hipotenusa = sqrt((pow(A, 2) + pow(B, 2)));

	printf("\nA soma dos catetos A (%.2lf) e B (%.2lf) têm o valor da hipotenusa igual a: %.2lf u.a.\n", A, B, hipotenusa);
	
	return 0;
}