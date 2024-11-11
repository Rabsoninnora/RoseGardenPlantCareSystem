#include "gardenerdetails.h"
#include "ui_gardenerdetails.h"


GardenerDetails::GardenerDetails(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GardenerDetails)
{
    ui->setupUi(this);
}

GardenerDetails::~GardenerDetails()
{
    delete ui;
}

void GardenerDetails::on_ViewEmployeeRecord_clicked()
{



    QSqlQuery QueryLoadData( MyDB::getInstance()->getDBInstance());

    QueryLoadData.prepare("SELECT * FROM addgardener");



    int NumberOFRowsToDisplay=100;

    if(QueryLoadData.exec())
    {
      ui->tableWidget->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;
        while (QueryLoadData.next()) {


            ui->tableWidget->setItem( RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("Employee_id").toString())));
            ui->tableWidget->setItem( RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("National_id").toString())));
            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("Name").toString())));
            ui->tableWidget->setItem( RowNumber, 3, new QTableWidgetItem(QString(QueryLoadData.value("Middle_name").toString())));
            ui->tableWidget->setItem( RowNumber, 4, new QTableWidgetItem(QString(QueryLoadData.value("Last_name").toString())));
            ui->tableWidget->setItem( RowNumber, 5, new QTableWidgetItem(QString(QueryLoadData.value("job_title").toString())));
            ui->tableWidget->setItem( RowNumber, 6, new QTableWidgetItem(QString(QueryLoadData.value("Description").toString())));
            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();

}


void GardenerDetails::on_btn_Insert_Employee_clicked()
{
    QSqlQuery InsertRecord( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    InsertRecord.prepare( "INSERT INTO addgardener(Employee_id,National_id,Name,Middle_name,Last_name,job_title,Description) VALUES(:Employee_id,:National_id,:Name,:Middle_name,:Last_name,:job_title,:Description) ");
    InsertRecord.bindValue(":Employee_id", ui->lineEdit_Employee_id->text());
    InsertRecord.bindValue(":National_id",ui->lineEdit_National_id->text());
    InsertRecord.bindValue(":Name",ui->lineEdit_First_name->text());
    InsertRecord.bindValue(":Middle_name",ui->lineEdit_Middle_name->text());
    InsertRecord.bindValue(":Last_name",ui->lineEdit_Last_name->text());
    InsertRecord.bindValue(":job_title",ui->lineEdit_job_title->text());
    InsertRecord.bindValue(":Description",ui->lineEdit_Description->text());
    InsertRecord.exec();
    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();

    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}

}


void GardenerDetails::on_btn_Update_Employee_clicked()
{
    QSqlQuery UpdateRecord( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    UpdateRecord.prepare(" UPDATE addgardener SET Employee_id=:Employee_id, National_id=:National_id, Name=:Name, Middle_name=:Middle_name, Last_name=:Last_name, job_title=:job_title, Description=:Description WHERE Employee_id=:Employee_id");
    UpdateRecord.bindValue(":Employee_id", ui->lineEdit_Employee_id->text());
    UpdateRecord.bindValue(":National_id", ui->lineEdit_National_id->text());
    UpdateRecord.bindValue(":Name", ui->lineEdit_First_name->text());
    UpdateRecord.bindValue(":Middle_name", ui->lineEdit_Middle_name->text());
    UpdateRecord.bindValue(":Last_name", ui->lineEdit_Last_name->text());
    UpdateRecord.bindValue(":job_title", ui->lineEdit_job_title->text());
    UpdateRecord.bindValue(":Description", ui->lineEdit_Description->text());
    UpdateRecord.exec();

    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();

    qDebug () <<"Error on update record" << UpdateRecord.lastError().text();

    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}


}


void GardenerDetails::on_btn_Delete_Employee_clicked()
{
    QSqlQuery Query_Delete_Data( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();

    Query_Delete_Data.prepare("DELETE FROM addgardener WHERE Employee_id="+ ui->lineEdit_Employee_id->text() +"");
    Query_Delete_Data.exec();
    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();


    foreach(QLineEdit *widget,this->findChildren<QLineEdit*>()){widget->clear();}
}

