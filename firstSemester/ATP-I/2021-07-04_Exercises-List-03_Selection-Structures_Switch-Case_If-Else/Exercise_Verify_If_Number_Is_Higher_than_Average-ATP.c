#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int num1, num2, num3;
	float average;

	printf("\nInsira um número: ");
	scanf("%d", &num1);

	printf("Insira mais um número: ");
	scanf("%d", &num2);

	printf("Insira outro número: ");
	scanf("%d", &num3);

	average = (num1 + num2 + num3) / 3;

	if(num1 >= average)
		printf("\nO número %d é maior ou igual a média dos números %d, %d e %d, que é igual a %.2f\n\n", num1, num1, num2, num3, average);
	else if(num2 >= average)
		printf("\nO número %d é maior ou igual a média dos números %d, %d e %d, que é igual a %.2f\n\n", num2, num1, num2, num3, average);
	else if(num3 >= average)
		printf("\nO número %d é maior ou igual a média dos números %d, %d e %d, que é igual a %.2f\n\n", num1, num1, num2, num3, average);

	return 0;
}