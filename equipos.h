#ifndef EQUIPOS_H
#define EQUIPOS_H
#include <QString>
#include "listasimple.h"
#include "usuarios.h"

class Equipos
{
public:
    Equipos();
    QString nombre,descripcion,cUsuario;
    ListaSimple<QString> *Ussers;
    Equipos(QString nombre, QString descripcion, QString cUsuario);
};

#endif // EQUIPOS_H
