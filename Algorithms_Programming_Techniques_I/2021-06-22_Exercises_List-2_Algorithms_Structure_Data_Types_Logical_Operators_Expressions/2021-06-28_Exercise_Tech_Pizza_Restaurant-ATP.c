#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int numTable, i, prodQtd = 0;
	float valTotal = 0;
	
	// arrays do cardápio
	char menu[5][14] = { "Refrigerante\0", "Cerveja\0", "Pizza\0", "Almoço\0", "Porção\0" };
	float price[5] = { 2.50, 4.00, 47.30, 15.00, 10.50 };

	printf("\nInsira o número da mesa: ");
	scanf("%d", &numTable);

	printf("\nInsira a quantidade de cada produto adquirido:\n");

	for(i = 0; i < 5; i++) {
		printf("\tQuantidade de %s: ", menu[i]);
		scanf("%d", &prodQtd);

		valTotal += prodQtd * price[i];
	}

	printf("\n\n========== Conta da Mesa ==========\n");
	printf("\nMesa: %d", numTable);
	printf("\nValor Acumulado: R$%.2lf", valTotal);

	printf("\n\nValor Total (+ serviços): R$%.2lf\n", (valTotal + (valTotal * 0.10)) );

	return 0;
}