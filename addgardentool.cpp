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
    DB_GardenTools.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryReadData(DB_GardenTools);
    QueryReadData.prepare("SELECT * FROM TOOLS");



    int NumberOFRowsToDisplay=100;

    if(QueryReadData.exec())
    {
        ui->tableWidget->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;
        while (QueryReadData.next()) {


            ui->tableWidget->setItem( RowNumber, 0, new QTableWidgetItem(QString(QueryReadData.value("tool_ID").toString())));
            ui->tableWidget->setItem( RowNumber, 1, new QTableWidgetItem(QString(QueryReadData.value("Item_name").toString())));
            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryReadData.value("Quantity").toString())));
            ui->tableWidget->setItem( RowNumber, 3, new QTableWidgetItem(QString(QueryReadData.value("Status").toString())));
            ui->tableWidget->setItem( RowNumber, 4, new QTableWidgetItem(QString(QueryReadData.value("Description").toString())));

            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    DB_GardenTools.close();

}


void AddGardenTool::on_btn_Delete_Record_clicked()
{
    DB_GardenTools.open();
    QSqlDatabase::database().transaction();
    QSqlQuery QueryDeleteData(DB_GardenTools);

    QueryDeleteData.prepare("DELETE FROM TOOLS WHERE tool_ID=:tool_ID");
    QueryDeleteData.bindValue(":tool_ID",ui->lineEdit_ID->text());


    QueryDeleteData.exec();

    QSqlDatabase::database().commit();
    DB_GardenTools.close();
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
    DB_GardenTools.open();
    QSqlDatabase::database().transaction();
    QSqlQuery QueryUpdateData(DB_GardenTools);
    QueryUpdateData.prepare("UPDATE TOOLS SET tool_ID=:tool_ID,Item_name=:Item_name,Quantity=:Quantity,Status=:Status,Description=:Description WHERE tool_ID=:tool_ID");

    QueryUpdateData.bindValue(":tool_ID",ui->lineEdit_ID->text());
    QueryUpdateData.bindValue(":Item_name",ui->lineEdit_Item_name->text());
    QueryUpdateData.bindValue(":Quantity",ui->lineEdit_Quantity->text());
    QueryUpdateData.bindValue(":Status",ui->lineEdit_Status->text());
    QueryUpdateData.bindValue(":Description",ui->lineEdit_Description->text());


    QueryUpdateData.exec();
    QSqlDatabase::database().commit();
    DB_GardenTools.close();

    qDebug()<<"Update error:" <<QueryUpdateData.lastError();
}

