#include "viewsystemadmin.h"
#include "ui_viewsystemadmin.h"

ViewSystemAdmin::ViewSystemAdmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewSystemAdmin)
{
    ui->setupUi(this);
}

ViewSystemAdmin::~ViewSystemAdmin()
{
    delete ui;
}
