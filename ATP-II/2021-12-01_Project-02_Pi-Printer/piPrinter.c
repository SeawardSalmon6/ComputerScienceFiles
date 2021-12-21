#include <stdio.h>

// protótipos das funções utilizadas/criadas
double CalcularPI(int);
double PrimeiroTermo(int);
double SegundoTermo(int);
double TerceiroTermo(double);
int NumeroPCasa(double, int);

void LerCasasDecimais(int *P) {
	do { // loop para forçar valores entre 1 <= P <= 20
		printf("\nInsira a quantidade de casas decimais: ");
		scanf(" %d", P);
	} while(*P < 1 || *P > 15);
}

int main() {
    int P; // quantidade de casas a serem exibidas
	double pi = 0; // variável de alocação do valor de PI

	LerCasasDecimais(&P);
	pi = CalcularPI(P);

	printf("\n-- O valor de pi é: %.*lf\n\n", P, pi);

	return 0;
}

// retorna o número posicionado na posição P em Pi-Parcial
int NumeroPCasa(double val, int P) {
	while(P--)
        val = (val * 10) - ((int) val) * 10;
    return val;
}

// Funções-Termos das Parcelas
double PrimeiroTermo(int num) {
	return (num / (num + 1.0));
}
double SegundoTermo(int exp) {
	return (1.0 / exp);
}
double TerceiroTermo(double val) {
	return (val * 0.25); // como P no Terceiro Termo aumenta em 2 == n^(p+2) == (0.5)^2 == 0.25
}

// calcula o valor de PI, utilizando a fórmula de Newton
double CalcularPI(int P) {
	int cont = 0; // variável para contar as três repetições da parcela, na posição P
	int numAux = 1, expoente = 3; // variáveis da fórmula de Newton, para o cálculo de PI
	int casaAnterior = 0, casaAtual = -1; // variáveis de controle para os testes das parcelas repetidas

	// variáveis de alocação dos valores parcial do Pri. e Ter. Termos para poupar processamento
	double priTermo = 1;
	double terTermo = 0.5;
	double piParcial = 3;

	// até que o valor de pi deixe de variar na P-ésima casa, por três parcelas, continue a calcular
	while(cont < 3) {
		priTermo *= PrimeiroTermo(numAux); // calcula o valor do primeiro termo na parcela N
		terTermo = TerceiroTermo(terTermo); // calcula o valor do terceiro termo na parcela N em relação ao valor anterior
		piParcial += 6 * priTermo * SegundoTermo(expoente) * terTermo; // calcula o valor de PI

		// captura o valor da casa P
		casaAtual = NumeroPCasa(piParcial, P);

		// testa o valor da casa e soma 1 ou reseta o contador
		cont = (casaAtual == casaAnterior) ? ++cont : 0;
		casaAnterior = casaAtual; // atualiza o valor da casaAnterior

		numAux += 2; expoente += 2; // atualiza as variáveis da fórmula, para a próxima parcela
	}

	// retorna o valor de PI, de acordo com a fórmula de Newton
	return (piParcial);
}
