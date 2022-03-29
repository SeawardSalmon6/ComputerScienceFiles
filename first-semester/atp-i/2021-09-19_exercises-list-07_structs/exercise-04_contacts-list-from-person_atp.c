/* 04. Crie um tipo registro chamado Cadastro que tenha os campos Nome (Alfanumérico), Ender (Endereco),
Dnasc (Data), Telefone (Alfanumérico). No mesmo programa, crie os tipos Data e Endereco. Crie um
vetor Contato do tipo Cadastro com 10 elementos. Faça um programa que leia todos os elementos de
Contato e em seguida os imprima. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_CONTACTS 2

typedef struct Contato {
    char nomeContato[20];
} TContato;

typedef struct Endereco {
    int numero;
    char rua[20], bairro[20];
} TEnd;

typedef struct Data {
    int dia, mes, ano;
} TData;

typedef struct Cadastro {
    char nome[30], tel[20];
    TEnd endereco;
    TData dataNasc;
    TContato listaContatos[MAX_CONTACTS];
} TCad;

int main() {
    setlocale(LC_ALL, "Portuguese");

    TCad newPessoa;
    puts("\n----------- Cadastro de Nova Pessoa -----------\n");
    printf("\n---> Nome: ");
    scanf(" %[^\n]s", newPessoa.nome);

    // Data de Nascimento
    printf("\n---> Data de Nascimento:");
    printf("\n   - Dia (dd): ");
    scanf(" %d", &newPessoa.dataNasc.dia);

    printf("   - Mês (mm): ");
    scanf(" %d", &newPessoa.dataNasc.mes);

    printf("   - Ano (aaaa): ");
    scanf(" %d", &newPessoa.dataNasc.ano);

    // Endereço
    printf("\n---> Endereço:");
    printf("\n   - Rua: ");
    scanf(" %[^\n]s", newPessoa.endereco.rua);

    printf("   - Número: ");
    scanf(" %d", &newPessoa.endereco.numero);

    printf("   - Bairro: ");
    scanf(" %[^\n]s", newPessoa.endereco.bairro);

    // Telefone
    printf("\n---> Telefone: ");
    scanf(" %[^\n]s", newPessoa.tel);

    // Lista de Contatos
    printf("\n---> Lista de Contatos: \n");
    
    for(int i = 0; i < MAX_CONTACTS; i++) {
        printf("   - Nome do Contato %d: ", i + 1);
        scanf(" %[^\n]s", newPessoa.listaContatos[i].nomeContato);
    }

    // Printing Results
    system("clear");
    puts("\n------------------ Dados da Pessoa ------------------");
    printf("\n-- Nome: %s", newPessoa.nome);
    printf("\n-- Data de Nascimento: %d/%d/%d", newPessoa.dataNasc.dia, newPessoa.dataNasc.mes, newPessoa.dataNasc.ano);
    printf("\n-- Telefone: %s", newPessoa.tel);
    printf("\n-- Endereço: %s, nº%d - Bairro %s", newPessoa.endereco.rua, newPessoa.endereco.numero, newPessoa.endereco.bairro);
    printf("\n-- Lista de Contatos:");
    
    // Printing Contacts List
    for(int i = 0; i < MAX_CONTACTS; i++)
        printf("\n   - Nome do Contato %d: %s", i + 1, newPessoa.listaContatos[i].nomeContato);

    puts("\n");

    return 0;
}