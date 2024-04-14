#include "Trie.h"
#include <string>
#include <iostream>
void Trie::insert(std::string word) {
    TrieNode * current = &root;
        for (size_t i = 0; i < str.size(); i++) {
            if (current->children[str.at(i)-'a'] == NULL) {
                current->children[str.at(i)-'a'] = new TrieNode;
                current->children[str.at(i)-'a']->letter = str.at(i);
            }
            current = current->children[str.at(i)-'a'];
        }
        current->end_of_word = true;
}


TrieNode * Search (string str) {
        TrieNode * current = &root;
        for (size_t i = 0; i < str.size(); i++) {
            if (current->children[str.at(i)-'a']) {
                current = current->children[str.at(i)-'a'];
             } else {
                current = NULL;
                break;
             }
        }
        return current;
    }



       void Trie::PrintLexical (TrieNode * current, string prefix, string suffix) {
        if (current->end_of_word and suffix.size() != 0) {
            cout << prefix+suffix << endl;
        }
        for (int i=0; i<26; i++) {
            string temp = suffix;
            if (current->children[i]) {
                temp += current->children[i]->letter;
                PrintLexical(current->children[i], prefix, temp);
            }
        }
    }
