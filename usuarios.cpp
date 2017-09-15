#include "usuarios.h"

Usuarios::Usuarios()
{
}

Usuarios::Usuarios(QString id, QString nombre, QString apellido, QString nacimiento, QString contratacion, QString rol,QString anotacion, QString pass)
{
    this->id=id;
    this->Nombres=nombre;
    this->Apellidos=apellido;
    this->fNacimiento=nacimiento;
    this->fContratacion=contratacion;
    this->rol=rol;
    this->Anotaciones=anotacion;
    this->pass=pass;
}
