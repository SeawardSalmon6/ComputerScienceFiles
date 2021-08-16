/* Dados do Aluno:
    -> Aluno: Jean Rayhan Vieira Achour
    -> RA: 211043486
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_ARRAY 8

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Array de MAX_ARRAY posições para armazenar os valores do usuário
    int arrUsuario[MAX_ARRAY] = { 0 };
    int maiorValor, menorValor;

    puts("\n----> Bem-vindo ao Divisor de Extremos 2000!\n");
    puts("Abaixo, insira 8 valores inteiros: ");

    // Loop-For para armazenar os valores do usuário
    for(int i = 0; i < MAX_ARRAY; i++) {
        printf("\n  -> Insira o %dº valor:  ", i + 1);
        scanf(" %d", &arrUsuario[i]);

        if(i == 0) {
            // Valores de inicialização
            maiorValor = arrUsuario[i];
            menorValor = arrUsuario[i];
        } else {

            // Armazenando os valores dos extremos - maior e menor números
            if(arrUsuario[i] >= maiorValor) maiorValor = arrUsuario[i];
            if(arrUsuario[i] <= menorValor) menorValor = arrUsuario[i];
        }
    }

    // Constante da diferença dos valores
    const int extDiferenca = maiorValor - menorValor;

    system("clear"); // limpando a tela
    puts("\n=========== VETOR ORIGINAL ===========");

    // Loop-For para apresentar o vetor original
    for(int i = 0; i < MAX_ARRAY; i++)
        printf("\n   Elemento nº %d  ->  %d", i + 1, arrUsuario[i]);

    if(extDiferenca == 0) {
        puts("\n---> O vetor não sofreu alteração, pois a diferença entre o maior e o menor número é igual a zero. Não é possível fazer divisão por zero!\n\n");

    } else {

        puts("\n\n\n=========== VETOR DIVIDO PELA DIFERENÇA DOS EXTREMOS ===========");

        // Loop-For para apresentar o vetor original
        double resDiv; // Variável de armazenamento
        double newArray[MAX_ARRAY] = { 0 };

        // Convertendo os valores inteiros do array original em um novo array do tipo double
        for(int i = 0; i < MAX_ARRAY; i++)
            newArray[i] = (double) arrUsuario[i];

        // Dividindo os valores e apresentando na tela
        for(int i = 0; i < MAX_ARRAY; i++) {
            resDiv = newArray[i] / extDiferenca;
            newArray[i] = resDiv;
            
            printf("\n   Elemento nº %d  ->  %.2lf", i + 1, newArray[i]);
        }
    }

    puts("\n\n");   

    return 0;
}