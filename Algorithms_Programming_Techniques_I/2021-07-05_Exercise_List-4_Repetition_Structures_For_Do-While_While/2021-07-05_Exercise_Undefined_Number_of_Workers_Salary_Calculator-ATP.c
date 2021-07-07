#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    float slrFunc = 0, slrAumento = 0;
	char resp;

    do {
		int i; i++;

		printf("\nInsira o salário do funcionário %d: R$", i);
		scanf(" %f", &slrFunc);

		if(slrFunc < 500)
			slrAumento += slrFunc * 1.15;
		else if (slrFunc >= 500 && slrFunc < 1000)
			slrAumento += slrFunc * 1.10;
		else if (slrFunc >= 1000)
			slrAumento += slrFunc * 1.05;

		printf("\n====== REAJUSTE FUNCIONÁRIO %d ======\n", i);
		printf("Salário do Funcionário: R$%.2f\n", slrFunc);
		printf("Salário Reajustado: R$%.2f\n\n", slrAumento);

		printf("Deseja calcular outro funcionário (S/N)?\n");
		scanf(" %c", &resp);

	} while(toupper(resp) == 'S');

    return 0;
}
