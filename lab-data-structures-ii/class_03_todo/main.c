#include <stdio.h>
#include <stdlib.h>

#define DATA_FILENAME "ToDo.txt"
#define INDEX_FILENAME "ToDoIndex.txt"
#define STARTING_KEY_ID 1000

typedef struct
{
  int id;
  char tarefa[60];
  int dia, mes, ano;
} ToDo;

typedef struct
{
  int id;
  long pos;
} ToDoIndex;

int keyId = STARTING_KEY_ID;

int cadastrar_todo(ToDoIndex **l, int quant, int tam, char *file)
{
  FILE *fp = fopen(file, "a+");

  if (!fp)
  {
    printf("\n\t!--> Erro ao abrir o arquivo!\n\n");
    exit(1);
  }

  if (quant < tam)
  {
    ToDo *novo = malloc(sizeof(ToDo));
    ToDoIndex *idxNovo = malloc(sizeof(ToDoIndex));
    printf("\nDigite a Tarefa: ");
    scanf("%60[^\n]", novo->tarefa);
    printf("\nDigite a data prevista dd mm aaaa: ");
    scanf("%2d%2d%4d", &novo->dia, &novo->mes, &novo->ano);
    getchar();
    novo->id = keyId++;

    fseek(fp, 0, SEEK_END);
    idxNovo->id = novo->id;
    idxNovo->pos = ftell(fp);

    fprintf(fp, "%d\n", novo->id);
    fprintf(fp, "%s\n", novo->tarefa);
    fprintf(fp, "%d %d %d\n", novo->dia, novo->mes, novo->ano);

    fclose(fp);
    return 1;
  }
  else
  {
    printf("\n\tERRO! Vetor cheio!\n");
    return 0;
  }
}

void imprimir(ToDoIndex **l, int quant, char *file)
{
  FILE *fp = fopen(file, "r");
  ToDo *todo;
  int i;
  printf("\n\t------ Lista de Tarefas ------\n");
  for (i = 0; i < quant; i++)
  {
    fseek(fp, l[i]->pos, SEEK_SET);
    fscanf(fp, "%d\n", &todo->id);
    fscanf(fp, "%60[^\n]\n", todo->tarefa);
    fscanf(fp, "%d %d %d\n", &todo->dia, &todo->mes, &todo->ano);
    printf("\t%d = %02d/%02d/%04d\t%s\n", todo->id, todo->dia, todo->mes, todo->ano, todo->tarefa);
  }
  printf("\t--------------------------------\n");
  fclose(fp);
}

long buscar_id(ToDoIndex **l, int id, int quant)
{
  int i;
  for (i = 0; i < quant; i++)
    if (l[i]->id == id)
      return l[i]->pos;
  return 0;
}

void alterar_todo(ToDoIndex **l, int quant, char *file)
{
  FILE *fp = fopen(file, "r+");
  char *before, *after;
  int id, pos, bytesBefore, bytesAfter;

  if (!fp)
  {
    printf("\n!--> Não foi possível abrir/encontrar o arquivo de dados!\n\n");
    exit(1);
  }

  imprimir(l, quant, INDEX_FILENAME);
  printf("\n\tDigite a tarefa a ser alterada: \n");
  scanf("%d", &id);
  getchar();

  pos = buscar_id(l, id, quant);
  if (pos != 0)
  {
    ToDo *novo = malloc(sizeof(ToDo));
    printf("\nDigite a nova tarefa: ");
    scanf("%60[^\n]", novo->tarefa);
    printf("\nDigite a data da tarefa dd mm aaaa: ");
    scanf("%2d%2d%4d", &novo->dia, &novo->mes, &novo->ano);
    getchar();

    bytesBefore = pos;
    before = malloc(bytesBefore * sizeof(char));

    pos = buscar_id(l, id + 1, quant);
    bytesAfter = fseek(fp, 0, SEEK_END);
    bytesAfter -= pos;
    malloc(bytesAfter * sizeof(char));

    rewind(fp);
    fread(before, 1, bytesAfter, fp);
    fseek(fp, pos, SEEK_SET);
    fread(after, 1, bytesAfter, fp);

    freopen(file, "w", fp);
    fwrite(before, 1, bytesBefore, fp);
    fprintf(file, "%d\n", novo->id);
    fprintf(file, "%s\n", novo->tarefa);
    fprintf(file, "%d %d %d\n", novo->dia, novo->mes, novo->ano);
    fwrite(after, 1, bytesAfter, fp);
    fclose(fp);
  }
  else
    printf("\n\tCodigo invalido!\n");
}

void salvar(ToDoIndex **l, int quant, char *arq, char *index)
{
  FILE *file = fopen(arq, "r");
  FILE *idxFile = fopen(index, "w");
  char *after;
  int i, pos, bytesAfter;

  if (file && idxFile)
  {
    if (l[0])
    {
      pos = l[0]->pos;
      fseek(file, 0, SEEK_END);
      bytesAfter = ftell(fp) - pos;
      after = malloc(bytesAfter * sizeof(char));
      fseek(file, pos, SEEK_SET);
      fread(after, 1, bytesAfter, file);
      freopen(arq, "w", file);
    }

    fprintf(file, "%d\n", quant);
    fwrite(after, 1, bytesAfter, file);

    fprintf(idxFile, "%d\n", quant);
    for (i = 0; i < quant; i++)
      fprintf(idxFile, "%d %ld\n", l[i]->id, ftell(file));

    fclose(file);
    fclose(idxFile);
  }
  else
    printf("\n\tERRO AO ABRIR/CRIAR O ARQUIVO!\n");
}

int ler_arquivo(ToDoIndex **l, char *index)
{
  FILE *idxFile = fopen(index, "r");
  int quant = 0, i;
  ToDoIndex *novoIdx;
  if (idxFile)
  {
    fscanf(idxFile, "%d\n", &quant);
    for (i = 0; i < quant; i++)
    {
      novoIdx = malloc(sizeof(ToDoIndex));
      fscanf(idxFile, "%d %ld\n", &novoIdx->id, &novoIdx->pos);
      l[i] = novo;
    }
    fclose(idxFile);
  }
  else
  {
    printf("\n\tERROR AO ABRIR/CRIAR O ARQUIVO!\n");
    return quant;
  }
}

int main()
{
  ToDoIndex *index[100];
  int opcao, tam = 100, quant = 0;
  do
  {
    printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n\t4 - Salvar\n\t5 - Ler arquivo\n");
    scanf("%d", &opcao);
    getchar();
    switch (opcao)
    {
    case 1:
      quant += cadastrar_todo(index, quant, tam, INDEX_FILENAME);
      break;
    case 2:
      alterar_todo(index, quant, INDEX_FILENAME);
      break;
    case 3:
      imprimir(index, quant, INDEX_FILENAME);
      break;
    case 4:
      salvar(index, quant, DATA_FILENAME, INDEX_FILENAME);
      break;
    case 5:
      quant = ler_arquivo(index, INDEX_FILENAME);
      keyId += quant;
      break;
    default:
      if (opcao != 0)
        printf("\n\tOpcao invalida!!!\n");
      break;
    }
  } while (opcao != 0);
  return 0;
}