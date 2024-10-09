#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_login_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username== "innora" && password == "659489+") //Default developer login
    {
        QMessageBox::information(this, "Welcome","Login is successful!");

        //creating a constructor for System Dashboard
        adminPanel =new AdminPanel(this);
        //calling secDialog object
        adminPanel->show();
         this->hide();

    }
    else
    {
        QSqlQuery GetAdmin(db);
        GetAdmin.prepare(" SELECT * FROM Admin_login WHERE username='" + username +"' AND password='" + password +"' ");
        if(GetAdmin.exec())
        {
            int UserFindCount = 0;
            while(GetAdmin.next())
            {
                UserFindCount = UserFindCount + 1; // If username and password is correct
            }
            if(UserFindCount == 1)//If username and password is correct
            {
                QMessageBox::information(this,"Welcome","login successful");

                //creating a constructor for System Dashboard
                adminPanel =new AdminPanel(this);
                //calling secDialog object
                adminPanel->show();
                this->hide();
            }
            else if(UserFindCount == 0)//If username and password is not correct
            {


                QMessageBox::warning(this,"Warning!", " Enter Valid Username Or Passwaord");
            }
        }

        else

        {
            QMessageBox::information(this, "Sorry!", "Check your Username and Password");
        }
    }

    qDebug();

}


void Admin::on_btn_Cancel_admin_login_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::warning(this,"Warning!", "You're about to Close the Application?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

