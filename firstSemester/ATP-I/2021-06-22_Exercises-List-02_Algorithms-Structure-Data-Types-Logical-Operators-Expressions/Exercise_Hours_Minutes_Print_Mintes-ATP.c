#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int time, hh, mm;

	printf("\nInsira o horário atual, em horas e minutos: ");
	scanf(" %d %d", &hh, &mm);

	time = (hh * 60) + mm;

	printf("\nO horário atual, em minutos é igual a: %d minutos\n", time);

	return 0;
}