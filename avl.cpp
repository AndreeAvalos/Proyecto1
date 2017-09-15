#include "avl.h"
#include "nodo.cpp"

template<typename T>
AVL<T>::AVL()
{
    this->raiz=nullptr;
    this->Aux=this->Aux2=this->nuevaRaiz=this->retorno=nullptr;
    this->apuntado=apuntado2=match=borrado=false;
}

template<typename T>
void AVL<T>::insertar(T val)
{
   this->raiz = add(val , this->raiz);
   EnlazarPadres(this->raiz,nullptr);
}

template<typename T>
Nodo<T>* AVL<T>::add(T valor, Nodo<T> *root)
{
    if(root==nullptr){
        root = new Nodo<T>(valor);
    }
    else if(comparar(valor, root->getValor())<0){
        Nodo<T> *nodoaux = add(valor,root->izquierda);
        root->izquierda= nodoaux;
        if((altura(root->derecha)-altura(root->izquierda))==2){
            if(comparar(valor, root->izquierda->getValor())<0){
                root = RotacionIzquierda(root);
            }else{
                root = RotacionDobleIzquierda(root);
            }
        }
    }else if(comparar(valor,root->getValor())>0){
        Nodo<T> *nodoaux = add(valor,root->derecha);
        root->derecha = nodoaux;

        if((altura(root->derecha)-altura(root->izquierda))==2){
            if(comparar(valor,root->derecha->getValor())>0){
                root=RotacionDerecha(root);

            }else{
                root=RotacionDobleDerecha(root);
            }
        }
    }
    root->altura=(MAX(altura(root->izquierda),altura(root->derecha))+1);
    return root;
}

template<typename T>
void AVL<T>::EnlazarPadres(Nodo<T> *nodo, Nodo<T> *padre)
{
    if(nodo!=nullptr){
        nodo->padre=padre;
        if(nodo->derecha!= nullptr)
            EnlazarPadres(nodo->derecha,nodo);
        if(nodo->izquierda!=nullptr)
            EnlazarPadres(nodo->izquierda,nodo);
    }
}

template<typename T>
int AVL<T>::altura(Nodo<T> *nodo)
{
    if(nodo==nullptr)
        return -1;
    else
        return nodo->altura;
}

template<typename T>
int AVL<T>::MAX(int v1,int v2)
{
    if (v1>v2)
        return v1;
    else
        return v2;

}

template<typename T>
Nodo<T>* AVL<T>::RotacionIzquierda(Nodo<T> *nodo)
{
    Nodo<T> *nodoaux = nodo->izquierda;
    nodo->izquierda=nodo->derecha;
    nodoaux->derecha= nodo;
    nodo->altura = MAX(altura(nodo->izquierda),altura(nodo->derecha))+1;
    nodoaux->altura = MAX(altura(nodoaux->izquierda),nodo->altura)+1;
    return nodoaux;
}

template<typename T>
Nodo<T>* AVL<T>::RotacionDerecha(Nodo<T> *nodo)
{
    Nodo<T> *nodoaux = nodo->derecha;
    nodo->derecha = nodoaux->izquierda;
    nodoaux->izquierda= nodo;
    nodo->altura= MAX(altura(nodo->derecha),altura(nodo->izquierda))+1;
    nodoaux->altura = MAX(altura(nodoaux->derecha),nodo->altura)+1;
    return nodoaux;

}

template<typename T>
Nodo<T>* AVL<T>::RotacionDobleIzquierda(Nodo<T> *nodo){
    nodo->izquierda= RotacionDerecha(nodo->izquierda);
    return RotacionIzquierda(nodo);

}

template<typename T>
Nodo<T>* AVL<T>::RotacionDobleDerecha(Nodo<T> *nodo)
{
   nodo->derecha = RotacionIzquierda(nodo->derecha);
   return RotacionDerecha(nodo);
}

template<typename T>
void AVL<T>::eliminar(QString  valor)
{
    Nodo<T> *nodo = buscar(valor, this->raiz,nullptr);
    match=false;
    EnlazarPadres(this->raiz,nullptr);
    elim(nodo);

}

template<typename T>
void AVL<T>::elim(Nodo<T> *nodo)
{
    bool derecha, izquierda;

   if(nodo->derecha != nullptr)
       derecha = true;
   else
       derecha = false;
   if(nodo->izquierda!=nullptr)
       izquierda = true;
   else
       izquierda = false;
   if(derecha == false && izquierda == false)
       reBalanceo(caso1(nodo));
   if(derecha != false && izquierda ==false)
       reBalanceo(caso2(nodo));
   if(derecha==false && izquierda != false)
       reBalanceo(caso2(nodo));
   if(derecha!=false && izquierda !=false)
       reBalanceo(caso3(nodo));


}

