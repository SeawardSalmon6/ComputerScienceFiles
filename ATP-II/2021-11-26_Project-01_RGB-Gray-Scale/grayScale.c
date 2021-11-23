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
    if(fpr == NULL || fpw == NULL) exit(-1);

    // ============================================= Inicio do Programa
    fscanf(fpr, "%d %d", &n, &k); // leitura da altura e largura da figura

    // verifica se os valores de altura e largura da imagem nao extrapolam as medidas maximas/minimas
    if(n < 12 || n > 1024 || k < 12 || k > 1024) {
        fclose(fpr); fclose(fpw); // fechando e salvando os arquivos utilizados
        exit(-1);
    }

    // escrita no novo arquivo, a largura e altura lidas
    fprintf(fpw, "%d %d\n", n, k);

    // laco de repeticao para a leitura do arquivo "figura.dat" por cada uma de suas linhas (altura)
    for(j = 0; j < k; j++) {
        // laco de repeticao buscando ler os pixels disponiveis em cada uma das linhas do arquivo (largura)
        for(i = 0; i < n; i++) {
            fscanf(fpr, "%d %d %d ", &r, &g, &b); // leitura dos valores RGB de cada pixel
            fprintf(fpw, "%d ", ((r + g + b) / 3)); // escrita do pixel reduzido em escala de cinza
        } fprintf(fpw, "\n"); // insercao de uma nova linha no arquivo de saida
    }

    fclose(fpr); fclose(fpw); // fechando e salvando os arquivos utilizados
    // ============================================= Fim do Programa

    return 0;
}
