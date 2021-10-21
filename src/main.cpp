#include <QApplication>
#include <QPushButton>
#include <widgets/MainWindow.h>
#include <net/net.h>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

#include <models/School.h>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    QPushButton button("Hello world!", &window);
    window.show();

    net::init();

    cout << net::getStatus() << endl;

    string str = R"({"id": "asdf", "name": "Queen's"})";

    auto js = nlohmann::json::parse(str);

    models::School s(js);

    cout << s.getName() << endl;

    return QApplication::exec();
}
