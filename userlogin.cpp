#include "userlogin.h"
#include "ui_userlogin.h"
#include <QMessageBox>
#include<QLineEdit>
#include<QSqlQuery>
#include "mydb.h"
UserLogin::UserLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserLogin)
{
    ui->setupUi(this);
}

UserLogin::~UserLogin()
{
    delete ui;
}

void UserLogin::on_pushButton_login_clicked()
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



    ///////////////////////////////////////////////////////////////////////////////////////////////
    foreach (QLineEdit *widget, this->findChildren<QLineEdit*>()) { widget->clear();}


}


void UserLogin::on_pushButton_login_3_clicked()
{

    QMessageBox::StandardButton reply;
    reply=QMessageBox::warning(this,"Warning!!", "Close the Application?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }

}
