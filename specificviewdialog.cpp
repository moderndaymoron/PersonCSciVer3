#include "specificviewdialog.h"
#include "ui_specificviewdialog.h"
#include <QDesktopServices>
#include <QUrl>

SpecificViewDialog::SpecificViewDialog(QWidget *parent, QString type, vector<Person> currentPersons, vector<Computer> currentComputers, int index) : QDialog(parent), ui(new Ui::SpecificViewDialog) {
    ui->setupUi(this);
    if(type == "Person") {
        displayedPerson = currentPersons[index];
        displayType = "Person";

    } else if(type == "Computer") {
        displayedComputer = currentComputers[index];
        displayType = "Computer";
    }
}

SpecificViewDialog::~SpecificViewDialog() {
    delete ui;
}

void SpecificViewDialog::on_pushButton_2_clicked() {
    SpecificViewDialog::close();
}



void SpecificViewDialog::on_pushButton_clicked() {
    if(displayType == "Person") {
        qDebug() << QString::fromStdString(displayedPerson.getName());
        QString link = QString::fromStdString(displayedPerson.getWikilink());
        //QString link = "www.google.com";
        qDebug() << "Attempting to open this url: " << link;
        QDesktopServices::openUrl(QUrl(link));
    }
}
