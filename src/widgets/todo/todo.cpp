#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_push1_clicked()
{
    ui->text1->setText("");
    ui->list1->setChecked(false);
}


void MainWindow::on_push2_clicked()
{
    ui->text2->setText("");
    ui->list2->setChecked(false);
}


void MainWindow::on_push3_clicked()
{
    ui->text3->setText("");
    ui->list3->setChecked(false);
}


void MainWindow::on_push4_clicked()
{
    ui->text4->setText("");
    ui->list4->setChecked(false);
}


void MainWindow::on_push5_clicked()
{
    ui->text5->setText("");
    ui->list5->setChecked(false);
}


void MainWindow::on_push6_clicked()
{
    ui->text6->setText("");
    ui->list6->setChecked(false);
}

