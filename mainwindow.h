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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void on_display_tab_tabBarClicked();
private slots:
    //void on_type_dropdown_activated();

    void on_search_field_textChanged();

    void on_button_add_clicked();

    //void on_button_delete_clicked();

    void on_search_field_2_textChanged();

    void on_comboBox_sort_by_person_activated();

    //void on_comboBox_sort_by_person_activated(const QString &arg1);

    void on_comboBox_sort_by_computer_activated();

    void on_display_tab_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;

    void display();
    void displayAll(bool searching);
    void displayComputers();
    void displayPersons();

    AddDialog *addDialog;

    std::vector<Person> currentPersons;
    std::vector<Computer> currentComputers;

    PersonService pService;
    ComputerService cService;

};

#endif // MAINWINDOW_H
