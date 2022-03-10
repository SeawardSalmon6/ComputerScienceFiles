#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NUMBERS_QUANTITY;

typedef struct Biggo {
    int high;
    int low;
} BigInt;

void TestFile(FILE*);

int main() {
    FILE *fw = fopen("bigint.dat", "w"); TestFile(fw);
    int i, nRandHigh, nRandLow;

    printf("\n--> Insira a quantidade de números a serem gerados: ");
    scanf(" %d", &NUMBERS_QUANTITY);
    
    printf("\n--> Gerando números...");

    srand(time(NULL)); // --> Setting rand() seed
    for(i = 0; i < NUMBERS_QUANTITY; i++) {
        nRandHigh = 2 * (rand() % 100) - 100;
        nRandLow = rand() % __INT_MAX__ + 1;
        fprintf(fw, "%d %d\n", nRandHigh, nRandLow);
    }

    printf("\n--> Números gerados! Encerrando programa...\n\n");
    fclose(fw);

    return 0;
}

void TestFile(FILE *fp) {
    if(!fp) {
        printf("\n--> Erro ao alocar memória. Saindo...\n\n");
        exit(1);
    }
}