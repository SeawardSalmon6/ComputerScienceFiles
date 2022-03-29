#include <stdio.h>

int fibonacci(int n) {
	return (n > 1) ? fibonacci(n - 1) + fibonacci(n - 2) : n;
}

int main() {
	int n;

	printf("\n Insert a number to get the value of it in the Fibonacci Sequence: ");
	scanf(" %d", &n);

	printf("\n -> The value of the %d-th number is: %d\n\n", n, fibonacci(n));

	return 0;
}
