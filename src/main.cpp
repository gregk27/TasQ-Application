#include <QApplication>
#include <QPushButton>
#include "widgets/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    //QPushButton button("Hello world!", &window); - delete
    window.show();
    return QApplication::exec();
}
