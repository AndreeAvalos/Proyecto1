#include "login.h"
#include <QApplication>
#include <sstream>
#include "equipos.h"
#include "proyectos.h"
#include "tareas.h"
#include "cola.cpp"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;

    Cola<QString> lst;

    lst.push("hola");
    lst.push("hola2");
    lst.push("hola3");
    lst.push("hola4");
    lst.pop();

    lst.push("hola1");
    lst.push("hola11");
    lst.push("hola12");
    lst.imprimir();
   // w.show();


    return a.exec();
}
