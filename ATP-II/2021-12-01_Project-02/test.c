#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	double counter;
	int a = 5, b = 6;

	counter = a / b;
	printf("%lf\n", counter);

	return 0;
}
