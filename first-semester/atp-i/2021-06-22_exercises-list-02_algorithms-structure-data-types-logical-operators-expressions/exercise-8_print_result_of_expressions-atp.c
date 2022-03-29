#include <stdio.h>
#include <math.h>

int main() {
	int A = 5,
		B = 10,
		C = -8;
	float D = 1.5,
		expression;
	
// a. 2 * A mod 3 – C 12
	expression = 2 * A % 3 - C;
	printf("a. Result = %.0lf\n", expression);

// b. sqrt(–2 * C) div 4 1
	expression = sqrt(-2 * C) / 4;
	printf("b. Result = %.0lf\n", expression);

// c. (30 % 4 * pot (3,3)) * –1 -54
	expression = (30 % 4 * pow(3, 3)) * -1;
	printf("c. Result = %.0lf\n", expression);

// d. pot (–C,2) + (D * 10) /A 67
	expression = pow(-C, 2) + (D * 10) / A;
	printf("d. Result = %.0lf\n", expression);

// e. rad (pot (A, B/A)) + C * D
	expression = sqrt(pow(A, B / A)) + C * D;
	printf("e. Result = %.0lf\n", expression);

	return 0;
}