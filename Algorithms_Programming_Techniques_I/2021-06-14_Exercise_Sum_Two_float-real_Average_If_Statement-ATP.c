#include <stdio.h>

int main() {
	float A, B, average;

	printf("Insira dois valores de notas (em reais), abaixo:\n");
	scanf("%f %f", &A, &B);

	average = (A + B) / 2;

	if(average >= 5) {
		printf("\nA média é maior ou igual a 5!\nMédia = %.2f\n", average);

	} else {
		printf("\nA média não é maior ou igual a 5!\nMédia = %.2f\n", average);
	} 

	return 0;
}