#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int value[4] = { 0 };
    int array[4][4] = { 0 };

    // Cabeçalho
    printf("\nInsira os 4 valores inteiros para que possamos criar a tabuada desses números:\n");

    // Capturando os valores inseridos pelo usuário
    for(int i = 0; i < 4; i++) {
        printf("\t%dº número:  ", i + 1);
        scanf(" %d", &value[i]);
    }
    
    printf("\n=============== Tabuada ===============\n");
    printf("\n\t    %d   %d   %d   %d  ", value[0], value[1], value[2], value[3]);
    printf("\n\t  ------------------------");

    for(int r = 0; r < 4; r++) {
        printf("\n\t%d | ", value[r]);
        
        for(int c = 0; c < 4; c++)
            printf("%d | ", array[r][c] = value[r] * value[c]);

        printf("\n\t  ------------------------");
    }

    puts("\n\n");

    return 0;
}