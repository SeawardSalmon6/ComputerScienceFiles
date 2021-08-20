#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Criando constantes com as dimensões da matriz A
    const int A_LIN = 2; const int A_COL = 3;
    int matA[A_LIN][A_COL] = { 0 };

    // Criando constantes com as dimensões da matriz B
    const int B_LIN = 3; const int B_COL = 4;
    int matB[B_LIN][B_COL] = { 0 };

    // Início do código
    puts("\nInsira os valores da --> Matriz A <--, abaixo:\n");

    // Loop para receber os valores da Matriz A
    for(int l = 0; l < A_LIN; l++)
        for(int c = 0; c < A_COL; c++) {
            printf("\n\tValor da linha %d, coluna %d:  ", l, c);
            scanf(" %d", &matA[l][c]);
        }

    puts("\n\nInsira os valores da --> Matriz B <--, abaixo:\n");

    // Loop para receber os valores da Matriz A
    for(int l = 0; l < B_LIN; l++)
        for(int c = 0; c < B_COL; c++) {
            printf("\n\tValor da linha %d, coluna %d:  ", l, c);
            scanf(" %d", &matB[l][c]);
        }

    // Inicialização de matriz para armazenar os valores multiplicados
    int matResultante[A_LIN][B_COL] = { 0 };

    // Loop para multiplicar os valores
    for(int l = 0; l < A_LIN; l++)
        for(int c = 0; c < B_COL; c++)
            for(int k = 0; k < A_COL; k++)
                matResultante[l][c] += matA[l][k] * matB[k][c];
                /* 
                    Posição N da Resultante recebe a soma das
                    multiplicações dos elementos da linha R da Matriz A
                    com a Coluna R da Matriz B
                 */

    // Printando os resultados na tela
    system("clear");

    // Variável para somar e calcular a média aritmética
    int soma = 0;
    printf("\n\n============== MATRIZ RESULTANTE (%dX%d) ==============", A_LIN, B_COL);

    for(int l = 0; l < A_LIN; l++)
        for(int c = 0; c < B_COL; c++) {
            if(c % B_COL == 0)
                printf("\n\t%d", matResultante[l][c]);
            else
                printf("\t%d", matResultante[l][c]);

            if(matResultante[l][c] >= 0)
                soma += matResultante[l][c];
        }
            
    // Variável para a média aritmética
    float mediaPositivos = (float) soma / (A_LIN * B_COL);
    printf("\n\n-----> Média dos Valores Positivos da Resultante: %.2f\n\n", mediaPositivos);

    return 0;
}