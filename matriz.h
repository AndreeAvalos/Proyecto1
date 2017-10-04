#ifndef MATRIZ_H
#define MATRIZ_H
#include "cola.h"
#include "cola.cpp"
#include "tareas.h"
#include "equipos.h"
#include "proyectos.h"
#include <QDebug>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
//------------------------------------------------------------------------------
struct nodoDispersa{
    Cola<Tareas> *valor;
    QString x,y;
    nodoDispersa *arriba, *abajo,*derecha, *izquierda;
    Equipos equipo;
    nodoDispersa *siguiente, *anterior;
    Proyectos proyecto;

    Cola<Tareas>* getValor(){
        return this->valor;
    }
    nodoDispersa(Equipos val){
        this->equipo=val;
        this->x=val.nombre;
        this->siguiente=this->anterior=nullptr;
         arriba=abajo=derecha=izquierda=nullptr;
    }
    nodoDispersa(Proyectos val){
        this->proyecto = val;
        this->y=val.nombre;
        this->siguiente=this->anterior=nullptr;
        arriba=abajo=derecha=izquierda=nullptr;
    }
    nodoDispersa(QString x, QString y){
        this->valor=new Cola<Tareas>();
        this->x=x;
        this->y=y;
        arriba=abajo=derecha=izquierda=nullptr;
        siguiente=anterior=nullptr;
    }
    QString getY(){
        return this->y;
    }
    QString getX(){
        return this->x;
    }
};
//--------------------------------------------------------------------------------

struct listaVertical{

    nodoDispersa *first, *last;

    int size;

    listaVertical(){
        this->first=nullptr;
        this->last=nullptr;
        size=0;
    }


    void insertar(Proyectos val){

        nodoDispersa *nuevo = new nodoDispersa(val);

        if(this->first==nullptr){
            first=nuevo;
            last=nuevo;
            size++;
            return;
        }else{
            inOrden(nuevo);
            size++;
        }
    }

    void imprimir(){
        nodoDispersa *temp = first;
        while(temp!=nullptr){
            qInfo() << temp->proyecto.nombre;
            temp = temp->abajo;
        }
    }

    nodoDispersa * buscar(QString val){
        nodoDispersa * temp = first;
        while(temp!=nullptr){
            if(temp->proyecto.nombre==val)
                return temp;
            else
                temp = temp->abajo;
        }
        return nullptr;
    }
    int esMayor(nodoDispersa * val1, nodoDispersa *val2){
        int contador =1;
        if(val1->proyecto.nombre.compare(val2->proyecto.nombre)>0)
            return true;
        else
            return false;
    }

    void inOrden(nodoDispersa *nodo){
        nodoDispersa *nodoaux = this->first;
        bool insertado = false;

        while(nodoaux!=nullptr){
            if(esMayor(nodo,nodoaux)==true)
                nodoaux=nodoaux->abajo;
            else{
                if(nodoaux==first){
                    nodo->abajo=nodoaux;
                    nodoaux->arriba=nodo;
                    first=nodo;
                    insertado=true;
                    break;
                }else{
                    nodo->arriba=nodoaux->arriba;
                    nodoaux->arriba->abajo=nodo;
                    nodo->abajo=nodoaux;
                    nodoaux->arriba=nodo;

                    insertado=true;
                    break;
                }
            }
        }
        if(insertado==false){
            last->abajo=nodo;
            nodo->arriba=last;
            last=nodo;
        }
    }

};
//------------------------------------------------------------------------------
struct listaHorizontal{

    nodoDispersa *first, *last;

    int size;

    listaHorizontal(){
        this->first=nullptr;
        this->last=nullptr;
        size=0;
    }


    void insertar(Equipos val){

        nodoDispersa *nuevo = new nodoDispersa(val);

        if(this->first==nullptr){
            first=nuevo;
            last=nuevo;
            size++;
            return;
        }else{
            inOrden(nuevo);
            size++;
        }
    }
    int esMayor(nodoDispersa * val1, nodoDispersa *val2){
        int contador =1;
        if(val1->equipo.nombre.compare(val2->equipo.nombre)<0)
            return true;
        else
            return false;
    }

