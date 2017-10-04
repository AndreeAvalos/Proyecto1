#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listasimple.cpp"
#include "avl.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MainWindow_destroyed()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_9_clicked()
{
    matriz->Graficar();
    this->rePintarMatriz();

}

void MainWindow::rePintarMatriz()
{
    QPixmap image("/home/andree/Escritorio/matriz.png");
    ui->label->setPixmap(image);
}

void MainWindow::cargarUsuarios()
{
    //aqui se va a cargar los usuarios al avl
    //Usuarios nuevo("admin1","s","s","s","s","s","s","s");
    try{
       QString fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("Json Files (*.json)"));//Cuadro de dialogo
       //para poder elegir la ubicacion del archivo

       QJsonDocument doc;//creamos el documento tipo JSON
       std::fstream ficheroEntrada;//para leer el archivo
       std::string linea;//
       QByteArray archivo;//
       ficheroEntrada.open(fileNames.toStdString(), ios::in);//abrimos el archivo con su ubicacion

       while (! ficheroEntrada.eof() ) {
           getline(ficheroEntrada,linea);//leemos linea por linea el archivo
           archivo.append(QString::fromStdString(linea));//lo adjuntamos al archivo
       }
       doc=QJsonDocument::fromJson(archivo);

       QJsonArray usuario = doc.array();
       QJsonObject ar1;
       for(int i =0; i<usuario.count();i++){
           ar1 = usuario.at(i).toObject();
           Usuarios nuevo (ar1["codigo"].toString(),ar1["nombres"].toString(),ar1["apellidos"].toString(),ar1["fecha_nacimiento"].toString(),ar1["fecha_contrato"].toString(),ar1["rol"].toString(),ar1["anotaciones"].toString(),ar1["password"].toString());
           avl->insertar(nuevo);
       }
       avl->impreArbol(avl->raiz,nullptr);


    }catch(exception e){

    }
}

void MainWindow::cargarEquipos()
{
    QString fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("Json Files (*.json)"));//Cuadro de dialogo
    //para poder elegir la ubicacion del archivo

    QJsonDocument doc;//creamos el documento tipo JSON
    std::fstream ficheroEntrada;//para leer el archivo
    std::string linea;//
    QByteArray archivo;//
    ficheroEntrada.open(fileNames.toStdString(), ios::in);//abrimos el archivo con su ubicacion

    while (! ficheroEntrada.eof() ) {
        getline(ficheroEntrada,linea);//leemos linea por linea el archivo
        archivo.append(QString::fromStdString(linea));//lo adjuntamos al archivo
    }
    doc=QJsonDocument::fromJson(archivo);
    QJsonArray equipo = doc.array();
    QJsonObject ar1;
    for(int i=0; i<equipo.count();i++){
        ar1 = equipo.at(i).toObject();
        Equipos nuevo(ar1["nombre"].toString(),ar1["descripcion"].toString(),ar1["especialista"].toString());

        QJsonArray lstusuarios = ar1["empleados"].toArray();
        for(int j = 0; j<lstusuarios.count();j++){

            nuevo.Ussers->agregar(lstusuarios.at(j).toString());
        }
        agregarEquipo(nuevo);
    }

    matriz->lsthorizontal->imprimir();


}

void MainWindow::cargarProyectos()
{
    QString fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("Json Files (*.json)"));//Cuadro de dialogo
    //para poder elegir la ubicacion del archivo

    QJsonDocument doc;//creamos el documento tipo JSON
    std::fstream ficheroEntrada;//para leer el archivo
    std::string linea;//
    QByteArray archivo;//
    ficheroEntrada.open(fileNames.toStdString(), ios::in);//abrimos el archivo con su ubicacion

    while (! ficheroEntrada.eof() ) {
        getline(ficheroEntrada,linea);//leemos linea por linea el archivo
        archivo.append(QString::fromStdString(linea));//lo adjuntamos al archivo
    }
    doc=QJsonDocument::fromJson(archivo);
    QJsonArray proyectos = doc.array();
    QJsonObject ar1;
    qInfo()<< proyectos.count();

    for(int i=0; i<proyectos.count();i++){
        ar1 = proyectos.at(i).toObject();
        Proyectos nuevo(ar1["titulo"].toString(),ar1["descripcion"].toString(),ar1["fecha_inicio"].toString(),ar1["fecha_final"].toString(),ar1["estado"].toString(),ar1["lider"].toString());
        agregarProyecto(nuevo);
    }
    matriz->lstvertical->imprimir();
}

