#include "addgardener.h"
#include "ui_addgardener.h"

AddGardener::AddGardener(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddGardener)
{
    ui->setupUi(this);
}

AddGardener::~AddGardener()
{
    delete ui;
}

void AddGardener::on_btnSave_clicked()
{
    QString EmployeeID = ui->txtEmployeeID->text();

}

