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

public slots:
    void onEventsChange();
};

#endif // ASSIGNMENTSSCREEN_H
