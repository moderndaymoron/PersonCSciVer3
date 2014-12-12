#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "person.h"
#include "computer.h"
#include <string>
#include "personservice.h"

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

private:
    Ui::AddDialog *ui;
    PersonService pService;
};

#endif // ADDDIALOG_H
