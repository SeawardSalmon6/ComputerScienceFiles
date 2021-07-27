#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int value, posX = 0, posY = 0;
    char resp;

    int array[5][5] = { 0 };

    // Cabeçalho
    printf("\nInsira os valores para a matriz 5x5:\n");

    // Faz a leitura linha-coluna dos valores da matriz
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++) {
            printf("\tLinha: %d; Coluna: %d    = ", r + 1, c + 1);
            scanf(" %d", &array[r][c]);
        }
        puts("\n");
    }

    bool valid;

    do {
        system("clear");
        puts("Insira um valor para pesquisarmos na matriz: ");
        scanf(" %d", &value);

        valid = true;
        
        for(int r = 0; r < 5; r++) {
            for(int c = 0; c < 5; c++)
                if(array[r][c] == value) {
                    printf("\n-> A primeira aparição desse valor está na posição: (%d, %d)\n", r, c);
                    valid = false;
                    break;
                }
                else if(r == 4 && c == 4)
                    printf("\n-> Valor não encontrado!\n");

            if(valid == false) break;
        }

        do {
            puts("\nDeseja pesquisar novamente (s/n)?");
            scanf(" %c", &resp);
        } while(toupper(resp) != 'S' && toupper(resp) != 'N');

    } while(toupper(resp) == 'S');

    puts("\n");

    return 0;
}