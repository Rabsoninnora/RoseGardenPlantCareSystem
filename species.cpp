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
    QByteArray ImageDataFromDataBase;
    QPixmap Image;
    QString ImageName;

    QSqlQuery QueryLoadData( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    QueryLoadData.prepare("SELECT * FROM addplant WHERE species LIKE ="+ ui->txtSpeciesName->text() + "");
    int NumberOFRowsToDisplay=1;

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

