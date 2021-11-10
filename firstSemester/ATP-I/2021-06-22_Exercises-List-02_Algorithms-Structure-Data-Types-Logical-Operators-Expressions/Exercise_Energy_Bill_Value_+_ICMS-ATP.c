#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	const double kWValue = 0.12;
	const double ICMS = 0.18;

	float kWatts, toPay, additionalICMS;

	printf("\n Insira a quantidade de quilowatts-hora (kWh) consumidos: ");
	scanf("%f", &kWatts);

	toPay = kWatts * kWValue;
	additionalICMS = ICMS * toPay;

	printf("\n ======= CONTA DE ENERGIA =======\n");
	printf(" Valor do Consumo: R$%.2f", toPay);
	printf("\n\t- Acréscimo ICMS: R$%.2f", additionalICMS);
	printf("\n\n ==> VALOR TOTAL A PAGAR: R$%.2f\n\n", toPay + additionalICMS);

	return 0;
}