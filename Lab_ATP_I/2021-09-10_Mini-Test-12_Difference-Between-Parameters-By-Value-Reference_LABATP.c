#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void porValor(int);
void porReferencia(int*);

int main() {
    setlocale(LC_ALL, "Portuguese");

    int valorQualquer = 25;
    puts("\nint valorQualquer = 25");

    porValor(valorQualquer);
    printf("\nPor valor (var: valorQualquer): %d \n", valorQualquer);

    porReferencia(&valorQualquer);
    printf("\nPor referência (var: valorQualquer): %d \n\n", valorQualquer);

    return 0;
}

void porValor(int param1) {
    param1 = 100000;
}

void porReferencia(int* param1) {
    *param1 = 100000;
}