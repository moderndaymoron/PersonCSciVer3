#ifndef SPECIFICVIEWDIALOG_H
#define SPECIFICVIEWDIALOG_H

#include <QDialog>
#include "PersonService.h"
#include "computerservice.h"
#include "person.h"
#include "computer.h"

namespace Ui {
class SpecificViewDialog;
}

class SpecificViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpecificViewDialog(QWidget *parent = 0, QString type = "", vector<Person> currentPersons = {}, vector<Computer> currentComputers  = {}, int index = 0);
    ~SpecificViewDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::SpecificViewDialog *ui;
    PersonService pService;
    ComputerService cService;

    Person displayedPerson;
    Computer displayedComputer;
    QString displayType;
};

#endif // SPECIFICVIEWDIALOG_H
