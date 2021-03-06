//
// Created by Greg on 2021-10-19.
//

#ifndef TASQ_APPLICATION_ENUMS_H
#define TASQ_APPLICATION_ENUMS_H
#include <QString>
#include <QMetaType>

namespace models::enums {
    /**
     * Exception representing an invalid database string when creating an enum
     */
    class EnumValueException : public std::exception {
        QString str;
    public:
        /**
         * Create a new EnumValueException
         * @param str Error message
         */
        explicit EnumValueException(QString str);
        const char * what() const noexcept override;
    };
    /**
     * Class representing a course's term
     */
    class Term {
    private:
        /** Number of supported terms */
        const static int numTerms = 4;

        /** Names used by database */
        const static QString dbNames[numTerms];
        /** Pretty-print names */
        const static QString prettyNames[numTerms];
        /** Letter short forms */
        const static char letters[numTerms];

        /** Index of this term in arrays */
        unsigned char val;

        /**
         * Create a new term
         * @param val Index of term in arrays
         */
        explicit Term(unsigned char val) : val(val) {}
    public:
        /** Winter term */
        const static Term WINTER;
        /** Spring term */
        const static Term SPRING;
        /** Summer term */
        const static Term SUMMER;
        /** Fall term */
        const static Term FALL;

        /**
         * Create a term from a database entry
         * @param s Database entry
         * @return Term with value based on dbNames
         */
        static Term fromDB(QString s);

        /**
         * Get the term's database name
         * @return Database name for term
         */
        QString toDB() const;

        /**
         * Get the term's pretty-print name
         * @return Pretty-print name for term
         */
        QString toString() const;

        /**
         * Get the term's single-letter name
         * @return Single-letter name for term
         */
        char toLetter() const;

        // Override comparison operators
        // Terms can be equal, but ordering is meaningless
        bool operator==(Term other) const;
        bool operator!=(Term other) const;
        bool operator>(Term other) = delete;
        bool operator>=(Term other) = delete;
        bool operator<(Term other) = delete;
        bool operator<=(Term other) = delete;
    };

    /**
    * Class representing a Event's type
    */
    class EventType {
    private:
        /** Number of supported eventTypes */
        const static int numEventTypes = 6;

        /** Names used by database */
        const static QString dbNames[numEventTypes];
        /** Pretty-print names */
        const static QString prettyNames[numEventTypes];

        /** Index of this eventType in arrays */
        unsigned char val;

        /**
         * Create a new eventType
         * @param val Index of eventType in arrays
         */
        explicit EventType(unsigned char val) : val(val) {}
    public:
        /** Lecture eventType */
        const static EventType LECTURE;
        /** Tutorial eventType */
        const static EventType TUTORIAL;
        /** Lab eventType */
        const static EventType LAB;
        /** Test eventType */
        const static EventType TEST;
        /** Quiz eventType */
        const static EventType QUIZ;
        /** Assignment eventType */
        const static EventType ASSIGNMENT;

        /**
         * Create a eventType from a database entry
         * @param s Database entry
         * @return EventType with value based on dbNames
         */
        static EventType fromDB(QString s);

        /**
         * Get the eventType's database name
         * @return Database name for eventType
         */
        QString toDB() const;

        /**
         * Get the eventType's pretty-print name
         * @return Pretty-print name for eventType
         */
        QString toString() const;

        // Override comparison operators
        // Terms can be equal, but ordering is meaningless
        bool operator==(EventType other) const;
        bool operator!=(EventType other) const;
        bool operator>(EventType other) = delete;
        bool operator>=(EventType other) = delete;
        bool operator<(EventType other) = delete;
        bool operator<=(EventType other) = delete;
    };
}

Q_DECLARE_METATYPE(models::enums::Term);
Q_DECLARE_METATYPE(models::enums::EventType);


#endif //TASQ_APPLICATION_ENUMS_H
