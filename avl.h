#ifndef AVL_H
#define AVL_H
#include <QString>
#include "nodo.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

template <class T>
class AVL
{
public:
    AVL();
    void insertar(T);
    Nodo<T>* add(T,Nodo<T>*);
    void EnlazarPadres(Nodo<T>*,Nodo<T>*);
    Nodo<T> *raiz,*nuevaRaiz, *Aux,*Aux2,*retorno,informacion;
    bool match,borrado,apuntado,apuntado2,cambiado;
    int altura(Nodo<T>*);
    int MAX(int, int);
    Nodo<T> *RotacionIzquierda(Nodo<T>*);
    Nodo<T> *RotacionDerecha(Nodo<T>*);
    Nodo<T> *RotacionDobleIzquierda(Nodo<T>*);
    Nodo<T> *RotacionDobleDerecha(Nodo<T>*);
    void eliminar(QString);
    void elim(Nodo<T>*);
    Nodo<T> *caso1(Nodo<T>*);
    Nodo<T> *caso2(Nodo<T>*);
    Nodo<T> *caso3(Nodo<T>*);
    Nodo<T> *buscar(QString,Nodo<T>*,Nodo<T>*);
    bool cambiarValor(Nodo<T> *nuevo, QString val, Nodo<T> *nodo, Nodo<T> *padre);
    void colocarAlturas(Nodo<T>*);
    void reBalanceo(Nodo<T>*);
    bool estaDesbalanceado(Nodo<T>*);
    Nodo<T> *mayorHijo(Nodo<T>*);
    Nodo<T> *recorrerIzquierda(Nodo<T>*);
    Nodo<T> *reestructuracion(Nodo<T>*,Nodo<T>*,Nodo<T>*);
    int comparar(T, T);
    void impreArbol(Nodo<T> *nodo, Nodo<T> *padre);

    std:: ofstream ficheroSalida;
};

#endif // AVL_H
