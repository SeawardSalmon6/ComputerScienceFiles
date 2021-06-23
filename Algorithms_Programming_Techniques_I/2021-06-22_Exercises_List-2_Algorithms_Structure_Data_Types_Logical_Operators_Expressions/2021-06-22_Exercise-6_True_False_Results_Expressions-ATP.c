#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
	int A = 2,
		B = 7;
	
	float C = 3.5;
	bool expression, L = false;

// a) 2<5 e 15/3=5
	expression = (2 < 5) && ((15 / 3) == 5);
	printf("a. %s \n", expression ? "Verdadeiro" : "Falso");

// b) 2<5 ou 15/3=5 .V.
	expression = (2 < 5) || ((15 / 3) == 5);
	printf("b. %s \n", expression ? "Verdadeiro" : "Falso");
 

// c) F ou 20 div(18/3) <> (21/3) div 2 .F.
	div_t div1, div2;
	div1 = div(20, (18 / 3));
	div2 = div((21 / 3), 2);
	expression = false || div1.quot != div2.quot;
	printf("c. %s \n", expression ? "Verdadeiro" : "Falso");

// d) não V ou pot (3,2)/3 <15 -35 mod 7 .V.
	expression = !true || pow(3, 2) / 3 < 15 - 35 % 7;
	printf("d. %s \n", expression ? "Verdadeiro" : "Falso");

// e) não ((5<> 10/2) ou V e 2 – 5 > 5 – 2 ou V) .F.
	expression = !((5 != 10 / 2) || true && 2 - 5 > 5 -2 || true);
	printf("e. %s \n", expression ? "Verdadeiro" : "Falso");

// f) pot (2,4) <> 4 + 2 ou 2 + 3 * 5/3 mod 5 > 0 .V.
	expression = pow(2, 4) != 4 + 2 || 2 + 3 * 5 / 3 % 5 > 0;
	printf("f. %s \n", expression ? "Verdadeiro" : "Falso");

// g) B = A * C e (L ou V) .V.
	expression = B == A * C && (L || true);
	printf("g. %s \n", expression ? "Verdadeiro" : "Falso");

// h) B > A ou B= pot(A,A) .V.
	expression = B > A || B == pow(A, A);
	printf("h. %s \n", expression ? "Verdadeiro" : "Falso");

// i) L e B div A >=C ou não A <= C .F.
	expression = (L && (B / A >= C)) || !(A <= C);
	printf("i. %s \n", expression ? "Verdadeiro" : "Falso");

// j) não L ou V e rad(A+B) >=C .V.
	expression = !L || (true && sqrt(A + B) >= C);
	printf("j. %s \n", expression ? "Verdadeiro" : "Falso");

// k) B/A = C ou B/A <> C .V.
	expression = B / A == C || B / A != C;
	printf("k. %s \n", expression ? "Verdadeiro" : "Falso");

// l) L ou pot (B,A) <= C * 10 + A*B .V.
	expression = L || pow(B, A) <= C * 10 + A * B;
	printf("l. %s \n", expression ? "Verdadeiro" : "Falso");

	return 0;
}