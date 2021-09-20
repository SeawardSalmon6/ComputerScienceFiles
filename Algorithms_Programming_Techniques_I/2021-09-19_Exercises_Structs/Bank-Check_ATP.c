#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Cheque {
    char nominal[30], data[10];
    float valor;
} TCheque;

int main() {
    setlocale(LC_ALL, "Portuguese");

    TCheque newCheque;
    puts("\n------------ Cadastro do Cheque ------------\n");
    printf("--> Data de Preenchimento (format.: DD/MM/AAAA): ");
    scanf(" %s", newCheque.data);

    printf("--> Valor do Cheque: ");
    scanf(" %f", &newCheque.valor);

    printf("--> Nome do Beneficiário: ");
    scanf(" %[^\n]s", newCheque.nominal);

    // Printing Results
    system("clear");
    puts("\n------------ Dados do Cheque ------------");
    printf("\n--> Data do Cheque: %s", newCheque.data);
    printf("\n--> Nome do Beneficiário: %s", newCheque.nominal);
    printf("\n--> Valor do Cheque: %.2f \n\n", newCheque.valor);

    return 0;
}