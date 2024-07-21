#include "addgardentool.h"
#include "ui_addgardentool.h"

AddGardenTool::AddGardenTool(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddGardenTool)
{
    ui->setupUi(this);

    QSqlDatabase DB_GardenTools = QSqlDatabase::addDatabase("QSQLITE");
    DB_GardenTools.setDatabaseName("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");
    //checking if the database file exist
    if(QFile::exists("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db"))
    {
        qDebug()<< "Database File Exists ! ";
    }   else
    {
        qDebug() << "Database File Does Not Exists !";
        return;
    }
}

AddGardenTool::~AddGardenTool()
{
    delete ui;
}

void AddGardenTool::on_btn_View_Record_clicked()
{

}


void AddGardenTool::on_btn_Delete_Record_clicked()
{

}


void AddGardenTool::on_btn_Insert_Record_clicked()
{
    DB_GardenTools.open();
    QSqlDatabase::database().transaction();
    QSqlQuery QueryInsertData(DB_GardenTools);

    QueryInsertData.prepare("INSERT INTO TOOLS(tool_ID,Item_name,Quantity,Status,Description) VALUES(:tool_ID,:Item_name,:Quantity,:Status,:Description)");
    QueryInsertData.bindValue(":tool_ID",ui->lineEdit_ID->text());
    QueryInsertData.bindValue(":Item_name",ui->lineEdit_Item_name->text());
    QueryInsertData.bindValue(":Quantity",ui->lineEdit_Quantity->text());
    QueryInsertData.bindValue(":Status",ui->lineEdit_Status->text());
    QueryInsertData.bindValue(":Description",ui->lineEdit_Description->text());

    QueryInsertData.exec();

    QSqlDatabase::database().commit();
    DB_GardenTools.close();
}


void AddGardenTool::on_btn_Update_Record_clicked()
{

}

