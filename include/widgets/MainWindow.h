#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_push1_clicked();

    void on_push2_clicked();

    void on_push3_clicked();

    void on_push4_clicked();

    void on_push5_clicked();

    void on_push6_clicked();

private:
    Ui::MainWindow *ui;
    int eventNumber;
};
#endif // MAINWINDOW_H
