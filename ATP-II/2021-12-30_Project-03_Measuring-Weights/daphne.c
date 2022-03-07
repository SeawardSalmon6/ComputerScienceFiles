#include <stdio.h>
#include <stdlib.h>

int *vetorResposta;
int numCasas = 0; // numero de casas do vetor resposta
int ordenacao(int *, int); // funcao que vai ordenar de forma decrescente algum vetor
int diminuirVetor(int *, int);

// int E = lado esquerdo da balanca, onde vai estar o peso que queremos igualar
int balanca(int E, int D, int *vetorPesos, int numDePeso) {
    if (E == 0 || E == D) // retornar 1 (verdade) se o lado esquerdo estiver vazio ou se o lado esquerdo e direito estarem iguais
        return 1;

	// percorrer o vetor que guarda as opcoes de peso, e se o peso que queremos for igual a um deles retornar 1
    for (int i = 0; i < numDePeso; i++)
        if (E == vetorPesos[i])
            return 1;

	// retornar falso se o vetor que guarda os pesos estiver vazio, com isso o backtracking vai acontecer, recuando e tentando novamente com outros valores
    if (numDePeso == 0)
        return 0;

    int p = diminuirVetor(vetorPesos, numDePeso); // essa funcao retorna o valor do numero que esta na ultima posicao do vetor pesos
    numDePeso--; //"diminui" o vetor pesos em -1

	// Coloca o peso p no lado esquerdo, se retornar verdade colocar esse peso p no vetor resposta com sinal negativo
    if(balanca(E + p, D, vetorPesos, numDePeso)) {
        vetorResposta[numCasas] = p * (-1);
        numCasas++;
        return 1;
    }

	// Verificar se o lado esquerdo e direito se igualam sem o peso p
    if(balanca(E, D, vetorPesos, numDePeso))
        return 1;

    if(balanca(E, D + p, vetorPesos, numDePeso)) { // Coloca o peso p no lado direito, se der verdade colocar esse peso p no vetor resposta
        vetorResposta[numCasas] = p;
        numCasas++;
        return 1;
    }

    return 0; // se chegar ate aqui e porque nao existe resposta
}

int diminuirVetor(int *vetorPesos, int numDePeso) {
    int aux = vetorPesos[numDePeso - 1];
    return (aux);
}

int main() {
    int n, m, peso;

    do scanf("%d %d", &n, &m);
    while (n < 1 || n > 100 || m < 5 || m > 20); // continuar perguntando ate n e m serem valores validos

    int *vetorPesos;
    vetorPesos = (int*) malloc(m * sizeof(int)); // vetor que ira guardar os pesos disponiveis

    int aux;
    do {
        aux = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d ", &vetorPesos[i]);
            if (vetorPesos[i] < 1 || vetorPesos[i] > 1000000)
                aux = 1;
        }
    } while(aux); // continuar perguntando ate todos os pesos serem valores validos

    int *pesoIdeal;
    pesoIdeal = (int*) malloc(n * sizeof(int)); // vetor que vai guardar os pesos que devemos atingir

    for (int i = 0; i < n; i++) {
        scanf("%d", &peso);
        pesoIdeal[i] = peso;
    }

    vetorResposta = (int*) malloc(m * sizeof(int));

    for (int i = 0; i < n; i++) // laco for para chamar a funcao balanca para cada um dos pesos que queremos atingir
        if(balanca(pesoIdeal[i], 0, vetorPesos, m)) {// se retornar 1 e porque achamos uma resposta
            *vetorResposta = ordenacao(vetorResposta, numCasas);
            for (int j = 0; j < numCasas; j++)
                printf("%d ", vetorResposta[j]);

            numCasas = 0; // o numero de casas do vetor resposta zera a cada resposta recebida
            printf("\n");
        }
        else
            printf("0\n"); // se nao retornar 1 e porque nao existe resposta

	return 0;
}

int ordenacao(int *v, int n) {
    int houve_troca;
    int aux2;

    do {
        houve_troca = 0;
        for (int i = 0; i < n - 1; i++)
            if (v[i] < v[i + 1]) { // se o numero for menor que o numero depois dele, inverter os dois
                aux2 = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux2;
                houve_troca = 1;
            }

    } while(houve_troca); // fazer isso ate a variavel houve_troca continuar nula ao percorrer o vetor inteiro

    return (*v); // retornar o vetor ordenado
}