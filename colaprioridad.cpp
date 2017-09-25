#include "colaprioridad.h"

template<typename T>
ColaPrioridad<T>::ColaPrioridad()
{

}

template<class T>
void ColaPrioridad<T>::push(T val, int prioridad1, int prioridad2, Cola<T> *a)
{
    try{
        // Inserta el dato en la cola almacenada en la prioridad indicada
        a[prioridad1][prioridad2].push(val);
    }catch(int e){
        qInfo() << "OUT OF MEMORY: ";
    }

}
