#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *pt1, *pt2;
    int number, aux, soma = 0;

    pt1 = fopen("numbers", "w");
    pt2 = fopen("sum", "w");

    if(pt1 == NULL || pt2 == NULL) {
        printf("Erro ao abrir arquivos.\n");
        exit(-1);
    }

    for(int i = 1000; i < 10000; i++)
        fprintf(pt1, "%d ", i);

    fclose(pt1);

    pt1 = fopen("numbers", "r");
    if(pt1 == NULL) {
        printf("Erro ao abrir arquivos.\n");
        exit(-1);
    }

    while(!feof(pt1)) {
        fscanf(pt1, "%d ", &number);

        while(number > 0) {    
            aux = number % 10;
            soma += aux;
            number = number / 10;
        }

        fprintf(pt2, "%d ", soma);
        soma = 0;
    }

    fclose(pt1); fclose(pt2);

    return 0;
}
