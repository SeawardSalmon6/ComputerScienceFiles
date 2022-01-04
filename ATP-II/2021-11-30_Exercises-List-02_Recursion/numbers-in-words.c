#include <stdio.h>

#define NUMBERS 10
#define STRING_SIZE 12

const char unidades[NUMBERS][STRING_SIZE] =
	{ "zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove" };
const char dez_vinte[NUMBERS][STRING_SIZE] =
	{ "", "onze", "doze", "treze", "quatorze", "quize", "dezesseis", "dezessete", "dezoito", "dezenove" };
const char dezenas[NUMBERS][STRING_SIZE] =
	{ "", "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa" };
const char centenas[NUMBERS][STRING_SIZE] =
	{ "", "cem", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos" };
const char suffixes[5][STRING_SIZE] = { "mil", "milhão", "milhões", "bilhão", "bilhões" };

char *EscreverNumero(int n, char *string) {
	
}

int main() {
	int n;
	char string[100];

	printf("\n Insira um número para escrevermos por extenso: ");
	scanf(" %d", &n);

	printf("\n -> O número por extenso é:\n   %s", EscreverNumero(n, string));

	return 0;
}
