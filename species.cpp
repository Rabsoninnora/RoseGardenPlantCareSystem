#include "species.h"
#include "ui_species.h"

Species::Species(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Species)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

Species::~Species()
{
    delete ui;

}

void Species::on_btnSearch_clicked()
{   QString sValue = ui->txtSpeciesName->text();
    QByteArray ImageDataFromDataBase;
    QPixmap Image;
    QString ImageName;

    QSqlQuery QueryLoadData( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();

    QueryLoadData.prepare("SELECT * FROM addplant WHERE species  like '%" + sValue + "%'");
    QueryLoadData.bindValue(":sValue", sValue);
    int NumberOFRowsToDisplay=1000;

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
            Image_Item->setData(Qt::DecorationRole, Image.scaled(200,200));
            ui->tableWidget->setItem( RowNumber, 1, Image_Item);
            ui->tableWidget->verticalHeader()->setDefaultSectionSize(30);
            //////////////////////////////////////////////////////////////////////////////////////////////////////////

            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("Plant_ID").toString())));
            ui->tableWidget->setItem( RowNumber, 3, new QTableWidgetItem(QString(QueryLoadData.value("species").toString())));
            ui->tableWidget->setItem( RowNumber, 4, new QTableWidgetItem(QString(QueryLoadData.value("description").toString())));

            RowNumber = RowNumber +1;

        }


    }

    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();

       foreach(QLineEdit *widget,this->findChildren<QLineEdit*>()){widget->clear();}


}


void Species::on_pushButton_2_clicked()
{
    this->close();
}

