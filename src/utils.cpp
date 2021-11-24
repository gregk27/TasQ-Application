//
// Created by Greg on 2021-11-21.
//

#include <utils.h>
#include <QCryptographicHash>
#include <QWidget>
#include <QSpacerItem>

int *utils::getColourForCourse(QString courseID) {
    auto hash = QCryptographicHash::hash(courseID.toLocal8Bit(), QCryptographicHash::Md5);
    return new int[3] {hash[0]+127, hash[1]+127, hash[2]+127};
}

// Implementation from SO: https://stackoverflow.com/questions/4857188/clearing-a-layout-in-qt
void utils::clearLayout(QLayout *layout){
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if(item->widget())
            delete item->widget();
        delete item;
    }
}