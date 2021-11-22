#include <widgets/registerdialog.h>
#include "ui_registerdialog.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_ok_clicked()
{
    /*  Need to include data model

      username = ui->l1->text().toStdString();
    password = ui->l2->text().toStdString();
     email = ui->l3->text().toStdString();
     school = ui->l4->text().toStdString();

     */
    close();
}


void RegisterDialog::on_cancel_clicked()
{
    close();
}

