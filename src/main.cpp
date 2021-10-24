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

//    net::init();
//
//    cout << net::getStatus() << endl;

    json j = {
            {"id","16c6bddb-2de2-11ec-a3fd-0023aea14009"},
            {"name","Software Dev"},
            {"code","cmpe320"},
            {"year",2021},
            {"term","Fall"},
            {"prof","El Mezouar"},
            {"owner","71e04118-2dd7-11ec-a3fd-0023aea14009"},
            {"school","5cd83d02-2dcf-11ec-a3fd-0023aea14009"},
            {"modified", 1635044502}
    };

    string str = R"({"id": "asdf", "name": "Queen's"})";

    auto js = nlohmann::json::parse(str);

    models::School s(js);

    cout << s.getName() << endl;

    return QApplication::exec();
}
