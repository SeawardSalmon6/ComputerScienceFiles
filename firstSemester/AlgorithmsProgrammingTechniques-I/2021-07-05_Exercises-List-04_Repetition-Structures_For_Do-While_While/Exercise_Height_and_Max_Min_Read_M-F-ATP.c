#include <stdio.h>
#include <ctype.h>
#include <locale.h>

float maxHM = 0, maxHF = 0, minHM = 0, minHF = 0, sumHeight;

void askHeight(char sex) {
	float altura = 0;

	printf("\n\t - Insira sua altura em metros: ");
	scanf(" %f", &altura);

	if(toupper(sex) == 'M') {
		if(maxHM == 0 && minHM == 0) {
		    maxHM = altura;
		    minHM = altura;
		}
		
		else if(altura >= maxHM)
			maxHM = altura;
		
		else if(altura <= minHM)
			minHM = altura;
			
	} else if(toupper(sex) == 'F') {
		if(maxHF == 0 && minHF == 0) {
		    maxHF = altura;
		    minHF = altura;
		} 
		
		else if(altura >= maxHF)
			maxHF = altura;
		
		else if(altura <= minHF)
			minHF = altura;

		sumHeight += altura;
	}
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    float femHAverage;
	int somaM = 0, somaF = 0;
	char sex;

    for(int i = 1; i <= 50; i++) {
		do {
			printf("\nPessoa %d -- Insira seu gênero (somente M ou F): ", i);
			scanf(" %c", &sex);
		} while(toupper(sex) != 'M' && toupper(sex) != 'F');

		if(toupper(sex) == 'M') {
			askHeight(sex);
			somaM++;

		} else if (toupper(sex) == 'F') {
			askHeight(sex);
			somaF++;
		}
	}

	femHAverage = sumHeight / somaF;

	printf("\n========== RESULTADOS ==========\n");
	printf("\nHomens:");
	printf("\n\t- Altura máxima: %.2lf", maxHM);
	printf("\n\t- Altura mínima: %.2lf", minHM);
	printf("\n\t- Quantidade de Homens: %d\n", somaM);

	printf("\nMulheres:");
	printf("\n\t- Altura máxima: %.2lf", maxHM);
	printf("\n\t- Altura mínima: %.2lf", minHM);
	printf("\n\t- Altura média: %.2lf", femHAverage);
	printf("\n\t- Quantidade de Mulheres: %d", somaF);

	double porcentagem = (somaM / 50.00) - (somaF / 50.00);

	printf("\n\nPorcentagem de Homens, em relação às Mulheres: %.2lf%%\n\n", porcentagem * 100);

    return 0;
}