template<typename T>
Nodo<T>* AVL<T>::caso1(Nodo<T> *nodo)
{
    Nodo<T> *nodoPadre;
    if(nodo->padre == nullptr){
        this->raiz==nullptr;
        return nullptr;
    }
    else{
        nodoPadre = nodo->padre;
        Nodo<T> *izquierda,*derecha;
        izquierda = nodoPadre->izquierda;
        derecha = nodoPadre->derecha;

        if(izquierda != nullptr)
            if(izquierda->getValor()==nodo->getValor())
                nodo->padre->derecha=nullptr;
        colocarAlturas(this->raiz);
    }
    return nodoPadre;
}

template<typename T>
Nodo<T>* AVL<T>::caso2(Nodo<T> *nodo)
{
    if(nodo->padre!=nullptr){
        Nodo<T> *hijoizquierdo = nodo->padre->izquierda;
        Nodo<T> *hijoderecho = nodo->padre->derecha;
         Nodo<T> *Actual;
        if(nodo->izquierda!=nullptr)
            Actual=nodo->izquierda;
        else
            Actual=nodo->derecha;

        if(hijoizquierdo==nodo){
            nodo->padre->izquierda=Actual;
            Actual->padre=nodo->padre;
            colocarAlturas(this->raiz);
            return Actual->padre;
        }
        if(hijoizquierdo==nodo){
            nodo->padre->derecha=Actual;
            Actual->padre=nodo->padre;
            colocarAlturas(this->raiz);
            return Actual->padre;
        }

    }else{
        Nodo<T> *der = nodo->derecha;
        Nodo<T> *iz = nodo->izquierda;

        if(der!=nullptr){
            this->raiz=der;
            der->padre= nullptr;
            return der;
        }else if( iz != nullptr){
            this->raiz=iz;
            iz->padre=nullptr;
            return iz;
        }
        colocarAlturas(this->raiz);
    }
    colocarAlturas(this->raiz);
    return nullptr;
}

template<typename T>
Nodo<T>* AVL<T>::caso3(Nodo<T> *nodo)
{
    Nodo<T> *ultimoIzquierda = recorrerIzquierda(nodo->derecha);

    if(ultimoIzquierda==nodo->derecha){
        ultimoIzquierda=nullptr;
    }
    if(ultimoIzquierda!=nullptr){
        if(nodo->padre==nullptr){
            this->raiz=ultimoIzquierda;
            return ultimoIzquierda;
        }else{
            if(nodo->padre->derecha==nodo)
                nodo->padre->derecha=ultimoIzquierda;
            else if(nodo->padre->izquierda==nodo)
                nodo->padre->izquierda=ultimoIzquierda;
        }
        ultimoIzquierda->padre->izquierda=nullptr;
        ultimoIzquierda->izquierda=nodo->izquierda;
        ultimoIzquierda->padre = nodo->padre;

        nodo->izquierda->padre=ultimoIzquierda;
        nodo->derecha->padre=ultimoIzquierda;

        colocarAlturas(this->raiz);
        return nodo->padre;
    }else{
      Nodo<T> *nodoDerecho = nodo->derecha;

      if(nodo->padre==nullptr)
          this->raiz=nodoDerecho;
      else{
          if(nodo->padre->derecha==nodo)
              nodo->padre->derecha=nodoDerecho;
          else if(nodo->padre->izquierda==nodo)
              nodo->padre->izquierda=nodoDerecho;

      }
      nodoDerecho->padre=nodo->padre;
      nodoDerecho->izquierda= nodo->izquierda;
      colocarAlturas(this->raiz);
      return nodoDerecho;
    }
    return nullptr;
}

template<typename T>
Nodo<T>* AVL<T>::buscar(QString valor, Nodo<T> *nodo, Nodo<T> *padre)
{

}

template<typename T>
void AVL<T>::colocarAlturas(Nodo<T> *)
{

}

template<typename T>
int AVL<T>::comparar(T v1, T v2)
{
    int resultado=0;
    if(v1.id<v1.id)
        resultado=-1;

    else if(v1.id>v2.id)
        resultado=1;
    else
        resultado = 0;

    return resultado;
}
