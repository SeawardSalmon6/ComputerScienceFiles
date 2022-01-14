/* Escreva, em C, um programa de controle de notas e frequencias de alunos. O
usuário do sistema e um professor, que pode ser responsavel por varias
disciplinas. O sistema permite cadastrar e consultar informacoes a respeito das
disciplinas pelas quais o professor e responsavel, bem como a respeito dos
alunos matriculados nessas disciplinas. As informacoes sao gravadas em arquivos
e podem ser consultadas a qualquer tempo. */

/* Hahaha ja aviso que me empolguei mesmo */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Menu(int*);
void CopyToFile(FILE*, FILE*);
void CadastrarDisciplina(FILE*);
void CadastrarAluno(FILE*);
void ApresentarDados(FILE*);

int main() {
	FILE *Caderneta;
	int opt = 0;

	if(fopen("controleAlunos.txt", "r") == NULL) {
		Caderneta = fopen("controleAlunos.txt", "w");

		if(Caderneta == NULL) {
			printf("\n---> Houve um erro ao abrir o arquivo! Saindo...\n\n");
			exit(1);
		}

		fclose(Caderneta);
	}

	Caderneta = fopen("controleAlunos.txt", "r+");
	if(Caderneta == NULL) {
		printf("\n---> Houve um erro ao abrir o arquivo! Saindo...\n\n");
		exit(1);
	}

	while(opt != 4) {
		system("clear");

		Menu(&opt);
		switch(opt) {
			case 1:
				system("clear");
				CadastrarDisciplina(Caderneta);
			break;

			case 2:
				system("clear");
				CadastrarAluno(Caderneta);
			break;

			case 3:
				system("clear");
				ApresentarDados(Caderneta);
			break;

			case 4:
				printf("\n\nObrigado por utilizar nosso programa!\n\n");
				remove("tmp");
				fclose(Caderneta);
			break;
		}
	}

	return 0;
}

void Menu(int *opt) {
	printf("\n======== Menu Principal =======\n");
	printf("\n(1) Cadastrar Disciplinas\n");
	printf("\n(2) Cadastrar Alunos\n");
	printf("\n(3) Apresentar Dados\n");
	printf("\n(4) Sair e Salvar\n");

	printf("\n\n-> Escolha uma opcao: ");
	scanf(" %d", opt);
}

void CadastrarDisciplina(FILE *fp) {
	char disciplina[20];

	printf("\n=========== Cadastrar Disciplina\n");
	printf("\n-> Insira o nome da disciplina:  ");
	scanf(" %s", disciplina);

	fseek(fp, 0, SEEK_END);
	fprintf(fp, "\n\n$%s", disciplina);

	// equivalente ao system("pause");
	puts("\n\nPressione uma tecla para continuar...");
	getchar(); scanf("c");
}

void CadastrarAluno(FILE *fp) {
    char disciplina[20], aux[20];
	int codigo, pos;
	float nota, freq;
	FILE *tmp;

	/* Cadastrar Alunos */
	printf("\n================ Cadastrar Alunos\n");
    printf("\n-> Insira o nome da disciplina:  ");
    scanf(" %s", aux);

    fseek(fp, 1, SEEK_SET);

    while(fgets(disciplina, 20, fp) != NULL)
		if(strstr(disciplina, aux) != NULL) {
			// Posiciona o ponteiro no arquivo
			while(!feof(fp) && fscanf(fp, "%d %f %f", &codigo, &nota, &freq));
			pos = ftell(fp);

			// Ler os dados do usuário
			printf("\n-> Insira o codigo do aluno:  ");
			scanf(" %d", &codigo);

			printf("\n-> Insira a nota do aluno:  ");
			scanf(" %f", &nota);

			printf("\n-> Insira a frequencia do aluno em decimal (ex.: 0.92):  ");
			scanf(" %f", &freq);

			// Insere os dados no arquivo
			if(feof(fp)) {
				fseek(fp, pos, SEEK_SET);
				fprintf(fp, "\n%d %f %f", codigo, nota, freq);
				break;
			}

			// Copying FILE
			tmp = fopen("tmp", "w+");
			if(tmp == NULL) {
				printf("\n---> Houve um erro ao abrir o arquivo! Saindo...\n\n");
				fclose(fp);
				exit(1);
			}

			// Make copy from fp to tmp
			CopyToFile(fp, tmp);

			// inserting new value into the original file
			fseek(fp, pos - 3, SEEK_SET);
			fprintf(fp, "\n%d %f %f\n\n", codigo, nota, freq);

			// copying content
			fseek(tmp, 0, SEEK_SET);
			CopyToFile(tmp, fp); // redo the copy inverse

			fclose(tmp);

			break;
		}

	// equivalente ao system("pause");
	puts("\n\nPressione uma tecla para continuar...");
	getchar(); scanf("c");
}

void ApresentarDados(FILE *fp) {
	char disciplina[20], c;
	int codigo;
	float nota, freq;

	fseek(fp, 2, SEEK_SET);

	printf("\n=========== Lista de Alunos e Disciplinas\n");
	while(!feof(fp)) {
		if(fscanf(fp, "$%s", disciplina) != 0)
			printf("\n\n========= %s", disciplina);

		c = ((char) fgetc(fp));
		if(c != '\n' && c != '\r' && c != EOF) {
			fseek(fp, -1, SEEK_CUR);

			// Escreve os dados dos alunos
			fscanf(fp, "%d %f %f", &codigo, &nota, &freq);
			printf("\n\n------ Aluno %0d", codigo);
			printf("\n---> Nota: %.2f", nota);
			printf("\n---> Frequência: %.2f%%\n", (freq * 100));
		}
	}

	// equivalente ao system("pause");
	puts("\n\nPressione uma tecla para continuar...");
	getchar(); scanf("c");
}

void CopyToFile(FILE *src, FILE *dest) {
	char c;
	c = fgetc(src);
	while(c != EOF){
		fputc(c, dest);
		c = fgetc(src);
	}
}
