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
boolean Vazia(Lista *lista);

// Função Cheia: retorna se a lista está cheia ou não
boolean Cheia(Lista *lista);

// Função Definir: cria uma nova lista
void Definir(Lista *lista);

// Função Apagar: apaga logicamente a lista
void Apagar(Lista *lista);

// Função Inserir_posic: Insere um elemento num certo índice da lista
boolean Inserir_posic(TipoElem novoElem, int pos, Lista *lista);

// Função Buscar: Busca de maneira linear um dado elemento
boolean Buscar(TipoChave chaveBuscada, Lista *lista, int *pos);

// Função Remover_posic: remove um elemento numa dada posição
void Remover_posic(int *pos, Lista *lista);

// Função Impr_elem: apresenta um elemento
void Impr_elem(TipoElem elem);

// Função Imprimir: imprime a lista toda
void Imprimir(Lista *lista);

// Função Tamanho: retorna a quantidade de elementos da lista
int Tamanho(Lista *lista);

// Função Inserir_ord: insere um elemento de maneira ordenada
boolean Inserir_ord(TipoElem novoElem, Lista *lista);

// Função Busca_ord: busca um elemento até o primeiro maior elemento da lista
boolean Buscar_ord(TipoChave chaveBuscada, Lista *lista, int *pos);

// Função Busca_bin: busca um elemento utilizando busca binária
boolean Busca_bin(TipoChave chaveBuscada, Lista *lista, int *pos);

// Função Remover_ch: remove um elemento utilizando busca binária e retorna se houve sucesso
boolean Remover_ch(TipoChave chaveBuscada, Lista *lista);