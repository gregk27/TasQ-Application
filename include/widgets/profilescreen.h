#ifndef PROFILESCREEN_H
#define PROFILESCREEN_H

#include <QWidget>
#include <models/User.h>
#include <QFrame>

namespace Ui {
class ProfileScreen;
}

class ProfileScreen : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileScreen(QWidget *parent = nullptr);
    ~ProfileScreen();

private:
    Ui::ProfileScreen *ui;

public slots:
    void onAuthStateChanged(models::User *localUser);
};

#endif // PROFILESCREEN_H
