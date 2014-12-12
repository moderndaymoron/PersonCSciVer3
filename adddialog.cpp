#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent, QString AddType) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    ui->ErrorLabel->setText("");
    if(AddType == "Computer") {
        ui->Name_label->setText("Name:");
        ui->second_input_label->setText("Build Year (YYYY):");
        ui->third_input_label->setText("Type:");
        ui->fourth_input_label->setText("Built(0/1)?");

    } else if (AddType == "Person") {
        ui->Name_label->setText("Name:");
        ui->second_input_label->setText("Gender (Male/Female):");
        ui->third_input_label->setText("Date of Birth (YYYY/MM/DD):");
        ui->fourth_input_label->setText("Date of Death (YYYY/MM/DD):");

    } else if (AddType == "Connection") {
        //TODO: display add screen for connection
    }
}


AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_ok_button_clicked() {
        Person temp;
        temp.setName(ui->name_input->text().toStdString());
        temp.setGender(ui->second_input->text().toStdString());
        temp.setDayOfBirth(ui->third_input->text().toStdString());
        temp.setDayOfDeath(ui->fourth_input->text().toStdString());
        if(temp.isValidPerson()) {
            pService.add(temp);
            AddDialog::close();
        } else {
            ui->ErrorLabel->setText("<b><span style='color:#FF0000'>ERROR: Invalid Person Entered!</b>");
        }
}

