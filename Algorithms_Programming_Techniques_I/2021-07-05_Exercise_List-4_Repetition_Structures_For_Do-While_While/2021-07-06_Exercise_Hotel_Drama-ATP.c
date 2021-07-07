#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define TAXA_MIN 12
#define TAXA_FIX 14
#define TAXA_MAX 20

int qtdHospedes = 0;
int opcao = 0;
float totalHotel = 0;

struct info {
	char nome[40];
	char endereco[40];
	char telefone[40];
	char cidade[40];
	char estado[3];
	int qtdDiarias;
	float toPay;
} listaHospedes[200];

void adicionarHospede(void) {
	char resp;

	if(qtdHospedes < 200) {
		do {
			printf("\n======== ADICIONAR HÓSPEDES ========\n");

			printf("\n====> Hospéde nº%d\n", qtdHospedes + 1);

			printf("\n  Qual o seu nome? \t\t\t ");
			scanf(" %[^\n]s", listaHospedes[qtdHospedes].nome);

			printf("\n  Qual o seu endereço? \t\t ");
			scanf(" %[^\n]s", listaHospedes[qtdHospedes].endereco);

			printf("\n  Qual o seu telefone? \t\t ");
			scanf(" %[^\n]s", listaHospedes[qtdHospedes].telefone);

			printf("\n  Qual a sua cidade? \t\t ");
			scanf(" %[^\n]s", listaHospedes[qtdHospedes].cidade);

			printf("\n  Qual o seu estado (UF)? \t ");
			scanf(" %[^\n]s", listaHospedes[qtdHospedes].estado);

			printf("\n  Quantos dias vai ficar? \t ");
			scanf(" %d", &listaHospedes[qtdHospedes].qtdDiarias);

			int dias = listaHospedes[qtdHospedes].qtdDiarias;

			if(dias < 15)
				listaHospedes[qtdHospedes].toPay = (dias * 300) + TAXA_MAX;

			else if(dias == 15)
				listaHospedes[qtdHospedes].toPay = (dias * 300) + TAXA_FIX;

			else if(dias > 15)
				listaHospedes[qtdHospedes].toPay = (dias * 300) + TAXA_MIN;
				
			printf("\n\t-> TOTAL A PAGAR: R$%.2lf\n", listaHospedes[qtdHospedes].toPay);

			totalHotel += listaHospedes[qtdHospedes].toPay;
			qtdHospedes++;

			printf("\nDeseja adicionar mais um hóspede (S/N)?\n");
			scanf(" %c", &resp);

		} while(toupper(resp) == 'S');

	} else {
		printf("\nALERTA: a quantidade máxima de hóspedes já lotou!\n\n");
	}
}

void buscarHospede(void) {
	char nomeBusca[40];
	int encontrados = 0;

	printf("\n========== BUSCAR HÓSPEDE ==========\n");
	printf("\nInsira o nome a ser procurado: ");
	scanf(" %[^\n]s", nomeBusca);

	for(int i = 0; i < qtdHospedes; i++) {
		if(strcmp(nomeBusca, listaHospedes[i].nome) == 0)
		{
			printf("\n====> Dados do Hóspede %d:\n", i + 1);
		
			printf("\t- Nome: \t\t\t\t%s\n", listaHospedes[i].nome);
			printf("\t- Endereço: \t\t\t%s\n", listaHospedes[i].endereco);
			printf("\t- Telefone: \t\t\t%s\n", listaHospedes[i].telefone);
			printf("\t- Cidade: \t\t\t\t%s\n", listaHospedes[i].cidade);
			printf("\t- Estado (UF): \t\t\t%s\n", listaHospedes[i].estado);
			printf("\t- Tempo de Estadia: \t%d dias(s)\n", listaHospedes[i].qtdDiarias);
			printf("\n\t  -> TOTAL A PAGAR: \tR$%.2lf\n", listaHospedes[i].toPay);

			printf("\n-------------------------");

			encontrados++;
		}
		
		else if(encontrados == 0 && i == qtdHospedes - 1)
			printf("\nNão encontramos nenhum convidado com este nome.\n");
	}
}

void mostraHospedes(void) {
	printf("\n========= LISTA DE HÓSPEDES =========\n");
	
	for(int i = 0; i < qtdHospedes; i++) {
		printf("\n====> Dados do Hóspede %d:\n", i + 1);
		
		printf("\t- Nome: \t\t\t\t%s\n", listaHospedes[i].nome);
		printf("\t- Endereço: \t\t\t%s\n", listaHospedes[i].endereco);
		printf("\t- Telefone: \t\t\t%s\n", listaHospedes[i].telefone);
		printf("\t- Cidade: \t\t\t\t%s\n", listaHospedes[i].cidade);
		printf("\t- Estado (UF): \t\t\t%s\n", listaHospedes[i].estado);
		printf("\t- Tempo de Estadia: \t%d dias(s)\n", listaHospedes[i].qtdDiarias);
		printf("\n\t  -> TOTAL A PAGAR: \tR$%.2lf\n", listaHospedes[i].toPay);

		printf("\n-------------------------------------------------");
	}

	printf("\nQuantidade de Hóspedes:   %d hóspede(s)", qtdHospedes);
	printf("\nTotal Ganho pelo Hotel:   R$%.2lf\n", totalHotel);
}

int menu(void) {

	printf("\n======== HOTEL NEVES =======\n");
	printf("1 - Adicionar Hóspede(s)\n");
	printf("2 - Buscar Hóspede(s)\n");
	printf("3 - Listar Todos os Hóspedes\n");
	printf("4 - Encerrar Programa\n");

	printf("\nQuantidade de Hóspedes: %d hóspede(s)", qtdHospedes);
	printf("\nTotal Ganho pelo Hotel: R$%.2lf\n", totalHotel);

	printf("\nEscolha uma opção: ");
	scanf(" %d", &opcao);

	return opcao;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	system("clear");
	opcao = menu();

	switch(opcao) {
		case 1:
			system("clear");
			adicionarHospede();
			break;
		case 2:
			system("clear");
			buscarHospede();
			break;
		case 3:
			system("clear");
			mostraHospedes();
			break;
		case 4:
			system("clear");
			printf("\nObrigado por utilizar nosso aplicativo!\n\n");
			return 0;
			break;
		default:
			system("clear");
			printf("\nInsira uma opção válida!\n");
			break;
	}

	puts("\nPressione uma tecla para continuar...");
	getchar(); scanf("c\n");

	return main();
}