#ifndef TO_DO_H
#define TO_DO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class To_Do; }
QT_END_NAMESPACE

class To_Do : public QMainWindow
{
    Q_OBJECT

public:
    To_Do(QWidget *parent = nullptr);
    ~To_Do();

private slots:
    void on_p1_clicked();

    void on_p2_clicked();

    void on_p3_clicked();

    void on_p4_clicked();

    void on_p5_clicked();

    void on_p6_clicked();

private:
    Ui::To_Do *ui;
};
#endif // TO_DO_H
