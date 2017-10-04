#include "activo.h"

Activo::Activo()
{
    this->id=nullptr;
    this->titulo=nullptr;
    this->descripcion=nullptr;
    this->cantidad=0;
    this->valormonetario= 0;
}

Activo::Activo(QString id, QString titulo, QString descripcion, int cantidad, int valormonetario)
{
    this->id=id;
    this->titulo=titulo;
    this->descripcion=descripcion;
    this->cantidad=cantidad;
    this->valormonetario= valormonetario;


}
