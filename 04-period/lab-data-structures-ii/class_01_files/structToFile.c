#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 20
#define RECORDS_QUANTITY 2
#define FILENAME "saida.txt"

typedef struct
{
  char nome[MAX_STRING_SIZE];
  int idade;
  float nota;
} TAluno;

int main()
{
  int i;
  TAluno aluno;
  FILE *fp;

  fp = fopen(FILENAME, "w");
  if (!fp)
  {
    printf("\n--> Erro ao abrir o arquivo. Saindo...\n\n");
    exit(EXIT_FAILURE);
  }

  printf("\n--> Lendo dados: \n");
  for (i = 0; i < RECORDS_QUANTITY; i++)
  {
    printf("\n======== Aluno %02d\n", i + 1);

    printf(" -) Insira o nome do aluno: ");
    scanf(" %[^\n]s", aluno.nome);

    printf(" -) Insira a idade do aluno: ");
    scanf(" %d", &aluno.idade);

    printf(" -) Insira a nota do aluno: ");
    scanf(" %f", &aluno.nota);

    fprintf(fp, "%s;%d;%.2f\n", aluno.nome, aluno.idade, aluno.nota);
  }

  fclose(fp);

  fp = fopen(FILENAME, "r");
  if (!fp)
  {
    printf("\n--> Erro ao abrir o arquivo. Saindo...\n\n");
    exit(EXIT_FAILURE);
  }

  printf("\n\n--> Dados armazenados no arquivo: ");
  for (i = 0; i < RECORDS_QUANTITY; i++)
  {
    fscanf(fp, "%[^;];%d;%f\n", aluno.nome, &aluno.idade, &aluno.nota);

    printf("\n\n======== Aluno %02d\n", i + 1);
    printf(" -) Nome: %s\n", aluno.nome);
    printf(" -) Idade: %02d\n", aluno.idade);
    printf(" -) Nota: %.2f\n", aluno.nota);
  }

  fclose(fp);

  puts("\n");
  return 0;
}