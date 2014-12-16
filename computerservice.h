#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "computerrepository.h"
#include <vector>

using namespace std;

class ComputerService {

public:
    ComputerService();
    bool add(Computer c);
    vector<Computer> getSortedComputers(string sortOrder);
    vector<Computer> search(string input, string word);

    vector<Computer> getComputersFromScientist(Person scientist);
    bool connectComputerToScientist(int PersonID, int ComputerID);

    bool remove(Computer c);
private:
    ComputerRepository compRepo;
};

#endif // COMPUTERSERVICE_H
