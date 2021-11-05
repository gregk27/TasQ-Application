#include "to_do.h"
#include "./ui_to_do.h"

To_Do::To_Do(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::To_Do)
{
    ui->setupUi(this);
}

To_Do::~To_Do()
{
    delete ui;
}


void To_Do::on_p1_clicked()
{
    ui->t1->setText("");
    ui->c1->setChecked(false);
}


void To_Do::on_p2_clicked()
{
    ui->t2->setText("");
    ui->c2->setChecked(false);
}


void To_Do::on_p3_clicked()
{
    ui->t3->setText("");
    ui->c3->setChecked(false);
}


void To_Do::on_p4_clicked()
{
    ui->t4->setText("");
    ui->c4->setChecked(false);
}


void To_Do::on_p5_clicked()
{
    ui->t5->setText("");
    ui->c5->setChecked(false);
}


void To_Do::on_p6_clicked()
{
    ui->t6->setText("");
    ui->c6->setChecked(false);
}

