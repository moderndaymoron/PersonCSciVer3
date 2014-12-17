#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QWidget>
#include "person.h"
#include "computer.h"
#include "personservice.h"
#include "computerservice.h"
#include "adddialog.h"
#include "formconnectiondialog.h"
#include "aboutdialog.h"
#include "specificviewdialog.h"

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
    //searches after each event
    void on_search_field_textChanged();
    //launches the add dialog
    void on_button_add_clicked();
    //searches after each event
    void on_search_field_2_textChanged();
    //handles the sorting options avalible for persons
    void on_comboBox_sort_by_person_activated();
    //handles the sorting options avalible for computers
    void on_comboBox_sort_by_computer_activated();
    //displays items depending on tab index
    void on_display_tab_tabBarClicked(int index);
    //removes entry
    void on_button_delete_clicked();
    //another way to enter add dialog
    void on_actionAdd_computer_triggered();
    //another way to enter add dialog
    void on_actionAdd_Person_triggered();
    //another way to enter add dialog
    void on_actionForm_Connection_triggered();
    //launches the about dialog
    void on_actionAbout_triggered();
    //delete button enabled
    void on_DisplayTable_clicked(const QModelIndex &index);
    //delete button enabled
    void on_DisplayTable_2_clicked(const QModelIndex &index);
    //launches specificview dialog
    void on_DisplayTable_2_doubleClicked(const QModelIndex &index);
    //launches specificview dialog
    void on_DisplayTable_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    //sets columns and combo box options
    void setDisplay();
    //display the items
    void displayAll(bool searching);
    //to prevent repeated code
    void displayComputers();
    //to prevent repeated code
    void displayPersons();
    //displays linked person and computer
    void displayConnections();

    AddDialog *addDialog;
    AboutDialog *aboutDialog;
    FormConnectionDialog *formConnectionDialog;
    SpecificViewDialog *specificViewDialog;

    std::vector<Person> currentPersons;
    std::vector<Computer> currentComputers;

    PersonService pService;
    ComputerService cService;

};

#endif // MAINWINDOW_H
