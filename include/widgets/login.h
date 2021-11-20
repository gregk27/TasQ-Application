#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "registerdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:


    void on_reg_clicked();

    void on_log_clicked();

private:
    Ui::login *ui;
    RegisterDialog *regi;
};
#endif // LOGIN_H
