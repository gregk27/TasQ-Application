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
        string email = "dummy@gregk.ca";
        string password = "password";
        net::auth::login(email, password);
        cout << "Logged in as " << net::auth::localUser->getName() << endl;
    } else {
        cout << "API connection failed" << endl;
    }

    return QApplication::exec();
}
