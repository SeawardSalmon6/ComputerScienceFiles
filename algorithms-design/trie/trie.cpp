#include "trie.h"
#include <stdexcept>
#include <iostream>

Trie::Trie(unsigned alphabetSize)
    : amountOfKeysStored(0)
{
  TrieNode::alphabetSize = alphabetSize;
}

bool Trie::search(const std::string key)
{

  /* Não são permitidas buscas nulas */
  if (key.empty())
    throw std::invalid_argument("The string must have some chars");

  /* chama o método recursivo get que fará a busca na árvore */
  TrieNode *x = get(trieRoot, key, 0);

  /* Chave não encontrada */
  if (x == nullptr)
    return false;

  /* se isLeaf == true então a chave foi encontrada */
  return true;
}

void Trie::searchByPrefix(const std::string prefix)
{
  /* Não são permitidas buscas nulas */
  if (prefix.empty())
    throw std::invalid_argument("The string must have some chars");

  /* chama o método recursivo getByPrefix que fará a busca na árvore */
  char *word = (char *)calloc(256, sizeof(char));
  bool res = getByPrefix(trieRoot, prefix, word, 0);

  /* Clears memory from word variable */
  free(word);
  word = NULL;

  /* Chave não encontrada */
  if (!res)
    std::cout << "Prefix \"" << prefix << "\" doesn't have any correspondences!";
  std::cout << std::endl;
}

bool Trie::getByPrefix(TrieNode *x, const std::string prefix, char *word, int trieLevel)
{
  /* Nó nulo a chave não se encontra na árvore */
  if (x == nullptr)
    return false;

  /*
   * Se a profundidade da árvore (trieLevel) for igual a quantidade de caracteres
   * (key.length()) então a chave tem um cadidato a "hit" se este nó for uma folha
   * (isLeafe() == true) então se tem um "hit" se não se tem um "miss"
   */
  if (trieLevel == prefix.length())
  {
    printWord(x, word, trieLevel);
    return true;
  }

  /*
   * Elemento não encontrado, recupera o próximo caractere e reinicia as
   * verificações com uma chamada recursiva
   */
  unsigned char c = prefix[trieLevel];
  word[trieLevel] = c;
  return getByPrefix(x->arrSubTries[c], prefix, word, trieLevel + 1);
}

void Trie::printWord(TrieNode *x, char *word, int trieLevel)
{
  for (int i = 0; i < TrieNode::alphabetSize; i++)
    if (x->arrSubTries[i])
    {
      word[trieLevel] = i;
      printWord(x->arrSubTries[i], word, trieLevel + 1);
    }

  if (x->isLeaf)
  {
    word[trieLevel] = '\0';
    std::cout << word << std::endl;
  }
}

TrieNode *Trie::get(TrieNode *x, const std::string key, int trieLevel)
{
  /* Nó nulo a chave não se encontra na árvore */
  if (x == nullptr)
    return nullptr;

  /*
   * Se a profundidade da árvore (trieLevel) for igual a quantidade de caracteres
   * (key.length()) então a chave tem um cadidato a "hit" se este nó for uma folha
   * (isLeafe() == true) então se tem um "hit" se não se tem um "miss"
   */
  if (trieLevel == key.length())
  {
    if (x->isLeaf)
      return x;
    else
      return nullptr;
  }

  /*
   * Elemento não encontrado, recupera o próximo caractere e reinicia as
   * verificações com uma chamada recursiva
   */
  unsigned char c = key[trieLevel];
  return get(x->arrSubTries[c], key, trieLevel + 1);
}

void Trie::insert(const std::string key)
{
  /* Não são permitidas inserções nulas */
  if (key.empty())
    throw std::invalid_argument("The string must have some chars");

  /* chama o método recursivo add que fará a inserção na árvore */
  trieRoot = add(trieRoot, key, 0);
}

TrieNode *Trie::add(TrieNode *x, const std::string key, int trieLevel)
{
  /*
   * Se o nó é nulo então a chave completa não está na árvore, é necessário criar
   * um novo nó para alocar tal caractere, perceba que este nó deve ser do tamanho
   * do alfabeto adotado
   */
  if (x == nullptr)
  {
    x = new TrieNode();
    x->setAlphabetSize(TrieNode::alphabetSize);
  }

  /*
   * Se a profundidade da árvore (trieLevel) for igual a quantidade de caracteres
   * (key.length()) então a chave está completa dentro da árvore;
   */
  if (trieLevel == key.length())
  {

    /*
     * Há que se verificar se a chave encontrada NÃO é uma folha. Caso NÃO seja
     * incrementa o indicador de quantidade de chaves armazenadas
     */
    if (!x->isLeaf)
    {
      this->amountOfKeysStored++;
    }

    /* Marca como folha */
    x->isLeaf = true;

    /* Retorna a folha inserida */
    return x;
  }

  /*
   * Se a profundidade da árvore (trieLevel) ainda não for igual a quantidade de
   * caracteres (key.length()) então prepara uma chamada recursiva para
   * verficação/criação de um novo nó
   */
  unsigned char c = key[trieLevel];
  x->arrSubTries[c] = add(x->arrSubTries[c], key, trieLevel + 1);

  /* Retorna a folha inserida */
  return x;
}

void Trie::deleteNode(const std::string key)
{

  /* Não são permitidas inserções nulas */
  if (key.empty())
    throw std::invalid_argument("The string must have some chars");

  /* chama o método recursivo get que fará a remoção na árvore */
  trieRoot = deleteNode(trieRoot, key, 0);
}

TrieNode *Trie::deleteNode(TrieNode *x, std::string key, int trieLevel)
{

  /* Nó nulo a chave não se encontra na árvore */
  if (x == nullptr)
    return nullptr;

  /*
   * Se a profundidade da árvore (trieLevel) for igual a quantidade de caracteres
   * (key.length()) então a chave tem um cadidato a remoção.
   */
  if (trieLevel == key.length())
  {
    /*
     * Se este nó for uma folha (isLeafe() == true) então o nó é desmarcado como
     * folha e a contagem de item da trie é decrementada
     */
    if (x->isLeaf)
      amountOfKeysStored--;

    x->isLeaf = false;
  }
  else
  {

    /*
     * Se a profundidade da árvore (trieLevel) ainda não for igual a quantidade de
     * caracteres (key.length()) então prepara uma chamada recursiva para
     * verficação/remoção de próximo nó
     */
    unsigned char c = key[trieLevel];
    x->arrSubTries[c] = deleteNode(x->arrSubTries[c], key, trieLevel + 1);
  }

  /*
   * Na volta das chamadas recursivas, no momento em que uma folha for encontrada a
   * deleção da árvore é terminada retornando-se um nó válido
   */
  if (x->isLeaf)
    return x;

  /*
   * Se o nó não é valido, anula todos os nós abaixo deste e, em seguinda, retorna
   * um endereço nulo para o nivel acima
   */
  for (int i = 0; i < TrieNode::alphabetSize; i++)
    if (x->arrSubTries[i] != nullptr)
      return x;

  delete x;
  return nullptr;
}