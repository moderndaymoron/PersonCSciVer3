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
    } else if(ui->type_dropdown->currentText() == "Computer") {
        ui->search_by_dropdown->addItem("Name");
        ui->search_by_dropdown->addItem("Build Year");
        ui->search_by_dropdown->addItem("Type");
        ui->search_by_dropdown->addItem("Built (boolean)");
    }
    displayAll(false);
}

void MainWindow::displayAll(bool searching) {
    ui->display_list->clear();
    qDebug() << "Calling display all";
    if(ui->type_dropdown->currentText() == "Person") {
        if(!currentPersons.size() && !searching) {
            currentPersons = pService.getSortedPersons("Name");
        }
        qDebug() << currentPersons.size();
        for(unsigned int i = 0; i < currentPersons.size(); i++) {
            Person currentPerson = currentPersons[i];
            string PersonStr = currentPerson.getName() + ", " + currentPerson.getGender() + ", " + currentPerson.getDayOfBirth() + ", " + currentPerson.getDayOfDeath() + ".";
            ui->display_list->addItem(QString::fromStdString(PersonStr));
        }

    } else if(ui->type_dropdown->currentText() == "Computer") {
        if(!currentComputers.size() && !searching) {
            currentComputers = cService.getSortedComputers("Name");
        }
        qDebug() << currentComputers.size();
        for(unsigned int i = 0; i < currentComputers.size(); i++) {
            Computer currentComputer = currentComputers[i];
            string ComputerStr = currentComputer.getName() + ", " + currentComputer.getBuildYear() + ", " + currentComputer.getType() + ", ";
            if(currentComputer.getBuilt()) {
                ComputerStr += "true.";
            } else {
                ComputerStr += "false.";
            }
            ui->display_list->addItem(QString::fromStdString(ComputerStr));
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

void MainWindow::on_display_list_clicked(const QModelIndex &index)
{
    ui->button_delete->setEnabled(true);
}
