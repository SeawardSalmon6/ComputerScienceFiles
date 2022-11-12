#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * ==== Constants
 */
#define SIZE 256
#define HUF_EXT "huf"
#define HUF_OUT_SUFFIX "_uncompressed"
#define PARENT_NODE_CHARACTER '*'
#define HUFFMAN_VERSION "HUFF-SS6 1.0"

/**
 * ==== Structs
 */
typedef struct node
{
  unsigned char c;
  unsigned long f;
  struct node *left;
  struct node *right;
  struct node *next;
} Node;

/**
 * ==== Prototypes
 * ------> Utils
 */
void showMenu(int *);
char **allocateDictionary(int);
void concat(char *, const char *, const int);
void freeTree(Node **);
void clearMemory(Node **, unsigned char **, char **, unsigned long **, char ***);

/**
 * -----> Files
 */
void getFilename(char *, char *, char *);
unsigned char *readTextFile(const char *);
Node *readHuffmanFile(Node *, const char *, const char *);
FILE *openFile(const char *, const char *);

/**
 * -----> Tree and List
 */
Node *createNode(unsigned char, unsigned long);
Node *extractFirstNode(Node **);
Node *insertInOrder(Node *, Node *);
int isLeaf(const Node *);
int getTreeHeight(const Node *);

/**
 * -----> Huffman Tree Encoding
 */
unsigned char convertByteToChar(const char *);
void convertCharToByte(unsigned char, char *);
void createFrequencyTable(unsigned long *, const unsigned char *);
int mountList(Node **, const unsigned long *);
Node *generateHuffmanTree(Node *);
void createDictionary(char **, const Node *, char *, int i);
void writeHuffmanEncoding(const unsigned char *, char **, const int, const char *);
void writeHuffmanFileHeader(const char *, Node *, const int);

int main()
{
  char textFilename[SIZE], hufFilename[SIZE], uncompressedFilename[SIZE];
  int lettersCount, op, height;
  unsigned char *text = NULL;
  unsigned long *freqTable = NULL;
  char **dictionary = NULL;
  char *binary = NULL;
  Node *root = NULL;

  getFilename(textFilename, hufFilename, uncompressedFilename);

  do
  {
    showMenu(&op);

    switch (op)
    {
    case 1:
      text = readTextFile(textFilename);
      freqTable = (unsigned long *)calloc(SIZE, sizeof(unsigned long));
      if (!freqTable)
      {
        printf("\n!--> Erro ao alocar memória para a tabela!\n\n");
        exit(1);
      }

      createFrequencyTable(freqTable, text);

      lettersCount = mountList(&root, freqTable);
      writeHuffmanFileHeader(hufFilename, root, lettersCount);
      root = generateHuffmanTree(root);

      height = getTreeHeight(root);
      dictionary = allocateDictionary(height);

      binary = (char *)calloc(height + 1, sizeof(char));
      if (!binary)
      {
        printf("\n!--> Erro ao alocar memória para a string!\n\n");
        exit(1);
      }

      createDictionary(dictionary, root, binary, 0);

      writeHuffmanEncoding(text, dictionary, height, hufFilename);
      printf("\n--> Arquivo compactado com sucesso!\n\n");

      clearMemory(&root, &text, &binary, &freqTable, &dictionary);

      break;

    case 2:
      root = readHuffmanFile(root, hufFilename, uncompressedFilename);
      printf("\n--> Arquivo descompactado com sucesso!\n\n");

      freeTree(&root);

      break;

    case 0:
      printf("\n--> Obrigado por utilizar nosso programa!\n\n");
      break;
    }
  } while (op != 0);

  return 0;
}

void getFilename(char *textFilename, char *hufFilename, char *uncompressedFilename)
{
  char *filename, *extension, aux[SIZE];
  FILE *fp;

  printf("\n--> Insira o nome do arquivo (com extensão) a ser compactado: ");
  fgets(aux, SIZE, stdin);
  aux[strcspn(aux, "\n")] = '\0';

  fp = openFile(aux, "r");

  filename = strtok(aux, ".");
  extension = strtok(NULL, ".");

  sprintf(textFilename, "%s%s%s", filename, extension ? "." : "", extension ? extension : "");
  sprintf(hufFilename, "%s.%s", filename, HUF_EXT);
  sprintf(uncompressedFilename, "%s%s%s%s", filename, HUF_OUT_SUFFIX, extension ? "." : "", extension ? extension : "");
}

unsigned char *readTextFile(const char *filename)
{
  unsigned char *text;
  long size;
  FILE *fp = openFile(filename, "rb");

  fseek(fp, 0, SEEK_END);
  size = ftell(fp);

  text = (unsigned char *)calloc(size + 1, sizeof(unsigned char));
  if (!text)
  {
    printf("\n!--> Erro ao alocar memória para a string!\n\n");
    exit(1);
  }

  rewind(fp);
  if (fread(text, size, 1, fp) != 1)
  {
    printf("\n!--> Erro ao ler o arquivo!\n\n");
    exit(1);
  }

  text[size] = '\0';
  fclose(fp);
  return text;
}

