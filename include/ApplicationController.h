//
// Created by Greg on 2021-11-22.
//

#ifndef TASQ_APPLICATION_APPLICATIONCONTROLLER_H
#define TASQ_APPLICATION_APPLICATIONCONTROLLER_H

#include <QObject>
#include <models/Models.h>

/**
 * Singleton controller for application state/data
 */
class ApplicationController : public QObject {
    Q_OBJECT

private:
    /** Singleton instance of ApplicationController */
    static ApplicationController *_instance;

    ApplicationController();
    ~ApplicationController();

public:
    static ApplicationController *instance();



};


#endif //TASQ_APPLICATION_APPLICATIONCONTROLLER_H
