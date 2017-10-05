#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "avl.h"
#include "matriz.h"
#include <sstream>
#include "generador.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <QDebug>
#include <QFileDialog>

#include <fstream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMainWindow>
#include <QCheckBox>
#include <QtGui>

/*

 *Programa creado por Andree Avalos
 *Ingeniero en Ciencias y Sistemas
 *Carnet 201408580
 *Estructuras de Datos

*/
using namespace std;
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
     AVL<Usuarios> *avl = new AVL<Usuarios>();
     matrizDispersa *matriz= new matrizDispersa();
     QPushButton *ta;
     int ck=0,ck2=0,ck3=0,ck4=0,ck5=0,ck6 =0, ck7=0,ck8=0,ck9=0,ck10=0;
     int contador=0;



    //matrizDispersa matriz;

    ~MainWindow();


public Q_SLOTS:
     void eliminarTarea(QString x, QString y);

private slots:
    void on_MainWindow_destroyed();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();


    void rePintarMatriz();
    void cargarUsuarios();
    void cargarEquipos();
    void cargarProyectos();
    void cargarActividades();
    void agregarUsuarios(Usuarios val);
    void agregarEquipo(Equipos val);
    void agregarProyecto(Proyectos val);
    void agregarActividades(Tareas val, QString equipo, QString proyecto);
    void imprimirH();
    void imprimirV();
    int posX(QString x);
    int posY(QString y);
    void imprimirT();
    void imprimirUsuarios();
    void impreArbol(Nodo<Usuarios> *nodo, Nodo<Usuarios> *padre);
    void imprimirEquipos();
    void imprimirProyectos();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_selecUsuario_currentIndexChanged(int index);

    void on_rolUsuario_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

    void on_equipoUsuario_activated(int index);

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_equipoActividades_activated(int index);

    void on_proyectoActividades_activated(int index);

    void on_tableWidget_2_cellClicked(int row, int column);

    void on_pushButton_20_clicked();

    void on_comboBox_2_activated(int index);

    void on_comboBox_3_activated(int index);

    void on_comboBox_4_currentIndexChanged(const QString &arg1);

    void on_comboBox_4_activated(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
