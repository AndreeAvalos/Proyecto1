#include "activo.h"

Activo::Activo()
{

}

Activo::Activo(QString id, QString titulo, QString descripcion, int cantidad, int valormonetario)
{
    this->id=id;
    this->titulo=titulo;
    this->descripcion=descripcion;
    this->cantidad=cantidad;
    this->valormonetario= valormonetario;


}
