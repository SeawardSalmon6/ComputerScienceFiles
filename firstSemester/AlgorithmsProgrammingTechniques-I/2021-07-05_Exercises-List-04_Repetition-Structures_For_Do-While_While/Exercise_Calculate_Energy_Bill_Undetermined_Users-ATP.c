#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    const double kWValue = 0.10;

    float kWatts, toPay, discount = 0;
    char respCont, respAposentado = 'N';

	do {
		int i; i++;

		printf("\n Morador %d - Insira a quantidade de quilowatts-hora (kWh) consumidos: ", i);
		scanf(" %f", &kWatts);

		printf(" Você é aposentado (S/N)?\n");
		scanf(" %c", &respAposentado);

		toPay = kWatts * kWValue;

		if(toupper(respAposentado) == 'S')
			discount = toPay * 0.15;

		printf("\n ======= CONTA DE ENERGIA -- Morador %d =======\n", i);
		printf(" Valor do Consumo: R$%.2f", toPay);
		printf("\n\t- Desconto para Aposentados: R$%.2f", discount);
		printf("\n\n ==> VALOR TOTAL A PAGAR: R$%.2f\n\n", toPay - discount);

		printf("Deseja realizar novo cálculo da Conta de Energia (S/N)?\n");
		scanf(" %c", &respCont);

	} while(toupper(respCont) == 'S');

    return 0;
}