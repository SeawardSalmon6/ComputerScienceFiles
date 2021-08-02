#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int fullDate, dd, mm, yy;

	printf("\nInsira uma data no formato 'DDMMAA':");
	scanf("%d", &fullDate);

	dd = fullDate / 10000;
	mm = fullDate / 100 - (dd * 100);
	yy = fullDate - (dd * 10000) - (mm * 100);

	printf("\nDia: %02d", dd);
	printf("\nMês: %02d", mm);
	printf("\nAno: %02d\n", yy);

	return 0;
}