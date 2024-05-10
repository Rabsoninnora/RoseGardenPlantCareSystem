#include "mainwindowplantcare.h"
#include "./ui_mainwindowplantcare.h"
#include <QMessageBox>
#include<QLineEdit>


MainWindowPlantCare::MainWindowPlantCare(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowPlantCare)
{
    ui->setupUi(this);
    connect(ui->pushButton_login_3,SIGNAL(clicked()), this, SLOT(close()));







}

MainWindowPlantCare::~MainWindowPlantCare()
{
    delete ui;
}


//Method
void MainWindowPlantCare::on_pushButton_login_clicked() {
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username== "innora" && password == "4321") //this is the default user
    {
        QMessageBox::information(this, "Welcome","Login is successful!");
        //hide first window
        //  hide();
         //creating a constructor for second dialog object with this class
         secDialog =new SecDialog(this);
        //calling secDialog object
        secDialog->show();

    }
       else
         {
         QMessageBox::warning(this, "Sorry","Username or password is not correct!");
    }




}

