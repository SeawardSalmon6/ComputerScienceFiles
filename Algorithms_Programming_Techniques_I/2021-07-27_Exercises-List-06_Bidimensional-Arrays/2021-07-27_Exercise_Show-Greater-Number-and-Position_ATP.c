#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int maior = 0, maiorX = 0, maiorY = 0;
    int array[4][4] = { 0 };

    // Cabeçalho
    printf("\nInsira os valores para a matriz 4x4:\n");

    // Faz a leitura linha-coluna dos valores da matriz
    for(int r = 0; r < 4; r++) {
        for(int c = 0; c < 4; c++) {
            printf("\tLinha: %d; Coluna: %d    = ", r + 1, c + 1);
            scanf(" %d", &array[r][c]);

            if(r == 0) maior = array[r][c];
            else if(array[r][c] >= maior) {
                maior = array[r][c];
                maiorX = r; 
                maiorY = c;
            }
        }
        puts("\n");
    }

    printf("------------------------------------------------------------\n");
    printf("O maior número é: %d - coordenadas: (%d, %d)\n\n", maior, maiorX, maiorY);

    return 0;
}