#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::RegisterDialog *ui;

signals:
    void registerUser(QString &username, QString &email, QString &password, QString &schoolId);
};

#endif // REGISTERDIALOG_H
