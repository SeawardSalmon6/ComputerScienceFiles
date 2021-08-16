/* Dados do Aluno:
    -> Aluno: Jean Rayhan Vieira Achour
    -> RA: 211043486
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    unsigned int qtdElementos;

    puts("\n----> Bem-vindo ao Fibonacci Presentator 2000!");

    // Criando um verificador para evitar números fora do intervalo 0 <= n <= 20
    do {
        puts("\nPara começarmos, quantos elementos gostaria de visualizar: ");
        scanf(" %d", &qtdElementos);

        if(qtdElementos < 0 || qtdElementos > 20)
            puts("\n!-> Insira valores no intervalo de 0 a 20!\n");

    } while(qtdElementos < 0 || qtdElementos > 20);

    unsigned int arrFibonacci[qtdElementos] = { 0 }; // Inicializando o vetor

    // 1. Criar uma função que armazene em um vetor a sequência de Fibonacci
    unsigned int valorAntAnterior = 0, valorAnterior = 0;

    for(int i = 0; i < qtdElementos; i++) {
        arrFibonacci[i] = valorAnterior + valorAntAnterior;
        
        valorAntAnterior = valorAnterior;
        valorAnterior = arrFibonacci[i];

        printf("\nPos.%d - %d", i, arrFibonacci[i]);
    }

    // 2. Apresentar os valores em ordem inversa - "i--"
    puts("\n================ SÉRIE DE FIBONACCI ================\n");

    for(int i = qtdElementos - 1; i >= 0; i--)
        printf("\nElemento %d -> %d", i, arrFibonacci[i]);

    return 0;
}