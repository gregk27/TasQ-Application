//
// Created by Greg on 2021-10-19.
//

#ifndef TASQ_APPLICATION_TERM_H
#define TASQ_APPLICATION_TERM_H
#include <string>
#include <exception>

using namespace std;

namespace models {
    /**
     * Class representing a course's term
     */
    class Term {
    private:
        /** Number of supported terms */
        const static int numTerms = 4;

        /** Names used by database */
        const static string dbNames[4];
        /** Pretty-print names */
        const static string prettyNames[4];
        /** Letter short forms */
        const static char letters[4];

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
        Term fromDB(string &s);

        /**
         * Get the term's database name
         * @return Database name for term
         */
        string toDB();

        /**
         * Get the term's pretty-print name
         * @return Pretty-print name for term
         */
        string toString();

        /**
         * Get the term's single-letter name
         * @return Single-letter name for term
         */
        char toLetter();
    };

    /**
     * Exception representing an invalid database string when creating a term
     */
    class InvalidTermException : public exception {
        string str;
    public:
        /**
         * Create a new InvalidTermException
         * @param str Error message
         */
        explicit InvalidTermException(string str);
        const char * what() const noexcept override;
    };
};

#endif //TASQ_APPLICATION_TERM_H
