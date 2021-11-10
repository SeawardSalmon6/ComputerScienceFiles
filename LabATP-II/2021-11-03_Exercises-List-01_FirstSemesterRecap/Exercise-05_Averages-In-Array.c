/* Faça um programa em C/C++ que receba duas de cada um dos dez alunos de uma turma, calcule a média de cada um deles e mostre-as, armazenando todas as notas e médias em vetores.  */

#include <stdio.h>
#include <locale.h>

#define MAX_STUDENTS 10

void getGrades(float*, float*);
void printAllGrades(float*);
float gradeAverage(float, float);

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i;
	float eval1, eval2, gradesArr[MAX_STUDENTS] = { 0 };

	puts("\n--- Exercise 05 - Students Averages Array");
	for(i = 0; i < MAX_STUDENTS; i++) {
		printf("\n---------- Aluno %d", i + 1);
		getGrades(&eval1, &eval2);

		// storing grades into the array
		gradesArr[i] = gradeAverage(eval1, eval2);

		printf("\n----> Média Final: %.2f\n", gradesArr[i]);
	}

	printAllGrades(gradesArr);
	puts("\n");

	return 0;
}

void getGrades(float *nt1, float *nt2) {
	int validation = 0;
	do {
		puts("\n\nInsira as duas notas do aluno: ");
		scanf(" %f %f", nt1, nt2);

		validation = (*nt1 < 0 || *nt1 > 10 || *nt2 < 0 || *nt2 > 10) ? 1 : 0;
		if(validation)
			puts("\n--> Aviso: Insira valores entre 0 e 10!");

	} while(validation);

	printf("\nNota 1: %.2f", *nt1);
	printf("\nNota 2: %.2f", *nt2);
}

void printAllGrades(float *arr) {
	printf("\n\n================== Todas as Notas");
	for(int i = 0; i < MAX_STUDENTS; i++) {
		printf("\n----- Aluno %d", i + 1);
		printf("\n--> Média Final: %.2f\n", arr[i]);
	}
}

float gradeAverage(float nt1, float nt2) {
	return (nt1 + nt2) / 2;
}
