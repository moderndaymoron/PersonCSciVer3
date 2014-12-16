#include "person.h"
#include <string>

Person::Person() {
    name = "";
    gender = "";
    dayOfBirth = "";
    dayOfDeath = "";
}

string Person::getName() {
    return name;
}

void Person::setName(string s) {
    name = s;
}

string Person::getGender() {
    return gender;
}

void Person::setGender(string s) {
    gender = s;
}

string Person::getDayOfBirth() {
    return dayOfBirth;
}

void Person::setDayOfBirth(string s) {
    dayOfBirth = s;
}

string Person::getDayOfDeath() {
    return dayOfDeath;
}

void Person::setDayOfDeath(string s) {
    dayOfDeath = s;
}

int Person::getID() {
    return ID;
}

void Person::setID(int id) {
    ID = id;
}

//Checks whether a given person is valid through the use of a series of if statements, and a for-loop for checking the formatting (YYYY/MM/DD) of the dateofbirth input
bool Person::isValidPerson() {
    if (name != "") {
        if(gender == "Male" || gender == "Female") {
            int counterForTrue = 0;
            for(int i = 0; i < dayOfBirth.size(); i++) {
                if(i >= 0 && i <= 3) {
                    if(isdigit(dayOfBirth[i])) {
                        counterForTrue++;
                    }
                } else if(i == 4) {
                    if(dayOfBirth[i] == '/') {
                        counterForTrue++;
                    }
                } else if(i == 5 || i == 6) {
                    if(isdigit(dayOfBirth[i])) {
                        counterForTrue++;
                    }
                } else if(i == 7) {
                    if(dayOfBirth[i] == '/') {
                        counterForTrue++;
                    }
                } else if(i == 8 || i == 9) {
                    if(isdigit(dayOfBirth[i])) {
                        counterForTrue++;
                    }
                }
            }

            if(counterForTrue == 10) {
                return true;
            } else {
                return false;
            }

        } else {
            return false;
        }
    } else {
        return false;
    }
}
