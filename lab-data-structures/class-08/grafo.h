// Estruturas para n� e grafo
//----------------------------------
struct no
{
    int id;
    int val;
    struct no *prox;
};

typedef struct no *No;

struct grafo
{
    int id;
    int nNo;     // nodes quantity
    No vertices; // vertexes list
};

typedef struct grafo *Grafo;
//----------------------------------

// Defini��o das fun��es
//----------------------------------
No criaNo(int id, int val);

void addNo(No n, int id, int val);

void imprimeNo(No n);

Grafo criaGrafo();

void readGraph(Grafo G, const char *filename);

void printGraph(Grafo G);
//----------------------------------
