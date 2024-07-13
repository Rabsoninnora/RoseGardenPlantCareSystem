#include "viewgardentools.h"
#include "ui_viewgardentools.h"

ViewGardenTools::ViewGardenTools(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewGardenTools)
{
    ui->setupUi(this);
}

ViewGardenTools::~ViewGardenTools()
{
    delete ui;
}
