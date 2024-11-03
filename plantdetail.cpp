#include "plantdetail.h"
#include "ui_plantdetail.h"

PlantDetail::PlantDetail(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlantDetail)
{
    ui->setupUi(this);
}

PlantDetail::~PlantDetail()
{
    delete ui;
}
