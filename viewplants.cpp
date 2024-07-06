#include "viewplants.h"
#include "ui_viewplants.h"

ViewPlants::ViewPlants(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewPlants)
{
    ui->setupUi(this);
}

ViewPlants::~ViewPlants()
{
    delete ui;
    //delete model;
}
