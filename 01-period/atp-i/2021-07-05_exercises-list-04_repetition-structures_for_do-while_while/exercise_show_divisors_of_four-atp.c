#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

	int counter = 0;
    printf("\n===== MÚLTIPLOS DE 4 [1-200] =====\n");

    for(int i = 0; i <= 200; i += 4) {
		if(counter % 10 == 0)
			printf("\n");
		
		printf(" | %d |", i);
		counter++;
	}

    printf("\n\n");

    return 0;
}