#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    printf("\n\nResolução de Sistema Incompatível: A(8x5) ; B(5x1) \n\n");

    const int qtdEquacoes = 8, qtdIncognitas = 5;

    double A[qtdEquacoes][qtdIncognitas];
    double B[qtdEquacoes][1];

    printf("\n\nPrimeira Matriz: A \n\n");

    for(int i = 0; i < qtdEquacoes; i++)
        for(int j = 0; j < qtdIncognitas; j++) {
            printf("\nDigite o elemento da linha %d e coluna %d: ", i, j);
            scanf(" %lf", &A[i][j]);
        }

    printf("\n\nSegunda Matriz: B \n\n");

    for(int i = 0; i < qtdEquacoes; i++)
        for(int j = 0; j < 1; j++) {
            printf("\nDigite o elemento da linha %d e coluna %d: ", i, j);
            scanf(" %lf", &B[i][j]);
        }

    system("clear");
    double AT[qtdIncognitas][qtdEquacoes];

    for(int i = 0; i < qtdIncognitas; i++)
        for(int j = 0; j < qtdEquacoes; j++)
            AT[i][j] = A[j][i];

    double AT_A[qtdIncognitas][qtdIncognitas];

    for(int i = 0; i < qtdIncognitas; i++)
        for(int j = 0; j < qtdIncognitas; j++) {
            AT_A[i][j] = 0; // zerando a matriz
            
            for(int k = 0; k < qtdEquacoes; k++)
                AT_A[i][j] += AT[i][k] * A[k][j]; // atribuindo os valores da multiplicação entre os valores de AT e A
        }

    double AT_B[qtdIncognitas][1];

    for(int i = 0; i < qtdIncognitas; i++)
        for(int j = 0; j < 1; j++) {
            AT_B[i][j] = 0;
            
            for(int k = 0; k < qtdEquacoes; k++)
                AT_B[i][j] += AT[i][k] * B[k][j];
        }
    
    printf("\n\nMatriz AT_A \n\n");
    
    for(int i = 0; i < qtdIncognitas; i++) {
        for(int j = 0; j < qtdIncognitas; j++)
            printf("%.3f\t", AT_A[i][j]);
        
        printf("\n");
    }

    printf("\n\n\n");
    printf("\n\nMatriz AT_B \n\n");
    
    for(int i = 0; i < qtdIncognitas; i++) {
        for(int j = 0; j < 1; j++)
            printf("%.3f\t", AT_B[i][j]);
        
        printf("\n");
    }

    double m; // Índice multiplicador

    for(int pivo = 0; pivo < (qtdIncognitas - 1); pivo++) { // elemento pivô -> o primeiro elemento pivô está na primeira linha e o último está na penúltima linha
        for(int i = pivo + 1; i < qtdIncognitas; i++) { // linhas que serão modificadas abaixo do pivô, até a última linha
            m = - AT_A[i][pivo] / AT_A[pivo][pivo];

            // printf("\nÍndice Multiplicativo m = %.qtdIncognitasf\n", m);
            for(int j = pivo; j < qtdIncognitas; j++) // percorre os elementos que estão na linha que está sendo modificada na matriz AT_A
                AT_A[i][j] += m * AT_A[pivo][j];
            
            AT_B[i][0] += m * AT_B[pivo][0]; // modifica o único elemento da mesma linha na matriz AT_B
        }
    }

    printf("\n\nMatriz AT_A Escalonada \n\n");
    
    for(int i = 0; i < qtdIncognitas; i++) {
        for(int j = 0; j < qtdIncognitas; j++)
            printf("%.3f\t", AT_A[i][j]);
        
        printf("\n");
    }

    printf("\n\n\n");
    printf("\n\nMatriz AT_B Escalonada\n\n");
    
    for(int i = 0; i < qtdIncognitas; i++) {
        for(int j = 0; j < 1; j++)
            printf("%.3f\t", AT_B[i][j]);
        
        printf("\n");
    }

    double s[qtdIncognitas];

    for(int i = (qtdIncognitas - 1); i >= 0; i--) {
        s[i] = AT_B[i][0]; // atribuição inicial de valores de B em S

        for(int j = i; j < (qtdIncognitas - 1); j++) // subtração de 0 termos, de 1 termo, de 2 termos, etc...
            s[i] = s[i] - AT_A[i][j + 1] * s[j + 1];
        
        s[i] = s[i] / AT_A[i][i];
    }

    printf("\n");

    for(int i = 0; i < qtdIncognitas; i++)
        printf("\nS[%d] = %.3f", i, s[i]);

    printf("\n\n");

    return 0;
}