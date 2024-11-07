#include "index.h"
#include "ui_index.h"

index::index(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::index)
{
    ui->setupUi(this);


    /*
     Use this for the Welcome page
     it must show Admin login and user login options

   */


}

index::~index()
{
    delete ui;
}

void index::on_btn_login_Admin_clicked()
{
    QString username = ui->lineEdit_usernameAdmin->text();
    QString password = ui->lineEdit_passwordAdmin->text();

    if(username== "innora" && password == "659489+") //Default developer login
    {
        QMessageBox::information(this, "Welcome","Login is successful!");

        //creating a constructor for System Dashboard
        AdminDashboard =new AdminPanel(this);
        //calling secDialog object
        AdminDashboard->show();
    }
    else
    {
        db.open();
        QSqlDatabase::database().transaction();
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
                AdminDashboard =new AdminPanel(this);
                //calling secDialog object
                AdminDashboard->show();
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
        QSqlDatabase::database().commit();
        db.close();
    }






}


void index::on_btn_Cancel_login_Admin_clicked()
{

}

