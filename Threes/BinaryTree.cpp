#include "BinaryTree.h"

template <class T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <class T>
BinaryTree<T>::~BinaryTree() {
    destroyTree(root);
}

template <class T>
void BinaryTree<T>::insert(T val) {
    root = insert(val, root);
}

template <class T>
BinaryNode<T>* BinaryTree<T>::insert(T val, BinaryNode<T>* node) {
    if (!node) {
        return new BinaryNode<T>(val);
    }
    if (val < node->data) {
        node->left = insert(val, node->left);
    } else {
        node->right = insert(val, node->right);
    }
    return node;
}

template <class T>
bool BinaryTree<T>::search(T val, BinaryNode<T>* node) const {
    if (!node) {
        return false;
    } else if (val == node->data) {
        return true;
    } else if (val < node->data) {
        return search(val, node->left);
    } else {
        return search(val, node->right);
    }
}

template <class T>
void BinaryTree<T>::destroyTree(BinaryNode<T>* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Implementación de inorderPrint, preorderPrint, postorderPrint, getHeight y getSize omitida por brevedad.
// Recuerda incluir la lógica para recorrer el árbol y procesar los nodos de forma adecuada.

// No olvides instanciar tu clase para los tipos específicos que usarás, como int, si decides separar la implementación en un archivo .cpp.
