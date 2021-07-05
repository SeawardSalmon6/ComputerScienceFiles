#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int num1, num2, num3, fstNum, scndNum, lastNum;

	printf("\nInsira um número: ");
	scanf("%d", &num1);

	printf("Insira mais um número: ");
	scanf("%d", &num2);

	printf("Insira outro número: ");
	scanf("%d", &num3);

	if((num1 <= num2 && num1 <= num3))
		fstNum = num1;
	else if((num2 <= num1 && num2 <= num3))
		fstNum = num2;
	else if((num3 <= num1 && num3 <= num2))
		fstNum = num3;

	if((num1 >= num2 && num1 >= num3))
		lastNum = num1;
	else if((num2 >= num1 && num2 >= num3))
		lastNum = num2;
	else if((num3 >= num1 && num3 >= num2))
		lastNum = num3;

	if((fstNum == num1 && lastNum == num2))
		scndNum = num3;
	else if((fstNum == num1 && lastNum == num3))
		scndNum = num2;
	else if((fstNum == num2 && lastNum == num1))
		scndNum = num3;
	else if((fstNum == num2 && lastNum == num3))
		scndNum = num1;
	else if((fstNum == num3 && lastNum == num1))
		scndNum = num2;
	else
		scndNum = num1;

	printf("\nNúmeros em ordem crescente:\n");
	printf("%d, %d, %d\n\n", fstNum, scndNum, lastNum);

	return 0;
}