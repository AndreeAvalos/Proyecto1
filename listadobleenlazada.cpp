#include "listadobleenlazada.h"

//Metodo para inicializar
template <typename T>
ListaDobleEnlazada<T>::ListaDobleEnlazada()
{
    this->first=this->last=nullptr;
    this->size=0;
}

//Metodo para verificar si esta vacia
template <typename T>
bool ListaDobleEnlazada<T>::empty()
{
    if(this->first==nullptr){//Si el nodo esta vacia regresa true
        return true;
    }
    return false;
}

//Metodo para insertar datos
template<typename T>
void ListaDobleEnlazada<T>::add(T val){
    //Creamos un nodo nuevo
    Nodo<T> *nuevo = new Nodo<T>();

    //Verificamos si el nodo esta vacia
    if(!empty()){
        first= nuevo;//El primero se vuelve el nuevo
        first->sig=first;// el siguiente va ser el mismo
        first->ant=first;// el anterior va ser el mismo
        last=first;// el ultimo va ser igual al primero
        //aumentamos el tamano de la lista
        size++;
        return;
    }else{
        last->sig=nuevo;//agregamos el nodo al final y lo apuntamos
        nuevo->sig=first;// el siguient del nuevo es el primero
        nuevo->ant=last;//el anterior del nuevo va ser el ultimo
        last=nuevo;//el nodo ultimo toma el valor del nuevo
        first->ant=last;//el primero apunta hacia el ultimo
        //aumentamos el tamano de la lista
        size++;
        return;
    }

}

template <typename T>
T ListaDobleEnlazada<T>::search(T val){
    Nodo<T> *temp = first;
/*
    while(temp->sig != first){
        if(temp->getValor()){

        }
    }*/
}
