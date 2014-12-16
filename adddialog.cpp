#include <QFileDialog>
#include "adddialog.h"
#include "ui_adddialog.h"
#include "mainwindow.h"
AddDialog::AddDialog(QWidget *parent, QString AddType) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    ui->ErrorLabel->setText("");
    if(AddType == "Computers") {
        ui->Name_label->setText("Name:");
        ui->second_input_label->setText("Build Year (YYYY):");
        ui->third_input_label->setText("Type:");
        ui->fourth_input_label->setText("Built(0/1)?");

    } else if (AddType == "Persons") {
        ui->Name_label->setText("Name:");
        ui->second_input_label->setText("Gender (Male/Female):");
        ui->third_input_label->setText("Date of Birth (YYYY/MM/DD):");
        ui->fourth_input_label->setText("Date of Death (YYYY/MM/DD):");

    } else if (AddType == "Connections") {
        //TODO: display add screen for connection
    }
}


AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_ok_button_clicked() {
    if(ui->second_input_label->text() == "Gender (Male/Female):") {
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
    } else {
        Computer temp;
        temp.setName(ui->name_input->text().toStdString());
        temp.setBuildYear(ui->second_input->text().toStdString());
        temp.setType(ui->third_input->text().toStdString());
        temp.setBuilt(ui->fourth_input->text().toInt());

        if(temp.isValidComputer()) {
            cService.add(temp);
            AddDialog::close();
        } else {
            ui->ErrorLabel->setText("<b><span style='color:#FF0000'>ERROR: Invalid Computer Entered!</b>");
        }
    }
}


void AddDialog::on_browse_Button_clicked()
{
    QFileDialog::getOpenFileName(
                this,
                "Browse for image",
                "",
                "Image files (*.png, *.jpg, *.jpeg)"
                );
}
