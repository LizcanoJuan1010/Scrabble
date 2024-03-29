
#ifndef TRIENODE_H
#define TRIENODE_H
#include <string>
class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;
    TrieNode();
    TrieNode *getNode();
    void insert(TrieNode *root, std::string key);
    bool search(struct TrieNode *root, std::string key);
};

#endif // TRIENODE_H
