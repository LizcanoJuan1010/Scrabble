#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryNode.h"

template <class T>
class BinaryTree {
private:
    BinaryNode<T>* root;

    void destroyTree(BinaryNode<T>* node);
    BinaryNode<T>* insert(T val, BinaryNode<T>* node);
    bool search(T val, BinaryNode<T>* node) const;
    void inorderPrint(BinaryNode<T>* node) const;
    void preorderPrint(BinaryNode<T>* node) const;
    void postorderPrint(BinaryNode<T>* node) const;
    unsigned int getHeight(BinaryNode<T>* node) const;
    unsigned int getSize(BinaryNode<T>* node) const;

public:
    BinaryTree();
    ~BinaryTree();

    void insert(T val);
    bool search(T val) const;
    void destroyTree();
    void inorderPrint() const;
    void preorderPrint() const;
    void postorderPrint() const;
    unsigned int getHeight() const;
    unsigned int getSize() const;
};

#endif // BINARYTREE_H