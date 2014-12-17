#include "specificviewdialog.h"
#include "ui_specificviewdialog.h"
#include <QDesktopServices>
#include <QUrl>

SpecificViewDialog::SpecificViewDialog(QWidget *parent, QString type, vector<Person> currentPersons, vector<Computer> currentComputers, int index) : QDialog(parent), ui(new Ui::SpecificViewDialog) {
    ui->setupUi(this);
    if(type == "Person") {
        displayedPerson = currentPersons[index];
        displayType = "Person";

        qDebug() << "Image path: " << QString::fromStdString(displayedPerson.getImagePath());

        if(displayedPerson.getImagePath() != "") {
            QPixmap pixmap(QString::fromStdString(displayedPerson.getImagePath()));
            ui->label_image->setPixmap(pixmap);
            ui->label_image->setScaledContents(true);
        } else {
            ui->label_image->setText("<b><span style='color:#FF0000'>No picture found.</b>");
        }

        ui->First_label->setText("Name:");
        ui->First_label_answer->setText(QString::fromStdString(displayedPerson.getName()));
        ui->Second_label->setText("Gender:");
        ui->Second_label_answer->setText(QString::fromStdString(displayedPerson.getGender()));
        ui->Third_label->setText("Date Of Birth:");
        ui->Third_label_answer->setText(QString::fromStdString(displayedPerson.getDayOfBirth()));
        ui->Fourth_label->setText("Date Of Death:");
        ui->Fourth_label_answer->setText(QString::fromStdString(displayedPerson.getDayOfDeath()));

    } else if(type == "Computer") {
        displayedComputer = currentComputers[index];
        displayType = "Computer";

        qDebug() << "Image path: " << QString::fromStdString(displayedComputer.getImagePath());

        if(displayedPerson.getImagePath() != "") {
            QPixmap pixmap(QString::fromStdString(displayedComputer.getImagePath()));
            ui->label_image->setPixmap(pixmap);
            ui->label_image->setScaledContents(true);

        } else {
            ui->label_image->setText("<b><span style='color:#FF0000'>No picture found.</b>");
        }

        ui->First_label->setText("Name:");
        ui->First_label_answer->setText(QString::fromStdString(displayedComputer.getName()));
        ui->Second_label->setText("Build Year:");
        ui->Second_label_answer->setText(QString::fromStdString(displayedComputer.getBuildYear()));
        ui->Third_label->setText("Type:");
        ui->Third_label_answer->setText(QString::fromStdString(displayedComputer.getType()));
        ui->Fourth_label->setText("Built?");
        ui->Fourth_label_answer->setText(QString::number(displayedComputer.getBuilt()));


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
        qDebug() << "Attempting to open this url: " << link;
        QDesktopServices::openUrl(QUrl(link));

    } else if(displayType == "Computer") {
        qDebug() << QString::fromStdString(displayedComputer.getName());
        QString link = QString::fromStdString(displayedComputer.getWikilink());
        qDebug() << "Attemption to open this url: " << link;
        QDesktopServices::openUrl(QUrl(link));
    }
}
