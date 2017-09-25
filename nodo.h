#ifndef NODO_H
#define NODO_H
#include <QString>

template <class T>
class Nodo
{
public:
    Nodo();
    Nodo(T);
    //Nodo(T,T,T);
    Nodo(T val, QString horizontal, QString vertical);
    Nodo *arriba,*abajo,*principal;
    Nodo *derecha,*izquierda;
    Nodo *sig,*ant;
    T getValor();
    //para matriz
    QString getX();
    QString getY();
    void setValor(T);
    int comparar(T);
    //para AVL
    Nodo *raiz,*padre;
    int altura;
    int getAltura();
    int getFE();

private:
    T val;
    QString x,y;
};

#endif // NODO_H
