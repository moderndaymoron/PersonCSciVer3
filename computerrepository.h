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

    vector<Computer> search(string input, string word);
    vector<Computer> getSortedComputers(string sortOrder);

    bool add(Computer c);

    vector<Computer> getComputersFromScientist(Person scientist);
    bool connectComputerToScientist(int PersonID, int ComputerID);
private:
    QSqlDatabase db;
};

#endif // COMPUTERREPOSITORY_H
