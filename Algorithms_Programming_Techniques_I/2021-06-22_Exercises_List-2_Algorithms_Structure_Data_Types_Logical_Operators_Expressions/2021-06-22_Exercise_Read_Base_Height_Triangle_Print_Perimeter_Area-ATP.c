#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	float b, h, area, perimeter;
	
	printf("\nInsira a base de seu triângulo: ");
	scanf("%f", &b);

	printf("Insira a altura do triângulo: ");
	scanf("%f", &h);

	perimeter = b * 3;
	area = (b * h) / 2;

	printf("\nO perímetro desse triângulo equilátero é de: %.2lf u.a.", perimeter);
	printf("\nA área desse triângulo equilátero é de: %.2lf u.a.\n", area);
	
	return 0;
}