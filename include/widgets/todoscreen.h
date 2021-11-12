#ifndef ToDoScreen_H
#define ToDoScreen_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ToDoScreen; }
QT_END_NAMESPACE

class ToDoScreen : public QWidget
{
    Q_OBJECT

public:
    ToDoScreen(QWidget *parent = nullptr);
    ~ToDoScreen();

private slots:
    void on_p1_clicked();

    void on_p2_clicked();

    void on_p3_clicked();

    void on_p4_clicked();

    void on_p5_clicked();

    void on_p6_clicked();

private:
    Ui::ToDoScreen *ui;
};
#endif // ToDoScreen_H
