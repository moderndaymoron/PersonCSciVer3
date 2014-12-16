#ifndef FORMCONNECTIONDIALOG_H
#define FORMCONNECTIONDIALOG_H

#include <QDialog>
#include "personservice.h"
#include "computerservice.h"

namespace Ui {
class FormConnectionDialog;
}

class FormConnectionDialog : public QDialog {
    Q_OBJECT

public:
    explicit FormConnectionDialog(QWidget *parent = 0);
    ~FormConnectionDialog();

private slots:


    void on_cancel_button_clicked();

    void on_form_connection_button_clicked();

private:
    Ui::FormConnectionDialog *ui;
    ComputerService cService;
    PersonService pService;
};

#endif // FORMCONNECTIONDIALOG_H
