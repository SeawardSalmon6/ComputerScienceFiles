#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

	double startInt, endInt, margErr, halfInt;

	printf("\nSolução da Equação: sen(x) - cos(x) = 0\n");
	printf("\n-> Digite o início do intervalo que contém a raiz: ");
	scanf("%lf", &startInt);

	printf("\n-> Digite o fim do intervalo que contém a raiz: ");
	scanf("%lf", &endInt);

	printf("\n-> Digite o erro máximo aceitável: ");
	scanf("%lf", &margErr);

	if(((sin(startInt) - cos(startInt)) * (sin(endInt) - cos(endInt))) < 0)
	{
		while((endInt - startInt) > margErr)
		{
			halfInt = (startInt + endInt) / 2.0;

			if(((sin(startInt) - cos(startInt)) * (sin(endInt) - cos(endInt))) < 0)
				endInt = halfInt;

			else if(((sin(startInt) - cos(startInt)) * (sin(endInt) - cos(endInt))) == 0) {
                startInt = margErr;
                endInt = margErr;
            }

            else
				startInt = halfInt;
		}

		printf("\n\nA solução é: %.10f\n\n", halfInt);
	}
    
    else if(((sin(startInt) - cos(startInt)) * (sin(endInt) - cos(endInt))) == 0)
        printf("\n\nAlgum dos valores do intervalo é a solução da equação.\n\n");

	else
		printf("\n\nO intervalo digitado não contém solução.\n\n");
    
	return 0;
}