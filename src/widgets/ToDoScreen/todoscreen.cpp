#include <widgets/todoscreen.h>
#include "./ui_todoscreen.h"

ToDoScreen::ToDoScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToDoScreen)
{
    ui->setupUi(this);
}

ToDoScreen::~ToDoScreen()
{
    delete ui;
}


void ToDoScreen::on_p1_clicked()
{
    ui->t1->setText("");
    ui->c1->setChecked(false);
}


void ToDoScreen::on_p2_clicked()
{
    ui->t2->setText("");
    ui->c2->setChecked(false);
}


void ToDoScreen::on_p3_clicked()
{
    ui->t3->setText("");
    ui->c3->setChecked(false);
}


void ToDoScreen::on_p4_clicked()
{
    ui->t4->setText("");
    ui->c4->setChecked(false);
}


void ToDoScreen::on_p5_clicked()
{
    ui->t5->setText("");
    ui->c5->setChecked(false);
}


void ToDoScreen::on_p6_clicked()
{
    ui->t6->setText("");
    ui->c6->setChecked(false);
}

