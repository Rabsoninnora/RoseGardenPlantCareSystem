#include "addgardentool.h"
#include "ui_addgardentool.h"

AddGardenTool::AddGardenTool(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddGardenTool)
{
    ui->setupUi(this);
}

AddGardenTool::~AddGardenTool()
{
    delete ui;
}
