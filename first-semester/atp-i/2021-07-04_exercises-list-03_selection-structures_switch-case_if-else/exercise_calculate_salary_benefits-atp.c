#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	float slrFunc, slrAumento = 0;

	printf("\nInsira o salário do funcionário: R$");
	scanf("%f", &slrFunc);

	if(slrFunc < 500)
		slrAumento += slrFunc * 1.15;
	else if (slrFunc >= 500 && slrFunc < 1000)
		slrAumento += slrFunc * 1.10;
	else if (slrFunc >= 1000)
		slrAumento += slrFunc * 1.05;

	printf("\n====== REAJUSTE ======\n");
	printf("Salário do Funcionário: R$%.2f\n", slrFunc);
	printf("Salário Reajustado: R$%.2f\n\n", slrAumento);

	return 0;
}