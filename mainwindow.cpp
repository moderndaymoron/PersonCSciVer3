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
            ui->display_list->addItem(QString::fromStdString(currentPerson.getName()));
        }

    } else if(ui->type_dropdown->currentText() == "Computer") {
        if(!currentComputers.size() && !searching) {
            currentComputers = cService.getSortedComputers("Name");
        }
        qDebug() << currentComputers.size();
        for(unsigned int i = 0; i < currentComputers.size(); i++) {
            Computer currentComputer = currentComputers[i];
            ui->display_list->addItem(QString::fromStdString(currentComputer.getName()));
        }

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
    }
}
