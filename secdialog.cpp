#include "secdialog.h"
#include "ui_secdialog.h"

SecDialog::SecDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecDialog)

{
    ui->setupUi(this);

    ptrAddPlant = new AddPlant();
    ptrSpecies = new Species();
    ptrViewPlants = new ViewPlants();
    ptrAdmin = new Admin();

}

SecDialog::~SecDialog()
{

    delete ptrAddPlant;

    delete ptrAdmin;
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

//method on_AddPlant_clicked
void SecDialog::on_AddPlant_clicked()
{
    ptrAddPlant->show();
}

//method on_AdminPanel_clicked
void SecDialog::on_AdminPanel_clicked()
{
     ptrAdmin->show();
}



void SecDialog::on_btn_logout_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::warning(this,"Warning!", "You're about to Close the Application?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }

}

