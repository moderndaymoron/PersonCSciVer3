#include "computerservice.h"
#include <vector>
#include <string>

using namespace std;
ComputerService::ComputerService() {
    compRepo = ComputerRepository();
}

bool ComputerService::add(Computer c) {
    return compRepo.add(c);
}

vector<Computer> ComputerService::getSortedComputers(string sortOrder) {
    return compRepo.getSortedComputers(sortOrder);
}

vector<Computer> ComputerService::search(string input, string word) {
    return compRepo.search(input, word);
}

vector<Computer> ComputerService::getComputersFromScientist(Person scientist) {
    return compRepo.getComputersFromScientist(scientist);
}

bool ComputerService::connectComputerToScientist(int PersonID, int ComputerID) {
    return compRepo.connectComputerToScientist(PersonID, ComputerID);
}
