#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_PEOPLE 10
#define MAX_ITEMS 3

int main() {
    setlocale(LC_ALL, "Portuguese");

    int option;

    int mnSandwich[MAX_ITEMS] = { 0 },
        mnPizza[MAX_ITEMS] = { 0 },
        mnDrink[MAX_ITEMS] = { 0 };

    do {
        system("clear");

        puts("\t----------- MENU PRINCIPAL -----------");
        puts("\t 1. Incluir Lanche");
        puts("\t 2. Incluir Pizza");
        puts("\t 3. Incluir Bebida");
        puts("\t 4. Fechar Conta");
        puts("\t 5. Fechar Caixa");
        puts("\t 6. Imprimir Relatório");
        puts("\t 7. Sair");

        do {
            puts("\n Escolha uma opção: ");
            scanf(" %d", &option);

            if(option < 1 || option > 7)
                puts("-> Insira um opção válida!\n");

        } while(option < 1 || option > 7);
    
    } while(option != 7);

    system("clear");
    puts("Obrigado por utilizar nosso aplicativo!\n\n");

    /* Criar variáveis e vetores para realizar a contagem dos produtos
        - vetor para contar a quantidade de produtos e seus tipos
        [lanche 1][lanche 2][lanche 3]
            0         0         0

        - variável de limite para os vetores MAX_VECTOR

        - fechar conta
            -> mostrar o total e cancelar novas inserções
        
        - fechar caixa
            -> mostrar o total ganho do restaurante

        - opção 6
            -> mostrar o total de produtos vendidos e o total em reais

            Três Tipos de Lanches
            -> Lanche 1
            -> Lanche 2
            -> Lanche 3

            Três Tipos de Pizzas
            -> Pizza 1
            -> Pizza 2
            -> Pizza 3

            Três Tipos de Bebidas
            -> Bebida 1
            -> Bebida 2
            -> Bebida 3
    */

    return 0;
}