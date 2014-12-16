#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "person.h"
#include "computer.h"
#include <string>
#include "personservice.h"
#include "computerservice.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0, QString AddType = "");
    ~AddDialog();

private slots:

    void on_ok_button_clicked();

    void on_browse_Button_clicked();

private:
    Ui::AddDialog *ui;
    PersonService pService;
    ComputerService cService;
};

#endif // ADDDIALOG_H
