#ifndef PROFILESCREEN_H
#define PROFILESCREEN_H

#include <QWidget>
#include <models/User.h>

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
    void onCoursesChanged();
};

#endif // PROFILESCREEN_H
