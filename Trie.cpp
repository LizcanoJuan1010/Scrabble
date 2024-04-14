#include "Trie.h"
#include <string>
#include <iostream>



void Trie::insert(std::string word) {

    TrieNode * current = &root;
        for (size_t i = 0; i < word.size(); i++) {
            if (current->children[word.at(i)-'a'] == NULL) {
                current->children[word.at(i)-'a'] = new TrieNode;
                current->children[word.at(i)-'a']->letter = word.at(i);
            }
            current = current->children[word.at(i)-'a'];
        }
        current->end_of_word = true;
}


TrieNode * Trie::search (std::string Word) {
        TrieNode * current = &root;
        for (size_t i = 0; i < Word.size(); i++) {
            if (current->children[Word.at(i)-'a']) {
                current = current->children[Word.at(i)-'a'];
             } else {
                current = NULL;
                break;
             }
        }
        return current;
    }



       void Trie::PrintLexical (TrieNode * current, std::string prefix, std::string suffix) {
        if (current->end_of_word and suffix.size() != 0) {
            std::cout << prefix+suffix << std::endl;
        }
        for (int i=0; i<26; i++) {
            std::string temp = suffix;
            if (current->children[i]) {
                temp += current->children[i]->letter;
                PrintLexical(current->children[i], prefix, temp);
            }
        }
    }
