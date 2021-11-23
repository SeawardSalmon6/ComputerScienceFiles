#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int n, k, i, j = 0;
    FILE *fp = fopen("figura.dat", "w");

    if(fp == NULL) exit(-1);

    srand(0);

    puts("-------- Figure Creator");
    printf("-> Insira os valores da largura e altura da figura: ");
    scanf(" %u %u", &n, &k);

    if(n < 12 || n > 1024 || k < 12 || k > 1024) {
        puts("\nAs medidas de altura e/ou largura do arquivo nao sao validas! Tente com valores entre 12 e 1024 pixels.\n");
        fclose(fp);
        exit(-1);
    }

    fprintf(fp, "%u %u\n", n, k);

    puts("\nIniciando escrita dos valores...\n");

    for(i = 0; i < k; i++) {
        for(j = 0; j < n * 3; j++)
            fprintf(fp, "%hhu ", (rand() % 255 + 1));
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}
