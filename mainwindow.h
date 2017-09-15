#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/*

 *Programa creado por Andree Avalos
 *Ingeniero en Ciencias y Sistemas
 *Carnet 201408580
 *Estructuras de Datos

*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_MainWindow_destroyed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
