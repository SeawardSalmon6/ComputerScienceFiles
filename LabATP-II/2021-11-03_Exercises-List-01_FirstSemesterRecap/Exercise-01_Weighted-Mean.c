/* Faça um programa em C/C++ que receba três notas de um aluno, e calcule a média ponderada desse aluno. Sabe-se que os pesos das avaliações são, respectivamente, 3, 5 e 2. Mostre se o aluno foi aprovado ou reprovado, sabendo-se que a média para aprovação é 7. */

#include <stdio.h>
#include <locale.h>

float weightedMean(float, float, float);
void isApproved(float);

int main() {
	setlocale(LC_ALL, "Portuguese");

	float eval1, eval2, eval3, stAvg;

	puts("\n--- Exercise 01 - Weighted Mean");
	puts("\nAbaixo, insira as três notas das avaliações do aluno: ");
	scanf(" %f %f %f", &eval1, &eval2, &eval3);

	stAvg = weightedMean(eval1, eval2, eval3);

	printf("\nMédia Ponderada do Aluno: %.2f", stAvg);
	isApproved(stAvg);

	return 0;
}

float weightedMean(float nt1, float nt2, float nt3) {
	const int we1 = 3, we2 = 5, we3 = 2;
	int sumWeights = we1 + we2 + we3;

	return (nt1 * we1 + nt2 * we2 + nt3 * we3) / sumWeights;
}

void isApproved(float avg) {
	const float minAvg = 7;
	if(avg >= minAvg)
		printf("\n--> Parabéns! O aluno foi aprovado com nota %.2f\n\n", avg);
	else
		printf("\n--> Que pena! O aluno foi reprovado com nota %.2f. A nota mínima para aprovação é %.2f\n\n", avg, minAvg);
}
