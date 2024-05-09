#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"

void getFilename(char *textFilename, char *hufFilename, char *uncompressedFilename) {
  char *filename, *extension, aux[SIZE];

  printf("\n--> Insira o nome do arquivo (com extensão) a ser compactado: ");
  fgets(aux, SIZE, stdin);
  aux[strcspn(aux, "\n")] = '\0';

  if (!openFile(aux, "r")) {
    exit(1);
  }

  filename = strtok(aux, ".");
  extension = strtok(NULL, ".");

  sprintf(textFilename, "%s%s%s", filename, extension ? "." : "", extension ? extension : "");
  sprintf(hufFilename, "%s.%s", filename, HUF_EXT);
  sprintf(uncompressedFilename, "%s%s%s%s", filename, HUF_OUT_SUFFIX, extension ? "." : "", extension ? extension : "");
}

unsigned char *readTextFile(const char *filename, unsigned long *filesize) {
  unsigned char *text;
  unsigned long size;
  FILE *fp = openFile(filename, "rb");

  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  *filesize = size;

  text = (unsigned char *)calloc(size + 1, sizeof(unsigned char));
  if (!text) {
    printf("\n!--> Erro ao alocar memória para a string!\n\n");
    exit(1);
  }

  rewind(fp);
  if (fread(text, size, 1, fp) != 1) {
    printf("\n!--> Erro ao ler o arquivo!\n\n");
    exit(1);
  }

  text[size] = '\0';
  fclose(fp);
  return text;
}

void createFrequencyTable(unsigned long *table, const unsigned char *text, const unsigned long filesize) {
  unsigned long i = 0;
  while (i < filesize)
    table[text[i++]]++;
}

