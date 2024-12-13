#include "adminpanel.h"
#include "ui_adminpanel.h"


AdminPanel::AdminPanel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
    this->showFullScreen();
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);


    ptrAddPlant = new AddPlant();
    ptrAddgardentool   = new AddGardenTool();

    ptrSuppliers       = new Suppliers();
    ptrAddGardener     = new AddGardener();
    ptrGardenerDetails = new GardenerDetails();
    ptrViewPlants = new ViewPlants();
    ptrAddUser = new AddUser();



}

AdminPanel::~AdminPanel()
{

    delete ptrAddgardentool;


    delete ptrSuppliers;
    delete ptrAddGardener;
    delete ptrGardenerDetails;
    delete ptrAddPlant;

    delete ptrViewPlants;
    delete ptrAddUser;

    delete ui;


}




void AdminPanel::on_AddGardenTool_clicked()
{
  ptrAddgardentool->show();

}








void AdminPanel::on_btn_Add_Admin_clicked()
{
  ptrAddUser->show();

}




void AdminPanel::on_btn_Add_Supplier_clicked()
{
    ptrSuppliers->show();

}


void AdminPanel::on_btn_Employees_clicked()
{
   ptrAddGardener->show();

}


void AdminPanel::on_btn_employee_view_clicked()
{
    ptrGardenerDetails->show();

}


void AdminPanel::on_Admin_panel_close_app_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::warning(this,"Warning!", "You're about to Close the Application?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


void AdminPanel::on_AddPlant_clicked()
{
    ptrAddPlant->show();

}




void AdminPanel::on_btn_view_plant_dmin_clicked()
{
   ptrViewPlants->show();

}








void AdminPanel::on_Admin_panel_close_log_out_clicked()
{
    this->close();
}

