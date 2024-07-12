#include "species.h"
#include "ui_species.h"

Species::Species(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Species)
{
    ui->setupUi(this);
}

Species::~Species()
{
    delete ui;

}

void Species::on_btnSearch_clicked()
{


}

