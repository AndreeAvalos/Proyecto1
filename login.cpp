#include "login.h"
#include "ui_login.h"
#include "avl.cpp"
#include "usuarios.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    w= new MainWindow();
}

QString Login::regresarConcatenado(QString cadena, int val)
{
    std::string name = cadena.toStdString();
    name += std::to_string(val);
    QString salida =QString::fromLocal8Bit(name.c_str());
    return salida;
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
    if(w->avl!=nullptr){
        avl=w->avl;
    }

    if(ui->lineEdit->text().toStdString()=="SUP3R"){
        if(ui->lineEdit_2->text().toStdString()=="edd1234"){
            if(ui->comboBox->itemText(ckey).toStdString()=="Administrador"){
                ui->label_4->setText("Usuario encontrado");

                //this->hide();

                w->show();

                ui->label_4->clear();
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();

            }
            else
                 ui->label_4->setText("Rol incorrecto");
        }else{
             ui->label_4->setText("Password incorrecta");
        }

    }else if(avl->raiz!=nullptr){
        Nodo<Usuarios> *nodo = avl->buscar(ui->lineEdit->text(),avl->raiz,nullptr);
        if(nodo!=nullptr){
            if(ui->lineEdit->text().toStdString()==nodo->getValor().id.toStdString()){
                if(ui->lineEdit_2->text().toStdString()==nodo->getValor().pass.toStdString()){
                    if(ui->comboBox->itemText(ckey).toStdString()==nodo->getValor().rol.toStdString()){
                        w->show();
                        ui->label_4->clear();
                        ui->lineEdit->clear();
                        ui->lineEdit_2->clear();
                    }else
                        ui->label_4->setText("Rol incorrecto");
                }else
                     ui->label_4->setText("Password incorrecta");
            }else
             ui->label_4->setText("No Existe el usuario");
        }
    }else
         ui->label_4->setText("No ha ingresado usuarios");
}

void Login::on_comboBox_activated(int index)
{
    ckey=index;
}

void Login::on_pushButton_clicked()
{
    ui->label_4->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void Login::on_pushButton_3_clicked()
{
    avl=w->avl;
}
