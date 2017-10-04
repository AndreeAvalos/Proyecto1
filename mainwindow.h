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

    //matrizDispersa matriz;

    ~MainWindow();

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

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
