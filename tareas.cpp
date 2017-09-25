#include "tareas.h"

Tareas::Tareas()
{

}

Tareas::Tareas(QString id, QString titulo, QString descripcion, QString fEntrega, QString prioridad, QString Estado, QString cUsuario)
{
    this->id=id;
    this->titulo=titulo;
    this->descripcion=descripcion;
    this->fEntrega=fEntrega;
    this->prioridad=prioridad;
    this->Estado=Estado;
    this->cUsuario=cUsuario;
}
