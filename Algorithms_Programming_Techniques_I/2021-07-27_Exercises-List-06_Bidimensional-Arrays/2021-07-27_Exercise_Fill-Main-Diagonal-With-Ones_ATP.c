#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int array[5][5] = { 0 };
    puts("\n=================== Matriz Principal ===================\n");

    // Cria a matriz com os números 1 na diagonal principal
    for(int r = 0; r < 5; r++)
        for(int c = 0; c < 5; c++)
            array[r][c] = r == c ? 1 : 0;

    // Printa a matriz
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++)
            printf("| %d | ", array[r][c]);
        
        puts("\n+---+-+---+-+---+-+---+-+---+");
    }

    puts("\n");

    return 0;
}