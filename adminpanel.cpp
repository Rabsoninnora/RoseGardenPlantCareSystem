#include "adminpanel.h"
#include "ui_adminpanel.h"


AdminPanel::AdminPanel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminPanel)
{
    ui->setupUi(this);

    ptrAddPlant = new AddPlant();
    ptrAddgardentool   = new AddGardenTool();
    ptrViewGardenTools = new ViewGardenTools();
    ptrAddSystemAdmin  = new AddSystemAdmin();
    ptrViewSystemAdmin = new ViewSystemAdmin();
    ptrAvailablePlants = new AvailablePlants();
    ptrSuppliers       = new Suppliers();
    ptrAddGardener     = new AddGardener();
    ptrGardenerDetails = new GardenerDetails();
    ptrViewPlants = new ViewPlants();
    ptrSpecies = new Species();
    ptrPlantDetail = new PlantDetail();


}

AdminPanel::~AdminPanel()
{

    delete ptrAddgardentool;
    delete ptrViewGardenTools;
    delete ptrAddSystemAdmin;
    delete ptrViewSystemAdmin;
    delete ptrAvailablePlants;
    delete ptrSuppliers;
    delete ptrAddGardener;
    delete ptrGardenerDetails;
    delete ptrAddPlant;
    delete ptrPlantDetail;
    delete ptrSpecies;
    delete ptrViewPlants;

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


void AdminPanel::on_btn_view_plant_detial_BY_ID_clicked()
{
 ptrPlantDetail->show();
}


void AdminPanel::on_btn_view_plant_dmin_clicked()
{
   ptrViewPlants->show();
}


void AdminPanel::on_btn_search_species_admin_clicked()
{
   ptrSpecies->show();
}


void AdminPanel::on_btn_view_Available_Plants_Admin_clicked()
{

}

