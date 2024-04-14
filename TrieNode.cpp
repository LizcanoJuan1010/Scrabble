#include "TrieNode.h"
#include <string>



TrieNode::TrieNode() {
   end_of_word = false;
    for (int i = 0; i < 26; i++) {
        children[i] = NULL;
    }
    letter = '\0';
}
