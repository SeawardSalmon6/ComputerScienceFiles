#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	float kWatts, toPay;

	printf("\n Insira a quantidade de quilowatts-hora (kWh) consumidos: ");
	scanf("%f", &kWatts);

	if(kWatts <= 50)
		toPay = kWatts * 1.00;

	else if(kWatts > 50 && kWatts <= 100)
		toPay = 50 + (kWatts - 50) * 1.30;

	else if(kWatts > 100 && kWatts <= 150)
		toPay = 50 + 65 + (kWatts - 100) * 1.60;

	else if(kWatts > 150)
		toPay = 50 + 65 + 80 + (kWatts - 150) * 2.00;

	printf("\n ======= CONTA DE ENERGIA =======\n");
	printf(" ==> VALOR TOTAL A PAGAR: R$%.2f\n\n", toPay);

	return 0;
}