#ifndef TRIENODE_H
#define TRIENODE_H



class TrieNode {

public:

    TrieNode * children[26];

    bool end_of_word;

    char letter;

    TrieNode();
    

};
