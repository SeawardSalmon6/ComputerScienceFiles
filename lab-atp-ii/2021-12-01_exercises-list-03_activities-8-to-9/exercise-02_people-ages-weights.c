/* Faça um programa em C que recebe a idade, a altura e o peso de cinco pessoas, calcule e mostre:
- a quantidade de pessoas com idade superior a 50 anos
- a média das alturas das pessoas com idades entre 10 e 20 anos
- a porcentagem de pessoas com peso inferior a 40 kg entre todas as pessoas analisadas */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ARRAY_SIZE 5

typedef struct Person {
	int age;
	float height;
	float weight;
} tPerson;

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i, less40KG = 0, higher50Old = 0, people10To20 = 0;
	float sumHeights = 0;

	tPerson people[ARRAY_SIZE];

	printf("\n============== Leitor de Pessoas\n");
	printf("Abaixo, insira as informações dos usuários: \n");

	for(i = 0; i < ARRAY_SIZE; i++) {
		printf("\n----- Pessoa %d\n", i + 1);

		do {
			printf("  - Insira sua altura em metros (m): ");
			scanf(" %f", &(people[i].height));
		} while(people[i].height < 1);

		do {
			printf("  - Insira sua idade: ");
			scanf(" %d", &(people[i].age));
		} while(people[i].age < 1);

		if(people[i].age > 50)
			higher50Old++;

		if(people[i].age >= 10 && people[i].age <= 20) {
			sumHeights += people[i].height;
			people10To20++;
		}

		do {
			printf("  - Insira seu peso em quilos (kg): ");
			scanf(" %f", &(people[i].weight));
		} while(people[i].weight < 1);

		if(people[i].weight < 40)
			less40KG++;
	}

	printf("\n\n============== RESULTADOS");
	printf("\n--- Quantidade pessoas com idade superior a 50 anos: %d", higher50Old);
	printf("\n--- Altura média das pessoas entre 10 anos e 20 anos: %.2fm", ((float) sumHeights / people10To20));
	printf("\n--- Porcentagem de pessoas com menos que 40kg: %.2f%%\n\n", ((float) less40KG / ARRAY_SIZE) * 100);

	return 0;
}