    void inOrden(nodoDispersa *nodo){
        nodoDispersa *nodoaux = this->first;
        bool insertado = false;

        while(nodoaux!=nullptr){
            if(esMayor(nodo,nodoaux)==true)
                nodoaux=nodoaux->derecha;
            else{
                if(nodoaux==first){
                    nodo->derecha=nodoaux;
                    nodoaux->izquierda=nodo;
                    first=nodo;
                    insertado=true;
                    break;
                }else{
                    nodo->izquierda=nodoaux->izquierda;
                    nodoaux->izquierda->derecha=nodo;
                    nodo->derecha=nodoaux;
                    nodoaux->izquierda=nodo;

                    insertado=true;
                    break;
                }
            }
        }
        if(insertado==false){
            last->derecha=nodo;
            nodo->izquierda=last;
            last=nodo;
        }
    }

    void imprimir(){
        nodoDispersa *temp = first;
        while(temp!=nullptr){
            qInfo() << temp->equipo.nombre;
            temp = temp->derecha;
        }
    }

    nodoDispersa * buscar(QString val){
        nodoDispersa * temp = first;
        while(temp!=nullptr){
            if(temp->equipo.nombre==val)
                return temp;
            else
                temp = temp->derecha;
        }
        return nullptr;
    }
};

//Declaracion de matriz en si
struct matrizDispersa{
    //Listas Verticales y Horizontales
    listaHorizontal *lsthorizontal;
    listaVertical *lstvertical;

    int size;

