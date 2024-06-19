#include "addplant.h"
#include "ui_addplant.h"
#include <QFileDialog> //For file opening
#include <QMessageBox> //pop up messages alerts infos and warning
#include <QPixmap> //
#include <QImage>  // Load Image
#include <QVector> // for arrays in the system code
#include <QQueue> // Queue data structures
#include <QPixmap>
#include <QLabel>
#include<QLineEdit>

AddPlant::AddPlant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPlant)
{
    ui->setupUi(this);

}

AddPlant::~AddPlant()
{
    delete ui;
}

//Read and process Image
void AddPlant::on_btnBrowse_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.png *.xpm *.jpg)"));

       //check if file_name is not empty
    if(!file_name.isEmpty()){
      //open prompt and display image
        QMessageBox::information(this, "......", file_name);
        QImage img(file_name);
        QPixmap pix = QPixmap::fromImage(img);

        //get lable dimensions
        int w = ui->load_image->width();
        int h = ui->load_image->height();
       //load image onto ui
        ui->load_image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));




    }


}







void AddPlant::on_btnSave_clicked()
{
    //Data received from the AddPlant form, passed to be posted in the database
    QString scientific_name = ui->txtScientificName->text();
    QString Genus = ui->txtGenus->text();
    QString common_name = ui->txtCommonName->text();
    QString species = ui->txtSpecies->text();
    QString description = ui->txtDescription->toPlainText();
    QString status = ui->cmbStatus->currentText();
    QString price = ui->txtPrice->text();
    QString quantity = ui->txtPrice->text();


    //check if the data can be passed/ if I can get this data
    qDebug()<<"scientific_name"
            <<scientific_name
            <<"Genus"
            <<Genus
            <<"common_name"
            <<common_name
            <<"species"
            <<species
            <<"description"
            <<description
            <<"status"
            <<status
            <<"price"
            <<price
            <<"quantity"
            <<quantity;
    //The data can be passed but now it must be posted inn the database
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");


    //checking if the database file exist
    if(QFile::exists("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db"))
    {
        qDebug()<< "Database File Exists ! ";
    }   else
    {
        qDebug() << "Database File Does Not Exists !";
        return;
    }



    //checking if the database can be opened

    if(!database.open())
    {
        qDebug() << "Error: Database Not Opened !";
        return;
    } else
    {
        qDebug() << "Database Succesfuly Opened !";
    }


    //posting data in the database in the addPlant Table/Relation
    QSqlQuery query(database);
    query.prepare("insert into addplant(scientific_name, Genus, common_name, species, description, status, price, quantity) values('"+ scientific_name +"', '"+ Genus +"', '"+ common_name +"','"+ species +"','"+ description +"','"+ status +"', '"+ price +"', '"+ quantity +"')");
    query.exec();
    qDebug() <<" Last error : "<< query.lastError().text();
    database.close();
    qDebug() << "Database closed  successfuly, Happy coding !";
}

///
