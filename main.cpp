#include "login.h"
#include <QApplication>
#include <sstream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login *w;/*

   // Cola<Tareas> lst;

    lst.push(nuevo);
    lst.push(nuevo1);
    lst.push(nuevo2);
    lst.push(nuevo3);
    lst.push(nuevo4);
    lst.pop();

    lst.imprimir();



    matrizDispersa matriz;
    Tareas tnuevo("tarea1","D","D","D",1,1,"D","D");
    Tareas tnuevo2("tarea2","D","D","D",1,2,"D","D");
    Equipos enuevo("edd","equipo edd","andree");
    Equipos enuevo2("edd2","equipo edd","andree");
    Equipos enuevo3("edd3","equipo edd","andree");
    Proyectos pnuevo("avance","fsdf","fsdf","fsdf","fsdf","fsdf");
    Proyectos pnuevo2("avance2","fsdf","fsdf","fsdf","fsdf","fsdf");
    Proyectos pnuevo3("avance3","fsdf","fsdf","fsdf","fsdf","fsdf");
    Tareas nuevo("titulo","titulo1","adftw","ssdf",1,1,"afdswg","ffasdw");
    Tareas nuevo1("titulo1","titulo2","tadfsf","ssdf",2,1,"fafsdf","adfhf");
    Tareas nuevo2("titulo2","titulo3","tfasdff","ssdf",1,2,"ffafsda","fhafds");
    Tareas nuevo3("titulo3","ultimo","tfasdff","ssdf",2,2,"ffafsda","fhafds");
    Tareas nuevo4("titulo4","primero","tfasdff","ssdf",1,2,"ffafsda","fhafds");


    matriz.insertarColumna(pnuevo);
    matriz.insertarColumna(pnuevo2);
    matriz.insertarColumna(pnuevo3);
    matriz.insertarFila(enuevo);
    matriz.insertarFila(enuevo2);
    matriz.insertarFila(enuevo3);
    matriz.insertar(tnuevo,"edd","avance");
    matriz.insertar(nuevo,"edd2","avance");
    matriz.insertar(nuevo2,"edd2","avance3");
    matriz.insertar(nuevo3,"edd","avance");
   // matriz.insertar(nuevo4,"edd3","avance3");
    matriz.Graficar();
*/
    w = new Login();
    w->show();

    // w.show();f
    return a.exec();
}
