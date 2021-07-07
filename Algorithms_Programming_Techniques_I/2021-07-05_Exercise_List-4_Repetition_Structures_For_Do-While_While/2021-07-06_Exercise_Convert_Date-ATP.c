#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	char strMes [12][10] = {
		"Janeiro\0",
		"Fevereiro\0",
		"Março\0",
		"Abril\0",
		"Maio\0",
		"Junho\0",
		"Julho\0",
		"Agosto\0",
		"Setembro\0",
		"Outubro\0",
		"Novembro\0",
		"Dezembro\0",
	};

	int dd, mm, yyyy;

	printf("\nInsira uma data no formato (DD/MM/AAAA): ");
	scanf(" %d/%d/%d", &dd, &mm, &yyyy);

	printf("\nA data é Dia %d de %s de %d.\n\n", dd, strMes[mm - 1], yyyy);

	return 0;
}