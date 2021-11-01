#ifndef TODOSCREEN_H
#define TODOSCREEN_H

#include <QWidget>

namespace Ui {
class ToDoScreen;
}

class ToDoScreen : public QWidget
{
    Q_OBJECT

public:
    explicit ToDoScreen(QWidget *parent = nullptr);
    ~ToDoScreen();

private:
    Ui::ToDoScreen *ui;
};

#endif // TODOSCREEN_H
