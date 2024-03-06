#ifndef GENERAL_THREE_H
#define GENERAL_THREE_H

#include "GeneralNode.h"

template <class T>
class GeneralThree {
private:
    GeneralNode<T>* root;
public:
    GeneralThree();
    GeneralThree(T& val);
    ~GeneralThree();
    bool isEmpty();
    GeneralNode<T>* getRoot();
    void setRoot(GeneralNode<T>* newRoot);
    bool insertNode(T& parent, T& nodeValue);
    bool deleteNode(T& nodeValue);
    bool search(T& value);
    unsigned int getHeight();
    unsigned int getSize();
    void preOrder();
    void postOrder();
    void levelOrder();
};

#endif // GENERAL_THREE_H
