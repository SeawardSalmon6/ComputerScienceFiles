#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int input, resto, hh, mm, ss;

	printf("\nInsira o tempo do processamento em segundos: ");
	scanf("%d", &input);

	hh = input / 3600;
	resto = input % 3600;
	mm = resto / 60;
	ss = resto % 60;

	printf("\nO tempo desse processo de %d, em horas, minutos e segundos, respectivamente é de:\n%d hora(s), %d minuto(s) e %d segundo(s)\n", input, hh, mm, ss);

	return 0;
}