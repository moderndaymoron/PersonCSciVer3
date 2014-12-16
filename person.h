#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person();

    string getName();
    void setName(string s);

    string getGender();
    void setGender(string s);

    string getDayOfBirth();
    void setDayOfBirth(string s);

    string getDayOfDeath();
    void setDayOfDeath(string s);

    string getWikilink();
    void setWikilink(string s);

    string getImagePath();
    void setImagePath(string s);

    int getID();
    void setID(int id);

    bool isValidPerson();

private:
    string name;
    string gender;
    string dayOfBirth;
    string dayOfDeath;
    string wikilink;
    string imagePath;

    int ID;


};

#endif // PERSON_H_INCLUDED
