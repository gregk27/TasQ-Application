//
// Created by Greg on 2021-10-14.
//

#ifndef TASQ_APPLICATION_MAINWINDOW_H
#define TASQ_APPLICATION_MAINWINDOW_H

#include <QtWidgets/QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //TASQ_APPLICATION_MAINWINDOW_H
