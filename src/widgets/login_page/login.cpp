#include "login.h"
#include "./ui_login.h"
#include "registerdialog.h"
#include<QMessageBox>

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_reg_clicked()
{
    //RegisterDialog regi;
    //regi.setModal(true);
    //regi.exec();
    regi = new RegisterDialog(this);
    regi->show();

}


void login::on_log_clicked()
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

