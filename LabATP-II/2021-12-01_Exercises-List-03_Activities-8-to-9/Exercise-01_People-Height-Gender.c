/* Elabore um programa em C para ler a altura e o sexo (masculino ou feminino) de 10 (dez) pessoas. Calcular e mostrar:
- a maior e a menor altura do grupo
- a média de altura das mulheres
- o número de homens (quantos homens)
- a porcentagem de mulheres (em relação ao total de pessoas) */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ARRAY_SIZE 10

typedef struct Person {
	float height;
	char gender;
} tPerson;

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i, men = 0, women = 0;
	float taller = 0, lower, womHeights = 0;
	tPerson people[ARRAY_SIZE];

	printf("\n============== Leitor de Altura e Sexo\n");
	printf("Abaixo, insira as informações dos usuários: \n");

	for(i = 0; i < ARRAY_SIZE; i++) {
		printf("\n----- Pessoa %d\n", i + 1);

		do {
			printf("  - Insira ao lado, sua altura em metros: ");
			scanf(" %f", &(people[i].height));
		} while(people[i].height < 1);

		if(people[i].height > taller)
			taller = people[i].height;

		if(people[i].height <= lower)
			lower = people[i].height;
		else if(i == 0)
			lower = people[i].height;

		do {
			printf("  - Insira ao lado, seu sexo (M/F): ");
			scanf(" %c", &(people[i].gender));
		} while(!(people[i].gender == 'M' || people[i].gender == 'm' || people[i].gender == 'f' || people[i].gender == 'F'));

		if(people[i].gender == 'm' || people[i].gender == 'M') men++;
		if(people[i].gender == 'f' || people[i].gender == 'F') womHeights += people[i].height;
	}

	women = ARRAY_SIZE - men;

	printf("\n\n============== RESULTADOS");
	printf("\n--- Maior altura do grupo: %.2fm", taller);
	printf("\n--- Menor altura do grupo: %.2fm", lower);
	printf("\n--- Quantidade de homens: %d", men);
	printf("\n--- Altura média das mulheres: %.2f", (womHeights / women));
	printf("\n--- Porcentagem de mulheres do grupo: %.2f%%\n\n", ((float) women / ARRAY_SIZE) * 100);

	return 0;
}
