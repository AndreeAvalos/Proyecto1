#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H
#include <iostream>
#include "nodo.h"
#include "cola.h"
#include <iomanip>
#include <stdio.h>
#include <exception>
#include <QDebug>

template<class T>
class ColaPrioridad
{
public:
    ColaPrioridad();
    void push(T val, int prioridad1, int prioridad2,Cola <T> *a);
};

#endif // COLAPRIORIDAD_H
