#include <stdio.h>
#include <math.h>
#include <quadmath.h>

// protótipos das funções utilizadas/criadas
int NumeroPCasa(__float128 parcial, int P, int aux);
__float128 PrimeiroTermo(__float128 numAux);
__float128 SegundoTermo(int expoente);
double TerceiroTermo(int expoente);
__float128 CalcularPI(int P);

void LerQuantidadeCasas(int *P) {
	do { // loop para forçar valores entre 1 <= P <= 20
		printf("\nInsira a quantidade de casas decimais: ");
		scanf(" %d", P);
	} while(*P < 1 || *P > 20);
}

int main()  {
    int P; // quantidade de casas a serem exibidas
	__float128 pi = 0; // variável de alocação do valor de PI
	char piString[50] = { 0 };

	// chama a função que calcula o valor de PI, utilizando a fórmula de Newton
	LerQuantidadeCasas(&P);
	pi = CalcularPI(P);

	// transforma o valor de um __float128 em string
	quadmath_snprintf(piString, sizeof(piString), "%.*Qf", P, pi);

	// printa o resultado após os cálculos
    printf("\n-- O valor de pi é: %s\n\n", piString);

	return 0;
}

// retorna o número posicionado na posição P em Pi-Parcial
int NumeroPCasa(__float128 parcial, int P, int aux) {
	if(aux > P) { // enquanto a qtd. de casas não for pelo menos igual a P, retorne -1
	    while(--P) // decresce o valor de P até que se encontre o número em P
	        parcial = (parcial * 10) - ((int) parcial * 10); // multiplica o parcial por 10 e subtrai a dezena
		return parcial;
	} else return -1;
}

__float128 PrimeiroTermo(__float128 numAux) {
	return (__float128) numAux / (numAux + 1);
}

__float128 SegundoTermo(int expoente) {
	return (__float128) 1 / expoente;
}

double TerceiroTermo(int expoente) {
	return pow(0.5, expoente);
}

// calcula o valor de PI, utilizando a fórmula de Newton + a função auxiliar acima
__float128 CalcularPI(int P) {
	int counter = 0; // variável para contar as três repetições da parcela, na posição P
	int numAux = 1, exp = 3; // variáveis da fórmula de Newton, para o cálculo de PI
	int casaAnterior = 0, casaAtual = 0; // variáveis de controle para os testes das parcelas repetidas
	__float128 priTermo = 1; // primeiro termo das parcelas
	__float128 piParcial = 0.5; // variável de armazenamento do valor parcial de PI

	// quando o valor de pi, deixar de variar na P-ésima casa, por três parcelas, continue a calcular
	while(counter < 3) {
		priTermo *= PrimeiroTermo(numAux); // calcula o valor do primeiro termo na parcela N
		piParcial += priTermo * SegundoTermo(exp) * TerceiroTermo(exp); // calcula o valor de PI / 6

		// captura o valor da casa P
		casaAtual = NumeroPCasa(piParcial * 6, P, numAux);
		counter = (casaAtual == casaAnterior) ? ++counter : 0; // testa o valor da casa e soma 1 ou reseta o contador

		// se o retorno de NumeroPCasa for nulo, a casaAnterior não se altera
		if(casaAtual >= 0)
			casaAnterior = casaAtual;

		numAux += 2; exp += 2; // atualiza as variáveis da fórmula, para a próxima parcela
	}

	return piParcial * 6; // retorna o valor de PI, de acordo com a fórmula de Newton
}
