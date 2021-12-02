from decimal import ROUND_HALF_DOWN, Decimal, getcontext
import math

getcontext().prec = 30;

def NumeroPCasa(parcial, P, aux) :
	if(aux > P) :
		while(P) :
			P -= 1;
			parcial = (parcial * 10) - (math.floor(parcial) * 10);
		return parcial;
	else : return -1;

def CalcularPI(P) :
	counter = 0;
	numAux = 1; exp = 3;
	casaAnterior = 0; casaAtual = 0;
	priTermo = Decimal(1); piParcial = Decimal(0.5);

	while(counter < 3) :
		priTermo *= Decimal(numAux) / Decimal(numAux + 1);
		piParcial += (
			Decimal(priTermo)
		  * (Decimal(1) / Decimal(exp))
		  * (Decimal(0.5) ** Decimal(exp))
		);

		casaAtual = int(NumeroPCasa(piParcial * 6, P, numAux));
		counter = counter + 1 if (casaAtual == casaAnterior) else 0;

		if(casaAtual >= 0) :
			casaAnterior = casaAtual;

		numAux += 2; exp += 2;

	return (Decimal(piParcial) * Decimal(6));

# Setting Precision Needs
P = int(input("\nInsira a quantidade de casas decimais para apresentarmos a solução: "));
PI = Decimal(CalcularPI(P));

print("\n-- O valor de PI é: %.*f\n" % (P, PI));
