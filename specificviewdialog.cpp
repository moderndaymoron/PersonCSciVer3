#include "specificviewdialog.h"
#include "ui_specificviewdialog.h"

SpecificViewDialog::SpecificViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpecificViewDialog)
{
    ui->setupUi(this);
}

SpecificViewDialog::~SpecificViewDialog()
{
    delete ui;
}
