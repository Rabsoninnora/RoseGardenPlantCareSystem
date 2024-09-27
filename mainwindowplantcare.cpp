#include "mainwindowplantcare.h"
#include "./ui_mainwindowplantcare.h"
#include <QMessageBox>
#include<QLineEdit>
#include<QSqlQuery>
#include "databaseheader.h"


MainWindowPlantCare::MainWindowPlantCare(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowPlantCare)
{
    ui->setupUi(this);


}

MainWindowPlantCare::~MainWindowPlantCare()
{
    delete ui;
}



void MainWindowPlantCare::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username== "innora" && password == "659489+") //Default developer login
    {
     QMessageBox::information(this, "Welcome","Login is successful!");

         //creating a constructor for System Dashboard
         secDialog =new SecDialog(this);
        //calling secDialog object
        secDialog->show();
    }
    else
    {
        QSqlQuery GetUser(db);
        GetUser.prepare(" SELECT * FROM Admin_login WHERE username='" + username +"' AND password='" + password +"' ");
        if(GetUser.exec())
        {
            int UserFindCount = 0;
            while(GetUser.next())
            {
                UserFindCount = UserFindCount + 1; // If username and password is correct
            }
            if(UserFindCount == 1)//If username and password is correct
            {
                QMessageBox::information(this,"Welcome","login successful");

                //creating a constructor for System Dashboard
                secDialog =new SecDialog(this);
                //calling secDialog object
                secDialog->show();
            }
            else if(UserFindCount == 0)//If username and password is not correct
            {


                QMessageBox::warning(this,"Warning!", "Please Enter Valid Username Or Passwaord");
            }
        }

        else

        {
            QMessageBox::information(this, "Sorry!", "Please check your Username and Password");
        }
    }






}

// Code ot close the application on login
void MainWindowPlantCare::on_pushButton_login_3_clicked()
{

    QMessageBox::StandardButton reply;
    reply=QMessageBox::warning(this,"Warning!!", "Close the Application?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }





}

