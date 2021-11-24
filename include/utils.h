//
// Created by Greg on 2021-11-21.
//

#ifndef TASQ_APPLICATION_UTILS_H
#define TASQ_APPLICATION_UTILS_H

#include <models/Course.h>
#include <QLayout>

namespace utils {
    /**
     * Generate a colour for a course based on it's MD5 hash
     * @param courseID ID of the course
     * @return int[3] with RGB values, must be deleted when done
     */
    int *getColourForCourse(QString courseID);

    /**
     * Clear all children of a QT Layout recursively
     * @param layout The layout to clear
     */
    void clearLayout(QLayout *layout);
}

#endif //TASQ_APPLICATION_UTILS_H
