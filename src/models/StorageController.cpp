//
// Created by Greg on 2021-11-23.
//

#include <models/StorageController.h>
#include <QStandardPaths>
#include <QFile>
#include <QDir>

using namespace std;

const QString StorageController::ROOT_DIR = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+"/tasq";
StorageController *StorageController::_instance = nullptr;

StorageController::StorageController() {
    QDir rootDir(ROOT_DIR);
    if(!rootDir.exists()){
        rootDir.mkpath(ROOT_DIR);
    }

    QFile file(ROOT_DIR+"/test.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    file.write("Hello World!");
}

StorageController *StorageController::instance() {
    if(!_instance)
        _instance = new StorageController();
    return _instance;
}
