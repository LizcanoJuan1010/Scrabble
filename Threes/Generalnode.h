#ifndef GENERALNODE_H
#define GENERALNODE_H

#include <list>

template<class T>
class GeneralNode {
protected:
    T data;
    std::list<GeneralNode<T>*> desc;

public:
    GeneralNode() : data(T()) {} 
    GeneralNode(T val) : data(val) {} 

    ~GeneralNode();

    T& getData();
    void setData(const T& val);

    void CleanList();
    void addDesc(const T& nval);
    void deleteDesc(const T& val);
};

#endif // GENERALNODE_H