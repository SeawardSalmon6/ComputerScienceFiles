#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int num1, num2, bigger, smaller;
	double avg;

	do {
		printf("\nInsira um número inteiro e positivo: ");
		scanf(" %d", &num1);

		if(num1 < 0)
			printf("Insira um valor válido!\n");

	} while(num1 < 0);

	do {
		printf("\nInsira outro número inteiro e positivo: ");
		scanf(" %d", &num2);

		if(num2 < 0)
			printf("Insira um valor válido!\n");

	} while(num2 < 0);

	// área de cáculos
	bigger = num1 >= num2 ? num1 : num2;
	smaller = num1 <= num2 ? num1 : num2;

	avg = (num1 + num2) / 2.00;

	printf("\n---------------------------------");

	printf("\nO maior número é %d", bigger);
	printf("\nO menor número é %d", smaller);
	printf("\nA média dos dois números é %.2lf\n\n", avg);

	return 0;
}