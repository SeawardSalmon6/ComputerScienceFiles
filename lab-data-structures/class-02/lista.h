#define MAX 100
#define TRUE 1
#define FALSE 0
#define boolean int

// Estruturas e tipos
// -------------------------------
// Tipo chave
typedef int TipoChave;

// Tipo registro
typedef struct
{
	char nome[30];
	// ... caso tenham mais campos
} TipoDado;

// Tipo elemento (registro + chave)
typedef struct
{
	TipoChave chave;
	TipoDado info;
} TipoElem;

// Tipo Lista (sequencial)
typedef struct
{
	int nelem; // número de elementos
	TipoElem arr[MAX + 1];
} Lista;

// Operações
// -----------------------------------
// Função Vazia: retorna se a lista está vazia ou não
boolean Vazia(Lista *);

// Função Cheia: retorna se a lista está cheia ou não
boolean Cheia(Lista *);

// Função Definir: cria uma nova lista
void Definir(Lista *);

// Função Apagar: apaga logicamente a lista
void Apagar(Lista *);

// Função Inserir_posic: Insere um elemento num certo índice da lista
boolean Inserir_posic(TipoElem, int, Lista *);

// Função Buscar: Busca de maneira linear um dado elemento
boolean Buscar(TipoChave, Lista *, int *);

// Função Remover_posic: remove um elemento numa dada posição
void Remover_posic(int *, Lista *);

// Função Impr_elem: apresenta um elemento
void Impr_elem(TipoElem);

// Função Imprimir: imprime a lista toda
void Imprimir(Lista *);

// Função Tamanho: retorna a quantidade de elementos da lista
int Tamanho(Lista *);

// Função Inserir_ord: insere um elemento de maneira ordenada
boolean Inserir_ord(TipoElem, Lista *);

// Função Busca_ord: busca um elemento até o primeiro maior elemento da lista
boolean Buscar_ord(TipoChave, Lista *, int *);

// Função Busca_bin: busca um elemento utilizando busca binária
boolean Busca_bin(TipoChave, Lista *, int *);

// Função Remover_ch: remove um elemento utilizando busca binária e retorna se houve sucesso
boolean Remover_ch(TipoChave, Lista *);
