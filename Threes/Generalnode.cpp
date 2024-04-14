#include "GeneralNode.h"

template<class T>
GeneralNode<T>::~GeneralNode() {
    CleanList();
}

template<class T>
T& GeneralNode<T>::getData() {
    return data;
}

template<class T>
void GeneralNode<T>::setData(const T& val) {
    data = val;
}

template<class T>
void GeneralNode<T>::CleanList() {
    for (auto child : desc) {
        delete child; 
    }
    desc.clear(); 
}

template<class T>
void GeneralNode<T>::addDesc(const T& nval) {
    GeneralNode<T>* newNode = new GeneralNode<T>(nval); 
    desc.push_back(newNode); 
}

template<class T>
void GeneralNode<T>::deleteDesc(const T& val) {
    for (auto it = desc.begin(); it != desc.end(); ) {
        if ((*it)->getData() == val) {
            delete *it; 
            it = desc.erase(it); 
        } else {
            ++it; 
        }
    }
}