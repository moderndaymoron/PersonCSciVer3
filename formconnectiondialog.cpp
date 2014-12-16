#include "formconnectiondialog.h"
#include "ui_formconnectiondialog.h"

FormConnectionDialog::FormConnectionDialog(QWidget *parent) : QDialog(parent), ui(new Ui::FormConnectionDialog) {
    ui->setupUi(this);
    cService = ComputerService();
    pService = PersonService();

    vector<Person> personVec = pService.getSortedPersons("Name");
    for(int i = 0; i < personVec.size(); i++) {
        ui->Person_Connector_comboBox->addItem(QString::fromStdString(personVec[i].getName()));
    }

    vector<Computer> computerVec = cService.getSortedComputers("Name");
    for(int i = 0; i < computerVec.size(); i++) {
        ui->Computer_Connector_comboBox->addItem(QString::fromStdString(computerVec[i].getName()));
    }
}

FormConnectionDialog::~FormConnectionDialog() {
    delete ui;
}
void FormConnectionDialog::on_cancel_button_clicked(){
    FormConnectionDialog::close();
}

void FormConnectionDialog::on_form_connection_button_clicked() {
    vector<Person> pResult;
    pResult = pService.search(ui->Person_Connector_comboBox->currentText().toStdString(), "Name");

    vector<Computer> cResult;
    cResult = cService.search(ui->Computer_Connector_comboBox->currentText().toStdString(), "Name");

    cService.connectComputerToScientist(pResult[0].getID(), cResult[0].getID());
    FormConnectionDialog::close();
}
