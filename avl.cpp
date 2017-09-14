#include "avl.h"
template<typename T>
AVL<T>::AVL()
{

}

template<typename T>
void AVL<T>::insertar(T val)
{
   this->raiz = add(val , this->raiz);
   EnlazarPadres(this->raiz,nullptr);
}

template<typename T>
Nodo<T> AVL<T>::add(T valor, Nodo<T> *root)
{
    if(root==nullptr){
        root = new Nodo<T>(valor);
    }
    else if(comparar(valor, root->getValor())<0){
        Nodo<T> *nodoaux = add(valor,root->izquierda);
        root->izquierda= nodoaux;
        if((altura(root->derecha)-altura(root->izquierda))==2){
            if(comparar(valor, root->izquierda.getValor())<0){
                root = RotacionIzquierda(root);
            }else{
                root = RotacionDobleIzquierda(root);
            }
        }
    }else if(comparar(valor,root->getValor())>0){
        Nodo<T> *nodoaux = add(valor,root->derecha);
        root->derecha = nodoaux;

        if((altura(root->derecha)-altura(root->izquierda))==2){
            if(comparar(valor,root->derecha.getValor())>0){
                root=RotacionDerecha(root);

            }else{
                root=RotacionDobleDerecha(root);
            }
        }
    }
    root->altura=(MAX(altura(root->izquierda),altura(root->derecha))+1);
    return root;
}
