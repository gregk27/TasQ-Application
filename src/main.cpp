#include <QApplication>
#include <QPushButton>
#include <widgets/MainWindow.h>
#include <net/net.h>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

#include <models/School.h>
#include <models/User.h>
#include <net/auth.h>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    QPushButton button("Hello world!", &window);
    window.show();

    net::init();
    bool netStat = net::getStatus();
    if(netStat) {
        net::auth::sessionToken = "e859b1a3-38e8-11ec-a3fd-0023aea14009";
        net::auth::localUID = "6df88578-3526-11ec-a3fd-0023aea14009";
        auto u = net::auth::getLocalUser();
        cout << "Authenticated as " << u->getName() << ", token: " << net::auth::sessionToken.value() << endl;
    } else {
        cout << "API connection failed" << endl;
    }

    return QApplication::exec();
}
