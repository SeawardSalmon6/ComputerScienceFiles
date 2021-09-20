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
    do { // Criando um verificador para evitar números fora do intervalo 0 <= n <= 20
        puts("\nPara começarmos, quantos elementos gostaria de visualizar: ");
        scanf(" %d", &qtdElementos);

        if(qtdElementos < 0 || qtdElementos > 20)
            puts("\n!-> Insira valores no intervalo de 0 a 20!\n");

    } while(qtdElementos < 0 || qtdElementos > 20);

    if(qtdElementos > 0) {
        // 1. Criar uma função que armazene em um vetor a sequência de Fibonacci
        unsigned int arrFibonacci[qtdElementos] = { 0, 1 }; // Inicializando o vetor
        unsigned int valorAntAnterior = 0, valorAnterior = 1;

        for(int i = 2; i < qtdElementos; i++) {
            arrFibonacci[i] = valorAnterior + valorAntAnterior;
        
            valorAntAnterior = valorAnterior;
            valorAnterior = arrFibonacci[i];
        }

        // 2. Apresentar os valores em ordem inversa - "i--"
        system("clear"); // Limpa a tela
        puts("\n\n================ SÉRIE DE FIBONACCI ================");

        for(int i = qtdElementos - 1; i >= 0; i--)
            printf("\nElemento %d -> %d", i + 1, arrFibonacci[i]);

        puts("\n");
    } else
        puts("\nAVISO --> Não existem valores disponíveis para 0 elementos!\n\n");

    return 0;
}