/* Faca um programa em C que recebe tres notas de um aluno, calcule a sua
media, mostrea e diga se ele foi APROVADO, REPROVADO, ou esta de EXAME. Considere
que a media para aprovacao deve ser maior ou igual a 7, e a media para reprovacao deve ser
menor que 3. */

#include <stdio.h>
#include <locale.h>

void getNotaAluno(float*, size_t);
void testAverage(float avg);

int main() {
	setlocale(LC_ALL, "Portuguese");

    float n1, n2, n3, avg;

	puts("\nInsira as três notas do aluno, abaixo: ");
	getNotaAluno(&n1, 1);
	getNotaAluno(&n2, 2);
	getNotaAluno(&n3, 3);

    // get the student mean
	avg = (n1 + n2 + n3) / 3;

	// prints student mean
	printf("\nMédia Final: %.1f\n", avg);

	// tells if the student is approved, reproved or will be examined
	testAverage(avg);

    return 0;
}

void getNotaAluno(float *nota, size_t n) {
	do {
		printf("\n   -> Insira a nota %ld do aluno: ", n);
		scanf(" %f", nota);

		if(*nota < 0 || *nota > 10)
			puts("\n--> AVISO: Insira um valor válido de 0 a 10!\n");

	} while(*nota < 0 || *nota > 10);
}

void testAverage(float avg) {
	if(avg < 3)
        printf("Aluno reprovado!\n\n");
    else if(avg >= 3 && avg < 7)
        printf("Aluno em exame!\n\n");
    else
        printf("Aluno aprovado!\n\n");
}
