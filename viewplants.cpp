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
    query.exec();
    if (query.exec())
    {
        while(query.next()){
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

