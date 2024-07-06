#include "species.h"
#include "ui_species.h"

Species::Species(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Species)
{
    ui->setupUi(this);
}

Species::~Species()
{
    delete ui;
    delete model;
}

void Species::on_btnSearch_clicked()
{

    //Data received from the AddPlant form, passed to be posted in the database
    QString species = ui->txtSpeciesName->text();



    //check if the data can be passed/ if I can get this data
    qDebug() <<"species"<<species;

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
    query.prepare("SELECT ID, species, description FROM addplant");
    query.exec();


    qDebug() <<" Last error : "<< query.lastError().text();

    if (model == NULL)
    {
        model = new QSqlQueryModel();
    }

    model->setQuery(std::move(query));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,200);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,200);
    database.close();

}

