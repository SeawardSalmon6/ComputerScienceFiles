#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	float actSalary = 0,
		actPercent = 0,
		promotion = 0,
		newSalary = 0;

	printf("\nInsira o valor do salário atual de seu funcionário: R$");
	scanf("%f", &actSalary);

	printf("Qual a porcentagem de aumento do salário desse funcionário? (ex.: escrever 20 é igual a 20%%)\n");
	scanf("%f", &actPercent);

	promotion = (actPercent / 100) * actSalary;
	newSalary = actSalary + promotion;

	printf("\n-------- RESULTADO -------\n");
	printf("Novo Salário: R$%.2lf\n", newSalary);
	printf("Valor do Aumento: R$%.2lf\n", promotion);

	return 0;
}