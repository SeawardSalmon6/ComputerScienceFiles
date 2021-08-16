/* Dados do Aluno:
    -> Aluno: Jean Rayhan Vieira Achour
    -> RA: 211043486
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_ARRAY 5

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Inicializando o array
    int matPrincipal[MAX_ARRAY][MAX_ARRAY] = { 0 };

    // Cabeçalho
    puts("\n-------> Bem-vindo ao Somador de Diagonais Superiores 2000!\n");
    puts("Abaixo, preencha com valores inteiros a matriz 5x5: ");

    // Capturando os valores da matriz, inseridos pelo usuário
    for(int l = 0; l < MAX_ARRAY; l++)
        for(int c = 0; c < MAX_ARRAY; c++) {
            printf("\n   Insira o valor do elemento da linha %d, coluna %d:   ", l + 1, c + 1);
            scanf(" %d", &matPrincipal[l][c]);
        }

    system("clear"); // Limpa tela 
    puts("\n================ MATRIZ ORIGINAL ================");

    // Printando Matriz Original
    for(int l = 0; l < MAX_ARRAY; l++)
        for(int c = 0; c < MAX_ARRAY; c++)
            if(c % 5 == 0)
                printf("\n\t%d", matPrincipal[l][c]);
            else
                printf("\t%d", matPrincipal[l][c]);

    // Printando a Matriz Alterada -- Transformando os valores que não fazem parte da soma, como 0
    puts("\n\n\n======== MATRIZ DE SOMA DA DIAGONAL SUPERIOR ========");

    // Variável da soma da Diagonal Superior
    int somaDiagSup = 0;

    for(int l = 0; l < MAX_ARRAY; l++)
        for(int c = 0; c < MAX_ARRAY; c++) {
            
            // Verificando se os valores estão na diagnoal superior ou inferior
            if(c < l)
                matPrincipal[l][c] = 0;
            else
                somaDiagSup += matPrincipal[l][c];

            // Printando a Matriz
            if(c % 5 == 0)
                printf("\n\t%d", matPrincipal[l][c]);
            else
                printf("\t%d", matPrincipal[l][c]);
        }

        printf("\n\n--------> A soma total da Diagonal Superior é de:  %d\n\n", somaDiagSup);

    return 0;
}