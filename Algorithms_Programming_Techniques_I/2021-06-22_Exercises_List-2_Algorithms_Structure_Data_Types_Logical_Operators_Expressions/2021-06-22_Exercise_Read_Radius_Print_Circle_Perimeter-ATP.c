#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	const float pi = 3.14159;
	float radius, perimeter;
	
	printf("\nInsira o raio de seu círculo: ");
	scanf("%f", &radius);

	perimeter = 2 * radius * pi;

	printf("\nO perímetro desse círculo é de: %.2lf u.a.\n", perimeter);
	
	return 0;
}