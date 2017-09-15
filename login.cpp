#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    w= new MainWindow();
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
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

    }
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
