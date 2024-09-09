#include "adminpanel.h"
#include "ui_adminpanel.h"

AdminPanel::AdminPanel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
    ptrAddgardentool   = new AddGardenTool();
    ptrViewGardenTools = new ViewGardenTools();
    ptrAddSystemAdmin  = new AddSystemAdmin();
    ptrViewSystemAdmin = new ViewSystemAdmin();
    ptrAvailablePlants = new AvailablePlants();
    ptrSuppliers       = new Suppliers();

}

AdminPanel::~AdminPanel()
{

    delete ptrAddgardentool;
    delete ptrViewGardenTools;
    delete ptrAddSystemAdmin;
    delete ptrViewSystemAdmin;
    delete ptrAvailablePlants;
    delete ptrSuppliers;
    delete ui;

}




void AdminPanel::on_AddGardenTool_clicked()
{
  ptrAddgardentool->show();
}


void AdminPanel::on_ViewGardenTools_clicked()
{
    ptrViewGardenTools->show();
}


void AdminPanel::on_btn_Available_Plants_clicked()
{
   ptrAvailablePlants->show();
}


void AdminPanel::on_btn_Add_Admin_clicked()
{
  ptrAddSystemAdmin->show();
}




void AdminPanel::on_btn_Add_Supplier_clicked()
{
    ptrSuppliers->show();
}

