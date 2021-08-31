#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int numPontos;
    printf("\n=========> Reta Média por Mínimos Quadrados\n");
    printf("\nDigite o número de pontos da reta: ");
    scanf(" %d", &numPontos);

    // Para linguagem C++ ou código escrito em C e COMPILADO com um compilador C++
    // double* x = new double[numPontos];
    // double* y = new double[numPontos];

    // Equivalente ao new (que só existe em C++) para a linguagem C
    // double *x = (double*) malloc(numPontos * sizeof(*x));
    // double *y = (double*) malloc(numPontos * sizeof(*y));
    double somaX = 0, somaXQuadrado = 0, somaY = 0, somaXY = 0;
    double iptX, iptY;

    for(int i = 0; i < numPontos; i++) {
        printf("\nDigite o valor de x[%d]: \n", i + 1);
        scanf(" %lf", &iptX);

        somaX += iptX;
        somaXQuadrado += iptX * iptX;

        printf("\nDigite o valor de y[%d]: \n", i + 1);
        scanf(" %lf", &iptY);

        somaY += iptY;
        somaXY += iptX * iptY;
    }

    double a = (numPontos * somaXY - somaX * somaY) / (numPontos * somaXQuadrado - somaX * somaX);
    double b = (somaXQuadrado * somaY - somaXY * somaX) / (numPontos * somaXQuadrado - somaX * somaX);

    printf("\n\n------> A Reta Média é y = %.3lfx + %.3lf \n\n", a, b);

    return 0;
}