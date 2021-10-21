#include <QApplication>
#include <QPushButton>
#include <widgets/MainWindow.h>
#include <net/net.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    QPushButton button("Hello world!", &window);
    window.show();

    net::init();

    net::getStatus();

    return QApplication::exec();
}
