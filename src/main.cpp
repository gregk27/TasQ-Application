#include <QApplication>
#include <QPushButton>
#include <widgets/MainWindow.h>
#include <net/net.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    QPushButton button("Hello world!", &window);
    window.show();

    net::init();

    cout << net::getStatus() << endl;

    return QApplication::exec();
}
