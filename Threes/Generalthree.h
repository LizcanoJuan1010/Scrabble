#ifndef GENERAL_TREE_H
#define GENERAL_TREE_H

#include "GeneralNode.h"

template <class T>
class GeneralTree {
private:
    GeneralNode<T>* root;
public:
    GeneralTree();
    GeneralTree(T& val);
    ~GeneralTree();
    bool isEmpty();
    GeneralNode<T>* getRoot();
    void setRoot(GeneralNode<T>* newRoot);
    bool insertNode(T& parent, T& nodeValue);
    bool deleteNode(T& nodeValue);
    bool search(T& value);
    unsigned int getHeight();
    unsigned int getSize();
    void preOrder(int n);
    void postOrder();
    void levelOrder();
};

#endif // GENERAL_TREE_H