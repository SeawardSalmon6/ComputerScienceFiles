#ifndef TRIENODE_H
#define TRIENODE_H

#include <vector>

class TrieNode {

public:
    bool isLeaf;
    static unsigned alphabetSize;
    std::vector<TrieNode*> arrSubTries;

    TrieNode();
    void setAlphabetSize(unsigned alphabetSize);
};
#endif // TRIENODE_H