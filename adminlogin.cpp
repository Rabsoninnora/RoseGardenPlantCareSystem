#include "adminlogin.h"
#include "ui_adminlogin.h"
#include <QMessageBox>
#include<QLineEdit>
#include<QSqlQuery>
#include "mydb.h"

AdminLogin::AdminLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_btn_Admin_login_clicked()
{


    QString username = ui->lineEdit_username_2->text();

    QString password = ui->lineEdit_password_2->text();

    if(username== "innora" && password == "659489+") //Default developer login
    {


        //creating a constructor for admin Dashboard
        adminPanel =new AdminPanel(this);

        //calling admindashboard
        adminPanel->show();



    }
    else
    {

        QSqlQuery GetUser( MyDB::getInstance()->getDBInstance());
        GetUser.prepare(" SELECT * FROM User_login WHERE username='" + username +"' AND password='" + password +"' ");
        if(GetUser.exec())
        {
            int UserFindCount = 0;
            while(GetUser.next())
            {
                UserFindCount = UserFindCount + 1; // If username and password is correct
            }
            if(UserFindCount == 1)//If username and password is correct
            {


                //creating a constructor for Admin Dashboard
                adminPanel =new AdminPanel(this);

                //calling Admin object
                adminPanel->show();


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



    ///////////////////////////////////////////////////////////////////////////////////////////////
    foreach (QLineEdit *widget, this->findChildren<QLineEdit*>()) { widget->clear();}

}


void AdminLogin::on_btn_Admin_Cancel_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::warning(this,"Warning!!", "Close the Application?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

