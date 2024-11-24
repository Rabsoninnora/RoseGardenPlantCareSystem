#include "availableplants.h"
#include "ui_availableplants.h"

AvailablePlants::AvailablePlants(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AvailablePlants)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

AvailablePlants::~AvailablePlants()
{
    delete ui;
}