    //Metodo Constructor
    matrizDispersa(){
        lsthorizontal = new listaHorizontal();
        lstvertical = new listaVertical();
        size=0;
    }
    //Metodo para insertar en matriz
    void insertar(Tareas val, QString x, QString y){

         nodoDispersa *horizontal=lsthorizontal->buscar(x);
         nodoDispersa *vertical = lstvertical->buscar(y);
         if(nullptr==horizontal && nullptr==vertical)
             qInfo() << "no existe";
         else{
             add(val,horizontal,vertical);
             //qInfo() <<"se inserto con exito";
         }

    }
    void add(Tareas val, nodoDispersa *horizontal, nodoDispersa *vertical){


        if(this->size==0){

            nodoDispersa * nuevo = new nodoDispersa(horizontal->equipo.nombre,vertical->proyecto.nombre);
            nuevo->getValor()->push(val);

            horizontal->abajo=nuevo;//enlazamos la cabecera con el nodo
            vertical->derecha=nuevo;//enlazamos cabecera con el nodo

            nuevo->arriba=horizontal;//enlazamos nodo con cabecera
            nuevo->izquierda=vertical;//enlazamos nodo con cabecera

            this->size++;

       }else if( this->size>0){
            if(comparar(horizontal->equipo.nombre,vertical->proyecto.nombre)==true){
                nodoDispersa *nodoAuxiliarHorizontal = lsthorizontal->buscar(horizontal->equipo.nombre);
                nodoDispersa *nodoAux = nodoAuxiliarHorizontal;
                while(nodoAux!=nullptr){
                    if(nodoAux->getY()==vertical->proyecto.nombre){
                        nodoAuxiliarHorizontal=nodoAux;
                        break;
                    }else
                        nodoAux=nodoAux->abajo;
                }
                nodoAuxiliarHorizontal->getValor()->push(val);
                return;

            }else{

                nodoDispersa *nodoAuxiliarHorizontal = lsthorizontal->buscar(horizontal->equipo.nombre);
                nodoDispersa *nodoAux = nodoAuxiliarHorizontal->abajo;

                nodoDispersa *nodo = new nodoDispersa(horizontal->equipo.nombre,vertical->proyecto.nombre);
                nodo->getValor()->push(val);

                nodoDispersa *nodoAuxiliarVertical =lstvertical->buscar(vertical->proyecto.nombre);
                nodoDispersa *nodoAux2 = nodoAuxiliarVertical->derecha;

                bool agregado=false;
                if(nodoAuxiliarVertical->derecha!=nullptr){
                while(nodoAux2!=nullptr){
                    if(horizontal->equipo.nombre==nodoAux2->getX())
                        nodoAux2= nodoAux2->derecha;
                    else{
                        nodo->derecha=nodoAux2;
                        nodo->izquierda=nodoAux2->izquierda;
                        nodoAux2->izquierda->derecha=nodo;
                        nodoAux2->izquierda=nodo;
                        agregado=true;
                        break;
                    }
                }

                if(agregado==false){
                    nodoAux2=nodoAuxiliarVertical->derecha;
                    while(nodoAux2->derecha!=nullptr){
                        nodoAux2=nodoAux2->derecha;
                    }
                    nodo->izquierda=nodoAux2;
                    nodoAux2->derecha=nodo;
                }

               }else{
                   nodoAuxiliarVertical->derecha=nodo;
                   nodo->izquierda=nodoAuxiliarVertical;
                }
                agregado = false;
                if(nodoAuxiliarHorizontal->abajo!=nullptr){
                while(nodoAux!=nullptr){
                    if(vertical->proyecto.nombre.compare(nodoAux->getY())>=0)
                        nodoAux=nodoAux->abajo;
                    else{
                        nodo->abajo=nodoAux;
                        nodo->arriba=nodoAux->arriba;
                        nodoAux->arriba->abajo=nodo;
                        nodoAux->arriba=nodo;
                        agregado=true;
                        break;
                    }
                }
                if(agregado==false){
                    nodoAux=nodoAuxiliarHorizontal->abajo;
                    while(nodoAux->abajo!=nullptr){
                        nodoAux=nodoAux->abajo;
                    }
                    nodo->arriba=nodoAux;
                    nodoAux->abajo=nodo;
                }

                }else{
                    nodoAuxiliarHorizontal->abajo=nodo;
                    nodo->arriba=nodoAuxiliarHorizontal;
                }
            }


            /*
            nodoDispersa *derecha = lsthorizontal->first;
            nodoDispersa *actual=derecha;

            while(derecha!=nullptr){
                    nodoDispersa *abajo = lstvertical->first;
                    while(abajo!=nullptr){
                        if(actual->abajo!=nullptr){
                            actual = actual->abajo;
                            if(actual->getX()==horizontal->equipo.nombre && actual->getY()==vertical->proyecto.nombre){
                                actual->getValor()->push(val);
                                qInfo()<<"Se encontro valor";
                                return;
                           }
                        }
                        abajo= abajo->abajo;
                    }
                    derecha=derecha->derecha;
                    actual=derecha;
                }
            //Creamos un nuevo nodo;
            nodoDispersa *nuevo = new nodoDispersa(horizontal->equipo.nombre,vertical->proyecto.nombre);
            nuevo->getValor()->push(val);

            derecha=lsthorizontal->first;
            while(derecha!=nullptr){
                if(derecha->equipo.nombre==horizontal->equipo.nombre){
                    actual=derecha->abajo;
                    if(derecha->abajo==nullptr){
                        derecha->abajo=nuevo;
                        nuevo->arriba=derecha;
                    }else{
                        while(actual->abajo!=nullptr){
                            actual=actual->abajo;
                        }
                        actual->abajo=nuevo;
                        nuevo->arriba=actual;

                    }
                     derecha=derecha->derecha;

                }else
                    derecha=derecha->derecha;
            }

            nodoDispersa *abajo =lstvertical->first;
            while(abajo!=nullptr){
                if(abajo->proyecto.nombre==vertical->proyecto.nombre){
                    actual=abajo->derecha;
                    if(abajo->derecha==nullptr){
                        abajo->derecha=nuevo;
                        nuevo->izquierda=abajo;

                    }else{
                        while(actual->derecha!=nullptr){
                            actual=actual->derecha;
                        }
                        actual->derecha=nuevo;
                        nuevo->izquierda=actual;

                    }
                    abajo=abajo->abajo;

                }else
                    abajo=abajo->abajo;
            }*/

        }

            this->size++;
    }
    bool eliminar(QString x,QString y){
       nodoDispersa *horizontal=lsthorizontal->first;


       while(horizontal!=nullptr){
           nodoDispersa *vertical = horizontal->abajo;
           while(vertical!=nullptr){
               if(vertical->getX()==x && vertical->getY()==y){
                   vertical->getValor()->pop();
                   return true;
               }
               vertical=vertical->abajo;
           }
           horizontal=horizontal->derecha;
       }
       return false;
    }

    //Metodo para insertar una fila
    void insertarFila(Equipos val){
        lsthorizontal->insertar(val);
    }
    //Metodo para insertar una columna
    void insertarColumna(Proyectos val){
        lstvertical->insertar(val);
    }


    bool comparar(QString horizontal, QString vertical){
        nodoDispersa *nodoAux = lsthorizontal->buscar(horizontal);

        while(nodoAux!=nullptr){
            if(nodoAux->getY()==vertical){
                return true;
            }else
                nodoAux=nodoAux->abajo;
        }
        return false;
    }


