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
    Nodo<T> * buscar(QString id);
    Nodo<T> *first, *last;
    int comparar(int val1, int val2);
};

#endif // COLA_H
