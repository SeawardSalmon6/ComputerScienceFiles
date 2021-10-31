#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	const float INSS = 0.08;

	float bruteSalary = 0,
		  valExtras = 0,
		  qtdExtras = 0,
		  salary = 0,
		  liquidSalary = 0,
		  deducINSS = 0;

	printf("\nInsira o valor do salário bruto de seu funcionário: R$");
	scanf("%f", &salary);

	printf("Insira o valor da hora extra: ");
	scanf("%f", &valExtras);

	printf("Insira a quantidade de horas extras desse funcionário: ");
	scanf("%f", &qtdExtras);

	deducINSS = salary * INSS;
	bruteSalary = salary + (valExtras * qtdExtras);
	liquidSalary = bruteSalary - deducINSS;

	printf("\n-------- FOLHA DE PAGAMENTO -------\n");
	printf("Salário Base: R$%.2lf\n", salary);
	printf("Salário Bruto (+ Horas Extras): R$%.2lf\n", bruteSalary);
	printf("\t-- Horas Extras: R$%.2lf", valExtras * qtdExtras);

	printf("\nDeduções:\n"
		   "\t-- INSS (8%%): R$%.2lf", deducINSS);

	printf("\n\nTOTAL SALÁRIO LÍQUIDO: R$%.2lf\n", liquidSalary);

	return 0;
}