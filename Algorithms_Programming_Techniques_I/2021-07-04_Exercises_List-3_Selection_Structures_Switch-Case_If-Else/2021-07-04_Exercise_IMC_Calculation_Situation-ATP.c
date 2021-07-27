#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	float altura, peso, IMC;

	printf("\nInsira sua altura em metros: ");
	scanf("%f", &altura);

	printf("Insira seu peso atual em quilos: ");
	scanf("%f", &peso);

	IMC = peso / (altura * altura);

	if(IMC < 18.5)
		printf("\nIMC = %.2f \t Situação: Desnutrição\n\n", IMC);
	else if(IMC >= 18.5 && IMC < 25)
		printf("\nIMC = %.2f \t Situação: Peso Normal\n\n", IMC);
	else if(IMC >= 25 && IMC < 30)
		printf("\nIMC = %.2f \t Situação: Sobrepeso\n\n", IMC);
	else if(IMC >= 30 && IMC < 40)
		printf("\nIMC = %.2f \t Situação: Obesidade\n\n", IMC);
	else if(IMC >= 40)
		printf("\nIMC = %.2f \t Situação: Obesidade Mórbida\n\n", IMC);

	return 0;
}