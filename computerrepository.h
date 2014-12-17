#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <QtSql>
#include "computer.h"
#include "person.h"

using namespace std;

class ComputerRepository {

public:
    ComputerRepository();
    ~ComputerRepository();

    bool add(Computer c);
    bool remove(Computer c);
    //links scientist and computer
    bool connectComputerToScientist(int PersonID, int ComputerID);

    //finds the computers that input scientist is paired with
    vector<Computer> getComputersFromScientist(Person scientist);
    //searches for an item in the database
    vector<Computer> search(string input, string word);
    //returns vector of sorted items
    vector<Computer> getSortedComputers(string sortOrder);

private:
    QSqlDatabase db;
};

#endif // COMPUTERREPOSITORY_H