void createFrequencyTable(unsigned long *table, const unsigned char *text)
{
  int i = 0;
  while (text[i] != '\0')
    table[text[i++]]++;
}

Node *createNode(const unsigned char c, const unsigned long f)
{
  Node *newNode = (Node *)malloc(sizeof(Node));

  if (!newNode)
  {
    printf("\n!--> Erro ao alocar memória para o nó!\n\n");
    exit(1);
  }

  newNode->c = c;
  newNode->f = f;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->next = NULL;
  return newNode;
}

Node *insertInOrder(Node *root, Node *newNode)
{
  Node *aux;

  if (!root)
    return newNode;

  if (newNode->f < root->f)
  {
    newNode->next = root;
    return newNode;
  }

  aux = root;
  while (aux->next && newNode->f >= aux->next->f)
    aux = aux->next;

  newNode->next = aux->next;
  aux->next = newNode;
  return root;
}

int mountList(Node **root, const unsigned long *table)
{
  int i, count = 0;
  Node *newNode;

  for (i = 0; i < SIZE; i++)
    if (table[i] > 0)
    {
      count++;
      newNode = createNode(i, table[i]);
      *root = insertInOrder(*root, newNode);
    }

  return count;
}

Node *extractFirstNode(Node **root)
{
  Node *fn = *root;

  if (!fn)
    return NULL;

  *root = (*root)->next;
  fn->next = NULL;
  return fn;
}

Node *generateHuffmanTree(Node *root)
{
  Node *n1, *n2, *p;

  while (root->next)
  {
    n1 = extractFirstNode(&root);
    n2 = extractFirstNode(&root);
    p = createNode(PARENT_NODE_CHARACTER, n1->f + n2->f);
    p->left = n1;
    p->right = n2;
    root = insertInOrder(root, p);
  }

  return root;
}

int getTreeHeight(const Node *root)
{
  int right = 0;
  int left = 0;

  if (!root)
    return -1;

  left = getTreeHeight(root->left) + 1;
  right = getTreeHeight(root->right) + 1;
  return left > right ? left : right;
}

char **allocateDictionary(const int height)
{
  int i;
  char **dictionary;

  dictionary = (char **)malloc(SIZE * sizeof(char *));
  if (!dictionary)
  {
    printf("\n!--> Erro ao alocar memória para o dicionário!\n\n");
    exit(1);
  }

  for (i = 0; i < SIZE; i++)
  {
    dictionary[i] = (char *)calloc(height + 1, sizeof(char));
    if (!dictionary[i])
    {
      printf("\n!--> Erro ao alocar memória para um pedaço do dicionário!\n\n");
      exit(1);
    }
  }

  return dictionary;
}

int isLeaf(const Node *node)
{
  return !node->left && !node->right;
}

void createDictionary(char **dictionary, const Node *root, char *binary, int i)
{
  if (isLeaf(root))
  {
    binary[i] = '\0';
    memcpy(dictionary[root->c], binary, i);
  }
  else
  {
    binary[i] = '0';
    createDictionary(dictionary, root->left, binary, i + 1);
    binary[i] = '1';
    createDictionary(dictionary, root->right, binary, i + 1);
  }
}

void writeHuffmanFileHeader(const char *filename, Node *root, const int lettersCount)
{
  Node *aux;
  FILE *fp = openFile(filename, "w");

  fprintf(fp, "%s\n", HUFFMAN_VERSION);
  fprintf(fp, "%d\n", lettersCount);

  aux = root;
  while (aux)
  {
    fprintf(fp, "%c %ld\n", aux->c, aux->f);
    aux = aux->next;
  }

  fclose(fp);
}

unsigned char convertByteToChar(const char *code)
{
  int i, j;
  unsigned char byte = 0;

  i = 0;
  j = 7;
  while (j >= 0 && code[i] != '\0')
  {
    if (code[i] == '1')
      byte |= (1 << j);
    j--;
    i++;
  }

  return byte;
}

void concat(char *dest, const char *src, const int size)
{
  const int lend = strlen(dest);
  const int lens = strlen(src);

  if (lend + lens < size)
  {
    memcpy(dest + lend, src, lens);
    *(dest + lens + lend) = '\0';
  }
  else
  {
    printf("\n!--> A string de destino é muito pequena para a concatenação!\n\n");
    exit(1);
  }
}

void writeHuffmanEncoding(const unsigned char *text, char **dictionary, const int height, const char *filename)
{
  const int maxLength = height * 128 + 1;
  char *codedText;
  int len, i, j;
  long characters;
  FILE *fp = openFile(filename, "a");

  codedText = (char *)calloc(maxLength, sizeof(char));
  if (!codedText)
  {
    printf("\n!--> Erro ao alocar memória para a string!\n\n");
    exit(1);
  }

  i = j = 0;
  while (text[i] != '\0')
  {
    concat(codedText, dictionary[text[i]], maxLength);
    len = strlen(codedText);

    if (len >= 8)
    {
      fprintf(fp, "%c", convertByteToChar(codedText));
      memcpy(codedText, codedText + 8, len - 8);
      *(codedText + (len - 8)) = '\0';
      len -= 8;
      j++;
    }

    i++;
  }

  characters = j * 8;
  if (len > 0)
  {
    characters += len;
    fprintf(fp, "%c", convertByteToChar(codedText));
  }

  fprintf(fp, "\n%ld\n", characters);

  printf("\n\t--> Total de Bytes do Arquivo Original: %ld\n", strlen((const char *)text));
  printf("\n\t--> Total de Bytes do Arquivo Compactado: %ld\n", ftell(fp));
  printf("\n\t--> Bytes Economizados: %ld (%02.2lf%%)\n", strlen((const char *)text) - ftell(fp), 100 * (double)ftell(fp) / strlen((const char *)text));

  free(codedText);
  fclose(fp);
}