void MainWindow::cargarActividades()
{
    QString fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("Json Files (*.json)"));//Cuadro de dialogo
    //para poder elegir la ubicacion del archivo

    QJsonDocument doc;//creamos el documento tipo JSON
    std::fstream ficheroEntrada;//para leer el archivo
    std::string linea;//
    QByteArray archivo;//
    ficheroEntrada.open(fileNames.toStdString(), ios::in);//abrimos el archivo con su ubicacion

    while (! ficheroEntrada.eof() ) {
        getline(ficheroEntrada,linea);//leemos linea por linea el archivo
        archivo.append(QString::fromStdString(linea));//lo adjuntamos al archivo
    }
    doc=QJsonDocument::fromJson(archivo);
    QJsonArray tareas = doc.array();
    QJsonObject ar1;
    QJsonObject ar2;


    for(int i=0; i<tareas.count();i++){
        ar1 = tareas.at(i).toObject();
        qInfo() << ar1["equipo"].toString()<< "--"<<ar1["proyecto"].toString() ;

        //Tareas nuevo(ar1["titulo"].toString(),ar1["descripcion"].toString(),ar1["fecha_inicio"].toString(),ar1["fecha_final"].toString(),ar1["estado"].toString(),ar1["lider"].toString());
        QJsonArray Actividades = ar1["actividades"].toArray();
        for(int j = 0; j<Actividades.count();j++){
            int priori=0;
            int priori2=0;

            if(ar2["prioridad"].toString()=="urgente")
                priori=1;
            else if(ar2["prioridad"].toString()=="alta")
                priori=2;
            else if(ar2["prioridad"].toString()=="media")
                priori=3;
            else if(ar2["prioridad"].toString()=="baja")
                priori=4;

            if(ar2["estado"].toString()=="en ejecucion")
                priori2=1;
            else if(ar2["estado"].toString()=="pendiente")
                priori2=2;
            else if(ar2["estado"].toString()=="en pausa")
                priori2=3;
            else if(ar2["estado"].toString()=="finalizada")
                priori2=4;
            else if(ar2["estado"].toString()=="cancelada")
                priori2=5;
            GeneradorID generador;

            Tareas nuevo(generador.generarID(10),ar1["titulo"].toString(),ar1["descripcion"].toString(),ar1["fecha_entrega"].toString(),priori,priori2,ar1["prioridad"].toString(),ar1["estado"].toString(),ar1["responsable"].toString());
            matriz->insertar(nuevo,ar1["equipo"].toString(),ar1["proyecto"].toString());
        }
        qInfo()<< Actividades.count();
    }


}

void MainWindow::agregarUsuarios(Usuarios val)
{
    avl->insertar(val);
}

void MainWindow::agregarEquipo(Equipos val)
{
    matriz->insertarFila(val);
}//

void MainWindow::agregarProyecto(Proyectos val)
{
    matriz->insertarColumna(val);
}

void MainWindow::agregarActividades(Tareas val, QString equipo, QString proyecto)
{
    //matriz.insertar(val,equipo,proyecto);
}


void MainWindow::on_pushButton_8_clicked()
{
    this->hide();
}

void MainWindow::on_pushButton_10_clicked()
{
    this->cargarUsuarios();
}

void MainWindow::on_pushButton_11_clicked()
{
    this->cargarEquipos();
}

void MainWindow::on_pushButton_12_clicked()
{
    this->cargarProyectos();
}

void MainWindow::on_pushButton_13_clicked()
{
    this->cargarActividades();
}
