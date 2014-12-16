#include "computer.h"
#include <string>

Computer::Computer() {
    name = "";
    buildYear = "";
    type = "";
    built = false;
    wikilink = "";
    imagePath = "";
}

string Computer::getName() {
    return name;
}

void Computer::setName(string s) {
    name = s;
}

string Computer::getBuildYear() {
    return buildYear;
}

void Computer::setBuildYear(string s) {
    buildYear = s;
}

string Computer::getType() {
    return type;
}

void Computer::setType(string s) {
    type = s;
}

string Computer::getWikilink() {
    return wikilink;
}

void Computer::setWikilink(string s) {
    wikilink = s;
}

string Computer::getImagePath() {
    return imagePath;
}

void Computer::setImagePath(string s) {
    imagePath = s;
}

bool Computer::getBuilt() {
    return built;
}

void Computer::setBuilt(bool b) {
    built  = b;
}

int Computer::getID() {
    return ID;
}

void Computer::setID(int id) {
    ID = id;
}

//Checks whether a given computer is valid through the use of a series of if statements, and a for-loop for checking the formatting of the buildyear input
bool Computer::isValidComputer() {
    if(name != "") {
        if(type != "") {
            int counter = 0;
            if(buildYear != "Never built") {
                for(int i = 0; i < 3; i++) {
                    if(isdigit(buildYear[i])) {
                        counter++;
                    }
                }
                if(counter == 3) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return true;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}
