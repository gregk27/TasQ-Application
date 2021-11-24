#include <widgets/registerdialog.h>
#include <net/auth.h>
#include "ui_registerdialog.h"
#include <widgets/login.h>

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    setModal(true);
    connect(this, &RegisterDialog::registerUser, AuthController::instance(), &AuthController::registerSlot);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_ok_clicked()
{
    QString username = ui->l1->text();
    QString password = ui->l2->text();
    QString email = ui->l3->text();
    QString school = ui->l4->text();

    emit registerUser(username, email, password, school);
    close();
    parentWidget()->close();
}


void RegisterDialog::on_cancel_clicked()
{
    close();
}

