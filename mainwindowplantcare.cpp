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

    DB_LOGIN_innora=QSqlDatabase::addDatabase("QSQLITE");
    DB_LOGIN_innora.setDatabaseName("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");
    DB_LOGIN_innora.open();
    QSqlDatabase::database().transaction();
    if(DB_LOGIN_innora.open())
    {
        qDebug() <<"Hi Innora! Database is open on Login";
    } else
    {
        qDebug() <<"Hi Innora!, Sorry Database is not open";
    }
    //the cancel button on login ui
    //connect(ui->pushButton_login_3, SIGNAL(clicked()),this, SLOT(close()));
    qDebug() << DB_LOGIN_innora.lastError().text();



}

MainWindowPlantCare::~MainWindowPlantCare()
{
    delete ui;
}


//
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
        QSqlQuery GetUser(DB_LOGIN_innora);
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

