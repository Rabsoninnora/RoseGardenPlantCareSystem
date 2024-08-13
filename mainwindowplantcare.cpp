#include "mainwindowplantcare.h"
#include "./ui_mainwindowplantcare.h"
#include <QMessageBox>
#include<QLineEdit>


MainWindowPlantCare::MainWindowPlantCare(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowPlantCare)
{
    ui->setupUi(this);
    //the cancel button on login ui
    connect(ui->pushButton_login_3, SIGNAL(clicked()),this, SLOT(close()));








}

MainWindowPlantCare::~MainWindowPlantCare()
{
    delete ui;
}


//
void MainWindowPlantCare::on_pushButton_login_clicked() {
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username== "innora" && password == "4321") //this is the default user
    {
     QMessageBox::information(this, "Welcome","Login is successful!");
        //hide first window
        // hide();
         //creating a constructor for System Dashboard
         secDialog =new SecDialog(this);
        //calling secDialog object
        secDialog->show();


    }
       else
         {
         QMessageBox::warning(this, "Sorry","Username or password is not correct!");
    }
    // Clear the login form after form submition
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();

    }




}

