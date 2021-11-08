//
// Created by Greg on 2021-10-26.
//

#ifndef TASQ_APPLICATION_SUBSCRIPTIONS_H
#define TASQ_APPLICATION_SUBSCRIPTIONS_H

#include <net/net.h>
#include <models/User.h>
#include <models/Course.h>

using namespace models;

namespace net::subscriptions {
    /**
     * Subscribe to a new course
     * @param course Course to subscribe to
     * @return True if subscription is successful
     */
    bool addSubscription(Course &course);

    /**
     * Unsubscribe from a course
     * @param courseID ID of the course to unsubscribe from
     * @return True if unsubscription is successful
     */
    bool removeSubscription(QString &courseID);
    /**
     * Unsubscribe from a course
     * @param course Course to unsubscribe from
     * @return True if unsubscription is successful
     * @see net::users::removeSubscription(string)
     */
    inline bool removeSubscription(Course &course){
        QString id = course.getId();
        return removeSubscription(id);
    }

    /**
     * Get the subscribed courses modified after a timestamp
     * @param lastModified Timestamp to filter courses which have not been udpated
     * @return Vector of courses which have been updated
     */
    shared_ptr<vector<Course>> updateSubscriptions(unsigned long long lastModified);
    /**
     * Get the courses the current user is subscribed to
     * @return Vector of courses the user is subscribed to
     * @see net::users::updateSubscriptions(unsigned long long)
     */
    inline shared_ptr<vector<Course>> getSubscriptions() {
        return updateSubscriptions(0);
    }
}

#endif //TASQ_APPLICATION_SUBSCRIPTIONS_H
