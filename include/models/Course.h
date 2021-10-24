//
// Created by Greg on 2021-10-19.
//

#ifndef TASQ_APPLICATION_COURSE_H
#define TASQ_APPLICATION_COURSE_H
#include "Models.h"
#include "Enums.h"

/**
 * Classes and functions for handling data models
 */
namespace models {
    /**
     * Data model representing a course
     */
    class Course {
    private:
        uuid id;
        string name;
        string code;
        unsigned short year;
        enums::Term term;
        string prof;
        string owner;
        uuid schoolId;
        unsigned long long modified;

    public:
        /**
         * Create a course from a json object with the structure
         * <pre>
         * "id": string,               - ID of the course<br/>
         * "name": string,             - Updated name of the course<br/>
         * "code": string,             - Updated course code<br/>
         * "year": int,                - Updated academic year of the course<br/>
         * "term": string,             - Updated term of the course<br/>
         * "prof": string,             - Updated professor teaching the course<br/>
         * "owner": string,            - ID of the user who maintains the course<br/>
         * "school": string,           - Updated ID of the course's school<br/>
         * "modified": long int        - Unix timestamp the course or it's children were last modified
         */
        explicit Course(json &json);

        /**
         * Get the course's id
         */
        uuid getId();

        /**
         * Get the course's name
         */
        string getName();
        /**
         * Set the course's name, will be reflected in databases
         */
        void setName(string &newName);

        /**
         * Get the course's course code
         */
        string getCode();
        /**
         * Set the course's course code, will be reflected in databases
         */
        void setCode(string &newCode);

        /**
         * Get the course's academic year
         */
        unsigned short getYear();
        /**
         * Set the course's academic year, will be reflected in databases
         */
        void setYear(unsigned short &newYear);

        /**
         * Get the course's academic term
         */
        enums::Term getTerm();
        /**
         * Set the course's academic term, will be reflected in databases
         */
        void setTerm(enums::Term &newTerm);

        /**
         * Get the course's professor
         */
        string getProf();
        /**
         * Set the course's professor, will be reflected in databases
         */
        void setProf(string &newProf);

        /**
         * Get the course's owner
         */
        string getOwner();

        /**
         * Get the course's school
         */
        uuid getSchoolId();
        /**
         * Set the course's school, will be reflected in databases
         */
        void setSchoolId(uuid &id);

        /**
         * Get the course's last modified date
         */
        unsigned long long getModified();
    };

}


#endif //TASQ_APPLICATION_COURSE_H
