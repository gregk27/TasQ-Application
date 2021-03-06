#include <widgets/MainWindow.h>

#include <QApplication>
#include <QMessageBox>
#include <net/net.h>
#include <string>

#include <ApplicationController.h>
#include <models/User.h>
#include <models/School.h>
#include <models/Course.h>
#include <net/api.h>
#include <net/auth.h>
#include <include/widgets/coursemod/addremoveclass.h>
#include <widgets/login.h>
#include <widgets/registerdialog.h>

#include <widgets/listview.h>
#include <ApplicationController.h>
#include <models/Event.h>
#include <models/StorageController.h>
#include <widgets/weekview.h>

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
    QCoreApplication::setOrganizationName("WH");
    QCoreApplication::setApplicationName("tasq");

    QApplication a(argc, argv);
//    if(!getenv("theme") || strcmp(getenv("theme"), "light") != 0)
//        setStyle(a);

    StorageController::instance();

    bool netStat = APIController::instance()->getStatus();
    if(!netStat) {
        cout << "API Connection Failed" << endl;
        // If there's no API connection, can't do anything
        QMessageBox::critical(nullptr, "Connection Error", "Unable to connect to server: "+APIRequest::BASE_URL+"\nCannot start application");
        QApplication::exit(1);
        return 1;
    }

    MainWindow window(nullptr);
    if(AuthController::instance()->hasSession()) {
        auto u = AuthController::instance()->getLocalUser();
        cout << "Authenticated as " << u->getName() << ", token: " << AuthController::instance()->getSessionToken() << endl;
        ApplicationController::instance()->pullData(false);
    } else {
        cout << "Authentication failed" << endl;
    }
    window.show();
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
