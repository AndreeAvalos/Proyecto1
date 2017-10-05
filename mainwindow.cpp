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
    //ui->label->setPixmap(image);
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
       //sirve para cargar las filas
       ui->tableWidget->setRowCount(usuario.count());
       for(int i =0; i<usuario.count();i++){
           ar1 = usuario.at(i).toObject();
           Usuarios nuevo (ar1["codigo"].toString(),ar1["nombres"].toString(),ar1["apellidos"].toString(),ar1["fecha_nacimiento"].toString(),ar1["fecha_contrato"].toString(),ar1["rol"].toString(),ar1["anotaciones"].toString(),ar1["password"].toString());
           avl->insertar(nuevo);
           ui->selecUsuario->addItem(nuevo.id);
           ui->comboBox_4->addItem(nuevo.id);
       }
       //avl->impreArbol(avl->raiz,nullptr);
       this->impreArbol(avl->raiz,nullptr);


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

    imprimirH();
    imprimirEquipos();


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
    imprimirV();
    imprimirProyectos();
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
        //qInfo() << ar1["equipo"].toString()<< "--"<<ar1["proyecto"].toString() ;

        //Tareas nuevo(ar1["titulo"].toString(),ar1["descripcion"].toString(),ar1["fecha_inicio"].toString(),ar1["fecha_final"].toString(),ar1["estado"].toString(),ar1["lider"].toString());
        QJsonArray Actividades = ar1["actividades"].toArray();
        for(int j = 0; j<Actividades.count();j++){
            ar2=Actividades.at(j).toObject();
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

            Tareas nuevo(generador.generarID(10),ar2["titulo"].toString(),ar2["descripcion"].toString(),ar2["fecha_entrega"].toString(),priori,priori2,ar2["prioridad"].toString(),ar2["estado"].toString(),ar2["responsable"].toString());
            //qInfo()<<nuevo.titulo;

            matriz->insertar(nuevo,ar1["equipo"].toString(),ar1["proyecto"].toString());
        }
        //qInfo()<< Actividades.count();
    }
    imprimirT();


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
    matriz->insertar(val,equipo,proyecto);
}

void MainWindow::imprimirH()
{
    nodoDispersa *temp= matriz->lsthorizontal->first;

    while(temp!=nullptr){
        QPushButton *nuevo = new QPushButton(temp->equipo.nombre);

        nuevo->setFixedHeight(60);
        ui->horizontalLayout->addWidget(nuevo);
        temp = temp->derecha;
    }

}

void MainWindow::imprimirV()
{
    nodoDispersa *temp= matriz->lstvertical->first;

    while(temp!=nullptr){
        QPushButton *nuevo = new QPushButton(temp->proyecto.nombre);
        nuevo->setFixedHeight(75);
        ui->verticalLayout->addWidget(nuevo);
        temp = temp->abajo;
    }
}

int MainWindow::posX(QString xx)
{
        int x =0;

       nodoDispersa *derecha = matriz->lsthorizontal->first;

        while(derecha!=nullptr){
            if(derecha->equipo.nombre==xx)
                return x;
            else{
                x++;
                derecha=derecha->derecha;
            }
        }
        return -1;
}

int MainWindow::posY(QString yy)
{
        int y =0;
        nodoDispersa *abajo=matriz->lstvertical->first;

        while(abajo!=nullptr){
            if(abajo->proyecto.nombre==yy)
                return y;
            else{
                y++;
                abajo=abajo->abajo;
            }
        }
        return -1;

}

