#ifndef THREEMAIN.H
#define THREEMAIN.H

template <class T>
class Generalthree {
private:
generalnode<T>* root;
public:
Generalthree();
Generalthree(T& val);
~Generalthree();
bool isEmpty();
Generalnode<T>* getroot();
void setroot(generalnode<T>* nraiz);
bool inserternode(T& padre, T& n);
bool deleternode(T& n);
bool Search(T& n);
unsigned int height();
unsigned int size();
void preOrder();
void posOrder();
void Orderlevel();
};


#endif // THREEMAIN.H