//
// Created by Greg on 2021-11-23.
//

#ifndef TASQ_APPLICATION_STORAGECONTROLLER_H
#define TASQ_APPLICATION_STORAGECONTROLLER_H

#include <QString>

class StorageController {
private:
    static StorageController *_instance;

    /**
     * Root directory for stored data
     */
    static const QString ROOT_DIR;

    StorageController();

public:
    static StorageController *instance();

};


#endif //TASQ_APPLICATION_STORAGECONTROLLER_H
