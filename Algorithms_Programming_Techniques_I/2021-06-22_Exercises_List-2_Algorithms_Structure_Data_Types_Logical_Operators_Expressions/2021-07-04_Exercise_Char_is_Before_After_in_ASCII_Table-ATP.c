#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	unsigned char fstChar, scndChar;

	printf("\n Insira um caractere: ");
	scanf("%c", &fstChar);

	printf(" Insira outro caractere: ");
	scanf(" %c", &scndChar);

	printf("\n ----- RESULTADO -----\n");

	if(fstChar > scndChar)
		printf(" O caractere %c(%d) vem ANTES do caractere %c(%d) na tabela ASCII.\n\n", fstChar, fstChar, scndChar, scndChar);
	else
		printf(" O caractere %c(%d) vem DEPOIS do caractere %c(%d) na tabela ASCII.\n\n", scndChar, scndChar, fstChar, fstChar);

	return 0;
}