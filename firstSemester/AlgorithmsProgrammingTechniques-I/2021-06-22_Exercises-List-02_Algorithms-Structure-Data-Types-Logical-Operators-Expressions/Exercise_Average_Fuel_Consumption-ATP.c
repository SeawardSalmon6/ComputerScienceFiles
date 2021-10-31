#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	double distanceKM, fuelUsed, AFC;

	printf("\n Qual foi a distância percorrida em quilômetros (km)?\n");
	scanf("%lf", &distanceKM);

	printf("\n Quanto combustível foi utilizado no percurso?\n");
	scanf("%lf", &fuelUsed);

	AFC = distanceKM / fuelUsed;

	printf("\n ======================== RESULTADO ========================\n");
	printf(" - Consumo Médio de Combustível por Quilômetro: %.2lf km/L\n\n", AFC);

	return 0;
}