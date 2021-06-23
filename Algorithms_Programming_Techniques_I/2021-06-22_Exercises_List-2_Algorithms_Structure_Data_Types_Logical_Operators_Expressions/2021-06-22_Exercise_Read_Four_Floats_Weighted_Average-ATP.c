#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	float A, B, C, D, weigAverage;

	printf("\nInsira a primeira nota: ");
	scanf("%f", &A);

	printf("Insira a segunda nota: ");
	scanf("%f", &B);

	printf("Insira a terceira nota: ");
	scanf("%f", &C);

	printf("Insira a quarta nota: ");
	scanf("%f", &D);

	weigAverage = ((A * 1) + (B * 2) + (C * 3) + (D * 4)) / 10;

	printf("\nA média entre as notas %.2f, %.2f, %.2f e %.2f é: média de %.2lf\n", A, B, C, D, weigAverage);
	
	return 0;
}