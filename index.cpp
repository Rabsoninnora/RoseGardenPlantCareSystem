#include "index.h"
#include "ui_index.h"

index::index(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::index)
{
    ui->setupUi(this);
}

index::~index()
{
    delete ui;
}
