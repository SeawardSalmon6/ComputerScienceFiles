#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int num1, num2, num3, num4, num5, bigger, smaller;

	printf("\nInsira um número: ");
	scanf("%d", &num1);

	printf("Insira mais um número: ");
	scanf("%d", &num2);

	printf("Insira outro número: ");
	scanf("%d", &num3);

	printf("Insira mais outro número: ");
	scanf("%d", &num4);

	printf("Insira o último número: ");
	scanf("%d", &num5);

	if((num1 <= num2 && num1 <= num3 && num1 <= num4 && num1 <= num5))
		smaller = num1;
	else if((num2 <= num1 && num2 <= num3 && num2 <= num4 && num2 <= num5))
		smaller = num2;
	else if((num3 <= num1 && num3 <= num2 && num3 <= num4 && num3 <= num5))
		smaller = num3;
	else if((num4 <= num1 && num4 <= num2 && num4 <= num3 && num4 <= num5))
		smaller = num4;
	else if((num5 <= num1 && num5 <= num2 && num5 <= num3 && num5 <= num4))
		smaller = num5;

	if((num1 >= num2 && num1 >= num3 && num1 >= num4 && num1 >= num5))
		bigger = num1;
	else if((num2 >= num1 && num2 >= num3 && num2 >= num4 && num2 >= num5))
		bigger = num2;
	else if((num3 >= num1 && num3 >= num2 && num3 >= num4 && num3 >= num5))
		bigger = num3;
	else if((num4 >= num1 && num4 >= num2 && num4 >= num3 && num4 >= num5))
		bigger = num4;
	else if((num5 >= num1 && num5 >= num2 && num5 >= num3 && num5 >= num4))
		bigger = num5;

	printf("\nO maior número é: %d", bigger);
	printf("\nO menor número é: %d\n\n", smaller);

	return 0;
}