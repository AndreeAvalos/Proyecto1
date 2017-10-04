#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    AVL<Usuarios> *avl = new AVL<Usuarios>();

    QString regresarConcatenado(QString cadena, int val);
    ~Login();

private slots:
    void on_pushButton_2_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    int ckey=0;
    MainWindow *w;
    Ui::Login *ui;
};

#endif // LOGIN_H
