#include "secdialog.h"
#include "ui_secdialog.h"

SecDialog::SecDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    ptrAddGardener = new AddGardener();
    ptrAddPlant = new AddPlant();
    ptrAdminPanel = new AdminPanel();
    ptrGardenerDetails = new GardenerDetails();
    ptrSpecies = new Species();
    ptrViewPlants = new ViewPlants();
}

SecDialog::~SecDialog()
{
    delete ptrAddGardener;
    delete ptrAddPlant;
    delete ptrAdminPanel;
    delete ptrGardenerDetails;
    delete ptrSpecies;
    delete ptrViewPlants;
    delete ui;
}


//method on_ViewSpecies_clicked
void SecDialog::on_ViewSpecies_clicked()
{
  ptrSpecies->show();
}

//method on_ViewPlants_clicked
void SecDialog::on_ViewPlants_clicked()
{
  ptrViewPlants->show();
}

//methos on_AddPlant_clicked
void SecDialog::on_AddPlant_clicked()
{
    ptrAddPlant->show();
}

//method on_AdminPanel_clicked
void SecDialog::on_AdminPanel_clicked()
{
    ptrAdminPanel->show();
}

//method on_AddGardener_clicked
void SecDialog::on_AddGardener_clicked()
{
    ptrAddGardener->show();
}

//method on_GardenerDetails_clicked
void SecDialog::on_GardenerDetails_clicked()
{
    ptrGardenerDetails->show();
}
