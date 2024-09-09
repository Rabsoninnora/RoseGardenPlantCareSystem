#include "suppliers.h"
#include "ui_suppliers.h"
#include "databaseheader.h"

Suppliers::Suppliers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Suppliers)
{
    ui->setupUi(this);
}

Suppliers::~Suppliers()
{
    delete ui;
}
