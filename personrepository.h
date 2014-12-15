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


    vector<Person> search(string input, string word);
    vector<Person> getSortedPersons(string sortOrder);

    QSqlDatabase getDatabaseConnection();
private:
    //vector<Person> plist;
    QSqlDatabase db;
    void displayPerson(const int index);
    char searchFor();

};

#endif // PERSONREPOSITORY_H_INCLUDED
