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
    void on_search_field_textChanged();

    void on_button_add_clicked();

    //void on_button_delete_clicked();

    void on_search_field_2_textChanged();

    void on_comboBox_sort_by_person_activated();

    void on_comboBox_sort_by_computer_activated();

    void on_display_tab_tabBarClicked(int index);

    void on_actionAdd_computer_triggered();

    void on_actionAdd_Person_triggered();

    void on_actionForm_Connection_triggered();

private:
    Ui::MainWindow *ui;

    void setDisplay();
    void displayAll(bool searching);
    void displayComputers();
    void displayPersons();
    void displayConnections();

    AddDialog *addDialog;
    FormConnectionDialog *formConnectionDialog;

    std::vector<Person> currentPersons;
    std::vector<Computer> currentComputers;

    PersonService pService;
    ComputerService cService;

};

#endif // MAINWINDOW_H
