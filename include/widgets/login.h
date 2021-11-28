#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "registerdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:


    void on_reg_clicked();

    void on_log_clicked();

private:
    Ui::Login *ui;
    RegisterDialog *regi;

signals:
    void login(QString email, QString password);
};
#endif // LOGIN_H
