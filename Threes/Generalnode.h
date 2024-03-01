#ifndef GENERALNODE_H // Corregir la directiva del preprocesador
#define GENERALNODE_H

#include <list> // Asegurar la inclusión de la biblioteca para std::list

template<class T>
class GeneralNode { // Normalizar la nomenclatura
protected:
    T data;
    std::list<GeneralNode<T>*> desc; // Corregir el tipo de los elementos de la lista

public:
    GeneralNode() {} // Constructor por defecto

    ~GeneralNode() { // Destructor
        CleanList();
    }

    T& getData() {
       
    }

    void setData(T& val) {
      
    }

    void CleanList() {
    
    }

    void addDesc(T& nval) {
       
    }

    void deleteDesc(T& val) {
       
    }
};

#endif // GENERALNODE_H
