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
    QSqlDatabase DB_SQLITE3 = QSqlDatabase::addDatabase("QSQLITE");
    DB_SQLITE3.setDatabaseName("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");

    DB_SQLITE3.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryLoadData(DB_SQLITE3);
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
    DB_SQLITE3.close();






}

