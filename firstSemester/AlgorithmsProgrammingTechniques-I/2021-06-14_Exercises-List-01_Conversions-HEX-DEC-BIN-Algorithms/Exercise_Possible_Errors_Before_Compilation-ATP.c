#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int expression;

	// Problema de falta de parênteses
		// a expressão deve ser igual a 4
		// expression = pow(2, 2;

	// Problema de falta de ponto-e-vírgula ao final do comando
		// a expressão deve ser igual a 4
		// expression = pow(2, 2)
		// expression = 2 * 2;

	// Problema de erro de digitação e/ou problema de variável não-declarada
		// inte newExpression = 2 * 2;
		// printf("%d\n", newExpression);

	printf("%d\n", expression);

	return 0;
}