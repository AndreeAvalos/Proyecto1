#ifndef USUARIOS_H
#define USUARIOS_H
#include <QString>

class Usuarios
{
public:
    Usuarios();
    QString Nombres, Apellidos,fNacimiento,fContratacion,rol,Anotaciones,pass,id;
    Usuarios(QString id,QString nombre,QString apellido,QString nacimiento,QString contratacion,QString rol,QString anotacion,QString pass);
};

#endif // USUARIOS_H
