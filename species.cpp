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

}

void Species::on_btnSearch_clicked()
{


    DB_SQLITE3.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryLoadData(DB_SQLITE3);
    QueryLoadData.prepare("SELECT * FROM addplant WHERE ID="+ ui->txtSpeciesName->text()+"");



    int NumberOFRowsToDisplay=100;

    if(QueryLoadData.exec())
    {
        ui->tableWidget->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;
        while (QueryLoadData.next()) {


            ui->tableWidget->setItem( RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("ID").toString())));
            ui->tableWidget->setItem( RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("species").toString())));
            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("description").toString())));

            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    DB_SQLITE3.close();

       foreach(QLineEdit *widget,this->findChildren<QLineEdit*>()){widget->clear();}


}

