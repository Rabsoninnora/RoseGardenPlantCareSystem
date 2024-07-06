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



private:
    Ui::ViewPlants *ui;
    //QSqlQueryModel *model;
};

#endif // VIEWPLANTS_H
