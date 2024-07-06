#ifndef VIEWPLANTS_H
#define VIEWPLANTS_H
#include "databaseheader.h"

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

    void on_btn_ReadData_clicked();

    void on_btn_home_clicked();

private:
    Ui::ViewPlants *ui;
    //QSqlQueryModel *model;
};

#endif // VIEWPLANTS_H
