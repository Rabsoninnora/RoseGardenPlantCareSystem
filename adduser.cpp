#include "adduser.h"
#include "ui_adduser.h"

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

}


void AddUser::on_btn_Delete_User_clicked()
{

}


void AddUser::on_btn_Insert_User_clicked()
{

    QSqlQuery InsertRecord( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();

    InsertRecord.prepare( "INSERT INTO User_login(username,password) VALUES(:username,:password) ");
    InsertRecord.bindValue(":username", ui->lineEdit_User_name->text());
    InsertRecord.bindValue(":password",ui->lineEdit_User_Password->text());

    InsertRecord.exec();
    QSqlDatabase::database().commit();
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
    QSqlQuery InsertRecord( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();

    InsertRecord.prepare( "INSERT INTO Admin_login(username,password) VALUES(:username,:password) ");
    InsertRecord.bindValue(":username", ui->lineEdit_username_admin->text());
    InsertRecord.bindValue(":password",ui->lineEdit_User_Password->text());

    InsertRecord.exec();
    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();

    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}
}

