#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	const double kWValue = 0.10;

	float kWatts, toPay, discount = 0;
	char resp = 'N';

	printf("\n Insira a quantidade de quilowatts-hora (kWh) consumidos: ");
	scanf("%f", &kWatts);

	printf(" Você é aposentado (S/N)?\n");
	scanf(" %c", &resp);

	toPay = kWatts * kWValue;

	if(toupper(resp) == 'S')
		discount = toPay * 0.15;

	printf("\n ======= CONTA DE ENERGIA =======\n");
	printf(" Valor do Consumo: R$%.2f", toPay);
	printf("\n\t- Desconto para Aposentados: R$%.2f", discount);
	printf("\n\n ==> VALOR TOTAL A PAGAR: R$%.2f\n\n", toPay - discount);

	return 0;
}