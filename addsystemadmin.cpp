#include "addsystemadmin.h"
#include "ui_addsystemadmin.h"

AddSystemAdmin::AddSystemAdmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddSystemAdmin)
{
    ui->setupUi(this);
}

AddSystemAdmin::~AddSystemAdmin()
{
    delete ui;
}
