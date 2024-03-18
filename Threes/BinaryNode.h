#ifndef BINARYNODE_H
#define BINARYNODE_H

template <class T>
class BinaryNode {
public:
    T data;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

#endif // BINARYNODE_H
