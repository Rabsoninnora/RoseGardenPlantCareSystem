#include "viewplants.h"
#include "ui_viewplants.h"
#include "databaseheader.h"

ViewPlants::ViewPlants(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewPlants)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

    ptrSpecies = new Species();
    ptrPlantDetail = new PlantDetail();




    if(!DatabaseManager::instance().openDatabase("C:/Project@rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db")){

        qDebug()<< "Database File Does Not Exist or Unable To Open! ";
    }

    if(QFile::exists("C:/Project@rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db"))
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
    delete ptrSpecies;
    delete ptrPlantDetail;

}

void ViewPlants::on_ViewPlantsRecord_clicked()
{
    QByteArray ImageDataFromDataBase;
    QPixmap Image;
    QString ImageName;


//////////////////////////////////////////////////////////////
    QSqlQuery QueryLoadData( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    QueryLoadData.prepare("SELECT * FROM addplant");
    int NumberOFRowsToDisplay=100;
    if(QueryLoadData.exec())
    {
        ui->tableWidget->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;

        while (QueryLoadData.next()) {

            ImageName = QueryLoadData.value("Image_Name").toString();
            ImageDataFromDataBase = QByteArray::fromBase64(QueryLoadData.value("Image_Data").toByteArray());
            Image.loadFromData(ImageDataFromDataBase, "JPG");


            ui->tableWidget->setItem( RowNumber, 0, new QTableWidgetItem(ImageName));
            QTableWidgetItem *Image_Item = new  QTableWidgetItem();
            Image_Item->setIcon(QIcon(Image));
            Image_Item->setData(Qt::DecorationRole,Image.scaled(200,200));


            ui->tableWidget->setItem( RowNumber, 1, Image_Item);
            ui->tableWidget->verticalHeader()->setDefaultSectionSize(30);
            //////////////////////////////////////////////////////////////////////////////////////////////////////////
            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("Plant_ID").toString())));
            ui->tableWidget->setItem( RowNumber, 3, new QTableWidgetItem(QString(QueryLoadData.value("scientific_name").toString())));
            ui->tableWidget->setItem( RowNumber, 4, new QTableWidgetItem(QString(QueryLoadData.value("Genus").toString())));
            ui->tableWidget->setItem( RowNumber, 5, new QTableWidgetItem(QString(QueryLoadData.value("common_name").toString())));
            ui->tableWidget->setItem( RowNumber, 6, new QTableWidgetItem(QString(QueryLoadData.value("species").toString())));
            ui->tableWidget->setItem( RowNumber, 7, new QTableWidgetItem(QString(QueryLoadData.value("description").toString())));
            ui->tableWidget->setItem( RowNumber, 8, new QTableWidgetItem(QString(QueryLoadData.value("status").toString())));
            ui->tableWidget->setItem( RowNumber, 9, new QTableWidgetItem(QString(QueryLoadData.value("price").toString())));
            ui->tableWidget->setItem( RowNumber, 10, new QTableWidgetItem(QString(QueryLoadData.value("quantity").toString())));
            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();
    /////////////////////////////////////////////////////////////////////////////////////////////

    ui->tableWidget->resizeRowsToContents();
    Image.save(QCoreApplication::applicationDirPath() + "/Image_From_Database.jpg");



    qDebug() <<"Last Error "<< QueryLoadData.lastError().text();




}


void ViewPlants::on_DeletePlantsRecord_clicked()
{
    QSqlQuery Query_Delete_Data( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    Query_Delete_Data.prepare("DELETE FROM addplant WHERE Plant_ID="+ ui->lineEdit_Delete->text() +"");
    Query_Delete_Data.exec();
    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();


    foreach(QLineEdit *widget,this->findChildren<QLineEdit*>()){widget->clear();}
}




void ViewPlants::on_btn_view_plant_detial_BY_ID_clicked()
{
    ptrPlantDetail->show();
}


void ViewPlants::on_btn_search_species_admin_clicked()
{
    ptrSpecies->show();
}


void ViewPlants::on_btn_back_viewPlant_clicked()
{
    this->close();
}

