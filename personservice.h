#ifndef PERSONSERVICE_H_INCLUDED
#define PERSONSERVICE_H_INCLUDED

#include <iostream>
#include "PersonRepository.h"

class PersonService {
public:
    PersonService();

    bool add(Person p);

    vector<Person> search(string input, string word);

    vector<Person> getSortedPersons(string order);

private:
    PersonRepository pRepo;

};

#endif // PERSONSERVICE_H_INCLUDED
