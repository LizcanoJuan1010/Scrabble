#include "GeneralTree.h"

template <class T>
GeneralTree<T>::GeneralTree() : root(nullptr) {}

template <class T>
GeneralTree<T>::GeneralTree(T& val) {
    root = new GeneralNode<T>();
    root->setData(val);
}

template <class T>
GeneralTree<T>::~GeneralTree() {
    if (root != nullptr) {
        delete root;
    }
}

template <class T>
bool GeneralTree<T>::isEmpty() {
    return root == nullptr;
}

template <class T>
GeneralNode<T>* GeneralTree<T>::getRoot() {
    return root;
}

template <class T>
void GeneralTree<T>::setRoot(GeneralNode<T>* newRoot) {
    root = newRoot;
}

// Los métodos insertNode, deleteNode, search, getHeight, getSize, preOrder, postOrder, y levelOrder
// son más complejos y requieren una implementación específica basada en la estructura y necesidades
// de tu árbol. A continuación, se proporciona un esquema básico para insertNode como ejemplo.

template <class T>
<<<<<<< Updated upstream
bool GeneralThree<T>::deleteNode(T& nodeValue){}

template <class T>
bool GeneralThree<T>::search(T& value){}

template <class T>
unsigned int GeneralThree<T>::getHeight(){}

template <class T>
unsigned int GeneralThree<T>::getSize(){}

template <class T>
void GeneralThree<T>::preOrder(int n){
    if (n.isLeaf()== NULL || n.isRight() == NULL) 
    {
        return;
    } void GeneralThree<T>::preOrder(int n.isLeaf())
    
    void GeneralThree<T>::preOrder(int n.isRight())

}

template <class T>
void GeneralThree<T>::postOrder(){}

template <class T>
void GeneralThree<T>::levelOrder(){}








=======
bool GeneralTree<T>::insertNode(T& parent, T& nodeValue) {
    if (isEmpty()) {
        root = new GeneralNode<T>();
        root->setData(nodeValue);
        return true;
    } else {
        // Esta función necesita ser implementada para buscar el nodo padre adecuado
        // y luego insertar el nuevo nodo como un descendiente de ese nodo.
        // Es un proceso que típicamente se hace de manera recursiva.
        return false; // Placeholder
    }
}
>>>>>>> Stashed changes

// Implementa las otras funciones siguiendo una lógica similar a la de insertNode,
// ajustándolas a las operaciones específicas que realizan.