void freeTree(Node **root)
{
  if (!(*root))
    return;

  if (isLeaf(*root))
  {
    free(*root);
    *root = NULL;
  }
  else
  {
    freeTree(&(*root)->left);
    freeTree(&(*root)->right);
    free(*root);
    *root = NULL;
  }
}

void convertCharToByte(unsigned char c, char *code)
{
  int i = 7;

  while (i >= 0)
  {
    code[i] = (c & 1) + '0';
    c >>= 1;
    i--;
  }

  code[8] = '\0';
}

Node *readHuffmanFile(Node *root, const char *hufFilename, const char *uncompressedFilename)
{
  int i, j, k, letters;
  char code[9], line[SIZE];
  unsigned char c, *text;
  unsigned long f, pos, end, bitsCounter;
  Node *aux, *newNode;
  FILE *huf = openFile(hufFilename, "rb");
  FILE *out = openFile(uncompressedFilename, "w");

  fgets(line, SIZE, huf); // Reads version
  line[strcspn(line, "\n")] = '\0';

  if (strcasecmp(line, HUFFMAN_VERSION) != 0)
  {
    printf("\n!--> As versão do arquivo não é suportada!\n\n");
    exit(1);
  }

  fgets(line, SIZE, huf); // Reads size of table
  letters = atoi(line);

  // Reads the table
  for (i = 0; i < letters; i++)
  {
    c = fgetc(huf);         // Reads first char
    fgets(line, SIZE, huf); // Reads the frequency
    f = atol(line);

    newNode = createNode(c, f);
    root = insertInOrder(root, newNode);
  }

  // Create Huffman File
  root = generateHuffmanTree(root);

  // Reads the quantity of actual bits in compactation
  pos = ftell(huf);
  fseek(huf, -2, SEEK_END);

  while ((c = fgetc(huf)) != '\n')
    fseek(huf, -2, SEEK_CUR);

  end = ftell(huf) - 1;
  fgets(line, SIZE, huf);
  bitsCounter = atol(line); // Read actual compacted bits quantity
  fseek(huf, pos, SEEK_SET);

  text = (unsigned char *)calloc((end - pos) + 1, sizeof(unsigned char));
  if (!text)
  {
    printf("\n!--> Erro ao alocar memória para a string!\n\n");
    exit(1);
  }

  if (fread(text, (end - pos), 1, huf) != 1)
  {
    printf("\n!--> Houve um erro ao ler o texto compactado!\n\n");
    exit(1);
  }

  i = k = 0;
  aux = root;
  while (i < (end - pos))
  {
    convertCharToByte(text[i], code);

    for (j = 0; j < 8; j++)
    {
      if (bitsCounter == 0)
        break;

      k++;
      if (code[j] == '1')
        aux = aux->right;
      else
        aux = aux->left;

      if (isLeaf(aux))
      {
        fprintf(out, "%c", aux->c);
        bitsCounter -= k;
        aux = root;
        k = 0;
      }
    }

    i++;
  }

  free(text);
  fclose(huf);
  fclose(out);
  return root;
}

void clearMemory(Node **root, unsigned char **text, char **binary, unsigned long **freqTable, char ***dictionary)
{
  int i;
  freeTree(root);

  free(*text);
  *text = NULL;
  free(*freqTable);
  *freqTable = NULL;
  free(*binary);
  *binary = NULL;

  for (i = 0; i < SIZE; i++)
  {
    free((*dictionary)[i]);
    (*dictionary)[i] = NULL;
  }

  free(*dictionary);
  *dictionary = NULL;
}

FILE *openFile(const char *filename, const char *mode)
{
  FILE *fp = fopen(filename, mode);

  if (!fp)
  {
    printf("\n!--> Erro ao abrir o arquivo \"%s\"!\n\n", filename);
    exit(1);
  }

  return fp;
}

void showMenu(int *op)
{
  int resScan = 0;
  char c;

  do
  {
    printf("\n===== ÁRVORE DE HUFFMAN");
    printf("\n(1) Compactar");
    printf("\n(2) Descompactar");
    printf("\n(0) Sair");

    printf("\n\n--> Digite a opção escolhida: ");
    resScan = scanf(" %d", op);

    while (!resScan && ((c = getchar()) == '\n' || c == EOF))
      ;

    if (!resScan || (*op < 0 && *op > 2))
      printf("\n!--> Insira uma opção válida!\n");
  } while (!resScan || (*op < 0 && *op > 2));
}