#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	char sex;

	printf("\nInsira seu gênero: ");
	scanf("%c", &sex);

	if(toupper(sex) == 'M')
		printf("\nVocê é do sexo Masculino.\n\n");
	else if (toupper(sex) == 'F')
		printf("\nVocê é do sexo Feminino.\n\n");
	else
		printf("\nVocê não inseriu um sexo válido.\n\n");

	return 0;
}