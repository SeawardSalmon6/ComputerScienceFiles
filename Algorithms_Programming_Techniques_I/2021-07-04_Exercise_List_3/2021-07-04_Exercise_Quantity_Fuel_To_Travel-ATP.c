#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	const float gasolina = 4.79, diesel = 2.64, alcool = 2.68;

	int fuelType;
	float distance, avgConsumption, toPay;

	printf("\n------- TIPO DE COMBUSTÍVEL -------\n");
	printf("1 - Diesel\n");
	printf("2 - Gasolina\n");
	printf("3 - Álcool\n");

	printf("\nEscolha um tipo de combustível: ");
	scanf("%d", &fuelType);

	if(fuelType == 1 || fuelType == 2 || fuelType == 3) {
		printf("\nInsira a distância que será percorrida: ");
		scanf("%f", &distance);

		printf("Insira o consumo médio por litro de seu carro: ");
		scanf("%f", &avgConsumption);

		switch(fuelType) {
			case 1:
				toPay = diesel * (distance / avgConsumption);
				break;
			case 2:
				toPay = diesel * (distance / avgConsumption);
				break;
			case 3:
				toPay = diesel * (distance / avgConsumption);
				break;
		}

		printf("\nA quantidade de combustível necessário é de %.2lfL", (distance / avgConsumption));
		printf("\nTotal a pagar pela quantidade: R$%.2lf\n\n", toPay);
	}
	else
		printf("\nO tipo de combustível é inválido.\n\n");

	return 0;
}