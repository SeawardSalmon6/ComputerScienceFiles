#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_LENGTH 2

typedef struct Aluno {
    float notaProva;
    float notaTrabalho;
    float media;
    char nome[20];
} TAluno;

int main() {
    setlocale(LC_ALL, "Portuguese");

    TAluno newAluno[MAX_LENGTH];

    puts("\n--------- Cadastro de Alunos ----------\n");

    /* Leitura dos Dados */
    for(int i = 0; i < MAX_LENGTH; i++) {
        printf("\nInsira o nome do aluno %d: ", i + 1);
        scanf(" %[^\n]s", newAluno[i].nome);

        printf("\n   - Insira o nota da prova do aluno: ");
        scanf(" %f", &newAluno[i].notaProva);

        printf("\n   - Insira o nota do trabalho do aluno: ");
        scanf(" %f", &newAluno[i].notaTrabalho);

        // Calculus Area
        newAluno[i].media = (newAluno[i].notaProva + newAluno[i].notaTrabalho) / 2;
    }

    // Printing Results
    system("clear");
    printf("\n\n--->> RESULTADOS");

    for(int i = 0; i < MAX_LENGTH; i++) {
        printf("\n- Nome do Aluno %d: %s", i + 1, newAluno[i].nome);
        printf("\n   -> Nota da Prova: %.2f", newAluno[i].notaProva);
        printf("\n   -> Nota do Trabalho: %.2f", newAluno[i].notaTrabalho);
        printf("\n---> Média Geral: %.2f \n\n", newAluno[i].media);
    }

    return 0;
}