#include "tareas.h"

Tareas::Tareas()
{

}

Tareas::Tareas(QString titulo, QString descripcion, QString fEntrega, QString prioridad, QString Estado, QString cUsuario)
{
    this->titulo=titulo;
    this->descripcion=descripcion;
    this->fEntrega=fEntrega;
    this->prioridad=prioridad;
    this->Estado=Estado;
    this->cUsuario=cUsuario;
}
