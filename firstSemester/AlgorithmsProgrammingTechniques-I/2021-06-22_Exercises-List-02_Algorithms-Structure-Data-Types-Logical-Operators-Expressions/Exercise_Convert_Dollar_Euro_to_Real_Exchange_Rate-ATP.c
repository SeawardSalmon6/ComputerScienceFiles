#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	float exrDollar, exrEuro, valDollar, valEuro, convDollar, convEuro;

	printf("\nInsira o valor da cotação do dólar hoje: ");
	scanf("%f", &exrDollar);

	printf("Quantos dólares gostaria de converter em reais?\n");
	scanf("%f", &valDollar);

	printf("\nInsira o valor da cotação do euro hoje: ");
	scanf("%f", &exrEuro);

	printf("Quantos dólares gostaria de converter em reais?\n");
	scanf("%f", &valEuro);

	convDollar = valDollar * exrDollar;
	convEuro = valEuro * exrEuro;

	printf("\n\n========== Resultado Conversão ==========\n");
	printf("\nValor do dólar hoje: %.2lf USD", exrDollar);
	printf("\n%.2lf USD é o equivalente a: %.2lf BRL\n", valDollar, convDollar);

	printf("\nValor do euro hoje: %.2lf EUR", exrDollar);
	printf("\n%.2lf EUR é o equivalente a: %.2lf BRL\n", valDollar, convEuro);

	return 0;
}