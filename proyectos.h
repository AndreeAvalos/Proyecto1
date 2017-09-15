#ifndef PROYECTOS_H
#define PROYECTOS_H
#include <QString>
#include "arbolb.h"

class Proyectos
{
public:
    Proyectos();
    QString nombre,descripcion,fInicio,fFin,Estado,Lider;
    ArbolB Activos;
    Proyectos(QString nombre,QString descripcion,QString fInicio,QString ffin,QString Estado,QString  lider, ArbolB Activos);


};

#endif // PROYECTOS_H
