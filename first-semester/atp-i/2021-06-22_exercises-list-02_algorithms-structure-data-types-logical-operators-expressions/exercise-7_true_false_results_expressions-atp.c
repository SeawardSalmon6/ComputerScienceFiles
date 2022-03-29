#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
	int X = 1,
		A = 3,
		B = 5,
		C = 8,
		D = 7;
	
	bool expression;

// a) não (X>3) .V.
	expression = !(X > 3);
	printf("a. %s \n", expression ? "Verdadeiro" : "Falso");

// b) (X<1) e não(B>D)
	expression = (X < 1) && !(B > D);
	printf("b. %s \n", expression ? "Verdadeiro" : "Falso");

// c) não (D<0) e (C>5)
	expression = !(D < 0) && (C > 5);
	printf("c. %s \n", expression ? "Verdadeiro" : "Falso");

// d) não (X>3) ou (C<7)
	expression = !(X > 3) || (C < 7);
	printf("d. %s \n", expression ? "Verdadeiro" : "Falso");

// e) (A>B) ou (C>B)
	expression = (A > B) || (C > B);
	printf("e. %s \n", expression ? "Verdadeiro" : "Falso");

// f) (X>=2)
	expression = X >= 2;
	printf("f. %s \n", expression ? "Verdadeiro" : "Falso");

// g) (X<1) e (B>=D)
	expression = (X < 1) && (B >= D);
	printf("g. %s \n", expression ? "Verdadeiro" : "Falso");

// h) (D<0) ou (C>5)
	expression = (D < 0) || (C > 5);
	printf("h. %s \n", expression ? "Verdadeiro" : "Falso");

// i) não (D>3) ou não(B<7)
	expression = !(D > 3) || !(B < 7);
	printf("i. %s \n", expression ? "Verdadeiro" : "Falso");

// j) (A>B) ou não (C>B)
	expression = (A > B) || !(C > B);
	printf("j. %s \n", expression ? "Verdadeiro" : "Falso");

	return 0;
}