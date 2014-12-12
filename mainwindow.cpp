#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->type_dropdown->addItem("Person");
    ui->type_dropdown->addItem("Computer");
    ui->type_dropdown->addItem("Connection");
    on_type_dropdown_activated();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_type_dropdown_activated()
{
    ui->button_add->setEnabled(true);
    ui->search_by_dropdown->clear();
    if(ui->type_dropdown->currentText() == "Person") {
        ui->search_by_dropdown->addItem("Name");
        ui->search_by_dropdown->addItem("Gender");
        ui->search_by_dropdown->addItem("Date Of Birth");
        ui->search_by_dropdown->addItem("Date Of Death");

        ui->DisplayTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
        ui->DisplayTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Gender"));
        ui->DisplayTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Date Of Birth"));
        ui->DisplayTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Date of Death"));

    } else if(ui->type_dropdown->currentText() == "Computer") {
        ui->search_by_dropdown->addItem("Name");
        ui->search_by_dropdown->addItem("Build Year");
        ui->search_by_dropdown->addItem("Type");
        ui->search_by_dropdown->addItem("Built (boolean)");

        ui->DisplayTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
        ui->DisplayTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Build Year"));
        ui->DisplayTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Type"));
        ui->DisplayTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Built?"));
    }
    displayAll(false);
}

void MainWindow::displayAll(bool searching) {
    ui->DisplayTable->clearContents();
    qDebug() << "Calling display all";

    if(ui->type_dropdown->currentText() == "Person") {
        if(!currentPersons.size() && !searching) {
            currentPersons = pService.getSortedPersons("Name");
        }
        qDebug() << currentPersons.size();
        ui->DisplayTable->setRowCount(currentPersons.size());
        for(unsigned int i = 0; i < currentPersons.size(); i++) {
            Person currentPerson = currentPersons[i];

            QString personName = QString::fromStdString(currentPerson.getName());
            QString personGender = QString::fromStdString(currentPerson.getGender());
            QString personDateOfBirth = QString::fromStdString(currentPerson.getDayOfBirth());
            QString personDateOfDeath = QString::fromStdString(currentPerson.getDayOfDeath());

            ui->DisplayTable->setItem(i, 0, new QTableWidgetItem(personName));
            ui->DisplayTable->setItem(i, 1, new QTableWidgetItem(personGender));
            ui->DisplayTable->setItem(i, 2, new QTableWidgetItem(personDateOfBirth));
            ui->DisplayTable->setItem(i, 3, new QTableWidgetItem(personDateOfDeath));

        }

    } else if(ui->type_dropdown->currentText() == "Computer") {
        if(!currentComputers.size() && !searching) {
            currentComputers = cService.getSortedComputers("Name");
        }
        qDebug() << currentComputers.size();
        ui->DisplayTable->setRowCount(currentComputers.size());
        for(unsigned int i = 0; i < currentComputers.size(); i++) {
            Computer currentComputer = currentComputers[i];

            QString computerName = QString::fromStdString(currentComputer.getName());
            QString computerBuildYear = QString::fromStdString(currentComputer.getBuildYear());
            QString computerType = QString::fromStdString(currentComputer.getType());
            QString computerBuilt = QString::number(currentComputer.getBuilt());

            ui->DisplayTable->setItem(i, 0, new QTableWidgetItem(computerName));
            ui->DisplayTable->setItem(i, 1, new QTableWidgetItem(computerBuildYear));
            ui->DisplayTable->setItem(i, 2, new QTableWidgetItem(computerType));
            ui->DisplayTable->setItem(i, 3, new QTableWidgetItem(computerBuilt));
        }

    } else {
        //TODO: get and display connections
    }

}

void MainWindow::on_search_field_textChanged() {
    string searchInput = ui->search_field->text().toStdString();
    string searchType = ui->search_by_dropdown->currentText().toStdString();

    bool searching = true;

    if(ui->type_dropdown->currentText() == "Person") {
        currentPersons = pService.search(searchInput, searchType);
        displayAll(searching);
    } else if(ui->type_dropdown->currentText() == "Computer") {
        currentComputers = cService.search(searchInput, searchType);
        displayAll(searching);
    } else {
        //TODO: Search connections
    }
}

void MainWindow::on_button_add_clicked() {
    addDialog = new AddDialog(this, ui->type_dropdown->currentText());
    addDialog->show();
}

void MainWindow::on_button_delete_clicked()
{
    if(ui->type_dropdown->currentText() == "Person") {

    } else if(ui->type_dropdown->currentText() == "Computer") {

    } else {

    }
}
