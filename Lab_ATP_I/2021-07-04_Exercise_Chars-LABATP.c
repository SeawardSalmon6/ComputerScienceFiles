#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	char rdChar;

	printf("\n Insira um único caracter e faremos uma conversão: ");
	scanf("%c", &rdChar);

	printf("\n ========= RESULTADO DA CONVERSÃO =========\n");
	printf("\n Caracter Inserido: %c", rdChar);

	if(rdChar >= 65 && rdChar <= 90) // se o caracter for Maiúsculo
	{
		rdChar += 32;
		printf("\n Caracter de Saída: %c\n\n", rdChar);
	}

	else if (rdChar >= 97 && rdChar <= 122) // se o caracter for Maiúsculo
	{
		rdChar -= 32;
		printf("\n Caracter de Saída: %c\n\n", rdChar);

	} else {
		printf("\n Aviso: O caracter não é uma letra. Não podemos fazer a conversão.\n\n");
	}

	return 0;
}