#include "equipos.h"
#include "listasimple.cpp"
Equipos::Equipos()
{

}

Equipos::Equipos(QString nombre, QString descripcion, QString cUsuario)
{
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->cUsuario=cUsuario;
    this->Ussers=new ListaSimple<QString>();
}
