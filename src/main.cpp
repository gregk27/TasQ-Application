#include <widgets/MainWindow.h>

#include <QApplication>
#include <net/net.h>
#include <string>

#include <ApplicationController.h>
#include <models/User.h>
#include <models/School.h>
#include <models/Course.h>
#include <net/api.h>
#include <net/auth.h>
#include <widgets/addremoveclass.h>
#include <widgets/login.h>
#include <widgets/registerdialog.h>

#include <widgets/schedulelistview.h>
#include <ApplicationController.h>
#include <models/Event.h>

using namespace std;
using namespace std::chrono;

// Add << operator to QString
std::ostream&  operator <<(std::ostream &stream,const QString &str)
{
    stream << str.toStdString();
    return stream;
}

void setStyle(QApplication &a);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    if(!getenv("theme") || strcmp(getenv("theme"), "light") != 0)
        setStyle(a);
    window.show();

    bool netStat = APIController::instance()->getStatus();
    if(netStat && AuthController::instance()->hasSession()) {
        auto u = AuthController::instance()->getLocalUser();
        cout << "Authenticated as " << u->getName() << ", token: " << AuthController::instance()->getSessionToken() << endl;
    } else {
        cout << "API connection failed" << endl;
    }

    ApplicationController::instance()->pullData(false);

    return QApplication::exec();
}

void setStyle(QApplication &a){
    a.setStyleSheet("QWidget {\n"
                    "\tcolor: rgb(255, 255, 255);\n"
                    "\tborder-color: rgb(255, 255, 255);\n"
                    "\tbackground-color: rgb(0, 0, 0);\n"
                    "}\n"
                    "\n"
                    "QMainWindow {\n"
                    "\tcolor: rgb(255, 255, 255);\n"
                    "\tborder-color: rgb(255, 255, 255);\n"
                    "\tbackground-color: rgb(0, 0, 0);\n"
                    "}\n"
                    "\n"
                    "QLayout {\n"
                    "\tcolor: rgb(255, 255, 255);\n"
                    "\tborder-color: rgb(255, 255, 255);\n"
                    "\tbackground-color: rgb(0, 0, 0);\n"
                    "}\n"
                    "centralWidget{\n"
                    "\tcolor: rgb(255, 255, 255);\n"
                    "\tborder-color: rgb(255, 255, 255);\n"
                    "\tbackground-color: rgb(0, 0, 0);\n"
                    "}\n"
                    "\n"
                    "QPushButton {\n"
                    "\tcolor: rgb(255, 255, 255);\n"
                    "\tbackground-color: rgb(81, 81, 81);\n"
                    "\tborder-color: rgb(255, 255, 255);\n"
                    "\tselection-background-color: rgb(112, 112, 112);\n"
                    "\tselection-color: rgb(255, 255, 255);\n"
                    "}\n"
                    "\n"
                    "QTableView{\n"
                    "\tcolor: rgb(255, 255, 255);\n"
                    "\tbackground-color: rgb(49, 49, 49);\n"
                    "\tgridline-color: rgb(255, 255, 255);\n"
                    "\tborder-color: rgb(255, 255, 255);\n"
                    "\tselection-background-color: rgb(49, 49, 49);\n"
                    "\tselection-color: rgb(255, 255, 255);\n"
                    "}\n"
                    "\n"
                    "QHeaderView{\n"
                    "\tcolor: rgb(0, 0, 0);\n"
                    "\tbackground-color: rgb(98, 98, 98);\n"
                    "\tgridline-color: rgb(255, 255, 255);\n"
                    "\tborder-color: rgb(255, 255, 255);\n"
                    "}");
}
