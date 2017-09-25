#include "matriz.h"
#include "colaprioridad.h"
#include "cola.h"


template<typename T>
Matriz<T>::Matriz()
{
    this->size=0;
    this->lstHorizontal=this->lstVertical=nullptr;
}
template<typename T>
void Matriz<T>::insert(QString fila, QString columna, T val){
    Nodo<T> *horitzontal=lstHorizontal->buscar(fila);//buscamos y asignamos el nodo
    Nodo<T> *vertical = lstVertical->buscar(columna);//buscamos y asignamos el nodo
    Nodo<T> *nuevo = new Nodo<T>(val);
    if(horitzontal!=nullptr)
    {
        if(vertical!=nullptr)

            this->insertar(horitzontal,vertical,val);
        else
            //ERROR NO EXISTE PROYECTO
            return;
    }else
        //ERROR NO EXISTE EQUIPO
        return;

}
template <typename T>
void Matriz<T>:: insertar(Nodo<T> *horizontal, Nodo<T> *vertical,T val){
    if(this->size==0){
        Nodo<T> *nuevo = new Nodo<T>(val,horizontal,vertical);//creamos un nodo que tenga el valor, y sus cabeceras
        horizontal->abajo=nuevo;//enlazamos la cabecera con el nodo
        vertical->derecha=nuevo;//enlazamos cabecera con el nodo

        nuevo->arriba=horizontal;//enlazamos nodo con cabecera
        nuevo->izquierda=vertical;//enlazamos nodo con cabecera

        this->size++;
    }else if( this->size>0){
        if(comparar(vertical,horizontal)){
        Nodo<T> *AuxiliarHorizontal = horizontal;
        Nodo<T> *nodoAux = AuxiliarHorizontal;
        while(nodoAux != nullptr){
            if(nodoAux->getY()==horizontal->getValor().nombre){
                AuxiliarHorizontal = nodoAux;
                nodoAux= nodoAux->abajo;
            }else
                nodoAux = nodoAux->abajo;
        }

        ColaPrioridad<T> lstTareas = AuxiliarHorizontal->getValor();

        lstTareas.push(val,val.prioridad1,val.prioridad1, val.cola);
        }
        else{
            Nodo<T> *AuxiliarHorizontal = horizontal;
            Nodo<T> *nodoAux = AuxiliarHorizontal->abajo;

            ColaPrioridad<T> lstTareas = AuxiliarHorizontal->getValor();
           lstTareas.push(val,val.prioridad1,val.prioridad1, val.cola);

            Nodo<T> *thenew = new Nodo<T>(lstTareas,horizontal,vertical);
            bool agregado =false;

            while(nodoAux != nullptr){
                if(horizontal->getValor().nombre > nodoAux->getY()){
                    nodoAux= nodoAux->abajo;
                }else{
                    thenew->abajo=nodoAux;
                    thenew->arriba = nodoAux->arriba;
                    nodoAux->arriba->abajo=thenew;
                    nodoAux->arriba=thenew;
                    agregado=true;
                    break;
                }
                if (agregado==false){
                    nodoAux=AuxiliarHorizontal->abajo;
                    while(nodoAux->abajo!=nullptr){
                        nodoAux=nodoAux->abajo;
                    }
                    thenew->arriba=nodoAux;
                    nodoAux->abajo=thenew;
                }
                Nodo<T> *AuxiliarVertial = vertical;
                Nodo<T> *nodoAux2 = AuxiliarVertial->derecha;

                agregado=false;

                while(nodoAux2!=nullptr){
                    if(vertical->getValor().nombre>nodoAux2->getX())
                        nodoAux2=nodoAux2->derecha;
                    else{
                        thenew->derecha=nodoAux2;
                        thenew->izquierda=nodoAux2->izquierda;
                        nodoAux2->izquierda->derecha=thenew;
                        nodoAux2->izquierda=thenew;
                        agregado=true;
                        break;
                    }
                }
                if(agregado==false){
                    nodoAux2=AuxiliarHorizontal->derecha;
                    while(nodoAux2->derecha!=nullptr){
                        nodoAux2=nodoAux2->derecha;
                        thenew->izquierda=nodoAux2;
                    }
                    nodoAux2->derecha=thenew;
                }
            }


        }
        this->size++;
    }
}

template<class T>
void Matriz<T>::comparar(Nodo<T> *columna, Nodo<T> *fila)
{
    Nodo<T> *aux = fila;
    while(aux!=nullptr){
        if(aux.getY()==columna->getValor().nombre)
            return true;
        else
            aux= aux->abajo;
    }
    return false;
}

