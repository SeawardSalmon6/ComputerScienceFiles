#define ROOT_RRN_KEYNAME "RAIZ"
#define INDEX_FILENAME "btree.idx"
#define NO_CHILD_KEY_VALUE "????"

const int TREE_ORDER = 3;
const int MAX_KEYS = TREE_ORDER - 1;
const int MIN_NODES = (TREE_ORDER / 2 + (TREE_ORDER / 2.0 - TREE_ORDER / 2 > 0 ? 1 : 0));
const int MIN_KEYS = MIN_NODES - 1;
const int SIZE_OF_BTREE_PAGE_RECORD = (TREE_ORDER + MAX_KEYS) * 4;

typedef struct no
{
  int count;
  int keys[MAX_KEYS + 1];
  struct no *children[TREE_ORDER];
} Node;

extern Node *raiz;
extern int indexRaiz;

Node *criarNo(int item, Node *filho);
void inserirValor(int item, int pos, Node *no, Node *filho);
void divideNo(int item, int *pval, int pos, Node *no, Node *filho, Node **novoNo);
int setNo(int item, int *pval, Node *no, Node **filho);
void inserir(int item);
int procura(Node *noSelecionado, int val);
void clearBuf();

void escreveArvBPorNivel(Node *root);
void escreveNivelArvB(Node *root, int nivel);
void escreveNoCompleto(Node *no);
int getTamanhoArvB(Node *root);
void escreveArvB(Node *noSelecionado);

int nodeHasChildren(Node *node);
void salvarArvore();
void salvarPai(Node *node, int *k, FILE *fp);
void salvarNode(Node *node, int *k, FILE *fp);