    void Graficar(){
        std:: ofstream ficheroSalida;
        ficheroSalida.open("/home/andree/Escritorio/matriz.txt");
        ficheroSalida << "digraph{ bgcolor = gray \n node[fontcolor = white, height = 0.5, color = white ] \n [shape=box, style=filled, color=black] \n rankdir=LR \n edge  [color=\"white\", dir=fordware]\n";
        nodoDispersa *derecha = lsthorizontal->first;
        nodoDispersa*Actual= derecha;
        int contador = 1;
        ficheroSalida << "inicial[style = \"filled\" ; label = \"inicial\" ; pos = \"0,0!\"] \n";

        //Obtener cabecera Horizontal
        while(derecha!=nullptr){
            ficheroSalida<< '\"'<< Actual->equipo.nombre.toStdString() << '\"'<< "[style =\"filled\"; label=\"" << Actual->equipo.nombre.toStdString() << "\";pos= \""<< std::to_string(contador)<< ",0! \"]\n";
            contador++;
            derecha= derecha->derecha;
            Actual=derecha;
        }

        //Obtener Cabecera Vertical
        contador= 1;
        nodoDispersa *abajo = lstvertical->first;
        Actual= abajo;

        while(abajo!=nullptr){
            ficheroSalida<< '\"'<< Actual->proyecto.nombre.toStdString() << '\"'<< "[style =\"filled\"; label=\"" << Actual->proyecto.nombre.toStdString() << "\";pos= \"0,"<< std::to_string(contador)<< "! \"]\n";
            contador++;
            abajo=abajo->abajo;
            Actual=abajo;

        }
        //Obtener Valores;

        derecha= lsthorizontal->first;
        Actual=derecha;

        while(derecha!=nullptr){
            abajo=lstvertical->first;
            while(abajo!=nullptr){
                if(Actual->abajo!=nullptr){
                    Actual= Actual->abajo;
                    Cola<Tareas> *tareas = Actual->getValor();
                    if(tareas->first!=nullptr)
                        ficheroSalida << tareas->first->getValor().id.toStdString() <<"[shape=box ,style =\"filled\"; label= \" "<<std::to_string(tareas->size) << " Tareas \" ; pos = \""<<std::to_string(posX(Actual->getX()))<<','<<std::to_string(posY(Actual->getY()))<<"!\"]\n" ;
                }
                abajo=abajo->abajo;
            }
            derecha=derecha->derecha;
            Actual=derecha;
        }


        //Enlazamos horizontal a la derecha
        derecha=lsthorizontal->first;
        abajo=lstvertical->first;

        ficheroSalida << "inicial->" <<'\"'<< derecha->equipo.nombre.toStdString()<< '\"' << "-> inicial -> "<<'\"'<<abajo->proyecto.nombre.toStdString()<<'\"'<<"->inicial; \n";
        bool first = true;
        Actual=derecha;

        while(derecha!=nullptr){
            if (first==true){
                ficheroSalida << '\"'<< Actual->equipo.nombre.toStdString() << '\"';
                first=false;
            }else
                ficheroSalida <<"->"<<'\"'<<Actual->equipo.nombre.toStdString() << '\"';
            derecha=derecha->derecha;
            Actual=derecha;
        }
        ficheroSalida<<";\n";

        //Enlazar Horizontales izquierda
        derecha=lsthorizontal->last;
        first = true;
        Actual = derecha;
        while(derecha!=nullptr){
                if (first==true){
                    ficheroSalida << '\"'<< Actual->equipo.nombre.toStdString() << '\"';
                    first=false;
                }else
                    ficheroSalida <<"->"<<'\"'<<Actual->equipo.nombre.toStdString() << '\"';
                derecha=derecha->izquierda;
                Actual=derecha;
            }


        ficheroSalida<<";\n";


        //Enlazamos vertical a la derecha
        derecha=lsthorizontal->first;
        abajo=lstvertical->first;

        first = true;
        Actual=abajo;

        while(abajo!=nullptr){
            if (first==true){
                ficheroSalida << '\"'<< Actual->proyecto.nombre.toStdString() << '\"';
                first=false;
            }else
                ficheroSalida <<"->"<<'\"'<<Actual->proyecto.nombre.toStdString() << '\"';
            abajo=abajo->abajo;
            Actual=abajo;
        }
        ficheroSalida<<";\n";

        //Enlazar verticales izquierda
        abajo=lstvertical->last;
        first = true;
        Actual = abajo;
        while(abajo!=nullptr){
            if (first==true){
                ficheroSalida << '\"'<< Actual->proyecto.nombre.toStdString() << '\"';
                first=false;
            }else
                ficheroSalida <<"->"<<'\"'<<Actual->proyecto.nombre.toStdString() << '\"';
            abajo=abajo->arriba;
            Actual=abajo;
        }
        ficheroSalida<<";\n";

        //enlazar valores hacia arriba
        derecha= lsthorizontal->first;

        while(derecha!=nullptr){
            ficheroSalida << '\"'<< derecha->equipo.nombre.toStdString() << '\"';
            abajo=derecha->abajo;
            while(abajo!=nullptr){
                //qInfo()<<abajo->getValor()->first->getValor().id;
                if(abajo->getValor()->first!=nullptr)
                    ficheroSalida << "-> \""<< abajo->getValor()->first->getValor().id.toStdString() << '\"';
                abajo=abajo->abajo;
            }
            derecha=derecha->derecha;
            ficheroSalida << "; \n";
        }
        //enlazar valores hacia derecha
        abajo = lstvertical->first;
        while(abajo!=nullptr){
            ficheroSalida << '\"'<< abajo->proyecto.nombre.toStdString() << '\"';
            derecha = abajo->derecha;
            while(derecha!=nullptr){
                if(derecha->getValor()->first!=nullptr)
                    ficheroSalida << "-> \""<< derecha->getValor()->first->getValor().id.toStdString() << '\"';

                derecha=derecha->derecha;
            }
            abajo=abajo->abajo;
            ficheroSalida << "; \n";
        }
        //enlazar valores hacia arriba
        derecha=lsthorizontal->first;
        Actual=derecha;

        while(derecha!=nullptr){

            while(Actual->abajo!=nullptr){
                Actual=Actual->abajo;
            }

            while(Actual->arriba!=nullptr){
                if(Actual->getValor()->first!=nullptr)
                    ficheroSalida << '\"'<< Actual->getValor()->first->getValor().id.toStdString() << "\" ->";
                Actual=Actual->arriba;
            }

            ficheroSalida << '\"'<< derecha->equipo.nombre.toStdString() << '\"';
            ficheroSalida <<"; \n";
            derecha=derecha->derecha;
            Actual=derecha;
        }

        //Enlazar valores hacia izquierda
        abajo=lstvertical->first;
        Actual=abajo;

        while(abajo!=nullptr){

            while(Actual->derecha!=nullptr){
                Actual=Actual->derecha;
            }

            while(Actual->izquierda!=nullptr){
                if(Actual->getValor()->first!=nullptr)
                    ficheroSalida << '\"'<< Actual->getValor()->first->getValor().id.toStdString() << "\" ->";
                Actual=Actual->izquierda;
            }

            ficheroSalida << '\"'<< abajo->proyecto.nombre.toStdString() << '\"';
            ficheroSalida <<"; \n";
            abajo=abajo->abajo;
            Actual=abajo;
        }



        ficheroSalida<<"}\n";



        qInfo() <<"Se imprimio";
        ficheroSalida.close();
        system("fdp -Tpng /home/andree/Escritorio/matriz.txt -o /home/andree/Escritorio/matriz.png");

    }

    int posX(QString horizontal)
    {
        int x =1;

       nodoDispersa*derecha = lsthorizontal->first;

        while(derecha!=nullptr){
            if(derecha->equipo.nombre==horizontal)
                return x;
            else{
                x++;
                derecha=derecha->derecha;
            }
        }
        return -1;
    }


    int posY(QString vertical)
    {
        int y =1;
        nodoDispersa *abajo=lstvertical->first;

        while(abajo!=nullptr){
            if(abajo->proyecto.nombre==vertical)
                return y;
            else{
                y++;
                abajo=abajo->abajo;
            }
        }
        return -1;
    }
};
struct nodoC{
    nodoC *first, *last;

    Tareas val;

    //void getValor(){
   //     return this->val;
    //}
    nodoC(){
        this->first=this->last=nullptr;
    }
};
struct ColaP{

};
#endif // MATRIZ_H

