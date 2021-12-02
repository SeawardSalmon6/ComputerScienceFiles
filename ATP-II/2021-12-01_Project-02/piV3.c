#include <stdio.h>
#include <math.h>
long double pi(long double);
long double parcela(long double);

int main()
{
	long double P;
	printf("Precisão: ");
	scanf("%Lf", &P);

	long double pipi = 6 * (pi(P + 8));

	printf("pipi: %.*Lf\n", (int) P, pipi);
}

long double pi(long double a)
{
	if(a == 1)
		return (0.5);
	else
		return pi(a - 1) + parcela(a);
}

long double parcela(long double n)
{
	if(n == 2)
		return pow(0.5, 4) * (1.0 / 3.0);
	else
		return (((2 * n - 3) * parcela(n - 1) * pow(0.5, 2)) * ((2 * n - 3) / (2 * n - 2))) / (2 * n - 1);
}
