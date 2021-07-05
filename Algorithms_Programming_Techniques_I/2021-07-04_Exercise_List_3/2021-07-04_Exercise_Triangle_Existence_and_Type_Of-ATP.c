#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int side1, side2, side3;

	printf("\nInsira o valor de uma lado do triângulo: ");
	scanf("%d", &side1);

	printf("Insira o valor de outro lado do triângulo: ");
	scanf("%d", &side2);

	printf("Insira o valor do último lado do triângulo: ");
	scanf("%d", &side3);

	if(side1 + side2 > side3 & side1 + side3 > side2 && side2 + side3 > side1) {
		if(side1 == side2 && side1 == side3 && side2 == side3)
			printf("\nEste triângulo é Equilátero.\n\n");

		else if(side1 == side2 || side1 == side3 || side2 == side3)
			printf("\nEste triângulo é Isósceles.\n\n");

		else
			printf("\nEste triângulo é Escaleno.\n\n");

	} else
		printf("\nOs valores inseridos não formam um triângulo!\n\n");

	return 0;
}