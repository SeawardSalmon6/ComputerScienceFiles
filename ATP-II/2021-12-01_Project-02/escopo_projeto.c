#include <stdio.h>
#include <math.h>

// protótipos das funções utilizadas/criadas
int NumeroPCasa(long double parcial, int P, int aux);
long double CalcularPI(int P);

int main()  {
    int P; // quantidade de casas a serem exibidas
	long double pi = 0; // variável de alocação do valor de PI

	do { // loop para forçar valores entre 1 <= P <= 20
		printf("\nInsira a quantidade de casas decimais: ");
		scanf(" %d", &P);
	} while(P < 1 || P > 20);

	// chama a função que calcula o valor de PI, utilizando a fórmula de Newton
	pi = floor(CalcularPI(P) * pow(10, P)) / pow(10, P);
    printf("\n-- O valor de pi é: %.*Lf\n\n", P, pi); // printa o resultado após os cálculos

	return 0;
}

// retorna o número posicionado na posição P em Pi-Parcial
int NumeroPCasa(long double parcial, int P, int aux) {
	if(aux > P) { // enquanto a qtd. de casas não for pelo menos igual a P, retorne -1
	    while(--P) // decresce o valor de P até que se encontre o número em P
	        parcial = (parcial * 10) - (floor(parcial) * 10); // multiplica o parcial por 10 e subtrai a dezena
		return parcial;
	} else return -1;
}

// calcula o valor de PI, utilizando a fórmula de Newton + a função auxiliar acima
long double CalcularPI(int P) {
	int counter = 0; // variável para contar as três repetições da parcela, na posição P
	int numAux = 1, exp = 3; // variáveis da fórmula de Newton, para o cálculo de PI
	int casaAnterior = 0, casaAtual = 0; // variáveis de controle para os testes das parcelas repetidas
	long double priTermo = 1; // primeiro termo das parcelas
	long double piParcial = 0.5; // variável de armazenamento do valor parcial de PI

	// quando o valor de pi, deixar de variar na P-ésima casa, por três parcelas, continue a calcular
	while(counter < 3) {
		priTermo *= (long double) numAux / (numAux + 1); // calcula o valor do primeiro termo na parcela N
		piParcial += priTermo * ((long double) 1 / exp) * pow(0.5, exp); // calcula o valor de PI / 6

		casaAtual = NumeroPCasa(piParcial * 6, P, numAux); // captura o valor da casa P
		counter = (casaAtual == casaAnterior) ? ++counter : 0; // testa o valor da casa e soma 1 ou reseta o contador

		if(casaAtual >= 0) // se o retorno de NumeroPCasa for nulo, a casaAnterior não se altera
			casaAnterior = casaAtual;

		numAux += 2; exp += 2; // atualiza as variáveis da fórmula, para a próxima parcela
	}

	return piParcial * 6; // retorna o valor de PI, de acordo com a fórmula de Newton
}
