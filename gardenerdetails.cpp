#include "gardenerdetails.h"
#include "ui_gardenerdetails.h"

GardenerDetails::GardenerDetails(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GardenerDetails)
{
    ui->setupUi(this);
}

GardenerDetails::~GardenerDetails()
{
    delete ui;
}
