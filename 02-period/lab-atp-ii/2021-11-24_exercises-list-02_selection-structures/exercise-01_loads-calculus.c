#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void getFU(int*);
void getLoadWeight(float*);
void getLoadCode(int*);
float calcWeightKG(float);
float calcLoadPrice(float, float);
float calcLoadTaxes(int, float);
float totalLoadPrice(float, float);

int main() {
    setlocale(LC_ALL, "Portuguese");

    int stateCode, loadCode;
    float loadWeight, loadPrice, taxValue, totalValue;

    /* Getting info from user */
    getFU(&stateCode);
    getLoadWeight(&loadWeight);
    getLoadCode(&loadCode);

    /* Calculus */
    loadWeight = calcWeightKG(loadWeight);
    loadPrice = calcLoadPrice(loadWeight, loadCode);
    taxValue = calcLoadTaxes(stateCode, loadPrice);
    totalValue = totalLoadPrice(loadPrice, taxValue);

    /* Showing results */
    system("clear");
    printf("\n =============== INFORMAÇÕES DO TRANSPORTE\n");

    printf("\n 1. Informações do Caminhão:\n");
    printf("    - Estado de Origem: %d\n", stateCode);
    printf("    - Peso da Carga em Toneladas: %.2f t\n", (loadWeight / 1000));
    printf("    - Código do Tipo de Carga: %d\n", loadCode);

    printf("\n 2. Valores da Carga:\n");
    printf("    - Peso da Carga em Quilos: %.2f kg\n", loadWeight);
    printf("    - Valor Total da Carga: R$%.2f\n", totalValue);
    printf("      -> Valor Bruto (sem impostos): R$%.2f\n", loadPrice);
    printf("      -> Valor do Imposto: R$%.2f\n\n", taxValue);

    return 0;
}

void getFU(int *state) {
    do {
        printf("\n - Insira o código do estado de origem da carga: ");
        scanf(" %d", state);

        if(*state < 1 || *state > 5)
            puts("\nErro: insira valores entre 1 e 5!");

    } while(*state < 1 || *state > 5);
}

void getLoadWeight(float *weight) {
    do {
        printf("\n - Insira o peso da carga, em toneladas: ");
        scanf(" %f", weight);

        if(*weight < 0)
            puts("\nErro: insira valores inteiros!");

    } while(*weight < 0);
}

void getLoadCode(int *ldCode) {
    do {
        printf("\n - Insira o código da carga: ");
        scanf(" %d", ldCode);

        if(*ldCode < 10 || *ldCode > 50)
            puts("\nErro: insira valores entre 10 e 50!");

    } while(*ldCode < 10 || *ldCode > 50);
}

float calcWeightKG(float tons) {
    return (tons * 1000);
}

float calcLoadPrice(float kg, float type) {
    if(type >= 10 && type <= 20)
        return (kg * 100);
    else if(type > 20 && type <= 30)
        return (kg * 250);
    else
        return (kg * 340);
}

float calcLoadTaxes(int stCode, float ldPrice) {
    switch(stCode) {
        case 1:
            return (0.35 * ldPrice);
        break;

        case 2:
            return (0.25 * ldPrice);
        break;

        case 3:
            return (0.15 * ldPrice);
        break;

        case 4:
            return (0.05 * ldPrice);
        break;

        case 5:
            return (0);
        break;

        default:
            return (-1);
        break;
    }
}

float totalLoadPrice(float load, float tax) {
    return (load + tax);
}