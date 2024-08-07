#include "viewplants.h"
#include "ui_viewplants.h"
#include "databaseheader.h"

ViewPlants::ViewPlants(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewPlants)
{
    ui->setupUi(this);

    if(!DatabaseManager::instance().openDatabase("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db")){

        qDebug()<< "Database File Does Not Exist or Unable To Open! ";
    }

    if(QFile::exists("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db"))
    {
        qDebug()<< "Database File Exists ! ";
    }   else
    {
        qDebug() << "Database File Does Not Exists !";
        return;
    }

}

ViewPlants::~ViewPlants()
{
    delete ui;

}

void ViewPlants::on_ViewPlantsRecord_clicked()
{

    DB_SQLITE3.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryLoadData(DB_SQLITE3);
    QueryLoadData.prepare("SELECT * FROM addplant");



    int NumberOFRowsToDisplay=100;

    if(QueryLoadData.exec())
    {
        ui->tableWidget->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;
        while (QueryLoadData.next()) {


            ui->tableWidget->setItem( RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("ID").toString())));
            ui->tableWidget->setItem( RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("scientific_name").toString())));
            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("Genus").toString())));
            ui->tableWidget->setItem( RowNumber, 3, new QTableWidgetItem(QString(QueryLoadData.value("common_name").toString())));
            ui->tableWidget->setItem( RowNumber, 4, new QTableWidgetItem(QString(QueryLoadData.value("species").toString())));
            ui->tableWidget->setItem( RowNumber, 5, new QTableWidgetItem(QString(QueryLoadData.value("description").toString())));
            ui->tableWidget->setItem( RowNumber, 6, new QTableWidgetItem(QString(QueryLoadData.value("status").toString())));
            ui->tableWidget->setItem( RowNumber, 7, new QTableWidgetItem(QString(QueryLoadData.value("price").toString())));
            ui->tableWidget->setItem( RowNumber, 8, new QTableWidgetItem(QString(QueryLoadData.value("quantity").toString())));
            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    DB_SQLITE3.close();


    qDebug() <<"Last Error "<< QueryLoadData.lastError().text();

}


void ViewPlants::on_DeletePlantsRecord_clicked()
{
    DB_SQLITE3.open();
    QSqlDatabase::database().transaction();
    QSqlQuery Query_Delete_Data(DB_SQLITE3);
    Query_Delete_Data.prepare("DELETE FROM addplant WHERE ID="+ ui->lineEdit_Delete->text() +"");
    Query_Delete_Data.exec();
    QSqlDatabase::database().commit();
    DB_SQLITE3.close();



}

