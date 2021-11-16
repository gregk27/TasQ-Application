#ifndef ASSIGNMENTSSCREEN_H
#define ASSIGNMENTSSCREEN_H

#include <QWidget>

namespace Ui {
class AssignmentsScreen;
}

class AssignmentsScreen : public QWidget
{
    Q_OBJECT

public:
    explicit AssignmentsScreen(QWidget *parent = nullptr);
    ~AssignmentsScreen();

private:
    Ui::AssignmentsScreen *ui;
};

#endif // ASSIGNMENTSSCREEN_H
