#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i;
	float numerator = 0, denominator = 0, X = 0;

	// arrays
	char letters[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	float values[6] = { 0 };

	printf("\nInsira os valores de 'a' até 'f', para que resolvamos a equação:\n");

	for(i = 0; i < 6; i++) {
		printf("\tInsira o valor de %c: ", letters[i]);
		scanf("%f", &values[i]);

		if((letters[i] == 'c' || letters[i] == 'd' || letters[i] == 'f') && values[i] == 0) {
			while(values[i] == 0) {
				printf("\nAviso: esta variável não pode ser igual a 0. Insira outro valor.\n");
				
				printf("\tInsira o valor de %c: ", letters[i]);
				scanf("%f", &values[i]);
			}
		}
	}

	numerator = values[0] + (values[1] / values[2]);
	denominator = values[3] - 2 * (values[4] / values[5]);
	X = (numerator / denominator) * 4 * values[0];

	printf("\n\n------ RESULTADO ------\n");
	printf("O resultado de X é igual a ==> %.2lf\n", X);

	return 0;
}