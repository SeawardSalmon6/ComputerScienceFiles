#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int exp, rn, i;
    do { // loop para que o usuário insira o valor especificado
        printf("\nEscolha um valor entre 4 e 10 para criarmos o arquivo: ");
        scanf(" %d", &exp);
    } while(exp <= 3 || exp >= 10);

    // criando o arquivo após input correto
    FILE *fp;
    fp = fopen("numbers", "w"); // arquivo "numbers" será escrito (w)

    srand(0); // seed do rand
	puts("\nProcessando informações...\n");

    // loop de inserção dos valores
    for(i = 0; i < pow(10, exp); i++) {
        // forçando sempre valores pares
        rn = rand() / 2 * 2;
        fprintf(fp, "%d ", rn); // insere os valores randomizados no arquivo
    }

    // insere uma linha vazia e fecha o arquivo
    fprintf(fp, "%c", '\n');
    fclose(fp);

    puts("\nArquivo criado com sucesso!\n");

    return 0;
}
