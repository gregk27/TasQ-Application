#include <widgets/login.h>
#include "./ui_login.h"
#include<QMessageBox>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_reg_clicked()
{
    //RegisterDialog regi;
    //regi.setModal(true);
    //regi.exec();
    regi = new RegisterDialog(this);
    regi->show();

}


void Login::on_log_clicked()
{
    /*  Need to include login data model

    email = ui->em1->text().toStdString();
    password = ui->pass1->text().toStdString();
    int valids;
    valids = User.query.filter_by(email=email, password=password).all()
    if (valids.length() != 1){
            QMessageBox::critical(this,"Error","Log in failed")
    }

    */

    QMessageBox::information(this,"Messgae","Need to include login data model");

}

