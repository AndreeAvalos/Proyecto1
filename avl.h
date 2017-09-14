#ifndef AVL_H
#define AVL_H
#include <QString>
#include "nodo.h"

template <typename T>
class AVL
{
public:
    AVL();
    void insertar(T);
    Nodo<T> add(T,Nodo<T>*);
    void EnlazarPadres(Nodo<T>*,Nodo<T>*);
    Nodo<T> *raiz, *Aux,*Aux2,*retorno,informacion;
    bool match,borrado,apuntado,apuntado2;
    void altura(Nodo<T>*);
    T MAX(T,T);
    Nodo<T> RotacionIzquierda(Nodo<T>*);
    Nodo<T> RotacionDerecha(Nodo<T>*);
    Nodo<T> RotacionDobleIzquierda(Nodo<T>*);
    Nodo<T> RotacionDobleDerecha(Nodo<T>*);
    void eliminar(T);
    void elim(Nodo<T>);
    Nodo<T> caso1(Nodo<T>*);
    Nodo<T> caso2(Nodo<T>*);
    Nodo<T> caso3(Nodo<T>*);
    Nodo<T> buscar(T,Nodo<T>*,Nodo<T>*);
    void colocarAlturas(Nodo<T>*);
    void reBalanceo(Nodo<T>*);
    bool estaDesbalanceado(Nodo<T>*);
    Nodo<T> mayorHijo(Nodo<T>*);
    Nodo<T> reestructuracion(Nodo<T>*,Nodo<T>*,Nodo<T>*);
    int comparar(T, T);

};

#endif // AVL_H
