#include <widgets/MainWindow.h>

#include <QApplication>
#include <net/net.h>
#include <string>

#include <models/User.h>
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
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    window.show();


    return QApplication::exec();
}