template<class T>
void Matriz<T>::Graficar()
{
    ficheroSalida.open("/home/andree/Escritorio/matriz.txt");
    ficheroSalida << "digraph{ bgcolor = gray \n node[fontcolor = \"white \", height = 0.5, color = \"white \"] \n [shape=circle, style=filled, color=blue] \n rankdir=LR \n edge  [color=\"black\", dir=fordware]\n";
    Nodo<T> *derecha = lstHorizontal->first;
    Nodo<T> *Actual= derecha;
    int contador = 1;

    ficheroSalida << "inicial[style = \"fiilled\" ; label = \"inicial\" ; pos = \"0,0!\"] \n";
    //Obtener cabecera Horizontal
    while(derecha!=nullptr){
        ficheroSalida<< '\"'<< Actual->getValor().nombre.toStdString() << '\"'<< "[style =\"filled\"; label=\"" << Actual->getValor().nombre.toStdString() << "\";pos= \""<< std::to_string(contador)<< ",0! \"]\n";
        contador++;
        derecha= derecha->derecha;
        Actual=derecha;
    }

    //Obtener Cabecera Vertical
    contador= 1;
    Nodo<T> *abajo = lstVertical->first;
    Actual= abajo;

    while(abajo!=nullptr){
        ficheroSalida<< '\"'<< Actual->getValor().nombre.toStdString() << '\"'<< "[style =\"filled\"; label=\"" << Actual->getValor().nombre.toStdString() << "\";pos= \"0,"<< std::to_string(contador)<< "! \"]\n";
        contador++;

        abajo=abajo->abajo;
        Actual=abajo;

    }
    //Obtener Valores;

    derecha= lstVertical->first;
    Actual=derecha;
    int cont = 0;

    while(derecha!=nullptr){
        abajo=lstHorizontal->first;
        while(abajo!=nullptr){
            if(Actual->abajo!=nullptr){
                Actual= Actual->abajo;
                ColaPrioridad<T> tareas = Actual->getValor();
                ficheroSalida << tareas.first->getValor().id.toStdString() <<"[shape=circle ,style =\"filled\"; label= \" "<<std::to_string(tareas.size) << " Tareas ; pos = \""<<std::to_string(posX(Actual->getX()))<<','<<std::to_string(posY(Actual->getY()))<<"!\"]\n" ;
            }
            abajo=abajo->abajo;
        }
        derecha=derecha->derecha;
        Actual->derecha;
    }

    //Enlazar Horizontal derecha
    derecha=lstHorizontal->first;
    abajo=lstVertical->first;

    ficheroSalida << "inicial->" <<'\"'<< derecha->getValor().nombre.toStdString()<< '\"' << "-> inicial -> "<<abajo->getValor().nombre.toStdString()<<"->inicial; \n";
    bool first = true;
    Actual=derecha;

    while(derecha!=nullptr){
        if (first==true){
            ficheroSalida << '\"'<< Actual->getValor().nombre.toStdString() << '\"';
            first=false;
        }else
            ficheroSalida <<"->"<<'\"'<<Actual->getValor().nombre.toStdString() << '\"';
        derecha=derecha->derecha;
        Actual=derecha;
    }
    ficheroSalida<<";\n";

    //Enlazar Horizontales izquierda

    first = true;
    Actual=derecha->izquierda;

    while(derecha!=nullptr){
        if (first==true){
            ficheroSalida << '\"'<< Actual->getValor().nombre.toStdString() << '\"';
            first=false;
        }else
            ficheroSalida <<"->"<<'\"'<<Actual->getValor().nombre.toStdString() << '\"';
        derecha=derecha->izquierda;
        Actual=derecha;
    }
    ficheroSalida<<";\n";

    //Enlazar Vertical abajo

    first=true;
    Actual=abajo;
    while(abajo!=nullptr){
        if(first==true){
            ficheroSalida<< '\"'<< Actual->getValor().nombre.toStdString() << '\"';
            first =false;
        }else
            ficheroSalida <<"->"<<'\"'<<Actual->getValor().nombre.toStdString() << '\"';
        abajo=abajo->abajo;
        Actual=abajo;
    }
    ficheroSalida <<";\n";

    //Enlazar Vertical arriba


    first=true;
    Actual=abajo->arriba;
    while(abajo!=nullptr){
        if(first==true){
            ficheroSalida<< '\"'<< Actual->getValor().nombre.toStdString() << '\"';
            first =false;
        }else
            ficheroSalida <<"->"<<'\"'<<Actual->getValor().nombre.toStdString() << '\"';
        abajo=abajo->arriba;
        Actual=abajo;
    }
    ficheroSalida <<";\n";

    //Enlazar Valores hacia derecha

    derecha= lstHorizontal->first;

    Actual=derecha;

    while(derecha!=nullptr){
        abajo=lstVertical->first;
        ficheroSalida << '\"'<< derecha->getValor().nombre.toStdString() << '\"';
        while(abajo!=nullptr){
            if(Actual!=nullptr){
                Actual=Actual->abajo;
                ficheroSalida << '\"'<< Actual->getValor().first->getValor().id.toStdString() << '\"';
            }
            abajo = abajo->abajo;

        }
        ficheroSalida << "; \n";
        derecha=derecha->derecha;
        Actual=derecha;
    }

    //Enlazar valores hacia abajo
    abajo=lstVertical->first;
    Actual=abajo;

    while(abajo!=nullptr){
       derecha=lstHorizontal->first;
       ficheroSalida <<  '\"'<< abajo->getValor().nombre.toStdString() << '\"';
       while(derecha!=nullptr){
           if(Actual->derecha!=nullptr){
               Actual=Actual->derecha;
               ficheroSalida << '\"'<< Actual->getValor().first->getValor().id.toStdString() << '\"';
           }
           derecha=derecha->derecha;
       }
       ficheroSalida << "; /n";
       abajo=abajo->abajo;
       Actual=abajo;
    }
    ficheroSalida << "\n\n\n";

    //Enlazamos de izquierda derecha

    derecha=lstHorizontal->first;
    Actual=derecha;

    while (derecha!=nullptr){
        while(Actual->abajo!=nullptr)
            Actual=Actual->abajo;
        while(Actual->arriba!=nullptr){
            ficheroSalida << '\"'<< Actual->getValor().first->getValor().id.toStdString() << '\"'<<" ->";
            Actual=Actual->arriba;
        }
        ficheroSalida << '\"'<< derecha->getValor().nombre.toStdString() << '\"';
        ficheroSalida << ";\n";
        derecha=derecha->derecha;
        Actual=derecha;
    }

    //Enlazamos de abajo a arriba
    abajo=lstVertical->first;
    Actual=abajo;

    while (abajo!=nullptr){
        while(Actual->derecha!=nullptr)
            Actual=Actual->derecha;
        while(Actual->izquierda!=nullptr){
            ficheroSalida << '\"'<< Actual->getValor().first->getValor().id.toStdString() << '\"'<<" ->";
            Actual=Actual->izquierda;
        }
        ficheroSalida << '\"'<< abajo->getValor().nombre.toStdString() << '\"';
        ficheroSalida << ";\n";
        abajo=abajo->abajo;
        Actual=abajo;
    }
    ficheroSalida << '}';
    system("fdp -Tpng /home/andree/Escritorio/matriz.txt -o /home/andree/Escritorio/matriz.png");
}

