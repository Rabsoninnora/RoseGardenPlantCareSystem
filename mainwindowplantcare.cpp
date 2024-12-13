#include "mainwindowplantcare.h"
#include "./ui_mainwindowplantcare.h"



MainWindowPlantCare::MainWindowPlantCare(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowPlantCare)
{
    ui->setupUi(this);
    this->showFullScreen();


    //Add admin login and user login separately
    ptrAdminLogin = new AdminLogin();
    ptrUserLogin  = new UserLogin();


}

MainWindowPlantCare::~MainWindowPlantCare()
{
    delete ui;
    delete  ptrAdminLogin;
    delete  ptrUserLogin;
}





void MainWindowPlantCare::on_pushButton_3_clicked()
{
  ptrAdminLogin->show();
}


void MainWindowPlantCare::on_pushButton_4_clicked()
{
   ptrUserLogin->show();
}

