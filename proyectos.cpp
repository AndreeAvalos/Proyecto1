#include "proyectos.h"

Proyectos::Proyectos()
{

}

Proyectos::Proyectos(QString nombre, QString descripcion, QString fInicio, QString ffin, QString Estado, QString lider)
{
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->fInicio=fInicio;
    this->fFin = ffin;
    this->Estado = Estado;
    this->Lider=lider;
    this->Activos=new ArbolB();
}
