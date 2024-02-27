#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	float decParte, A;

	printf("\nInsira um número: ");
	scanf("%f", &A);

	decParte = A * 0.1;

	printf("\nO resultado de 10%% de %.2lf é: %.2lf\n", A, decParte);
	
	return 0;
}