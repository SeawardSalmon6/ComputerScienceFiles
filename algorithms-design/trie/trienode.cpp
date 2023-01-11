#include "trienode.h"

TrieNode::TrieNode()
    : isLeaf(false)
{
}

unsigned TrieNode::alphabetSize = 0;

void TrieNode::setAlphabetSize(unsigned alphabetSize)
{
    TrieNode::alphabetSize = alphabetSize;
    this->arrSubTries.resize(alphabetSize);
}