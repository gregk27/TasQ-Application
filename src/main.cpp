#include <widgets/MainWindow.h>

#include <QApplication>
#include <net/net.h>
#include <string>

#include <ApplicationController.h>
#include <models/User.h>
#include <models/School.h>
#include <models/Course.h>
#include <net/api.h>
#include <widgets/addremoveclass.h>

using namespace std;
using namespace std::chrono;

// Add << operator to QString
std::ostream&  operator <<(std::ostream &stream,const QString &str)
{
    stream << str.toStdString();
    return stream;
}


int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow window(nullptr);
//    window.show();

    cout << ApplicationController::instance()->getSchool()->getId() << endl;
    for(auto c : ApplicationController::instance()->getInstances<Course>()){
        cout << c.first << ": " << c.second->getCode() << endl;
    }
    cout << ApplicationController::instance()->getInstance<Course>("16c6bddb-2de2-11ec-a3fd-0023aea14009")->getCode() << endl;

    return 0;
//    return QApplication::exec();
}
