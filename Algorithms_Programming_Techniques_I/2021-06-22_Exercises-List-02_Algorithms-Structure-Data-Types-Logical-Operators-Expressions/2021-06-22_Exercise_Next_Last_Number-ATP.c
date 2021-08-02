#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	int num, ant, suc;

	printf("\nInsira um número: ");
	scanf("%d", &num);

	ant = num - 1;
	suc = num + 1;

	printf("\nO número sucesso de %d é: %d\nO número antecessor de %d é: %d\n", num, ant, num, suc);
	
	return 0;
}