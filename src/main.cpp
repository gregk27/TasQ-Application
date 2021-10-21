#include <QApplication>
#include <QPushButton>
#include <widgets/MainWindow.h>
#include <net/net.h>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    QPushButton button("Hello world!", &window);
    window.show();

    net::init();

    cout << net::getStatus() << endl;

    string s = R"({"status": "Alive"})";

    auto js = nlohmann::json::parse(s);

    cout << js["status"] << endl;
    cout << js["payload"] << endl;

    return QApplication::exec();
}
