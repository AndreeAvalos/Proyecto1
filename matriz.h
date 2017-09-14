#ifndef MATRIZ_H
#define MATRIZ_H
#include "listadobleenlazada.h"
#include "nodo.h"
#include <QString>

template<class T>
class Matriz
{
public:
    Matriz();
    void insertar(T,T,T);
    ListaDobleEnlazada<T> *lstHorizontal, *lstVertical;
    int size;
};

#endif // MATRIZ_H
