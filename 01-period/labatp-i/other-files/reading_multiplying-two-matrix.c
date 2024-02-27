#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "mylib.h"

int main() {
    setLocale;

    // Criando variáveis com as dimensões das matrizes
    int A_LIN = 0, A_COL = 0;
    int B_LIN = 0, B_COL = 0;

    puts("\nVamos multiplicar duas matrizes?");

    // Captura de linhas e colunas da matriz A
    puts("\n---> Dimensões da Matriz A");
    printf("\t- Quantidade de Linhas: ");
    scanf(" %d", &A_LIN);

    printf("\t- Quantidade de Colunas: ");
    scanf(" %d", &A_COL);

    // Captura de linhas e colunas da matriz B  
    puts("\n---> Dimensões da Matriz B");
    printf("\t- Quantidade de Linhas: ");
    scanf(" %d", &B_LIN);

    printf("\t- Quantidade de Colunas: ");
    scanf(" %d", &B_COL);

    if(A_COL == B_LIN && A_LIN * A_COL * B_COL * B_LIN != 0) {
        int matA[A_LIN][A_COL];
        int matB[B_LIN][B_COL];

        // Reset to 0 values, the two arrays A and B  
        clearMatrix(matA, A_LIN, A_COL);
        clearMatrix(matB, B_LIN, B_COL);

        // Início do código
        system("clear");
        puts("\nInsira os valores da --> Matriz A <--, abaixo:\n");

        // Loop para receber os valores da Matriz A
        for(int l = 0; l < A_LIN; l++)
            for(int c = 0; c < A_COL; c++) {
                matA[l][c] = 0;
                
                printf("\n\tValor da linha %d, coluna %d:  ", l + 1, c + 1);
                scanf(" %d", &matA[l][c]);
            }

        puts("\n\nInsira os valores da --> Matriz B <--, abaixo:\n");

        // Loop para receber os valores da Matriz A
        for(int l = 0; l < B_LIN; l++)
            for(int c = 0; c < B_COL; c++) {
                matB[l][c] = 0;

                printf("\n\tValor da linha %d, coluna %d:  ", l + 1, c + 1);
                scanf(" %d", &matB[l][c]);
            }

        // Inicialização de matriz para armazenar os valores multiplicados
        int matResultante[A_LIN][B_COL];
        clearMatrix(matResultante, A_LIN, B_COL);

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

    } else
        puts("\n\n--> ATENÇÃO: Não é possível multiplicar matrizes se a quantidade de colunas da Matriz A for diferente da quantidade de linhas da Matriz B. E os valores para linhas e colunas deve ser maior do que 0.\n\n");

    return 0;
}