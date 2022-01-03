#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int n;
	printf("\n%p\n", gloArr);

	printf("size of array: ");
	scanf(" %d", &n);

	int gloArr[n];

	printf("\n-> new %lu\n", gloArr);
	for (int i = 0; i < n; i++) {
		gloArr[i] = i + 1;
		printf("\n-> %d", gloArr[i]);
	}

	return 0;
}
