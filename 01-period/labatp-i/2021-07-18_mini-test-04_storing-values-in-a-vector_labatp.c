#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_COUNT 10

int main() {
    setlocale(LC_ALL, "Portuguese");

    int qtdNegativos = 0;
    double arrNumeros[MAX_COUNT] = { 0 };

    printf("\nSeja bem-vindo!\n");
    printf("\nAbaixo, insira 10 valores reais e verificaremos quantos números negativos foram digitados:\n");

    /* Recebendo os números e armazenando no Array */
    for(int i = 0; i < MAX_COUNT; i++) {
        printf("\t-- Insira o %dº valor: ", i + 1);
        scanf(" %lf", &arrNumeros[i]);
    }

    /* Somando a quantidade de números negativos */
    for(int i = 0; i < MAX_COUNT; i++)
        if(arrNumeros[i] < 0) qtdNegativos++;

    printf("\n--------------------------------------------");
    printf("\nA quantidade de números negativos digitados foi de:");
    printf("\n  ==> %d número(s) negativo(s)\n\n", qtdNegativos);

    return 0;
}