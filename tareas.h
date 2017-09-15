#ifndef TAREAS_H
#define TAREAS_H
#include <QString>


class Tareas
{
public:
    Tareas();
    QString titulo,descripcion,fEntrega, prioridad,Estado,cUsuario;
    Tareas(QString titulo,QString descripcion,QString fEntrega,QString prioridad,QString Estado,QString cUsuario);

};

#endif // TAREAS_H
