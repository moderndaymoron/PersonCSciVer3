#ifndef SPECIFICVIEWDIALOG_H
#define SPECIFICVIEWDIALOG_H

#include <QDialog>

namespace Ui {
class SpecificViewDialog;
}

class SpecificViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpecificViewDialog(QWidget *parent = 0);
    ~SpecificViewDialog();

private:
    Ui::SpecificViewDialog *ui;
};

#endif // SPECIFICVIEWDIALOG_H
