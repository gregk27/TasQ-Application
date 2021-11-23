//
// Created by Greg on 2021-11-21.
//

#include <utils.h>
#include <QCryptographicHash>

int *utils::getColourForCourse(QString courseID) {
    auto hash = QCryptographicHash::hash(courseID.toLocal8Bit(), QCryptographicHash::Md5);
    return new int[3] {hash[0]+127, hash[1]+127, hash[2]+127};
}