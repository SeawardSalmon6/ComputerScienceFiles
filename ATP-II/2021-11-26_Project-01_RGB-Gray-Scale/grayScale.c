#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, g, b; // inicializacao das variaveis das cores
    int n, k, i, j; // inicializacao das variaveis da altura e largura da figura + indices

    // inicializacao dos arquivos "figura.dat" (leitura) e "cinza.dat" (saida)
    FILE *fpr = fopen("figura.dat", "r"),
         *fpw = fopen("cinza.dat", "w");

    /* realizacao de um teste para verificar se os arquivos realmente foram criados;
    se o retorno da alocacao de memoria for nulo, ocorreu um erro e o programa se encerra */
    if(fpr == NULL || fpw == NULL) exit(1);

    // ============================================= Inicio do Programa
    fscanf(fpr, "%d %d", &n, &k); // leitura da altura e largura da figura
    fprintf(fpw, "%d %d\n", n, k); // escrita no novo arquivo, a largura e altura lidas

    // laco para a leitura do arquivo "figura.dat" para cada uma de suas linhas (altura)
    for(j = 0; j < k; j++) {
        // laco para ler os pixels (grupos de tres) disponiveis em cada uma das linhas do arquivo (largura)
        for(i = 0; i < n; i++) {
            fscanf(fpr, "%d %d %d ", &r, &g, &b); // leitura dos valores RGB de cada pixel
            fprintf(fpw, "%d ", ((r + g + b) / 3)); // escrita do pixel reduzido em escala de cinza
        } fprintf(fpw, "\n"); // insercao de uma nova linha no arquivo de saida
    }

    fclose(fpr); fclose(fpw); // fechando e salvando os arquivos utilizados
    // ============================================= Fim do Programa

    return 0;
}
