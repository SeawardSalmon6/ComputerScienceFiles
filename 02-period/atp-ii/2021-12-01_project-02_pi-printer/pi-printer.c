#include <stdio.h>

// prototipos das funcoes utilizadas/criadas
double CalcularPI(int);
double PrimeiroTermo(int);
double SegundoTermo(int);
double TerceiroTermo(double);
int NumeroPCasa(double, int);

void LerCasasDecimais(int *P) {
	do { // loop para forcar valores entre 1 <= P <= 20
		printf("\nInsira a quantidade de casas decimais: ");
		scanf(" %d", P);
	} while(*P < 1 || *P > 15);
}

int main() {
    int P; // quantidade de casas a serem exibidas
	double pi = 0; // variavel de alocacao do valor de PI

	LerCasasDecimais(&P);
	pi = CalcularPI(P);

	printf("\n-- PI: %.*lf\n\n", P, pi);

	return 0;
}

// retorna o numero posicionado na posicao P em Pi-Parcial
int NumeroPCasa(double val, int P) {
	while(P--)
        val = (val * 10) - ((int) val) * 10;
    return val;
}

// Funcoes-Termos das Parcelas
double PrimeiroTermo(int num) {
	return (num / (num + 1.0));
}
double SegundoTermo(int exp) {
	return (1.0 / exp);
}
double TerceiroTermo(double val) {
	return (val * 0.25); // como P no Terceiro Termo aumenta em 2 == n^(p+2) == (0.5)^2 == 0.25
}

// calcula o valor de PI, utilizando a formula de Newton
double CalcularPI(int P) {
	int cont = 0; // variavel para contar as tres repeticoes da parcela, na posicao P
	int numAux = 1, expoente = 3; // variavel da formula de Newton, para o calculo de PI
	int casaAnterior = 0, casaAtual = -1; // variavel de controle para os testes das parcelas repetidas

	// variavel de alocacao dos valores parcial do Pri. e Ter. Termos para poupar processamento
	double priTermo = 1;
	double terTermo = 0.5;
	double piParcial = 3;

	// ate que o valor de pi deixe de variar na P-esima casa, por tres parcelas, continue a calcular
	while(cont < 3) {
		priTermo *= PrimeiroTermo(numAux); // calcula o valor do primeiro termo na parcela N
		terTermo = TerceiroTermo(terTermo); // calcula o valor do terceiro termo na parcela N em relacao ao valor anterior
		piParcial += 6 * priTermo * SegundoTermo(expoente) * terTermo; // calcula o valor de PI

		// captura o valor da casa P
		casaAtual = NumeroPCasa(piParcial, P); // 3.14159 -> 4

		// testa o valor da casa e soma 1 ou reseta o contador
		cont = (casaAtual == casaAnterior) ? ++cont : 0;
		casaAnterior = casaAtual; // atualiza o valor da casaAnterior

		numAux += 2; expoente += 2; // atualiza as variavel da formula, para a próxima parcela
	}

	// retorna o valor de PI, de acordo com a formula de Newton
	return (piParcial);
}
