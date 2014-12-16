#include "PersonService.h"

PersonService::PersonService() {
    pRepo = PersonRepository();
}

bool PersonService::add(Person p) {
    return pRepo.add(p);
}

bool PersonService::remove(Person p) {
    return pRepo.remove(p);
}

vector<Person> PersonService::getSortedPersons(string order) {
    return pRepo.getSortedPersons(order);
}

vector<Person> PersonService::search(string input, string word) {
    return pRepo.search(input, word);
}

