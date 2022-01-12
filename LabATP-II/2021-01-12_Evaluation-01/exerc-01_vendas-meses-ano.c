/* Escreva um programa, em C, que preencha uma matriz 12 x 4 com os valores
das vendas de uma loja, em que cada linha representa um mes do ano e cada
coluna representa uma semana do mes. O programa  calcular e mostrar:
a) o total vendido em cada mes do ano, mostrando o nome do mes por extenso;
b) o total vendido em cada semana durante todo o ano;
c) o total vendido pela loja no ano. */

#include <stdio.h>

// Tamanhos constantes da matriz
const int N = 12, M = 4;

// Vetor com os meses do ano
char MesesDoAno[N][N] = { "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };

int main() {
	// Inicializacao com valores zerados da matriz
	int i, j, k = 0;
	float somaMes = 0, somaAno = 0, Vendas[N][M] = { 0 };

	// Leitura dos dados de vendas
	printf("\n======== Leitura das Vendas");
	for(i = 0; i < N; i++)
	for(j = 0; j < M; j++) {
		printf("\n-> Insira o valor das vendas do mes de %s, semana %0d:  ", MesesDoAno[i], j + 1);
		scanf(" %f", &Vendas[i][j]);
	}

	// a) Totais de cada um dos meses
	printf("\n\n======== Totais das Vendas de Cada Mes");
	for(i = 0; i < N; i++) {
		printf("\n----- Mes de %s", MesesDoAno[i]);

		somaMes = 0;
		for(j = 0; j < M; j++)
			somaMes += Vendas[i][j];

		printf("\n-> Total: R$%.2f\n", somaMes);
	}

	// b) Totais por semana
	printf("\n\n======== Totais das Vendas Por Semana");
	for(i = 0; i < N; i++)
	for(j = 0; j < M; j++) {
		printf("\n----- Semana %0d", ++k);
		printf("\n-> Total: R$%.2f\n", Vendas[i][j]);
		somaAno += Vendas[i][j]; // soma do total anual
	}

	printf("\n\n======== Totais das Vendas do Ano Todo");
	printf("\n-> Total: R$%.2f\n\n", somaAno);

	return 0;
}
