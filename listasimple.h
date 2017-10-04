#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "nodo.h"

template <class T>
class ListaSimple
{
public:
    ListaSimple();
    void agregar(T);
    Nodo<T> *first;
    int size;
    T getValor();
private:
    T val;
};

#endif // LISTASIMPLE_H
