#ifndef ACTIVO_H
#define ACTIVO_H
#include <QString>

class Activo
{
public:
    Activo();
    QString titulo,descripcion,id;
    int cantidad,valormonetario;
    Activo(QString id, QString titulo, QString descripcion, int cantidad, int valormonetario);
};

#endif // ACTIVO_H
