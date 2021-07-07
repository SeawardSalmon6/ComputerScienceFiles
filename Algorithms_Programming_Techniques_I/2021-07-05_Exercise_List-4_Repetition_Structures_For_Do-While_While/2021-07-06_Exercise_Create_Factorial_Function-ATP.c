#include <stdio.h>
#include <locale.h>

int fact(int n) {
	int result = 1;
	for(int i = 1; i <= n; i++)
		result *= i;
	return result;
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int number;

	printf("\nInsira um número inteiro: ");
	scanf("%d", &number);

	printf("\n============ RESULTADO ============\n");
	printf("(%d!) -- %d fatorial é: %d\n\n", number, number, fact(number));
	
	return 0;
}