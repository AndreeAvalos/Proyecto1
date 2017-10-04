#ifndef TAREAS_H
#define TAREAS_H
#include <QString>


class Tareas
{
public:
    Tareas();
    QString titulo,descripcion,fEntrega,Estado,cUsuario,id,priori;
    int prioridad,prioridad2;

    Tareas(QString id, QString titulo,QString descripcion,QString fEntrega,int prioridad, int priorida2,QString prio ,QString Estado,QString cUsuario);
    int compare(Tareas dato);
};

#endif // TAREAS_H
