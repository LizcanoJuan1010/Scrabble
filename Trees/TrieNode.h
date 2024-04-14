#ifndef TRIENODE_H
#define TRIENODE_H

#include "letter"


class TrieNode {
private:
   TrieNode * children[26];

    bool end_of_word;

    char letter;

public:

    TrieNode();
    

}







#endif // TRIENODE_H