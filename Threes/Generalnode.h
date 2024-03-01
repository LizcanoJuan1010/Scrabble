#ifndef GENERALNODE.H
#define GENERALNODE.H

#include <list>
template< class T >
class Generalnode {
protected:
T data;
std::list <generalnode<T>*> desc;
public:
Generalnode();
~Generalnode();
T& getData();
void setData(T& val);
void CleanList();
void addDesc(T& nval);
void deleteDesc(T& val);
};

#endif // GENERALNODE.H