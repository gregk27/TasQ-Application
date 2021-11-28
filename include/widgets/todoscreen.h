#ifndef ToDoScreen_H
#define ToDoScreen_H

#include <QWidget>
#include <models/Todo.h>

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
    void createTodo();

    void update();
private:
    Ui::ToDoScreen *ui;

    QWidget *createTodoWidget(models::Todo *t);
};
#endif // ToDoScreen_H
