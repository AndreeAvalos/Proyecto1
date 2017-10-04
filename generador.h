#ifndef GENERADOR_H
#define GENERADOR_H
#include "listasimple.h"
#include <cstdlib>

struct GeneradorID{
    ListaSimple<QString> *lst;
    GeneradorID(){
        lst = new ListaSimple<QString>();
        lst->agregar("1");
        lst->agregar("2");
        lst->agregar("3");
        lst->agregar("4");
        lst->agregar("5");
        lst->agregar("6");
        lst->agregar("7");
        lst->agregar("8");
        lst->agregar("9");
        lst->agregar("0");
        lst->agregar("a");
        lst->agregar("b");
        lst->agregar("c");
        lst->agregar("d");
        lst->agregar("e");
        lst->agregar("f");
        lst->agregar("g");
        lst->agregar("h");
        lst->agregar("i");
        lst->agregar("j");
        lst->agregar("k");
        lst->agregar("l");
        lst->agregar("m");
        lst->agregar("n");
        lst->agregar("o");
        lst->agregar("p");
        lst->agregar("q");
        lst->agregar("r");
        lst->agregar("s");
        lst->agregar("t");
        lst->agregar("u");
        lst->agregar("v");
        lst->agregar("w");
        lst->agregar("x");
        lst->agregar("y");
        lst->agregar("z");
    }
    QString generarID(int num){
        QString cadena="";
        int cont=0;
        int cont2;
        while(cont<num){
            cont2=0;
            int numero = rand() % 34;
            Nodo<QString> *nodoAux= lst->first;
            while(nodoAux!=nullptr&& cont2<=numero){
                nodoAux=nodoAux->sig;
                cont2++;
            }
            cadena+=nodoAux->getValor();
            cont++;
        }
        return cadena;
    }

};
#endif // GENERADOR_H
