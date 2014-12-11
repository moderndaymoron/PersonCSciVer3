#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "person.h"
#include "computer.h"
#include "personservice.h"
#include "computerservice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_type_dropdown_activated();

    void on_search_field_textChanged();

private:
    Ui::MainWindow *ui;

    void display();
    void displayAll(bool searching);

    std::vector<Person> currentPersons;
    std::vector<Computer> currentComputers;

    PersonService pService;
    ComputerService cService;
};

#endif // MAINWINDOW_H
