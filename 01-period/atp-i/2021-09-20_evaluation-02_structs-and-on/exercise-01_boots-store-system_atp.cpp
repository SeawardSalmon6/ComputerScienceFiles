/* Dados do Aluno:
    -> Aluno: Jean Rayhan Vieira Achour
    -> RA: 211043486
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#define MAX 15 // Limita o total de entradas

typedef struct model {
    char nome[40];
    char modelo;
} Tmodel;

typedef struct d {
    int dia;
    int mes;
    int ano;
} Tdata;

typedef struct resumo {
    int estoque; // (quantidade do produto em estoque)
    int qtd; // (quantidade vendida)
    Tmodel prod;
    Tdata data;
} Tresumo;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int i = 0;
    int aux_qtd = 0; // Permite armazenar a quantidade do produto mais vendido.
    int indice = 0; // Permite armazenar o índice do registro.

    Tresumo registro[MAX];

    ///////////////////////////////////////// LENDO OS DADOS
    puts("\n============== BEM-VINDO À BIPI-PÉ ==============");
    puts("\nA seguir, iremos cadastrar nossos calçados disponíveis em estoque:");
    for(i = 0; i < MAX; i++) {
        printf("\n\n------------ Calçado %d", i + 1);

        /* Registro da Identificação do Calçado */
        printf("\n\n-- Nome do Calçado:  ");
        scanf(" %[^\n]s", registro[i].prod.nome);

        printf("-- Modelo:  ");
        scanf(" %c", &registro[i].prod.modelo);
        registro[i].prod.modelo = toupper(registro[i].prod.modelo); // Trabalhando com modelos maiúsculos

        /* Registro dos Dados de Estoque */
        printf("\n-- Quantidade Disponível em Estoque:  ");
        scanf(" %d", &registro[i].estoque);

        printf("-- Quantidade de Unidades Vendidas:  ");
        scanf(" %d", &registro[i].qtd);

        /* Registro da Data de Venda */
        printf("\n-- Data da Venda:  ");
        printf("\n   -> Dia (dd):  ");
        scanf(" %d", &registro[i].data.dia);

        printf("   -> Mês (mm):  ");
        scanf(" %d", &registro[i].data.mes);

        printf("   -> Ano (aaaa):  ");
        scanf(" %d", &registro[i].data.ano);
    }

    system("clear");
    ///////////////////////////////////////// FIM LEITURA DOS DADOS




    ///////////////////////////////////////// (a) nome(s) do calçado(s) e total da venda, cujo modelo seja A, vendido na primeira quinzena dos meses de 3 a 5;
    printf("\n\n\n==============> Calçados da Categoria 'A'");
    puts("\n----> Os calçados abaixo foram vendidos na primeira quinzena dos meses entre Março e Maio.");
    
    for(i = 0; i < MAX; i++) {
        // Verifica se o produto é da categoria 'A' e está na quinzena
        if((registro[i].prod.modelo == 'A') && ((registro[i].data.dia > 0) && (registro[i].data.dia <= 15))) {
            if(registro[i].data.mes >= 3 && registro[i].data.mes <= 5) { // Verifica se está entre o período dos meses 03 a 05
                printf("\n\n------------ Calçado %d", i + 1);

                printf("\n\n-- Nome do Calçado:  %s", registro[i].prod.nome);
                printf("\n-- Total de Unidades Vendidas:  %d", registro[i].qtd);
                indice++; // Utilizando a variável como verificadora para a existência ou não de produtos que atendam aos requisitos.
            }
        }
        
        if((i == MAX - 1) && (indice == 0)) // Se não forem encontrados nenhum produto, apresentar a mensagem abaixo
            puts("\n\nAVISO --------> Não houveram registros de vendas no período especificado.");
    }

    puts("\n\n\nFIM VERIFICAÇÃO CALÇADOS CATEGORIA 'A' <==============\n");
    //////////////////////////////////////// FIM ITEM A




    //////////////////////////////////////// (b) nome do calçado do modelo C que foi o mais vendido;
    // Forçando as variáveis a iniciarem com valor 0
    aux_qtd = 0;
    indice = 0;

    for(i = 0; i < MAX; i++) { // Verificando antes do print, se existem valores que atendam aos requisitos
        if(registro[i].prod.modelo == 'C') {
            if(registro[i].qtd >= aux_qtd) {
                aux_qtd = registro[i].qtd;
                indice = i;
            }
        }
    }
    
    if(aux_qtd > 0) { // Se for encontrado o valor correspondente, printa o requisitado
        printf("\n\n\n==============> Calçado da Categoria 'C' Mais Vendido");
        puts("\n----> Abaixo, está apresentado o produto da categoria 'C' mais vendido.");

        printf("\n\n------------ Calçado %d", indice + 1);
        printf("\n\n-- Nome do Calçado:  %s", registro[indice].prod.nome);

        puts("\n\n\nFIM CALÇADO MAIS VENDIDO CATEGORIA 'C' <==============\n");
    }
    //////////////////////////////////////// FIM ITEM B




    //////////////////////////////////////// (c) nome do calçado e quantidade em estoque do produto mais vendido no mês 12;
    // Iniciando as variáveis verificadoras em 0
    aux_qtd = 0;
    indice = 0;

    for(i = 0; i < MAX; i++) { // Verifica os valores antes de possivelmente, printar os resultados obtidos
        if(registro[i].data.mes == 12 && registro[i].qtd >= aux_qtd) {
            aux_qtd = registro[i].qtd;
            indice = i;
        }
    }

    if(aux_qtd > 0) { // Se for encontrado o produto requisitado, apresenta o relatório
        printf("\n\n\n==============> Calçado Mais Vendido em Dezembro");
        puts("\n----> Abaixo, está apresentado o produto da categoria mais vendido no mês de Dezembro(12).");

        printf("\n\n------------ Calçado %d", indice + 1);
        printf("\n\n-- Nome do Calçado:  %s", registro[indice].prod.nome);
        printf("\n-- Quantidade em Estoque:  %d", registro[indice].estoque);

        puts("\n\n\nFIM VERIFICAÇÃO DE ESTOQUE <==============\n");
    }
    //////////////////////////////////////// FIM ITEM C




    /////////////////////////////////////// (d) apresentar os nomes e modelos dos calçados com estoque zerado. Os resultados para os itens (b) e (c) devem ser apresentados somente se "aux_qtd" for diferente zero.
    printf("\n\n\n==============> Reposição de Estoque");
    puts("\n----> Os calçados abaixo precisam de reposição de estoque. NENHUMA UNIDADE DISPONÍVEL.");

    for(i = 0; i < MAX; i++) { // For para rodar em todos os produtos do vetor
        if(registro[i].estoque == 0) { // Verifica se não há unidades em estoque, de algum produto
            printf("\n\n------------ Calçado %d", i + 1);

            printf("\n\n-- Nome do Calçado:  %s", registro[i].prod.nome);
            printf("\n-- Modelo:  %c", registro[i].prod.modelo);
        } else if(i == MAX - 1) { // Se os produtos anteriores ao último produto e o último produto não cumprirem os requisitos, aprensenta a mensagem abaixo
            puts("\n\nAVISO -----> seu estoque está em dia, temos pelo menos uma unidade de cada calçado!");
        }
    }

    puts("\n\n\nFIM VERIFICAÇÃO DE ESTOQUE <==============\n");
    //////////////////////////////////////// FIM ITEM D

    puts("\n");
    return 0;
}