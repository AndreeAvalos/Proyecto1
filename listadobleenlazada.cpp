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

template<class T>
Nodo<T> ListaDobleEnlazada<T>::buscar(QString nombre)
{
    if(first != nullptr){//comparamos si la lista esta vacia
        Nodo<T> *temp = first;// creamos un nodeo temporal

        while(temp!=nullptr){//Mientras el temporal no sea igual al imero entonces que siga recorriendo
            if(temp->getValor().nombre==nombre)//si el valor del nombre es igual al valor mandado entonces regresamos el nodo
                return temp;//retornamos el nodo
            else
                temp = temp->sig;// de lo contrario sigue
        }
    } else{
        return nullptr;// si no exite devolvemos nulo
    }
}

//Metodo para insertar datos
template<typename T>
void ListaDobleEnlazada<T>::add(T val){
    //Creamos un nodo nuevo
    Nodo<T> *nuevo = new Nodo<T>();

    //Verificamos si el nodo esta vacia
    if(!empty()){
        first=nuevo;//el primer nodo va ser igual al nodo nuevo
        size++;//aumentamos el valor de la lista
        return;
    }else{
        nuevo->sig=first;//apuntamos el nuevo hacia el primero
        first->ant=nuevo;//apuntamos el primero hacia el nuevo
        first= nuevo;//decimos que el primero va ser el nuevo nodo
        //aumentamos el tamano de la lista
        size++;
        return;
    }

}

