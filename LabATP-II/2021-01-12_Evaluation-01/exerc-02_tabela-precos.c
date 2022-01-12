/* Uma loja vende 5 diferentes produtos. Os códigos e preços dos produtos
são informados na tabela abaixo. A loja funciona 6 dias por semana. Escreva
um programa C que recebe pares de valores (código do produto ; quantidade
vendida em um dia) relativos a uma semana qualquer. O programa calcula e exibe
o valor total obtido na semana com a venda dos produtos. */

#include <stdio.h>

// Valor constante da quantidade de produtos e dias trabalhados
const int nProd = 5, diasTrabalhados = 6;
float TabelaPrecos[2][nProd] = { // Tabela de precos fixa
	{ 1, 2, 3, 4, 5 },
	{ 10, 22, 15, 8, 31 },
};

int main() {
	// Inicializacao do vetor que armazena as vendas
	int ProdutosVendidos[2][diasTrabalhados] = { 0 };
	float somaSemana = 0;
	int i, j;

	// Leitura das vendas
	printf("\n======== Leitura das Vendas da Semana N\n");
	for(j = 0; j < diasTrabalhados; j++) {
		do {
			printf("\n -> Insira o codigo do produto vendido no dia %0d:  ", j + 1);
			scanf(" %d", &ProdutosVendidos[0][j]);

			if(ProdutosVendidos[0][j] > nProd - 1)
				printf("\n--> Aviso: produto nao existe.\n");
		} while(ProdutosVendidos[0][j] > nProd - 1);

		printf(" -> Insira quantos produtos foram vendidos no dia %0d:  ", j + 1);
		scanf(" %d", &ProdutosVendidos[1][j]);
	}

	// Valores obtidos na semana N
	printf("\n\n=========== Totais da Semana N\n");
	for(i = 0; i < diasTrabalhados; i++)
		for(j = 0; j < nProd; j++)
			if(ProdutosVendidos[0][i] == TabelaPrecos[0][j])
				somaSemana += ProdutosVendidos[1][i] * TabelaPrecos[1][j];

	printf("\n----> Total: R$%.2f\n\n", somaSemana);

	return 0;
}
