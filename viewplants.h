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
    void on_pushButton_clicked();

private:
    Ui::ViewPlants *ui;
};

#endif // VIEWPLANTS_H
