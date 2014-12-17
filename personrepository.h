#ifndef PERSONREPOSITORY_H_INCLUDED
#define PERSONREPOSITORY_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include "person.h"
#include <QtSql>

class PersonRepository {
public:
    PersonRepository();
    ~PersonRepository();

    bool add(Person p);
    bool remove(Person p);

     //searches for a person in the database
    vector<Person> search(string input, string word);
    //returns list of sorted persons
    vector<Person> getSortedPersons(string sortOrder);

    QSqlDatabase getDatabaseConnection();
private:
    QSqlDatabase db;
    //to prevent repeated code
    void displayPerson(const int index);
    char searchFor();

};

#endif // PERSONREPOSITORY_H_INCLUDED