void MainWindow::imprimirT()
{
    for(int i=0; i<matriz->lsthorizontal->size;i++){
        for(int j =0;j < matriz->lstvertical->size;j++){
            QPushButton *nuevo = new QPushButton(" ");
            nuevo->setFixedHeight(75);
            nuevo->setEnabled(false);

            ui->gridLayout_2->addWidget(nuevo,j,i);
        }
    }

    nodoDispersa *derecha= matriz->lsthorizontal->first;
    nodoDispersa *Actual=derecha;

    while(derecha!=nullptr){
        nodoDispersa *abajo=matriz->lstvertical->first;
        while(abajo!=nullptr){
            if(Actual->abajo!=nullptr){
                Actual= Actual->abajo;
                Cola<Tareas> *tareas = Actual->getValor();
                if(tareas->first!=nullptr){
                QPushButton *nuevo = new QPushButton(QString::number(tareas->size) + " Tareas");
                nuevo->setFixedHeight(75);

                //qInfo() << posY(Actual->getY())<<" "<< posX(Actual->getX());
                ui->gridLayout_2->addWidget(nuevo,posY(Actual->getY()),posX(Actual->getX()));

                }
            }
            abajo=abajo->abajo;
        }
        derecha=derecha->derecha;
        Actual=derecha;
    }

}

void MainWindow::imprimirUsuarios()

{

}

void MainWindow::impreArbol(Nodo<Usuarios> *nodo, Nodo<Usuarios> *padre)
{
    if(nodo!=nullptr){
        if(padre==nullptr){

            ui->tableWidget->setItem(contador,0,new QTableWidgetItem());
            ui->tableWidget->setItem(contador,1,new QTableWidgetItem(nodo->getValor().id));
             ui->tableWidget->setItem(contador,2,new QTableWidgetItem(nodo->getValor().Nombres));
            ui->tableWidget->setCellWidget(contador,0,new QCheckBox);
            contador++;
            impreArbol(nodo->izquierda,nodo);
            impreArbol(nodo->derecha,nodo);

        }else{
            ui->tableWidget->setItem(contador,0,new QTableWidgetItem());
            ui->tableWidget->setItem(contador,1,new QTableWidgetItem(nodo->getValor().id));
             ui->tableWidget->setItem(contador,2,new QTableWidgetItem(nodo->getValor().Nombres));
            ui->tableWidget->setCellWidget(contador,0,new QCheckBox);
            contador++;
            impreArbol(nodo->izquierda,nodo);
            impreArbol(nodo->derecha,nodo);
        }
    }

}

void MainWindow::imprimirEquipos()
{

    nodoDispersa *temp = matriz->lsthorizontal->first;
    while(temp!=nullptr){
        ui->equipoUsuario->addItem(temp->equipo.nombre);
        ui->equipoActividades->addItem(temp->equipo.nombre);
        temp=temp->derecha;
    }


}

void MainWindow::imprimirProyectos()
{
    nodoDispersa *temp = matriz->lstvertical->first;
    while(temp!=nullptr){
        //ui->equipoUsuario->addItem(temp->proyecto.nombre);
        ui->proyectoActividades->addItem(temp->proyecto.nombre);
        temp=temp->abajo;
    }
}

