//
// Created by Greg on 2021-11-21.
//

#ifndef TASQ_APPLICATION_UTILS_H
#define TASQ_APPLICATION_UTILS_H

#include <models/Course.h>
#include <models/Event.h>
#include <QLayout>
#include <QDate>

namespace utils {
    /**
     * Generate a colour for a course based on it's MD5 hash
     * @param courseID ID of the course
     * @param fullCSS If true, will output full CSS rule. If false just outputs rgb()
     * @return String with CSS rules for background and text colour
     */
    QString getColourForCourse(QString courseID, bool fullCSS = true);

    /**
     * Clear all children of a QT Layout recursively
     * @param layout The layout to clear
     */
    void clearLayout(QLayout *layout);

    std::shared_ptr<std::vector<models::Event>> computeWeekly(models::Event *e, QDate endDate);
}

#endif //TASQ_APPLICATION_UTILS_H
