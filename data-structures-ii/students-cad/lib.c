#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

void clearTerminalEOF()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void fillRecord(FILE *fp, TAluno record)
{
  int nDigits = (int)(log10(abs(record.raUnesp))) + 1;
  int nameSize = strnlen(record.nome, MAX_STRING_SIZE);
  int courseSize = strnlen(record.curso, MAX_STRING_SIZE);
  int i;

  for (i = 0; i < RECORD_SIZE - (nDigits + nameSize + courseSize + 3); i++)
    fprintf(fp, "#");
}

void showMenu(FILE *fp, FILE *ind)
{
  int op;

  do
  {
    fp = fopen(LIST_FILENAME, "a+");
    ind = fopen(INDEX_FILENAME, "a+");

    if (!fp || !ind)
    {
      printf("\n--> Erro ao abrir o arquivo!\n\n");
      exit(EXIT_FAILURE);
    }

    printf("\n===== MENU");
    printf("\n(1) Gravar Aluno");
    printf("\n(2) Buscar Aluno");
    printf("\n(3) Sair");

    printf("\n\n--> Digite a opção escolhida: ");
    scanf(" %d", &op);

    switch (op)
    {
    case 1:
      readStudent(fp, ind);
      break;
    case 2:
      findStudent(fp, ind);
      break;
    case 3:
      printf("\n--> Obrigado por utilizar nossa aplicação!\n\n");
      break;
    default:
      printf("\n!-> Insira uma opção válida!\n\n");
      break;
    }
  } while (op != 3);

  fclose(fp);
  fclose(ind);
}

void readStudent(FILE *fp, FILE *ind)
{
  TAluno aux;
  long pos;
  char fillString[RECORD_SIZE];

  fseek(fp, 0, SEEK_END);
  pos = ftell(fp);

  clearTerminalEOF();
  printf("\n======= GRAVAR ALUNO\n");

  printf("\n-> Insira o nome: ");
  fgets(aux.nome, MAX_STRING_SIZE, stdin);
  aux.nome[strcspn(aux.nome, "\n")] = '\0';

  printf("\n-> Insira o nome do curso: ");
  fgets(aux.curso, MAX_STRING_SIZE, stdin);
  aux.curso[strcspn(aux.curso, "\n")] = '\0';

  do
  {
    printf("\n-> Insira o RA UNESP: ");
    scanf(" %d", &aux.raUnesp);

    if (aux.raUnesp <= 0 || aux.raUnesp > 99999)
      printf("\n\n!--> Insira um valor entre 1 e 99999!\n");
  } while (aux.raUnesp <= 0 || aux.raUnesp > 99999);

  fprintf(fp, "%d;%s;%s;", aux.raUnesp, aux.nome, aux.curso);
  fillRecord(fp, aux);
  fprintf(ind, "%d;%ld\n", aux.raUnesp, pos);

  fclose(fp);
  fclose(ind);
}

void findStudent(FILE *fp, FILE *ind)
{
  int pos, ra, check = 0;
  char *token, line[RECORD_SIZE];

  printf("\n======= BUSCAR ALUNO\n");
  printf("\n--> Insira o RA do aluno: ");
  scanf(" %d", &ra);

  while (!feof(ind) && fgets(line, RECORD_SIZE + 1, ind) != NULL)
  {
    token = strtok(line, FIELDS_DELIMETER);

    if (atoi(token) == ra)
    {
      token = strtok(NULL, FIELDS_DELIMETER);
      pos = atoi(token);

      fseek(fp, pos, SEEK_SET);
      if (fgets(line, RECORD_SIZE + 1, fp) != NULL)
      {
        token = strtok(line, FIELDS_DELIMETER);

        printf("\n--> RA do Aluno: %d", atoi(token));
        token = strtok(NULL, FIELDS_DELIMETER);

        printf("\n--> Nome do Aluno: %s", token);
        token = strtok(NULL, FIELDS_DELIMETER);

        printf("\n--> Curso: %s", token);
        token = strtok(NULL, FIELDS_DELIMETER);

        printf("\n");
      }
      check = 1;
    }
  }

  if (!check)
    printf("\n!-> O aluno especificado não foi encontrado!\n");

  fclose(fp);
}