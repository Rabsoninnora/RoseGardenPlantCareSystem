#include "mainwindowplantcare.h"
#include "./ui_mainwindowplantcare.h"
#include <QMessageBox>
#include<QLineEdit>
#include<QSqlQuery>
#include "databaseheader.h"
#include "mydb.h"


MainWindowPlantCare::MainWindowPlantCare(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowPlantCare)
{
    ui->setupUi(this);

    //Add admin login and user login separately


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

        QSqlQuery GetUser( MyDB::getInstance()->getDBInstance());
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


void MainWindowPlantCare::on_btn_Admin_login_clicked()
{



    QString admin_username = ui->lineEdit_username_2->text();

    QString admin_password = ui->lineEdit_password_2->text();

    if(admin_username== "innora" && admin_password == "659489+") //Default developer login
    {


        //creating a constructor for System Dashboard
        Admin_Dashboard = new AdminPanel(this);
        Admin_Dashboard->show();

       QMessageBox::information(this, "Welcome","Login is successful!");

    }
    else
    {
        QSqlQuery GetUser(db);
        GetUser.prepare(" SELECT * FROM Admin_login WHERE username='" + admin_username +"' AND password='" + admin_password +"' ");
        if(GetUser.exec())
        {
            int UserFindCount = 0;
            while(GetUser.next())
            {
                UserFindCount = UserFindCount + 1; // If username and password is correct
            }
            if(UserFindCount == 1)//If username and password is correct
            {


                //Creating a constructor for System Dashboard
                Admin_Dashboard = new AdminPanel(this);
                Admin_Dashboard->show();



            }
            else if(UserFindCount == 0)//If admin_username and admin_password is not correct
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

