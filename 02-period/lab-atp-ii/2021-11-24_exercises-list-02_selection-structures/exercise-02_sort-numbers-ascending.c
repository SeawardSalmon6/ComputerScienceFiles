/* Faça um programa em C/C++ que receba três números e os mostre em ordem crescente */

#include <stdio.h>
#include <locale.h>

void sortAsc(int, int, int);

int main() {
	setlocale(LC_ALL, "Portuguese");

	int n1, n2, n3;

	puts("\n--- Exercise 04 - Sorting Numbers");
	puts("\nAbaixo, insira três números inteiros e os ordenaremos em ordem crescente: ");
	scanf(" %d %d %d", &n1, &n2, &n3);

	// run sorter function
	sortAsc(n1, n2, n3);
	puts("\n");

	return 0;
}

void sortAsc(int a, int b, int c) {
	int hi = 0, lo = 0, mid = 0, i;

	if(a >= b && a >= c) {
		hi = a;
		if(b >= c) { lo = c; mid = b; }
		else { lo = b; mid = c; }
	} else if(b >= a && b >= c) {
		hi = b;
		if(a >= c) { lo = c; mid = a; }
		else { lo = a; mid = c; }
	} else {
		hi = c;
		if(a >= b) { lo = b; mid = a; }
		else { lo = a; mid = b; }
	}

	printf("\n---- Ordem Crescente: \n");
	printf("\n\t--> %d %d %d", lo, mid, hi);
}
