#include "mainwindowplantcare.h"
#include "databaseheader.h"
#include "./ui_mainwindowplantcare.h"
#include <QMessageBox>
#include<QLineEdit>
#include<QSqlQuery>


MainWindowPlantCare::MainWindowPlantCare(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowPlantCare)
{
    ui->setupUi(this);
    //the cancel button on login ui
    //connect(ui->pushButton_login_3, SIGNAL(clicked()),this, SLOT(close()));



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


    } else{
        db.open();
        QSqlDatabase::database().transaction();
        QSqlQuery Query_login(db);
        Query_login.prepare("SELECT * FROM Adminlogin WHERE UserName='" +username+ "' AND PassWord='"+ password +"'");

      int   FindCount=0;
        if(Query_login.exec()){
            while (Query_login.next()) {

                FindCount= FindCount +1;//if UserName and PassWord is correct
            }
            if(FindCount==1) //if UserName and PassWord is correct
            {
            QMessageBox::information(this, "Welcome","Login is successful!");
                //hide first window
                // hide();
                //creating a constructor for System Dashboard
                secDialog =new SecDialog(this);
                //calling secDialog object
                secDialog->show();

            } else if(FindCount==0) //if UserName and PassWord is not correct
            {
             QMessageBox::warning(this, "Sorry","Username or password is not correct!");
            }
        }

        QSqlDatabase::database().commit();
        db.close();
      }

    // Clear the login form after form submition
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();

    }




}


void MainWindowPlantCare::on_pushButton_login_3_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::warning(this,"Warning!!", "Close the Application?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

