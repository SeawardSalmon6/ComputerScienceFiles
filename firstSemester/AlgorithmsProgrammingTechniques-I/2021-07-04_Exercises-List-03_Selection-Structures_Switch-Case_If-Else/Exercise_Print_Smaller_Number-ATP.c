#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int num1, num2, num3, smaller;

	printf("\nInsira um número: ");
	scanf("%d", &num1);

	printf("Insira mais um número: ");
	scanf("%d", &num2);

	printf("Insira outro número: ");
	scanf("%d", &num3);

	if(num1 == num2 || num1 == num3 || num2 == num3)
		printf("\nTodos os números devem ser diferentes! Insira-os novamente.\n\n");

	else {
		if((num1 <= num2 && num1 <= num3))
			smaller = num1;
		else if((num2 <= num1 && num2 <= num3))
			smaller = num2;
		else if((num3 <= num1 && num3 <= num2))
			smaller = num3;

		printf("\nO maior número é: %d\n\n", smaller);
	}

	return 0;
}