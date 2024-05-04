#ifndef VIEWPLANTS_H
#define VIEWPLANTS_H

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

private:
    Ui::ViewPlants *ui;
};

#endif // VIEWPLANTS_H
