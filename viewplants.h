#ifndef VIEWPLANTS_H
#define VIEWPLANTS_H
#include "mydb.h"
#include <QTableWidgetItem>

#include <QDialog>

namespace Ui {
class ViewPlants;
}

class ViewPlants : public QDialog
{
    Q_OBJECT

public:
    explicit ViewPlants(QWidget *parent = nullptr);
    ~ViewPlants();

private slots:



    void on_ViewPlantsRecord_clicked();

    void on_DeletePlantsRecord_clicked();

    void on_btn_print_PDF_clicked();

private:
    Ui::ViewPlants *ui;

    QSqlDatabase DB_SQLITE3;
    ViewPlants *tableWidget;
    ViewPlants *NumberOFRowsToDisplay;

};

#endif // VIEWPLANTS_H
