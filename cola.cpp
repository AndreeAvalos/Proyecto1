#include "cola.h"
#include "nodo.cpp"
#include <QDebug>

template<typename T>
Cola<T>::Cola()
{
    this->first=this->last=nullptr;
    this->size=0;
}

template<class T>
void Cola<T>::push(T val)
{
    Nodo<T> *nuevo = new Nodo<T>(val);
    if(first==nullptr){
        first=nuevo;
        last=nuevo;
        size++;
    }else{
        last->sig=nuevo;
        last=nuevo;
        size++;
    }
}

template<class T>
bool Cola<T>::pop()
{
    if(first==nullptr){
        return false;
    }else{
        Nodo<T> *temp = first;
        temp = temp->sig;
        first=temp;
        size--;
        return true;
    }
}

template<class T>
void Cola<T>::imprimir()
{
    Nodo<T> *temp = first;
    if(temp==nullptr){
       qInfo() << "No existe nada";
    }else{
        Nodo<T> *temp = first;

        while(temp!=nullptr){
           qInfo()<<temp->getValor();
            temp = temp->sig;
        }
    }
}
