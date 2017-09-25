#ifndef COLA_H
#define COLA_H
#include "nodo.h"
template <class T>
class Cola
{
public:
    Cola();
    void push(T);
    bool pop();
    void imprimir(void);
    int size;
    Nodo<T> * buscar(int indice);
    Nodo<T> *first, *last;
};

#endif // COLA_H
