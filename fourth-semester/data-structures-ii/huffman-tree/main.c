#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

int main()
{
  char textFilename[SIZE], hufFilename[SIZE], uncompressedFilename[SIZE];
  int lettersCount, op, height;
  unsigned long filesize;
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
      text = readTextFile(textFilename, &filesize);
      freqTable = (unsigned long *)calloc(SIZE, sizeof(unsigned long));
      if (!freqTable)
      {
        printf("\n!--> Erro ao alocar memória para a tabela!\n\n");
        exit(1);
      }

      createFrequencyTable(freqTable, text, filesize);

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

      writeHuffmanEncoding(text, filesize, dictionary, height, hufFilename);
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