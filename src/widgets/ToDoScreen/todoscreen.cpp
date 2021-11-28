#include <widgets/todoscreen.h>
#include "./ui_todoscreen.h"
#include <ApplicationController.h>

ToDoScreen::ToDoScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToDoScreen)
{
    ui->setupUi(this);

    connect(ApplicationController::instance(), &ApplicationController::todosChanged, this, &ToDoScreen::update);
}

ToDoScreen::~ToDoScreen()
{
    delete ui;
}

void ToDoScreen::createTodo() {
    if(ui->todoInput->text().isEmpty()) return;
    QJsonObject js = {
            {"id", ""},
            {"name", ui->todoInput->text()},
            {"completed", false}
    };
    ApplicationController::instance()->addInstance<Todo>(new Todo(js));
}

void ToDoScreen::update(){
    auto todos = ApplicationController::instance()->getInstances<Todo>();
    ui->activeTodos->clearContent();
    ui->completedTodos->clearContent();
    for(auto [tId, t] : todos){
        if(t->getCompleted()){
            ui->completedTodos->addWidget(createTodoWidget(t));
        } else {
            ui->activeTodos->addWidget(createTodoWidget(t));
        }
    }
}

QWidget *ToDoScreen::createTodoWidget(models::Todo *t) {
    auto widget = new QWidget();
    widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    widget->setLayout(new QHBoxLayout());

    auto l = new QLabel(t->getName());
    widget->layout()->addWidget(l);

    auto btn = new QPushButton();
    btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    widget->layout()->addWidget(btn);
    if(t->getCompleted()){
        l->setEnabled(false);
        btn->setText("Remove");
        connect(btn, &QPushButton::clicked, [=]{
            ApplicationController::instance()->removeInstance<Todo>(t);
        });
    } else {
        btn->setText("Complete");
        connect(btn, &QPushButton::clicked, [=]{
            t->setCompleted(true);
            ApplicationController::instance()->modifyInstance<Todo>(t);
        });
    }
    return widget;
}
