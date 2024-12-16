#include "adduser.h"
#include "ui_adduser.h"
#include <QMessageBox>
#include <QCryptographicHash>

AddUser::AddUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddUser)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::on_btn_View_User_clicked()
{

    QSqlQuery QueryLoadData( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    QueryLoadData.prepare("SELECT * FROM User_login");



    int NumberOFRowsToDisplay=10;

    if(QueryLoadData.exec())
    {
        ui->tableWidget->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;
        while (QueryLoadData.next()) {


            ui->tableWidget->setItem( RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("User_ID").toString())));
            ui->tableWidget->setItem( RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("username").toString())));
            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("password").toString())));
            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();
}


void AddUser::on_btn_Update_User_clicked()
{
    QSqlQuery QueryUpdateData(MyDB::getInstance()->getDBInstance());

    QSqlDatabase::database().transaction();


    // Hash the password before updating

    QByteArray hashedPassword = QCryptographicHash::hash(ui->lineEdit_User_Password->text().toUtf8(), QCryptographicHash::Sha256).toHex();


    QueryUpdateData.prepare("UPDATE User_login SET username=:username, password=:password WHERE User_ID=:User_ID");

    QueryUpdateData.bindValue(":User_ID", ui->lineEdit_User_ID->text());

    QueryUpdateData.bindValue(":username", ui->lineEdit_User_name->text());

    QueryUpdateData.bindValue(":password", hashedPassword); // Use the hashed password

    if (QueryUpdateData.exec())

    {
        QSqlDatabase::database().commit();
    }

    else

    {
         qDebug() << "Update error:" << QueryUpdateData.lastError();
         QSqlDatabase::database().rollback();
    }


    QSqlDatabase::database().close();


    // Clear input fields

    foreach (QLineEdit *widget, this->findChildren<QLineEdit*>())

    {

        widget->clear();

    }


    // Refresh the user table

    on_btn_View_User_clicked();

}


void AddUser::on_btn_Delete_User_clicked()
{
    QSqlQuery Query_Delete_Data( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    Query_Delete_Data.prepare("DELETE FROM User_login WHERE User_ID="+ ui->lineEdit_User_ID->text() +"");
    Query_Delete_Data.exec();
    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();

    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) { widget->clear();}
    // Refresh the user table

    on_btn_View_User_clicked();
}


void AddUser::on_btn_Insert_User_clicked()
{
    QSqlQuery InsertRecord(MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    // Hash the password before inserting
    QByteArray hashedPassword = QCryptographicHash::hash(ui->lineEdit_User_Password->text().toUtf8(), QCryptographicHash::Sha256).toHex();
    InsertRecord.prepare("INSERT INTO User_login(username,password) VALUES(:username,:password)");
    InsertRecord.bindValue(":username", ui->lineEdit_User_name->text());
    InsertRecord.bindValue(":password", hashedPassword); // Use the hashed password
    if (InsertRecord.exec())

    {
        QSqlDatabase::database().commit();
    }
    else
    {
        qDebug() << "Insert error:" << InsertRecord.lastError();
        QSqlDatabase::database().rollback();
    }
    QSqlDatabase::database().close();
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}
}


void AddUser::on_btn_Reset_User_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}
}


void AddUser::on_btn_View_admin_clicked()
{
    QSqlQuery QueryLoadData( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    QueryLoadData.prepare("SELECT * FROM Admin_login");



    int NumberOFRowsToDisplay=10;

    if(QueryLoadData.exec())
    {
        ui->tableWidget_2->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;
        while (QueryLoadData.next()) {


            ui->tableWidget_2->setItem( RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("ID").toString())));
            ui->tableWidget_2->setItem( RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("username").toString())));
            ui->tableWidget_2->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("password").toString())));
            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();
}


void AddUser::on_btn_Insert_admin_clicked()
{
    QSqlQuery InsertRecord(MyDB::getInstance()->getDBInstance());

    QSqlDatabase::database().transaction();


    // Hash the password before inserting

    QByteArray hashedPassword = QCryptographicHash::hash(ui->lineEdit_admin_password->text().toUtf8(), QCryptographicHash::Sha256).toHex();


    InsertRecord.prepare("INSERT INTO Admin_login(username,password) VALUES(:username,:password)");

    InsertRecord.bindValue(":username", ui->lineEdit_username_admin->text());

    InsertRecord.bindValue(":password", hashedPassword); // Use the hashed password


    if (InsertRecord.exec())

    {

        QSqlDatabase::database().commit();

    }

    else

    {

        qDebug() << "Insert error:" << InsertRecord.lastError();

        QMessageBox::information(this, "Sorry!", "Enter UNIQUE Username and Password");

        QSqlDatabase::database().rollback();

    }


    QSqlDatabase::database().close();

    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}
    // Refresh the user table
     on_btn_View_User_clicked();

}


void AddUser::on_btn_log_back_clicked()
{
    this->close();
}


void AddUser::on_btn_Delete_admin_clicked()
{


    QSqlQuery Query_Delete_Data(MyDB::getInstance()->getDBInstance());

    QSqlDatabase::database().transaction();
    Query_Delete_Data.prepare("DELETE FROM Admin_login WHERE ID="+ ui->lineEdit_Admin_ID->text() +"");

    if (Query_Delete_Data.exec()) {

        QSqlDatabase::database().commit();

    } else {

        qDebug() << "Delete error:" << Query_Delete_Data.lastError();


        QSqlDatabase::database().rollback();

    }


    QSqlDatabase::database().close();


    // Clear input fields

    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {

        widget->clear();

    }


    // Refresh the user table

    on_btn_View_User_clicked();
}


void AddUser::on_btn_Update_admin_clicked()
{

    QSqlQuery QueryUpdateData(MyDB::getInstance()->getDBInstance());

    QSqlDatabase::database().transaction();

    // Hash the password before inserting

    QByteArray hashedPassword = QCryptographicHash::hash(ui->lineEdit_admin_password->text().toUtf8(), QCryptographicHash::Sha256).toHex();

    QueryUpdateData.prepare("UPDATE Admin_login SET username=:username, password=:password WHERE ID=:ID");

    QueryUpdateData.bindValue(":ID", ui->lineEdit_Admin_ID->text());

    QueryUpdateData.bindValue(":username", ui->lineEdit_username_admin->text());

    QueryUpdateData.bindValue(":password", hashedPassword); // Use hashedPassword


    if (QueryUpdateData.exec()) {

        QSqlDatabase::database().commit();

    } else {

        qDebug() << "Update error:" << QueryUpdateData.lastError();
        QMessageBox::information(this, "Sorry!", "Enter UNIQUE Username and Password");

        QSqlDatabase::database().rollback();
    }
    QSqlDatabase::database().close();

    // Clear input fields
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {

        widget->clear();
    }


    // Refresh the user table

    on_btn_View_User_clicked();
}

