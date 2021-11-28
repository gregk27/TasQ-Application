#include <widgets/login.h>
#include "./ui_login.h"
#include<QMessageBox>
#include <net/auth.h>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setModal(true);
    connect(this, &Login::login, AuthController::instance(), &AuthController::loginSlot);
}

Login::~Login()
{
    delete ui;
}


void Login::on_reg_clicked()
{
    regi = new RegisterDialog(this);
    regi->show();
}


void Login::on_log_clicked()
{
    QString email = ui->em1->text();
    QString pass = ui->pass1->text();
    emit login(email, pass);
    close();
}

