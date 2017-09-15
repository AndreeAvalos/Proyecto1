#include "listasimple.h"

template<typename T>
ListaSimple<T>::ListaSimple()
{
    this->first=nullptr;
    this->size=0;
}

template <typename T>
void ListaSimple<T>::agregar(T val){
    Nodo<T> *nuevo= new Nodo<T>(val);
    if(first==nullptr){
        first=nuevo;
        size++;
        return;
    }else{
        nuevo->sig=first;
        first=nuevo;
        size++;
        return;
    }
}
