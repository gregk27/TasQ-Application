//
// Created by Greg on 2021-10-17.
//

#ifndef TASQ_APPLICATION_MODELBASE_H
#define TASQ_APPLICATION_MODELBASE_H

#include <string>
#include <sstream>


using namespace std;

/**
 * Classes and functions for handling data models
 */
namespace models {
    /** SQL UUID is a 36-bit string */
    typedef string uuid;
    /**
     * Base class for data models <br/>
     * Will be used to implement common networking code
     */
    class ModelBase {
    private:

        ~ModelBase();

    protected:
        ModelBase();

    public:

    };
}
#endif //TASQ_APPLICATION_MODELBASE_H