Node *createNode(const unsigned char c, const unsigned long f) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  if (!newNode) {
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

Node *insertInOrder(Node *root, Node *newNode) {
  Node *aux;

  if (!root)
    return newNode;

  if (newNode->f < root->f) {
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

int mountList(Node **root, const unsigned long *table) {
  int i, count = 0;
  Node *newNode;

  for (i = 0; i < SIZE; i++)
    if (table[i] > 0) {
      count++;
      newNode = createNode(i, table[i]);
      *root = insertInOrder(*root, newNode);
    }

  return count;
}

Node *extractFirstNode(Node **root) {
  Node *fn = *root;

  if (!fn)
    return NULL;

  *root = (*root)->next;
  fn->next = NULL;
  return fn;
}

Node *generateHuffmanTree(Node *root) {
  Node *n1, *n2, *p;

  while (root->next) {
    n1 = extractFirstNode(&root);
    n2 = extractFirstNode(&root);
    p = createNode(PARENT_NODE_CHARACTER, n1->f + n2->f);
    p->left = n1;
    p->right = n2;
    root = insertInOrder(root, p);
  }

  return root;
}

int getTreeHeight(const Node *root) {
  int right = 0;
  int left = 0;

  if (!root)
    return -1;

  left = getTreeHeight(root->left) + 1;
  right = getTreeHeight(root->right) + 1;
  return left > right ? left : right;
}

char **allocateDictionary(const int height) {
  int i;
  char **dictionary;

  dictionary = (char **)malloc(SIZE * sizeof(char *));
  if (!dictionary) {
    printf("\n!--> Erro ao alocar memória para o dicionário!\n\n");
    exit(1);
  }

  for (i = 0; i < SIZE; i++) {
    dictionary[i] = (char *)calloc(height + 1, sizeof(char));
    if (!dictionary[i]) {
      printf("\n!--> Erro ao alocar memória para um pedaço do dicionário!\n\n");
      exit(1);
    }
  }

  return dictionary;
}

int isLeaf(const Node *node) {
  return !node->left && !node->right;
}

void createDictionary(char **dictionary, const Node *root, char *binary, int i) {
  if (isLeaf(root)) {
    binary[i] = '\0';
    memcpy(dictionary[root->c], binary, i);
  } else {
    binary[i] = '0';
    createDictionary(dictionary, root->left, binary, i + 1);
    binary[i] = '1';
    createDictionary(dictionary, root->right, binary, i + 1);
  }
}

void writeHuffmanFileHeader(const char *filename, Node *root, const int lettersCount) {
  Node *aux;
  FILE *fp = openFile(filename, "w");

  fprintf(fp, "%s\n", HUFFMAN_VERSION);
  fprintf(fp, "%d\n", lettersCount);

  aux = root;
  while (aux) {
    fprintf(fp, "%c %ld\n", aux->c, aux->f);
    aux = aux->next;
  }

  fclose(fp);
}

unsigned char convertByteToChar(const char *code) {
  int i, j;
  unsigned char byte = 0;

  i = 0;
  j = 7;
  while (j >= 0 && code[i] != '\0') {
    if (code[i] == '1')
      byte |= (1 << j);
    j--;
    i++;
  }

  return byte;
}

char *slice(char *str, const unsigned int start, const unsigned int end) {
  const unsigned int len = strlen(str);

  if (!str || end > len || start > end)
    return NULL;

  memcpy(str, str + start, end - start);
  *(str + (end - start)) = '\0';
  return str;
}

char *concat(char *dest, const char *src, const unsigned int size) {
  const unsigned int lend = strlen(dest);
  const unsigned int lens = strlen(src);

  if (!dest || !src || size == 0)
    return NULL;

  if (lend + lens < size) {
    memcpy(dest + lend, src, lens);
    *(dest + lens + lend) = '\0';
  } else {
    printf("\n!--> A string de destino é muito pequena para a concatenação!\n\n");
    exit(1);
  }

  return dest;
}

void writeHuffmanEncoding(const unsigned char *text, const unsigned long filesize, char **dictionary, const int height, const char *filename) {
  const int maxLength = height * 256 + 1;
  char *codedText;
  unsigned long len, i, j;
  long characters, sizeCompact;
  FILE *fp = openFile(filename, "a");

  codedText = (char *)calloc(maxLength, sizeof(char));
  if (!codedText) {
    printf("\n!--> Erro ao alocar memória para a string!\n\n");
    exit(1);
  }

  i = j = 0;
  while (i < filesize) {
    concat(codedText, dictionary[text[i]], maxLength);
    len = strlen(codedText);

    if (len >= BITS_IN_A_BYTE) {
      fprintf(fp, "%c", convertByteToChar(codedText));
      slice(codedText, BITS_IN_A_BYTE, len);
      len -= BITS_IN_A_BYTE;
      j++;
    }

    i++;
  }

  characters = j * BITS_IN_A_BYTE;
  if (len > 0) {
    characters += len;
    fprintf(fp, "%c", convertByteToChar(codedText));
  }

  fprintf(fp, "\n%ld\n", characters);

  sizeCompact = ftell(fp);
  printf("\n\t--> Total de Bytes do Arquivo Original: %ld\n", filesize);
  printf("\n\t--> Total de Bytes do Arquivo Compactado: %ld\n", sizeCompact);
  printf("\n\t--> Bytes Economizados: %ld (%02.2lf%%)\n", filesize - sizeCompact, 100 * (1 - (double)sizeCompact / filesize));

  free(codedText);
  codedText = NULL;
  fclose(fp);
}

void freeTree(Node **root) {
  if (!(*root))
    return;

  if (isLeaf(*root)) {
    free(*root);
    *root = NULL;
  } else {
    freeTree(&(*root)->left);
    freeTree(&(*root)->right);
    free(*root);
    *root = NULL;
  }
}

void convertCharToByte(unsigned char c, char *code) {
  int i = 7;

  while (i >= 0) {
    code[i] = (c & 1) + '0';
    c >>= 1;
    i--;
  }

  code[BITS_IN_A_BYTE] = '\0';
}

Node *readHuffmanFile(Node *root, const char *hufFilename, const char *uncompressedFilename) {
  unsigned long i, j, k, letters;
  char code[9], line[SIZE];
  unsigned char c, *text;
  unsigned long f, pos, end, bitsCounter;
  Node *aux, *newNode;
  FILE *huf = openFile(hufFilename, "rb");
  FILE *out = openFile(uncompressedFilename, "w");

  fgets(line, SIZE, huf); // Reads version
  line[strcspn(line, "\n")] = '\0';

  if (strcasecmp(line, HUFFMAN_VERSION) != 0) {
    printf("\n!--> As versão do arquivo não é suportada!\n\n");
    exit(1);
  }

  fgets(line, SIZE, huf); // Reads size of table
  letters = atoi(line);

  // Reads the table
  for (i = 0; i < letters; i++) {
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
  if (!text) {
    printf("\n!--> Erro ao alocar memória para a string!\n\n");
    exit(1);
  }

  if (fread(text, (end - pos), 1, huf) != 1) {
    printf("\n!--> Houve um erro ao ler o texto compactado!\n\n");
    exit(1);
  }

  i = k = 0;
  aux = root;
  while (i < (end - pos)) {
    convertCharToByte(text[i], code);

    for (j = 0; j < BITS_IN_A_BYTE; j++) {
      if (bitsCounter == 0)
        break;

      k++;
      if (code[j] == '1')
        aux = aux->right;
      else
        aux = aux->left;

      if (isLeaf(aux)) {
        fprintf(out, "%c", aux->c);
        bitsCounter -= k;
        aux = root;
        k = 0;
      }
    }

    i++;
  }

  free(text);
  text = NULL;
  fclose(huf);
  fclose(out);
  return root;
}

void clearMemory(Node **root, unsigned char **text, char **binary, unsigned long **freqTable, char ***dictionary) {
  int i;
  freeTree(root);

  free(*text);
  *text = NULL;
  free(*freqTable);
  *freqTable = NULL;
  free(*binary);
  *binary = NULL;

  for (i = 0; i < SIZE; i++) {
    free((*dictionary)[i]);
    (*dictionary)[i] = NULL;
  }

  free(*dictionary);
  *dictionary = NULL;
}

FILE *openFile(const char *filename, const char *mode) {
  FILE *fp = fopen(filename, mode);

  if (!fp) {
    printf("\n!--> Erro ao abrir o arquivo \"%s\"!\n\n", filename);
    exit(1);
  }

  return fp;
}

void showMenu(int *op) {
  int resScan = 0;
  char c;

  do {
    printf("\n===== ÁRVORE DE HUFFMAN");
    printf("\n(1) Compactar");
    printf("\n(2) Descompactar");
    printf("\n(0) Sair");

    printf("\n\n--> Digite a opção escolhida: ");
    resScan = scanf(" %d", op);

    while (!resScan && ((c = getchar()) == '\n' || c == EOF))
      ;

    if (!resScan || *op < 0 || *op > 2)
      printf("\n!--> Insira uma opção válida!\n");
  } while (!resScan || *op < 0 || *op > 2);
}