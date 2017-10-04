#ifndef PROYECTOS_H
#define PROYECTOS_H
#include <QString>

class Proyectos
{
public:
    Proyectos();
    QString nombre,descripcion,fInicio,fFin,Estado,Lider;
    //arbolB *Activos;
    Proyectos(QString nombre,QString descripcion,QString fInicio,QString ffin,QString Estado,QString  lider);


};

#endif // PROYECTOS_H
