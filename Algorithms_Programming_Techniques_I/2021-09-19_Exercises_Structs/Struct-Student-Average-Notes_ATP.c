#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Aluno {
    float notaProva;
    float notaTrabalho;
    float media;
    char nome[20];
} TAluno;

int main() {
    setlocale(LC_ALL, "Portuguese");

    TAluno newAluno;

    printf("\nInsira o nome do aluno: \n");
    scanf(" %[^\n]s", newAluno.nome);

    printf("\nInsira o nota da prova do aluno: \n");
    scanf(" %f", &newAluno.notaProva);

    printf("\nInsira o nota do trabalho do aluno: \n");
    scanf(" %f", &newAluno.notaTrabalho);

    // Calculus Area
    newAluno.media = (newAluno.notaProva + newAluno.notaTrabalho) / 2;

    // Printing Results
    printf("\n\n--->> RESULTADOS");
    printf("\n- Nome do Aluno: %s", newAluno.nome);
    printf("\n- Nota da Prova: %.2f", newAluno.notaProva);
    printf("\n- Nota do Trabalho: %.2f", newAluno.notaTrabalho);
    printf("\n---> Média Geral: %.2f \n\n", newAluno.media);

    return 0;
}