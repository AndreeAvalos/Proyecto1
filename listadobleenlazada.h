#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H
#include "nodo.h"

template <class T>
class ListaDobleEnlazada
{
public:
    ListaDobleEnlazada();
    void add(T);
    bool empty();
    int getSize();
    Nodo<T> buscar(QString nombre);
private:
    Nodo<T> *first,*last;
    int size;
};

#endif // LISTADOBLEENLAZADA_H
