#include "viewplants.h"
#include "ui_viewplants.h"

ViewPlants::ViewPlants(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewPlants)
{
    ui->setupUi(this);
}

ViewPlants::~ViewPlants()
{
    delete ui;
}




void ViewPlants::on_pushButton_clicked()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");
    database.open();
    QSqlQuery query(database);
    query.prepare("SELECT * FROM addplant");

    if (query.exec())
    {
             int RowNumber = 0;

              ui->tableWidget->setRowCount(query.size());
        while(query.next()){


            ui->tableWidget->setItem(RowNumber,0, new QTableWidgetItem(QString::number(query.value("ID").toInt())));
            ui->tableWidget->setItem(RowNumber,1, new QTableWidgetItem(QString(query.value("scientific_name").toString())));
            ui->tableWidget->setItem(RowNumber,2, new QTableWidgetItem(QString(query.value("Genus").toString())));
            ui->tableWidget->setItem(RowNumber,3, new QTableWidgetItem(QString(query.value("common_name").toString())));
            ui->tableWidget->setItem(RowNumber,4, new QTableWidgetItem(QString(query.value("species").toString())));
            ui->tableWidget->setItem(RowNumber,5, new QTableWidgetItem(QString(query.value("description").toString())));
            ui->tableWidget->setItem(RowNumber,6, new QTableWidgetItem(QString(query.value("status").toString())));
            ui->tableWidget->setItem(RowNumber,7, new QTableWidgetItem(QString(query.value("price").toString())));
            ui->tableWidget->setItem(RowNumber,8, new QTableWidgetItem(QString::number(query.value("quantity").toInt())));
            RowNumber = RowNumber + 1;
            qDebug() <<query.value("ID").toInt()
                     <<query.value("scientific_name").toString()
                     <<query.value("Genus").toString()
                     <<query.value("common_name").toString()
                     <<query.value("species").toString()
                     <<query.value("description").toString()
                     <<query.value("status").toString()
                     <<query.value("price").toString()
                     <<query.value("quantity").toInt();
        }
    }
    qDebug() <<" Last error : "<< query.lastError().text();
    database.close();
    qDebug() << "Databse closed  successfuly, Happy coding !";
}