void MainWindow::eliminarTarea(QString x, QString y)
{
    nodoDispersa *temp = matriz->buscar(x,y);
    qInfo()<< temp->getValor()->pop();

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

void MainWindow::on_pushButton_15_clicked()
{
    QString id = ui->idUsuario->text();
    QString nombre = ui->nombreUsuario->text();
    QString apellido = ui->apellidoUsuario->text();
    QString pass = ui->passUsuario->text();
    QString anotacion = ui->anotacionesUsuario->toPlainText();
    QString rol = ui->rolUsuario->itemText(ck2);
    QString fNacimiento = ui->fechaInicioUsuario->text();
    QString fContratacion = ui->contratacionUsuario->text();
    avl->match=false;
    Nodo<Usuarios> *temp = avl->buscar(id,avl->raiz,nullptr);
    avl->match=false;
    if(temp!=nullptr){
        Usuarios nuevo(id,nombre,apellido,fNacimiento,fContratacion,rol,anotacion,pass);
        temp->setValor(nuevo);
        //qInfo()<< avl->cambiarValor(temp,id,avl->raiz,nullptr);
        avl->cambiado=false;
    }else{
        Usuarios nuevo(id,nombre,apellido,fNacimiento,fContratacion,rol,anotacion,pass);
        agregarUsuarios(nuevo);
    }
}

void MainWindow::on_selecUsuario_currentIndexChanged(int index)
{
    ck=index;
    //qInfo()<<ui->selecUsuario->itemText(ck);
    QString id= ui->selecUsuario->itemText(index);
    Nodo<Usuarios> *temp = avl->buscar(id,avl->raiz,nullptr);
    avl->match=false;
    if(temp!=nullptr){
        Usuarios aux = temp->getValor();
        ui->idUsuario->setText(aux.id);
        ui->nombreUsuario->setText(aux.Nombres);
        ui->apellidoUsuario->setText(aux.Apellidos);
        ui->anotacionesUsuario->clear();
        ui->anotacionesUsuario->appendPlainText(aux.Anotaciones);
        ui->fechaInicioUsuario->setText(aux.fNacimiento);
        ui->contratacionUsuario->setText(aux.fContratacion);
        ui->passUsuario->setText(aux.pass);
    }
}

void MainWindow::on_rolUsuario_currentIndexChanged(int index)
{
    ck2=index;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ck3=index;
}




void MainWindow::on_pushButton_18_clicked()
{
    QString id= ui->selecUsuario->itemText(ck);
    Nodo<Usuarios> *temp = avl->buscar(id,avl->raiz,nullptr);
    avl->match=false;

    if(temp!=nullptr){
        Usuarios aux = temp->getValor();
        ui->idUsuario->setText(aux.id);
        ui->nombreUsuario->setText(aux.Nombres);
        ui->apellidoUsuario->setText(aux.Apellidos);
        ui->anotacionesUsuario->clear();
        ui->anotacionesUsuario->appendPlainText(aux.Anotaciones);
        ui->fechaInicioUsuario->setText(aux.fNacimiento);
        ui->contratacionUsuario->setText(aux.fContratacion);
        ui->passUsuario->setText(aux.pass);
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->idUsuario->clear();
    ui->selecUsuario->repaint();
    ui->nombreUsuario->clear();
    ui->apellidoUsuario->clear();
    ui->anotacionesUsuario->clear();
    ui->anotacionesUsuario->clear();
    ui->fechaInicioUsuario->clear();
    ui->contratacionUsuario->clear();
    ui->passUsuario->clear();
}

void MainWindow::on_equipoUsuario_activated(int index)
{
  ck5=index;
}

void MainWindow::on_pushButton_17_clicked()
{
    nodoDispersa *temp = matriz->lsthorizontal->buscar(ui->equipoUsuario->itemText(ck5));
    if(temp!=nullptr){

        for(int i =0; i<ui->tableWidget->rowCount();i++){
            //esto sirve para castear objetos
            QCheckBox *temp2 = dynamic_cast<QCheckBox*>(ui->tableWidget->cellWidget(i,0));
            if(temp2->isChecked()==true){
                QString temp3 = ui->tableWidget->item(i,1)->text();

                temp->equipo.Ussers->agregar(temp3);
            }
        }
    }
}


void MainWindow:: on_pushButton_19_clicked()
{
    QString x = ui->equipoActividades->itemText(ck6);
    QString y = ui->proyectoActividades->itemText(ck7);
    nodoDispersa *temp = matriz->buscar(x,y);
    //asignamos valor a la tabla

    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);

    if(temp!=nullptr){
        Cola<Tareas> *temp2 = temp->getValor();
        ui->tableWidget_2->setRowCount(temp->getValor()->size);
        if(temp2->first!=nullptr){

            Nodo<Tareas> *temp3=temp2->first;
            int cont =0;
            while(temp3!=nullptr){
                //qInfo()<<temp3->getValor().titulo;
                ui->tableWidget_2->setItem(cont,0,new QTableWidgetItem(temp3->getValor().id));
                ui->tableWidget_2->setItem(cont,1,new QTableWidgetItem(temp3->getValor().titulo));
                ui->tableWidget_2->setItem(cont,2,new QTableWidgetItem(temp3->getValor().fEntrega));
                ui->tableWidget_2->setItem(cont,3,new QTableWidgetItem(temp3->getValor().priori));
                ui->tableWidget_2->setItem(cont,4,new QTableWidgetItem(temp3->getValor().Estado));
                ui->tableWidget_2->setItem(cont,5,new QTableWidgetItem(temp3->getValor().cUsuario));
                ui->tableWidget_2->setItem(cont,6,new QTableWidgetItem("M"));
                // ui->tableWidget_2->setItem(cont,7,new QTableWidgetItem("M"));

                //nuevo->clicked();

                //QObject::connect(ui->tableWidget_2->cellWidget(cont,6), SIGNAL(clicked()), this, SLOT(eliminarTarea(x,y)));
                //ui->tableWidget_2->setCellWidget(cont,6,ta);
                //connect(nuevo, SIGNAL (clicked()), MainWindow, SLOT ());

                QPushButton *nuevo2 = new QPushButton();


                cont++;
                temp3=temp3->sig;
            }
        }



    }
}

void MainWindow::on_equipoActividades_activated(int index)
{
    ck6=index;
}

void MainWindow::on_proyectoActividades_activated(int index)
{
    ck7=index;
}

void MainWindow::on_tableWidget_2_cellClicked(int row, int column)
{
    if(column==6){
        //qInfo()<<"Se escogio ";
        qInfo()<< ui->tableWidget_2->item(row,0)->text();
        QString x = ui->equipoActividades->itemText(ck6);
        QString y = ui->proyectoActividades->itemText(ck7);
        nodoDispersa *temp = matriz->buscar(x,y);
        Tareas temp2 =temp->getValor()->buscar(ui->tableWidget_2->item(row,0)->text())->getValor();

        ui->id->setText(temp2.id);
        ui->actividadesTitulo->setText(temp2.titulo);
        ui->actividadesFecha->setText(temp2.fEntrega);
        ui->actividadesDescripcion->setPlainText(temp2.descripcion);
    }
}

void MainWindow::on_pushButton_20_clicked()
{
    QString id =ui->id->text();
    QString titulo =ui->actividadesTitulo->text();
    QString fecha = ui->actividadesFecha->text();
    QString descripcion = ui->actividadesDescripcion->toPlainText();
    QString prioridad = ui->comboBox_2->itemText(ck8);
    QString estado = ui->comboBox_3->itemText(ck9);
    QString encargado =ui->comboBox_4->itemText(ck10);
    int pri=0;
    int pri2=0;

    if(prioridad=="urgente"){
        pri=1;
    }else if(prioridad=="alta")
        pri=2;
    else if(prioridad=="media")
        pri=3;
    else if(prioridad=="baja")
        pri=4;
    else
        pri=0;

    if(estado=="en ejecucion")
        pri2=1;
    else if(estado=="pendiente")
        pri2=2;
    else if(estado=="en pausa")
        pri2=3;
    else if(estado=="finalizada")
        pri2=4;
    else if(estado=="cancelada")
        pri2=5;

    QString x = ui->equipoActividades->itemText(ck6);
    QString y = ui->proyectoActividades->itemText(ck7);
    nodoDispersa *temp = matriz->buscar(x,y);
    Nodo<Tareas> *temp2= temp->getValor()->buscar(id);

    Tareas nueva(id,titulo,descripcion,fecha,pri,pri2,prioridad,estado,encargado);
    temp2->setValor(nueva);


}

void MainWindow::on_comboBox_2_activated(int index)
{
    ck8=index;
}

void MainWindow::on_comboBox_3_activated(int index)
{
    ck9=index;
}

void MainWindow::on_comboBox_4_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_comboBox_4_activated(int index)
{
    ck10=index;
}
