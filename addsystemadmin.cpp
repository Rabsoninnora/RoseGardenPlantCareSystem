#include "addsystemadmin.h"
#include "ui_addsystemadmin.h"

AddSystemAdmin::AddSystemAdmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddSystemAdmin)
{
    ui->setupUi(this);
}

AddSystemAdmin::~AddSystemAdmin()
{
    delete ui;
}

void AddSystemAdmin::on_ViewAccessDetail_clicked()
{

    db.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryLoadData(db);
    QueryLoadData.prepare("SELECT * FROM Admin_login");



    int NumberOFRowsToDisplay=10;

    if(QueryLoadData.exec())
    {
        ui->tableWidget->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;
        while (QueryLoadData.next()) {


            ui->tableWidget->setItem( RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("ID").toString())));
            ui->tableWidget->setItem( RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("username").toString())));
            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("password").toString())));
            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    db.close();



}


void AddSystemAdmin::on_InsertAccessDetail_clicked()
{
    db.open();
    QSqlDatabase::database().transaction();
    QSqlQuery InsertRecord(db);
    InsertRecord.prepare( "INSERT INTO Admin_login(username,password) VALUES(:username,:password) ");
    InsertRecord.bindValue(":username", ui->lineEdit_UserName->text());
    InsertRecord.bindValue(":password",ui->lineEdit_Password->text());

    InsertRecord.exec();
    QSqlDatabase::database().commit();
    db.close();

    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}
}


void AddSystemAdmin::on_DeleteAccessDetail_clicked()
{
    db.open();
    QSqlDatabase::database().transaction();
    QSqlQuery Query_Delete_Data(db);
    Query_Delete_Data.prepare("DELETE FROM Admin_login WHERE ID="+ ui->lineEdit_ID->text() +"");
    Query_Delete_Data.exec();
    QSqlDatabase::database().commit();
    db.close();


    foreach(QLineEdit *widget,this->findChildren<QLineEdit*>()){widget->clear();}
}

