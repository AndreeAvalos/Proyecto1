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
};

#endif // LISTASIMPLE_H
