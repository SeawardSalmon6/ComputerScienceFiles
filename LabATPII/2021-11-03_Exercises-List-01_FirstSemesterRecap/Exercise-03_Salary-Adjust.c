/* Faça um programa em C/C++, para calcular o novo salário de um funcionário. Sabe-se que os funcionários que recebem atualmente salário de até R$ 500 terão aumento de 20%. Os que recebem até R$ 1000 terão aumento de 10%. Os demais terão aumento de 5%. */

#include <stdio.h>
#include <locale.h>

float updateSalary(float);

int main() {
	setlocale(LC_ALL, "Portuguese");

	float funcSalary;

	puts("\n--- Exercise 03 - Salary Adjust");
	puts("\nInsira o salário de seu funcionário: ");
	scanf(" %f", &funcSalary);

	printf("\n--> Salário Atual: R$%.2f", funcSalary);
	printf("\n--> Salário Reajustado: R$%.2f\n\n", updateSalary(funcSalary));

	return 0;
}

float updateSalary(float salary) {
	const float til500 = 0.20, til1000 = 0.10, others = 0.05;
	if(salary < 500)
		salary += salary * til500;
	else if(salary >= 500 && salary < 1000)
		salary += salary * til1000;
	else
		salary += salary * others;

	return salary;
}
