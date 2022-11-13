#include <stdio.h>

/**
 * ==== Constants
 */
#define SIZE 256
#define HUF_EXT "huf"
#define HUF_OUT_SUFFIX "_uncompressed"
#define PARENT_NODE_CHARACTER '*'
#define HUFFMAN_VERSION "HUFF-SS6 1.0"
#define BITS_IN_A_BYTE 8

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
char *slice(char *, const unsigned int, const unsigned int);
char *concat(char *, const char *, const unsigned int);
void freeTree(Node **);
void clearMemory(Node **, unsigned char **, char **, unsigned long **, char ***);

/**
 * -----> Files
 */
void getFilename(char *, char *, char *);
unsigned char *readTextFile(const char *, unsigned long *);
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
void createFrequencyTable(unsigned long *, const unsigned char *, const unsigned long);
int mountList(Node **, const unsigned long *);
Node *generateHuffmanTree(Node *);
void createDictionary(char **, const Node *, char *, int i);
void writeHuffmanEncoding(const unsigned char *, const unsigned long, char **, const int, const char *);
void writeHuffmanFileHeader(const char *, Node *, const int);