#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int num;

	printf("\nInsira um número: ");
	scanf("%d", &num);

	printf("\nAcho que consigo descobrir qual número você escolheu... é o número %d?\nEu acertei não é mesmo?\n", num);
	
	return 0;
}