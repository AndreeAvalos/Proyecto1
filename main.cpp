#include "login.h"
#include <QApplication>
#include "avl.cpp"
#include "usuarios.h"
#include <sstream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;

    AVL<Usuarios> arbolAVL;

    for(int i = 0; i <5 ;i++){
        std::stringstream ss;
        ss << "Admin" << i;

        QString id = QString::fromStdString(ss.str());

        Usuarios nuevo = Usuarios(id,"rr","rr","rr","rr","rr","rr","rr");

        arbolAVL.insertar(nuevo);

    }
    arbolAVL.impreArbol(arbolAVL.raiz,nullptr);

   // w.show();



    return a.exec();
}
