#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int numPontos;
    printf("\n=========> Parábola Média pelos Mínimos Quadrados\n");
    do { /* Loop para prevenir número de pontos menor do que zero */
        printf("\nDigite o número de pontos da reta: ");
        scanf(" %d", &numPontos);

        if(numPontos < 1)
            puts("\n\n--> Insira um valor maior do que zero.");
    } while(numPontos < 1);
    
    double somaX = 0, somaXQuadrado = 0, somaXCubo = 0, somaXQuarta = 0;
    double somaY = 0, somaXY = 0, somaXQuadradoY = 0;
    double iptX, iptY;

    for(int i = 0; i < numPontos; i++) {
        printf("\nDigite o valor de x[%d]: \n", i + 1);
        scanf(" %lf", &iptX);

        somaX += iptX;
        somaXQuadrado += pow(iptX, 2);
        somaXQuadrado += pow(iptX, 3);
        somaXQuadrado += pow(iptX, 4);

        printf("\nDigite o valor de y[%d]: \n", i + 1);
        scanf(" %lf", &iptY);

        somaY += iptY;
        somaXY += iptX * iptY;
        somaXQuadradoY += pow(iptX, 2) * iptY;
    }

    /* Definição das fórmulas das determinantes */
    double det = (pow(somaXQuadrado, 3) + pow(somaXCubo, 2)) * (numPontos + somaXQuadrado * pow(somaX, 2)) - (numPontos * somaXQuadrado * somaXQuarta) - (2 * (somaX * somaXQuadrado * somaXCubo));
    double detA = (somaY * pow(somaXQuadrado, 2)) + (pow(somaX, 2) * somaXQuadradoY) + (numPontos * somaXY * somaXCubo) - (numPontos * somaXQuadrado * somaXQuadradoY) - (somaXCubo * somaX * somaY) - (somaXY * somaX * somaXQuadrado);
    double detB = (pow(somaXQuadrado, 2) * somaXY) + (somaY * somaX * somaXQuarta) + (numPontos * somaXQuadradoY * somaXCubo) - (numPontos * somaXY * somaXQuarta) - (somaY * somaXCubo * somaXQuadrado) - (somaX * somaXY * somaXQuadrado);
    double detC = (pow(somaXQuadrado, 2) * somaXQuadradoY) + (somaX * somaXY * somaXQuarta) + (somaY * pow(somaXCubo, 2)) - (somaY * somaXQuadrado * somaXQuarta) - (somaX * somaXCubo * somaXQuadradoY) - (somaXQuadrado * somaXY * somaXCubo);

    /* Variáveis de armazenamento dos resultados */
    double a = detA / det;
    double b = detB / det;
    double c = detC / det;

    /* Se A for 0, significa que a função é de primeiro grau e não forma uma parábola */
    if(a != 0)
        if(b >= 0)
            if(c >= 0)
                printf ("\n\nA parábola média é: y = %.3lfx² + %.3lfx + %.3lf\n\n", a, b, c);
            else
                printf ("\n\nA parábola média é: y = %.3lfx² + %.3lfx %.3lf\n\n", a, b, c);
       
        else if(b < 0)
            if(c >= 0)
                printf ("\n\nA parábola média é: y = %.3lfx² %.3lfx + %.3lf\n\n", a, b, c);
            else
                printf ("\n\nA parábola média é: y = %.3lfx² %.3lfx %.3lf\n\n", a, b, c);

    else
        printf ("\n\nOs pontos apresentados não formam uma parábola!\n\n");

    return 0;
}