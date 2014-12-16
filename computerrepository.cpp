#include "computerrepository.h"
#include <vector>
#include "computer.h"
#include "person.h"
#include <QtSql>

using namespace std;

ComputerRepository::ComputerRepository() {
    if(QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("PersonCompSci.sqlite");
        db.open();
    }
}
ComputerRepository::~ComputerRepository() {
    db.close();
}

bool ComputerRepository::add(Computer c) {
    db.open();
    QSqlQuery query;
    query.prepare("INSERT INTO Computers(Name, BuildYear, Type, Built, Wikilink, ImagePath)"
                  "VALUES (:name, :buildyear, :type, :built, :wikilink, :imagepath)");
    query.bindValue(":name", QString::fromStdString(c.getName()));
    query.bindValue(":buildyear", QString::fromStdString(c.getBuildYear()));
    query.bindValue(":type", QString::fromStdString(c.getType()));
    query.bindValue(":built", QString::number(c.getBuilt()));
    query.bindValue(":wikilink", QString::fromStdString(c.getWikilink()));
    query.bindValue(":imagepath", QString::fromStdString(c.getImagePath()));
    qDebug() << QString::fromStdString(c.getWikilink());
    if(query.exec()) {
        db.close();
        return true;
    } else {
        db.close();
        return false;
    }
}

bool ComputerRepository::remove(Computer c) {
    db.open();
    QSqlQuery query;
    qDebug() << "Calling remove on computer" << QString::fromStdString(c.getName());
    query.prepare("DELETE FROM Computers WHERE ID = :id");
    query.bindValue(":id", c.getID());

    if(query.exec()) {
        db.close();
        return true;
    } else {
        db.close();
        return false;
    }
}


vector<Computer> ComputerRepository::getSortedComputers(string sortOrder) {
    db.open();
    QSqlQuery query;

    if(sortOrder == "Name") {
        query.prepare("SELECT * FROM Computers ORDER BY Name");

    } else if(sortOrder == "Build Year") {
        query.prepare("SELECT * FROM Computers ORDER BY BuildYear");

    } else if(sortOrder == "Type") {
        query.prepare("SELECT * FROM Computers ORDER BY Type");

    } else if(sortOrder == "Built") {
        query.prepare("SELECT * FROM Computers ORDER BY Built");
    } else {
        query.prepare("SELECT * FROM Computers");
    }

    query.exec();

    vector<Computer> temp;

    while(query.next()) {
        Computer c;

        c.setName(query.value("Name").toString().toStdString());
        c.setBuildYear(query.value("BuildYear").toString().toStdString());
        c.setType(query.value("Type").toString().toStdString());
        c.setBuilt(query.value("Built").toInt());
        c.setID(query.value("ID").toInt());
        c.setWikilink(query.value("Wikilink").toString().toStdString());
        QString::fromStdString(c.getWikilink());
        c.setImagePath(query.value("ImagePath").toString().toStdString());

        temp.push_back(c);
    }
    db.close();
    return temp;
}


vector<Computer> ComputerRepository::search(string input, string word) {
    db.open();
    vector<Computer> temp;

    QString qinput = QString::fromStdString(input);

    QString likeInput = "%" + qinput + "%";


    QSqlQuery query;

    if(word == "Name") {
        query.prepare("SELECT * FROM Computers c WHERE c.Name LIKE :contains ORDER BY Name;");

    } else if(word == "Build Year") {
        query.prepare("SELECT * FROM Computers c WHERE c.BuildYear LIKE :contains ORDER BY Name");

    } else if(word == "Type") {
        query.prepare("SELECT * FROM Computers c WHERE c.Type LIKE :contains ORDER BY Name");

    } else {
        query.prepare("SELECT * FROM Computers c WHERE c.Built LIKE :contains ORDER BY Name");

    }

    query.bindValue(":contains",likeInput);
    query.exec();

    while(query.next()) {
        Computer c;

        c.setName(query.value("Name").toString().toStdString());
        c.setBuildYear(query.value("BuildYear").toString().toStdString());
        c.setType(query.value("Type").toString().toStdString());
        c.setBuilt(query.value("Built").toInt());
        c.setID(query.value("ID").toInt());
        c.setWikilink(query.value("Wikilink").toString().toStdString());
        c.setImagePath(query.value("ImagePath").toString().toStdString());

        temp.push_back(c);
    }
    db.close();
    return temp;

}

vector<Computer> ComputerRepository::getComputersFromScientist(Person scientist) {
    db.open();
    vector<Computer> temp;
    QSqlQuery query;
    query.prepare("SELECT * FROM Computers c JOIN Linker l ON l.c_ID = c.ID AND l.p_ID = ?");
    query.addBindValue(scientist.getID());
    query.exec();
    while(query.next()) {
        Computer c;

        c.setName(query.value("Name").toString().toStdString());
        c.setBuildYear(query.value("BuildYear").toString().toStdString());
        c.setType(query.value("Type").toString().toStdString());
        c.setBuilt(query.value("Built").toInt());
        c.setID(query.value("ID").toInt());
        c.setWikilink(query.value("Wikilink").toString().toStdString());
        c.setImagePath(query.value("ImagePath").toString().toStdString());

        temp.push_back(c);
    }

    db.close();
    return temp;
}

bool ComputerRepository::connectComputerToScientist(int PersonID, int ComputerID) {
    db.open();
    QSqlQuery query;
    query.prepare("INSERT INTO Linker(p_ID, c_ID) VALUES(:personID, :computerID)");
    query.bindValue(":personID", QString::number(PersonID));
    query.bindValue(":computerID", QString::number(ComputerID));
    if(!query.exec()) {
        db.close();
        return false;
    } else {
        db.close();
        return true;
    }

}
