#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int totalProdutos = 0, qtdProdutos[5] = { 0 };
float precoProdutos[5] = { 0 };

void aumentarPreco(int produto) {
	float novoPreco = 0;
	
	do {
		printf("\n\n========== PRODUTO %d ==========", produto);
		printf("\nPreço Atual: R$%.2lf\n", precoProdutos[produto - 1]);
		printf("\nInsira o novo preço: R$");
		scanf(" %f", &novoPreco);

		if(novoPreco < precoProdutos[produto - 1])
			printf("\nAVISO: insira algum valor maior ou igual ao atual!");
		else
			precoProdutos[produto - 1] = novoPreco;

	} while(novoPreco < precoProdutos[produto - 1]);
}

void diminuirPreco(int produto) {
	float novoPreco = 0;
	
	do {
		printf("\n\n========== PRODUTO %d ==========", produto);
		printf("\nPreço Atual: R$%.2lf\n", precoProdutos[produto - 1]);
		printf("\nInsira o novo preço: R$");
		scanf(" %f", &novoPreco);

		if(novoPreco > precoProdutos[produto - 1])
			printf("\nAVISO: insira algum valor menor ou igual ao atual!");
		else
			precoProdutos[produto - 1] = novoPreco;

	} while(novoPreco > precoProdutos[produto - 1]);
}

void aumentarEstoque(int produto) {
	int units = 0;
	
	do {
		printf("\n\n========== PRODUTO %d ==========", produto);
		printf("\nEstoque Atual: %d unidades\n", qtdProdutos[produto - 1]);
		printf("\nDeseja adicionar quantas unidades?\n");
		scanf(" %d", &units);

		if(units <= 0)
			printf("\nAVISO: insira algum valor maior do que zero!");
		else {
			qtdProdutos[produto - 1] += units;
			totalProdutos += units;
		}

	} while(units <= 0);
}

void diminuirEstoque(int produto) {
	int units = 0;
	
	do {
		printf("\n\n========== PRODUTO %d ==========", produto);
		printf("\nEstoque Atual: %d unidades\n", qtdProdutos[produto - 1]);
		printf("\nDeseja diminuir quantas unidades?\n");
		scanf(" %d", &units);

		if(units <= 0)
			printf("\nAVISO: insira algum valor maior do que zero!");
		else {
			qtdProdutos[produto - 1] -= units;
			totalProdutos -= units;
		}

	} while(units <= 0);
}

int menuProduto(void) {
	int produto;

	printf("\n======== PRODUTOS ========");
	printf("\n1- Produto 1");
	printf("\n2- Produto 2");
	printf("\n3- Produto 3");
	printf("\n4- Produto 4");
	printf("\n5- Produto 5");

	printf("\n\nEscolha um produto: ");
	scanf(" %d", &produto);

	return produto;
}

int menuPrincipal(void) {
	int opcao;

	printf("\n======== MENU ========");
	printf("\n1- Aumentar estoque");
	printf("\n2- Baixar estoque");
	printf("\n3- Visualizar estoque de um produto");
	printf("\n4- Visualizar estoque total");
	printf("\n5- Aumentar Preço");
	printf("\n6- Diminuir Preço");
	printf("\n7- Trocar produto");
	printf("\n8- Encerrar");

	printf("\n\nEscolha uma opção: ");
	scanf(" %d", &opcao);

	return opcao;
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int opcao, produto, units = 0;
	char resp;

	printf("\n========= CONFIGURAÇÃO ==========\n");
	
	for(int i  = 0; i < 5; i++) {
		printf("\n -> Produto %d - Insira a quantidade em estoque: ", i + 1);
		scanf(" %d", &qtdProdutos[i]);

		totalProdutos += qtdProdutos[i];

		printf("\t      - Insira o preço unitário: R$");
		scanf(" %f", &precoProdutos[i]);
	}

	do {
		system("clear");

		opcao = menuPrincipal();

		switch(opcao) {	
			case 1:
				produto = menuProduto();
				aumentarEstoque(produto);
				break;

			case 2:
				produto = menuProduto();
				
				if(totalProdutos > 0)
					diminuirEstoque(produto);
				else
					printf("\nAVISO: não temos nenhum produto em estoque!");
				
				break;

			case 3:
				produto = menuProduto();
				printf("\n\n========== PRODUTO %d ==========", produto);
				printf("\n -> Estoque Atual:    %d unidade(s)", qtdProdutos[produto - 1]);
				printf("\n -> Valor em Estoque: R$%.2lf", qtdProdutos[produto - 1] * precoProdutos[produto - 1]);
				break;

			case 4:
				printf("\n\n========== ESTOQUE ==========");
				printf("\n -> Produto 1 - Estoque Atual: %d unidade(s)", qtdProdutos[0]);
				printf("\n -> Produto 2 - Estoque Atual: %d unidade(s)", qtdProdutos[1]);
				printf("\n -> Produto 3 - Estoque Atual: %d unidade(s)", qtdProdutos[2]);
				printf("\n -> Produto 4 - Estoque Atual: %d unidade(s)", qtdProdutos[3]);
				printf("\n -> Produto 5 - Estoque Atual: %d unidade(s)", qtdProdutos[4]);
				printf("\n\n===> Estoque Total: %d unidade(s)", totalProdutos);
				break;

			case 5:
				produto = menuProduto();
				aumentarPreco(produto);
				break;

			case 6:
				produto = menuProduto();
				
				if(precoProdutos[produto - 1] > 0)
					diminuirPreco(produto);
				else
					printf("\nAVISO: este produto ainda não tem preço definido! Defina-o primeiro!");
				
				break;

			case 7:
				produto = menuProduto();

				if(qtdProdutos[produto - 1] > 0) {
					do {
						printf("\nO produto está com defeito (S/N)?\n");
						scanf(" %c", &resp);

					} while(toupper(resp) != 'S' && toupper(resp) != 'N');

					if(toupper(resp) == 'S')
						qtdProdutos[produto - 1]--;

					printf("\n\n--> O produto foi trocado com sucesso!");

				} else {
					printf("\n\nAVISO: não temos mais unidades disponíveis deste produto!\n");
				}
				
				break;

			case 8:
				printf("\n\nFim da execução\n\n");
				break;

			default:
				printf("\nAVISO: Escolha uma opção válida!");
				break;
		}

		// equivalente a system("pause")
		if(opcao != 8) {
			puts("\n\nPressione uma tecla para continuar...");
			getchar(); scanf("c\n");
		}

	} while(opcao != 8);

	return 0;
}