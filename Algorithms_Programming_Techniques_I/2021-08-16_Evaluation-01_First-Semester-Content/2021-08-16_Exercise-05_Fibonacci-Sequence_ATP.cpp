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

    unsigned int arrFibonacci[qtdElementos]; // Inicializando o vetor

    // 1. Criar uma função que armazene em um vetor a sequência de Fibonacci
    unsigned int valorAntAnterior = 0, valorAnterior = 0;

    for(int i = 0; i <= qtdElementos; i++) {
        if(i > 1) {
            arrFibonacci[i] = valorAnterior + valorAntAnterior;
        
            valorAntAnterior = valorAnterior;
            valorAnterior = arrFibonacci[i];

        } else if(i == 1) {
			arrFibonacci[0] = 0;
			
            valorAnterior = 1;
            arrFibonacci[i] = valorAnterior + valorAntAnterior;
        }
    }

    // 2. Apresentar os valores em ordem inversa - "i--"

    system("clear"); // Limpa a tela

    puts("\n\n================ SÉRIE DE FIBONACCI ================");

    for(int i = qtdElementos; i >= 0; i--)
        printf("\nElemento %d -> %d", i, arrFibonacci[i]);

    puts("\n\n");

    return 0;
}