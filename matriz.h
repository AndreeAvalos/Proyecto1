#ifndef MATRIZ_H
#define MATRIZ_H
#include "listadobleenlazada.h"
#include "nodo.h"
#include <QString>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "colaprioridad.h"

    template<class T>
    class Matriz
    {
    public:
        Matriz();
        void insert(QString fila, QString columna, T val);//Metodo para insertar teniendo el nombre de la columna y fila
        void insertar(Nodo<T>*,Nodo<T>*,T);// anoda filas y columnas
        static ListaDobleEnlazada<T> *lstHorizontal, *lstVertical;
        void comparar(Nodo<T>* columna, Nodo<T>* fila);
        void Graficar();
        int size;
        int posX(QString horizontal);
        int posY(QString vertical);
        void eliminar(QString fila, QString columna);
        int Y(QString valor);
        int X(QString valor);


        std:: ofstream ficheroSalida;
    };

#endif // MATRIZ_H
