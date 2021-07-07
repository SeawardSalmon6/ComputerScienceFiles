#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    const float kW50 = 1,
				kW100 = 1.3,
				kW150 = 1.6,
				kWMax = 2.0;

	float kWatts, toPay;
	char resp;

	do {
		int i; i++;

		printf("\n Morador %d - Insira a quantidade de quilowatts-hora (kWh) consumidos: ", i);
		scanf(" %f", &kWatts);

		if(kWatts <= 50)
			toPay = kWatts * kW50;

		else if(kWatts > 50 && kWatts <= 100)
			toPay = (50 * kW50) + (kWatts - 50) * kW100;

		else if(kWatts > 100 && kWatts <= 150)
			toPay = (50 * kW50) + (50 * kW100) + (kWatts - 100) * kW150;

		else if(kWatts > 150)
			toPay = (50 * kW50) + (50 * kW100) + (50 * kW150) + (kWatts - 150) * kWMax;

		printf("\n ======= CONTA DE ENERGIA -- Morador %d =======\n", i);
		printf(" ==> VALOR TOTAL A PAGAR: R$%.2f\n\n", toPay);

		printf("Deseja calcular novamente (S/N)?\n");
		scanf(" %c", &resp);

		printf("\n------------------");

	} while(toupper(resp) == 'S');

    return 0;
}