#include "nodo.h"

//Instancia de nodo sin valor
template <typename T>
Nodo<T>::Nodo()
{
    this->abajo=this->arriba=this->derecha=this->izquierda=this->principal=nullptr;
    this->raiz=nullptr;
    this->altura=0;
    this->padre=nullptr;
    this->sig=this->ant=nullptr;

}
//Instancia de nodo con Valor
template <typename T>
Nodo<T>::Nodo(T val)
{
    this->abajo=this->arriba=this->derecha=this->izquierda=this->principal=nullptr;
    this->val=val;
    this->x=this->y="";
    this->raiz=nullptr;
    this->altura=0;
    this->padre=nullptr;
    this->sig=this->ant=nullptr;

}
//Obtener el valor del nodo
template<typename  T>
T Nodo<T>::getValor(){
    return this->val;
}
//Dar valor al nodo
template<typename T>
void Nodo<T>::setValor(T val){
    this->val=val;
}
template<typename T>
QString Nodo<T>::getX(){
    return this->x;
}
template<typename T>
QString Nodo<T>::getY(){
    return this->y;
}
/*
template<typename T>
Nodo<T>::Nodo(T horizontal, T vertical, T valor){
    this->x= horizontal;
    this->y= vertical;
    this->val=valor;
}
*/

template<class T>
Nodo<T>::Nodo(T val, QString horizontal, QString vertical)
{
    this->abajo=this->arriba=this->derecha=this->izquierda=this->principal=nullptr;

    this->val=val;
    this->x=horizontal;
    this->y=vertical;

    this->raiz=nullptr;
    this->altura=0;
    this->padre=nullptr;
    this->sig=this->ant=nullptr;
}

/*
template<typename T>
int Nodo<T>::comparar(T val){
    this->getValor().titulo.compare(val.titulo);
}
*/

//---------------------------PARA AVL--------------------------
template <typename T>
int Nodo<T>::getAltura(){
    int val1=0;
    int val2=0;
    if(this->izquierda!=nullptr)
        val1=izquierda.getAltura();

    if(derecha!=nullptr)
        val2=derecha.getAltura();

    if(val1 != 0 && val2 !=0 ){
        if (val1 < val2)
            altura=val2+1;
        else if (val1>val2)
            altura = val1+1;
        else
            altura=val1+1;
    }else{
        if (val1==0)
            altura= val1+1;
        else if (val2==0)
            altura = val2+1;
        else
            altura = 0;
    }
    return altura;
}

template <typename T>
int Nodo<T>::getFE(){
    int val1=0;
    int val2=0;

    if(this->izquierda!=nullptr)
        val1=izquierda.getAltura();

    if(derecha!=nullptr)
        val2=derecha.getAltura();
    return val2-val1;

}
//-------------------------------------------------------
