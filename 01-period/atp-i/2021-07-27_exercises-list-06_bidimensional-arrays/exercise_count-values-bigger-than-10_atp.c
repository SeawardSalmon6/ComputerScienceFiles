#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int soma = 0;
    int array[4][4] = { 0 };

    // Cabeçalho
    printf("\nInsira os valores para a matriz 4x4:\n");

    // Faz a leitura linha-coluna dos valores da matriz
    for(int r = 0; r < 4; r++) {
        for(int c = 0; c < 4; c++) {
            printf("\tLinha: %d; Coluna: %d    = ", r + 1, c + 1);
            scanf(" %d", &array[r][c]);

            // Verificando os valores - se maior que 10
            if(array[r][c] > 10) soma++;
        }
        puts("\n");
    }

    printf("------------------------------------------------------------\n");
    printf("A quantidade de valores maiores do que 10 é de:  %d valor(es)\n\n", soma);

    return 0;
}