template<class T>
int Matriz<T>::posX(QString horizontal)
{
    int x =1;

    Nodo<T> *derecha = lstHorizontal->first;

    while(derecha!=nullptr){
        if(derecha->getValor().nombre==horizontal)
            return x;
        else{
            x++;
            derecha=derecha->derecha;
        }
    }
    return -1;
}

template<class T>
int Matriz<T>::posY(QString vertical)
{
    int y =1;
    Nodo<T> *abajo=lstVertical->first;

    while(abajo!=nullptr){
        if(abajo->getValor().nombre==vertical)
            return y;
        else{
            y++;
            abajo=abajo->abajo;
        }
    }
    return -1;
}

template<class T>
int Matriz<T>::Y(QString valor)
{
    int contador = 0;
    Nodo<T> *abajo= lstVertical->first;
    Nodo<T> *actual=abajo;

    while(abajo!=nullptr){
        if(abajo->getValor().nombre==valor){
            Nodo<T> *derecha =lstVertical->first;
            while(derecha!=nullptr && actual->derecha!=nullptr){
                if(actual->derecha!=nullptr)
                    actual=actual->derecha;
                contador++;
            }
            derecha=derecha->derecha;
            break;
        }
        else{
            abajo=abajo->abajo;
            actual=abajo;
        }
    }
    return contador;
}

template<class T>
int Matriz<T>::X(QString valor)
{
    int contador = 0;
    Nodo<T> *derecha= lstHorizontal->first;
    Nodo<T> *actual=derecha;

    while(derecha!=nullptr){
        if(derecha->getValor().nombre==valor){
            Nodo<T> *abajo =lstVertical->first;
            while(abajo!=nullptr && actual->abajo!=nullptr){
                if(actual->abajo!=nullptr)
                    actual=actual->abajo;
                contador++;
            }
            abajo=abajo->abajo;
            break;
        }
        else{
            derecha=derecha->derecha;
            actual=derecha;
        }
    }
    return contador;
}

template<class T>
void Matriz<T>::eliminar(QString fila, QString columna)
{
    Nodo<T> *auxVertical=lstVertical->buscar(fila);
    Nodo<T> *auxHorizontal=lstHorizontal->buscar(columna);

    if(auxVertical!=nullptr && auxHorizontal!=nullptr){
        Nodo<T> *aux = auxHorizontal;
        while(aux->abajo!=nullptr){
            aux=aux->abajo;
            if(aux->getY()==fila){
                aux->getValor().pop();
                if(aux->getValor().first==nullptr){
                    if(X(fila)!=1){
                        if(aux->abajo!=nullptr){
                            aux->arriba->abajo=aux->abajo;
                            aux->abajo->arriba=aux->arriba;
                        }else if(aux->abajo==nullptr){
                            aux->arriba->abajo=nullptr;
                        }
                    }
                    if(Y(columna)!=1){
                        if(aux->derecha!=nullptr){
                            aux->izquierda->derecha=aux->derecha;
                            aux->derecha->izquierda=aux->izquierda;
                        }else if(aux->derecha==nullptr)
                            aux->izquierda->derecha=nullptr;
                    }
                }
            }
        }
    }

}
