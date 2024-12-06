#include "secdialog.h"
#include "ui_secdialog.h"

SecDialog::SecDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecDialog)

{
    ui->setupUi(this);
    this->showFullScreen();
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);



    ptrSpecies = new Species();
    ptrViewPlants = new ViewPlants();

    ptrPlantDetail = new PlantDetail();


}

SecDialog::~SecDialog()
{




    delete ptrSpecies;
    delete ptrViewPlants;
    delete ptrPlantDetail;
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










void SecDialog::on_btn_Plant_Detail_clicked()
{
    ptrPlantDetail->show();
}


void SecDialog::on_btn_user_admin_close_app_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::warning(this,"Warning!", "You're about to Close the Application?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }

}


void SecDialog::on_btn_back_userdashboard_clicked()
{
    this->close();
}


void SecDialog::on_btn_logout_1_clicked()
{
     this->close();
}

