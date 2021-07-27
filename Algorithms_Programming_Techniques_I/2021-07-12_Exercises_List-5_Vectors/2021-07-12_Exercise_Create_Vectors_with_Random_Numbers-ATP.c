#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 1000

int main() {
	setlocale(LC_ALL, "Portuguese");

	int soma_par = 0, soma_impar = 0, soma_vet, qtdNum = 0, qtdPar = 0, qtdImpar = 0;
	double media_par = 0, media_impar = 0, media_num = 0;
	
	int vetA[MAX] = { 0 };
	srand(time(NULL));

	printf("\n================== Lista de Números Gerados ==================\n\n");
	
	for(int i = 0; i < MAX; i++) {
		int counter; counter++;
		
		vetA[i] = rand() % 100;

		// realiza os prints dos números gerados + formatação
		if((i + 1) % 5 == 0)
			printf("Número (%d) = %d\n", i, vetA[i]);
		else
			printf("Número (%d) = %d    ", i, vetA[i]);

		qtdNum++;
		soma_vet += vetA[i];

		if(vetA[i] % 2 == 0) {
			qtdPar++;
			soma_par += vetA[i];
		}
		else {
			qtdImpar++;
			soma_impar += vetA[i];
		}
	}

	// área de cálculos
	media_num = (double) soma_vet / qtdNum;
	media_par = (double) soma_par / qtdPar;
	media_impar = (double) soma_impar / qtdImpar;

	printf("\n================== RESULTADOS ==================\n");
	printf("\nA média de todos os números é:       %.2lf", media_num);
	printf("\n\t- A média dos números pares é:   %.2lf", media_par);
	printf("\n\t- A média dos números ímpares é: %.2lf", media_impar);
	printf("\nA soma dos números pares é:          %d", soma_par);
	printf("\nA soma dos números ímpares é:        %d\n\n", soma_impar);

	return 0;
}