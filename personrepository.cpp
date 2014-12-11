#include "PersonRepository.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <QtSql>


using namespace std;

PersonRepository::PersonRepository() {
    if(QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("PersonCompSci.sqlite");
        db.open();
    }
}

PersonRepository::~PersonRepository() {
    db.close();
}

bool PersonRepository::add(Person p) {
    db.open();
    QSqlQuery query;
    query.prepare("INSERT INTO Persons(Name, Gender, DateOfBirth, DateOfDeath)"
                  "VALUES (:name, :gender, :dateofbirth, :dateofdeath)");
    query.bindValue(":name", QString::fromStdString(p.getName()));
    query.bindValue(":gender", QString::fromStdString(p.getGender()));
    query.bindValue(":dateofbirth", QString::fromStdString(p.getDayOfBirth()));
    query.bindValue(":dateofdeath", QString::fromStdString(p.getDayOfDeath()));
    query.exec();
    db.close();
    return true;

}

vector<Person> PersonRepository::getSortedPersons(string sortOrder) {
    db.open();
    QSqlQuery q;

    if(sortOrder == "Name") {
        q.prepare("SELECT * FROM Persons ORDER BY Name");

    } else if(sortOrder == "Gender") {
        q.prepare("SELECT * FROM Persons ORDER BY Gender");

    } else if(sortOrder == "Date Of Birth") {
        q.prepare("SELECT * FROM Persons ORDER BY DateOfBirth");

    } else if(sortOrder == "Date Of Death") {
        q.prepare("SELECT * FROM Persons ORDER BY DateOfDeath");
    } else {
        q.prepare("SELECT * FROM Persons");
    }

    q.exec();

    vector<Person> temp;

    while(q.next()) {
        Person p;

        p.setName(q.value("Name").toString().toStdString());
        p.setGender(q.value("Gender").toString().toStdString());
        p.setDayOfBirth(q.value("DateOfBirth").toString().toStdString());
        p.setDayOfDeath(q.value("DateOfDeath").toString().toStdString());
        p.setID(q.value("ID").toInt());

        temp.push_back(p);
    }
    db.close();
    return temp;
}

QSqlDatabase PersonRepository::getDatabaseConnection() {
    QString connectionName = "PersonConnection";
    QSqlDatabase db;
    if(QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName("PersonCompSci.sqlite");
        db.open();
    }
    return db;
}


vector<Person> PersonRepository::search(string input, string word) {
    db.open();
    vector<Person> temp;

    QString qinput = QString::fromStdString(input);
    QString likeInput = "%" + qinput + "%";


    QSqlQuery query;

    if(word == "Name") {
        query.prepare("SELECT * FROM Persons p WHERE p.Name LIKE :contains ORDER BY Name");
        query.bindValue(":contains",likeInput);

    } else if(word == "Gender") {
        query.prepare("SELECT * FROM Persons p WHERE p.Gender LIKE :contains ORDER BY Name");
        query.bindValue(":contains",likeInput);

    } else if(word == "Date Of Birth") {
        query.prepare("SELECT * FROM Persons p WHERE p.DateOfBirth LIKE :contains ORDER BY Name");
        query.bindValue(":contains",likeInput);

    } else {
        query.prepare("SELECT * FROM Persons p WHERE p.DateOfDeath LIKE :contains ORDER BY Name");
        query.bindValue(":contains",likeInput);
    }

    query.exec();

    while(query.next()) {
        Person tempP;

        tempP.setName(query.value("Name").toString().toStdString());
        tempP.setGender(query.value("Gender").toString().toStdString());
        tempP.setDayOfBirth(query.value("DateOfBirth").toString().toStdString());
        tempP.setDayOfDeath(query.value("DateOfDeath").toString().toStdString());
        tempP.setID(query.value("ID").toInt());

        temp.push_back(tempP);
    }
    db.close();
    return temp;

}




/*double PersonRepository::getSize() {
    return plist.size();
}*/
