#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->display_tab->setCurrentIndex(0);
    display();
    on_comboBox_sort_by_person_activated();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::display()
{
    ui->button_add->setEnabled(true);
    ui->search_by_dropdown->clear();
    ui->search_by_dropdown_2->clear();

        ui->search_by_dropdown->addItem("Name");
        ui->search_by_dropdown->addItem("Gender");
        ui->search_by_dropdown->addItem("Date Of Birth");
        ui->search_by_dropdown->addItem("Date Of Death");

        ui->DisplayTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
        ui->DisplayTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Gender"));
        ui->DisplayTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Date Of Birth"));
        ui->DisplayTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Date Of Death"));

        ui->search_by_dropdown_2->addItem("Name");
        ui->search_by_dropdown_2->addItem("Build Year");
        ui->search_by_dropdown_2->addItem("Type");
        ui->search_by_dropdown_2->addItem("Built (boolean)");

        ui->DisplayTable_2->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
        ui->DisplayTable_2->setHorizontalHeaderItem(1, new QTableWidgetItem("Build Year"));
        ui->DisplayTable_2->setHorizontalHeaderItem(2, new QTableWidgetItem("Type"));
        ui->DisplayTable_2->setHorizontalHeaderItem(3, new QTableWidgetItem("Built?"));

    displayAll(false);
}

void MainWindow::displayAll(bool searching) {
    ui->DisplayTable->clearContents();
    ui->DisplayTable_2->clearContents();
    qDebug() << "Calling display all";
    if(ui->display_tab->currentIndex() == 0) {
        if(!currentPersons.size() && !searching) {
            currentPersons = pService.getSortedPersons("Name");
            //on_comboBox_sort_by_person_activated();
            qDebug() << "!CP.size && !searching";
        }
        qDebug() << "getting persons size" << currentPersons.size();
        on_comboBox_sort_by_person_activated();


    } else if(ui->display_tab->currentIndex() == 1) {
        if(!currentComputers.size() && !searching) {
            currentComputers = cService.getSortedComputers("Name");
            qDebug() << "!CC.size && !searching";
        }
        qDebug() << "getting computer size" <<currentComputers.size();
        on_comboBox_sort_by_computer_activated();

        /*ui->DisplayTable_2->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
        ui->DisplayTable_2->setHorizontalHeaderItem(1, new QTableWidgetItem("Build Year"));
        ui->DisplayTable_2->setHorizontalHeaderItem(2, new QTableWidgetItem("Type"));
        ui->DisplayTable_2->setHorizontalHeaderItem(3, new QTableWidgetItem("Built?"));*/
    } else {
        //TODO: get and display connections
    }

}

void MainWindow::displayPersons() {

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
}

void MainWindow::on_search_field_textChanged() {
    ui->display_tab->setCurrentIndex(0);
    string searchInput = ui->search_field->text().toStdString();
    string searchType = ui->search_by_dropdown->currentText().toStdString();

    bool searching = true;
    qDebug() << ui->display_tab->currentIndex();
    if(ui->display_tab->currentIndex() == 0) {
        currentPersons = pService.search(searchInput, searchType);
        displayAll(searching);

    } else {
        //TODO: Search connections
    }
}

void MainWindow::on_button_add_clicked() {

    if(ui->display_tab->currentIndex() == 0) {
    addDialog = new AddDialog(this, ui->display_tab->tabText(0));
    }else if(ui->display_tab->currentIndex() == 1) {
        addDialog = new AddDialog(this, ui->display_tab->tabText(1));
    }
    addDialog->show();
}

/*void MainWindow::on_button_delete_clicked()
{
    if(ui-> display_tab->tabText() == "Person") {

    } else if(ui->display_tab->tabText() == "Computer") {

    } else {

    }
}
*/

void MainWindow::on_search_field_2_textChanged() {
       ui->display_tab->setCurrentIndex(1);
       string searchInput = ui->search_field_2->text().toStdString();
       string searchType = ui->search_by_dropdown_2->currentText().toStdString();

       bool searching = true;

      if(ui->display_tab->currentIndex() == 1) {
           currentComputers = cService.search(searchInput, searchType);
           displayAll(searching);
       } else {
           //TODO: Search connections
       }
}

void MainWindow::on_comboBox_sort_by_person_activated() {

    if(ui->comboBox_sort_by_person->currentText() == "Name") {
        currentPersons = pService.getSortedPersons("Name");
        displayPersons();
    }else if(ui->comboBox_sort_by_person->currentText() == "Gender") {
        currentPersons = pService.getSortedPersons("Gender");
        displayPersons();
    }else if(ui->comboBox_sort_by_person->currentText() == "Date of Birth") {
        currentPersons = pService.getSortedPersons("Date Of Birth");
        displayPersons();
    }else if(ui->comboBox_sort_by_person->currentText() == "Date of Death"){
        currentPersons = pService.getSortedPersons("Date Of Death");
        displayPersons();
    }
}

void MainWindow::on_comboBox_sort_by_computer_activated()
{
    if(ui->comboBox_sort_by_computer->currentText() == "Name") {
        currentComputers = cService.getSortedComputers("Name");
        displayComputers();
    } else if(ui->comboBox_sort_by_computer->currentText() == "Build Year") {
        currentComputers = cService.getSortedComputers("Build Year");
        displayComputers();
    } else if(ui->comboBox_sort_by_computer->currentText() == "Type"){
        currentComputers = cService.getSortedComputers("Type");
        displayComputers();
    } else if(ui->comboBox_sort_by_computer->currentText() == "Built?") {
        currentComputers = cService.getSortedComputers("Built");
        displayComputers();
    }
}
void MainWindow::displayComputers() {

    ui->DisplayTable_2->setRowCount(currentComputers.size());
    for(unsigned int i = 0; i < currentComputers.size(); i++) {
        Computer currentComputer = currentComputers[i];

        QString computerName = QString::fromStdString(currentComputer.getName());
        QString computerBuildYear = QString::fromStdString(currentComputer.getBuildYear());
        QString computerType = QString::fromStdString(currentComputer.getType());
        QString computerBuilt = QString::number(currentComputer.getBuilt());

        ui->DisplayTable_2->setItem(i, 0, new QTableWidgetItem(computerName));
        ui->DisplayTable_2->setItem(i, 1, new QTableWidgetItem(computerBuildYear));
        ui->DisplayTable_2->setItem(i, 2, new QTableWidgetItem(computerType));
        ui->DisplayTable_2->setItem(i, 3, new QTableWidgetItem(computerBuilt));
    }

}
