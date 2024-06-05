#include "addgardener.h"
#include "ui_addgardener.h"


AddGardener::AddGardener(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddGardener)
{
    ui->setupUi(this);
}

AddGardener::~AddGardener()
{
    delete ui;
}

void AddGardener::on_btnSave_clicked()
{
    QString Employee_id = ui->txtEmployeeID->text();
    QString National_id = ui->txtNationalID->text();
    QString Name = ui->txtName->text();
    QString Middle_name = ui->txtMiddleName->text();
    QString Last_name = ui->txtLastName->text();
    QString Job_title = ui->txtJobTitle->text();
    QString Description = ui->txtDescription->toPlainText();


//Check if the information can be passed // if I can get the information
    qDebug() << "EmployeeID :"
             <<Employee_id
             << "NationalID :"
             <<National_id
             << "Name :"
             <<Name
             << "MiddleName :"
             <<Middle_name
             <<"LastName :"
             <<Last_name
             <<"JobTile :"
             <<Job_title
             <<"Description :"
             <<Description;

    //I am able to get the information, but now it must be saved in the database
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");

    //Check if database file exists
    if(QFile::exists("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db"))
    {
        qDebug() <<" Databse File Exists ";

    } else {
        qDebug() <<" Database File Does not Exists";
        return;
    }



   // See if the database can be opened
    if(!database.open())
    {
        qDebug() << "Error: unable to open Database! ";
        return;
    } else
    {
        qDebug() << "Database opened successfuly ..!";
    }


/// Posting data in the database, the addgardener table/relation
    QSqlQuery query(database);
    query.prepare("insert into addgardener(Employee_id, National_id, Name, Middle_name, Last_name, Job_title, Description) values('"+ Employee_id +"', '"+ National_id +"', '"+ Name +"','"+ Middle_name +"','"+ Last_name +"','"+ Job_title +"', '"+ Description +"')");
    query.exec();
    qDebug() <<" Last error : "<< query.lastError().text();
    database.close();
}


