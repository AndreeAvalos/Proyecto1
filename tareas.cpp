#include "tareas.h"

Tareas::Tareas()
{

}

Tareas::Tareas(QString id, QString titulo, QString descripcion, QString fEntrega, int prioridad, int prioridad2, QString Estado, QString cUsuario)
{

    this->id=id;
    this->titulo=titulo;
    this->descripcion=descripcion;
    this->fEntrega=fEntrega;
    this->prioridad=prioridad;
    this->prioridad2=prioridad2;
    this->Estado=Estado;
    this->cUsuario=cUsuario;
}

int Tareas::compare(Tareas dato)
{
    if(this->prioridad>=dato.prioridad){
        return 1;
    }else{
        if(this->prioridad2>=dato.prioridad2){
            return 1;
        }else{
            return -1;
        }
    }
}
