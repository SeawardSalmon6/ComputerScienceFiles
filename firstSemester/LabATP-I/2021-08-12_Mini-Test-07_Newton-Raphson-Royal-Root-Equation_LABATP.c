#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    double anterior, erroMax, proximo, erroCor;
    
    puts("\nSolução da Equação: x² - 3x + 2 = 0\n");

    // Evita que o usuário insira um valor igual a 0 para a raiz
    do {
        puts("\nDigite o valor aproximado para a raiz: ");
        scanf(" %lf", &anterior);

        if(anterior == 0)
            puts("\n-> Insira um valor diferente de 0!");

    } while(anterior == 0);

    puts("\nDigite o erro máximo aceitável: ");
    scanf(" %lf", &erroMax);

    puts("\n============== LOG ==============");

    do {
        // Verifica se o divisor (derivada da equação) é igual a zero
        if((2 * anterior - 3) == 0) anterior *= anterior;
        
        proximo = anterior - ( (anterior * anterior - 3 * anterior + 2) / (2 * anterior - 3) );

        printf("\nA aproximação corrente para a raiz é: %.10f", proximo);

        erroCor = ( (proximo - anterior >= 0) ? (proximo - anterior) : (anterior - proximo) );
        anterior = proximo;

    } while((erroCor >= erroMax) && (erroMax != 0));

    puts("\n\n\n============== Resultado ==============\n");
    printf("A solução é: %.10f\n\n", proximo);

    return 0;
}