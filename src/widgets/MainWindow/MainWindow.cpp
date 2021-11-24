#include <widgets/MainWindow.h>
#include <net/auth.h>
#include <widgets/login.h>
#include <ApplicationController.h>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(AuthController::instance(), &AuthController::authStateChanged, this, &MainWindow::authStateChanged);
    // Pump the authStateChanged event to update any widgets listening for it (bad practice, but necessary)
    emit AuthController::instance()->authStateChanged(AuthController::instance()->getLocalUser().get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::authStateChanged(){
    if(AuthController::instance()->hasSession()){
        // Pull new data if user newly logged in
        ApplicationController::instance()->pullData();
    } else {
        // Open a login dialog
        Login *l = new Login(this);
        l->show();
    }
}