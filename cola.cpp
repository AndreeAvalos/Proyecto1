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

                 first = nuevo;
                 size++;
                 return;
             }

             //Actualmente solo hay un elemento en la lista
             if(first->sig == nullptr) {
                 //Se compara el valor nuevo a insertar contra el unico valor que existe en la lista
                 int comparison = comparar(first->getValor().prioridad,val.prioridad);
                 int comparison2 = comparar(first->getValor().prioridad2,val.prioridad2);
                 //Si el valor nuevo es mayor que el unico valor de la lista,
                 //insertar despues del primero, en otras palabras INSERTAR AL FINAL
                 if(comparison > 0) {

                     first->sig = nuevo;
                     size++;
                     return;
                 }


                 //Si el valor nuevo es menor que el unico valor de la lista,
                 //insertar antes del primero, en otras palabras INSERTAR AL INICIO
                 if(comparison < 0) {

                     nuevo->sig = first;
                     first = nuevo;
                     size++;
                     return;
                 }
                 if(comparison==0){
                     if(comparison2 > 0) {

                         first->sig = nuevo;
                         size++;
                         return;
                     }


                     //Si el valor nuevo es menor que el unico valor de la lista,
                     //insertar antes del primero, en otras palabras INSERTAR AL INICIO
                     if(comparison2 <= 0) {

                         nuevo->sig = first;
                         first = nuevo;
                         size++;
                         return;
                     }

                 }

                 //Si no es mayor, ni tampoco es menor, entonces los elementos son iguales...

                 return;
             }

             //Nodo auxiliar para recorrer la lista, se busca el punto de insercion correcto
             //Como la lista esta ordenada la nueva insercion tiene que ser justo antes del
             //primer elemento que sea "menor" que el valor nuevo.
             Nodo<T> *aux = first;
             Nodo<T> *ant = nullptr;
              int comparison;
              int comparison2;
             while(aux->sig != nullptr){
                 comparison = comparar(aux->getValor().prioridad,val.prioridad);
                 comparison2 = comparar(aux->getValor().prioridad2,val.prioridad2);

                 //Es necesario evaluar el siguiente elemento
                 if(comparison > 0) {
                     ant = aux;
                     aux = aux->sig;
                     continue;
                 }

                 //El nuevo elemento va entre el elemento apuntado por ANT y AUX
                 if(comparison < 0) {
                     if(ant==nullptr) {

                         nuevo->sig = first;
                         first = nuevo;
                     } else {

                         ant->sig = nuevo;
                         nuevo->sig = aux;
                     }
                     size++;
                     return;
                 }
                 if(comparison==0){

                     if(comparison2 > 0) {
                         ant = aux;
                         aux = aux->sig;
                         continue;
                     }

                     //El nuevo elemento va entre el elemento apuntado por ANT y AUX
                     if(comparison2 <= 0) {
                         if(ant==nullptr) {

                             nuevo->sig = first;
                             first = nuevo;
                         } else {

                             ant->sig = nuevo;
                             nuevo->sig = aux;
                         }
                         size++;
                         return;
                     }
                 }

                 return;
             }

             comparison = comparar(aux->getValor().prioridad,val.prioridad);
             comparison2 = comparar(aux->getValor().prioridad2,val.prioridad2);
             if(comparison > 0) {
                 aux->sig = nuevo;
             }
             if(comparison < 0) {
                 if(ant==nullptr) {
                     nuevo->sig = first;
                     first = nuevo;
                 } else {
                     ant->sig = nuevo;
                     nuevo->sig = aux;

                 }
             }

             if(comparison==0){
                 if(comparison2 > 0) {
                     aux->sig = nuevo;
                 }
                 if(comparison2 <= 0) {
                     if(ant==nullptr) {
                         nuevo->sig = first;
                         first = nuevo;
                     } else {
                         ant->sig = nuevo;
                         nuevo->sig = aux;

                     }
                 }
             }
             size++;
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
           qInfo()<<temp->getValor().titulo;
            temp = temp->sig;
        }
    }
}

template<class T>
int Cola<T>::comparar(int val1, int val2)
{
    if(val1>val2)
        return -1;
    else if(val1<val2)
        return 1;
    else
        return 0;
}

