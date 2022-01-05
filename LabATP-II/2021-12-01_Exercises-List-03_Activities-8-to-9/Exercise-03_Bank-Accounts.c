#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_ACCOUNTS 15

typedef struct Pessoa {
	unsigned int accountNumber;
	char name[50];
	float balance;
} tPessoa;

void ShowMenu(int*);
void AddAccounts(tPessoa*, int*);
void ShowAccounts(tPessoa*, int);
void RemoveAccount(tPessoa*, int*);

int main() {
	setlocale(LC_ALL, "Portuguese");

	int option = -1, lastUser = 0;
	tPessoa UsersList[MAX_ACCOUNTS];

	while(option != 4) {
		system("clear");
		ShowMenu(&option);

		switch(option) {
			case 1: system("clear");
				AddAccounts(UsersList, &lastUser);
			break;
			case 2: system("clear");
				ShowAccounts(UsersList, lastUser);
			break;
			case 3: system("clear");
				RemoveAccount(UsersList, &lastUser);
			break;
			case 4:
				printf("\n-> Saindo... Obrigado por utilizar nosso aplicativo!\n\n");
			break;
		}
	}

	return 0;
}

void ShowMenu(int *opt) {
	printf("\n========== MENU PRINCIPAL ==========\n");
	printf("\n(1) Cadastrar Contas");
	printf("\n(2) Visualizar Todas as Contas de um Determinado Cliente");
	printf("\n(3) Excluir a Conta com Menor Saldo");
	printf("\n(4) Sair");

	do {
		printf("\n\n--> Escolha uma opção: ");
		scanf(" %d", opt);
	} while(*opt < 1 || *opt > 4);
}

int Continue(void) {
	char resp = 'n';

	do {
		printf("\n\n-> Deseja continuar (s/n)? ");
		scanf(" %c", &resp);
	} while((resp != 's' && resp != 'n') && (resp != 'S' && resp != 'N'));

	return (resp == 'n' || resp == 'N') ? 0 : 1;
}

void AddAccounts(tPessoa *UsersList, int *last) {
	printf("\n========= CADASTRAR CLIENTES =========\n");

	for(int i = *last; i < MAX_ACCOUNTS; i++) {
		printf("\n\n---------- Cliente %0d", i + 1);
		printf("\n   Número da Conta Bancária: ");
		scanf(" %u", &UsersList[i].accountNumber);

		printf("\n   Nome Completo: ");
		scanf(" %[^\n]", UsersList[i].name);

		printf("\n   Saldo Disponível: ");
		scanf(" %f", &UsersList[i].balance);

		*last = *last + 1;

		if(Continue() == 0) break;
	}

	puts("\n\nPressione uma tecla para continuar...");
	getchar(); scanf("c");
}

void ShowAccounts(tPessoa *UsersList, int last) {
	int i, j = 0;
	char srcName[50] = { 0 };

	printf("\n========= APRESENTAR CONTAS DO CLIENTE =========\n");
	printf("-> Insira o nome do cliente (igual ao do cadastro): ");
	scanf(" %[^\n]", srcName);

	printf("\n\n======= Contas de %s", srcName);

	for(i = 0; i < last; i++)
		if(strcasecmp(srcName, UsersList[i].name) == 0) {
			printf("\n\n----------- Conta %0d", j + 1);
			printf("\n   -> Número da Conta: %u", UsersList[i].accountNumber);
			printf("\n   -> Saldo da Conta: R$%.2f", UsersList[i].balance);

			j++;
		}

	if(j == 0)
		printf("\n\n---> Não encontramos nenhuma conta referente a este cliente.");

	puts("\n\nPressione uma tecla para continuar...");
	getchar(); scanf("c");
}

void RemoveAccount(tPessoa *UsersList, int *last) {
	int i, j = -1;
	float lower = UsersList[0].balance;

	printf("\n========= REMOVER CONTA DE MENOR SALDO =========\n");

	for(i = 0; i < *last; i++)
		if(UsersList[i].balance < lower && UsersList[i].accountNumber != 0) {
			lower = UsersList[i].balance;
			j = i;
		}

	if(j >= 0) {
		printf("\n---> Aviso: a conta nº%0d, de %s será excluída!", UsersList[i].accountNumber, UsersList[i].name);

		printf("\n\n----------- Conta de %s", UsersList[j].name);
		printf("\n   -> Número da Conta: %u", UsersList[j].accountNumber);
		printf("\n   -> Saldo da Conta: R$%.2f", UsersList[j].balance);

		for(i = j + 1; i <= *last; i++) {
			UsersList[i - 1].accountNumber = UsersList[i].accountNumber;
			strcpy(UsersList[i - 1].name, UsersList[i].name);
			UsersList[i - 1].balance= UsersList[i].balance;
		}

		printf("\n\n-----> A conta foi excluída com sucesso!");
	} else
		printf("\n\n--->> Ocorreu um Erro Interno, nenhum conta foi excluída.");

	puts("\n\nPressione uma tecla para continuar...");
	getchar(); scanf("c");
}
