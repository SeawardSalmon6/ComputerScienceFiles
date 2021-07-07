#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int number;

	printf("\nInsira um número inteiro: ");
	scanf("%d", &number);

	printf("\n===== TABUADA DO %d =====\n", number);

	for(int i = 1; i <= 10; i++)
		printf("\n%d x %d = %d", number, i, number * i);

	printf("\n\n");

	return 0;
}