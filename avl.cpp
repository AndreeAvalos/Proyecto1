#include "avl.h"
#include <QtDebug>
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
    if(val.id=="O090"){
        qInfo()<<"Aqui";
    }
   this->raiz = add(val, this->raiz);
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
        if((altura(root->derecha)-altura(root->izquierda))==-2){
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
    nodo->setAltura( MAX(altura(nodo->izquierda),altura(nodo->derecha))+1);
    nodoaux->setAltura(MAX(altura(nodoaux->izquierda),nodo->getAltura())+1);
    return nodoaux;
}

template<typename T>
Nodo<T>* AVL<T>::RotacionDerecha(Nodo<T> *nodo)
{
    Nodo<T> *nodoaux = nodo->derecha;
    nodo->derecha = nodoaux->izquierda;
    nodoaux->izquierda= nodo;
    nodo->setAltura( MAX(altura(nodo->derecha),altura(nodo->izquierda))+1);
    nodoaux->setAltura( MAX(altura(nodoaux->derecha),nodo->getAltura())+1);
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
        this->raiz=nullptr;
        return nullptr;
    }
    else{
        nodoPadre = nodo->padre;
        Nodo<T> *izquierda,*derecha;
        izquierda = nodoPadre->izquierda;
        derecha = nodoPadre->derecha;

        if(izquierda != nullptr)
            if(izquierda->getValor().id==nodo->getValor().id)
                nodo->padre->izquierda=nullptr;
        if (derecha!=nullptr)
            if(derecha->getValor().id==nodo->getValor().id)
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
        if(hijoderecho==nodo){
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
        ultimoIzquierda->derecha=nodo->derecha;
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
    //return nullptr;
}

template<typename T>
Nodo<T>* AVL<T>::buscar(QString valor, Nodo<T> *nodo, Nodo<T> *padre)
{
    if(nodo!=nullptr){
        if(padre== nullptr){
            if(valor.compare(nodo->getValor().id)>0)
                buscar(valor,nodo->derecha,nodo);
            else if (valor.compare(nodo->getValor().id)<0)
                buscar(valor,nodo->izquierda,nodo);
            else{
                this->retorno = nodo;
                return this->retorno;
            }
        }
        else{
            if(valor ==nodo->getValor().id){
                this->match=true;
                retorno=nodo;

            }else{
                if(this->match!=true){
                    if(valor>nodo->getValor().id)
                        buscar(valor,nodo->derecha,nodo);
                    else
                        buscar(valor,nodo->izquierda,nodo);
                }
            }
        }
    }
    return this->retorno;
}

template<class T>
bool AVL<T>::cambiarValor(Nodo<T> *nuevo, QString val, Nodo<T> *nodo, Nodo<T> *padre)
{
    if(nodo!=nullptr){
        if(padre== nullptr){
            if(val.compare(nodo->getValor().id)>0)
                cambiarValor(nuevo,val,nodo->derecha,nodo);
            else if (val.compare(nodo->getValor().id)<0)
                cambiarValor(nuevo,val,nodo->izquierda,nodo);
            else{
                nodo->setValor(nuevo->getValor());
                return true;
            }
        }
        else{
            if(val==nodo->getValor().id){
                this->match=true;

                nodo->setValor(nuevo->getValor());
                cambiado = true;

            }else{
                if(this->match!=true){
                    if(val>nodo->getValor().id)
                        cambiarValor(nuevo,val,nodo->derecha,nodo);
                    else
                        cambiarValor(nuevo,val,nodo->izquierda,nodo);
                }
            }
        }
    }
    return cambiado;
}

template<typename T>
void AVL<T>::colocarAlturas(Nodo<T> *nodo)
{
    if(nodo!= nullptr)
        nodo->obtenerAltura();
}

template<class T>
void AVL<T>::reBalanceo(Nodo<T> *nodo)
{
    while(nodo!=nullptr){
        if(this->estaDesbalanceado(nodo)){
            Nodo<T> *y=this->mayorHijo(nodo);
            Nodo<T> *z=this->mayorHijo(y);
            nodo= this->reestructuracion(nodo,y,z);
            colocarAlturas(this->raiz);
        }
        if(nodo!=nullptr)
            nodo=nodo->padre;
    }
}

template<class T>
bool AVL<T>::estaDesbalanceado(Nodo<T> *nodo)
{
    if(nodo->getFE() >= 1 || nodo->getFE()<=-1)
        return true;
    else
        return false;
}

template<class T>
Nodo<T> *AVL<T>::mayorHijo(Nodo<T> *nodo)
{
    Nodo<T> *iz=nullptr,*der = nullptr;
    if(nodo!=nullptr){
        if(nodo->izquierda!=nullptr)
            iz = nodo->izquierda;
        if(nodo->derecha !=nullptr)
            der = nodo->derecha;
        if(iz != nullptr && der != nullptr){
            if (iz->altura > der->altura)
                return iz;
            else if (iz->altura < der->altura)
                return der;
            else
                return der;
        }else if (iz != nullptr)
            return iz;
        else if(der != nullptr)
            return der;
        else
            return nullptr;
    }
    return nullptr;
}

template<class T>
Nodo<T> *AVL<T>::recorrerIzquierda(Nodo<T> *nodo)
{
    if(nodo->izquierda!=nullptr)
        return recorrerIzquierda(nodo->izquierda);
    return nodo;
}

template<class T>
Nodo<T> *AVL<T>::reestructuracion(Nodo<T> *x, Nodo<T> *y, Nodo<T> *z)
{
    if(x!=nullptr && y != nullptr && z != nullptr){
        if(x->getFE()<-1){
            if(y->getFE()==1){
                if(this->raiz != x)
                    return RotacionDobleIzquierda(x);
                else{
                    this->raiz=RotacionDobleIzquierda(x);
                    return raiz;
                }
            }
            else if(y->getFE()==-1){
                if(this->raiz!=x)
                    return RotacionIzquierda(x);
                else{
                    this->raiz = RotacionIzquierda(x);
                    return raiz;
                }
            }
           else if(y->getFE()==0){
                if(this->raiz!= x)
                    return RotacionIzquierda(x);
                else{
                    this->raiz = RotacionIzquierda(x);
                    return raiz;
                }

            }
        }
        else if(x->getFE()>1){
            if(y->getFE()==-1){
                if(this->raiz != x)
                    return RotacionDobleDerecha(x);
                else{
                    this->raiz=RotacionDobleDerecha(x);
                    return raiz;
                }
            }
            else if(y->getFE()==1){
                if(this->raiz!=x)
                    return RotacionDerecha(x);
                else{
                    this->raiz = RotacionDerecha(x);
                    return raiz;
                }
            }
           else if(y->getFE()==0){
                if(this->raiz!= x)
                    return RotacionDerecha(x);
                else{
                    this->raiz = RotacionDerecha(x);
                    return raiz;
                }

            }
        }
    }
    return nullptr;
}

template<typename T>
int AVL<T>::comparar(T v1, T v2)
{
    int resultado=0;
    if(v1.id.compare(v2.id)<0)
        resultado=-1;

    else if(v1.id.compare(v2.id)>0)
        resultado=1;
    else
        resultado = 0;

    return resultado;
}

#include "iostream"

template<class T>
void AVL<T>::impreArbol(Nodo<T> *nodo, Nodo<T> *padre)
{
    if(nodo!=nullptr){
        if(padre==nullptr){
           ficheroSalida.open("/home/andree/Escritorio/avl.txt");
           ficheroSalida << "digraph{ bgcolor = gray \n node[fontcolor = \"white \", height = 0.5, color = \"white \"] \n [shape=circle, style=filled, color=blue] \n rankdir=UD \n edge  [color=\"white\", dir=fordware]\n";
           ficheroSalida << '\"' << nodo->getValor().id.toStdString() << "\" ; \n";
           impreArbol(nodo->izquierda,nodo);
           impreArbol(nodo->derecha,nodo);
           ficheroSalida<< "}";
           ficheroSalida.close();
           system("dot -Tpng /home/andree/Escritorio/avl.txt -o /home/andree/Escritorio/avl.png");
        }else{
            ficheroSalida << '\"'<< padre->getValor().id.toStdString() << '\"'<< "->" << '\"'<< nodo->getValor().id.toStdString() <<"\" ; \n";
            impreArbol(nodo->izquierda,nodo);
            impreArbol(nodo->derecha,nodo);
        }
    }
}
