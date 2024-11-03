#include "plantdetail.h"
#include "ui_plantdetail.h"

PlantDetail::PlantDetail(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlantDetail)
{
    ui->setupUi(this);
}

PlantDetail::~PlantDetail()
{
    delete ui;
}

void PlantDetail::on_btnSearchPlant_clicked()
{
    QByteArray ImageDataFromDataBase;
    QPixmap Image;
    QString ImageName;

    DB_SQLITE3.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryLoadData(DB_SQLITE3);
    QueryLoadData.prepare("SELECT * FROM addplant WHERE Plant_ID="+ ui->txtPlantID->text()+"");





    if(QueryLoadData.exec())
    {


        while (QueryLoadData.next()) {
            ImageName = QueryLoadData.value("Image_Name").toString();
            ImageDataFromDataBase = QByteArray::fromBase64(QueryLoadData.value("Image_Data").toByteArray());

            ui->txtScientificName->setText(QueryLoadData.value(0).toString());
            ui->txtGenus->setText(QueryLoadData.value(1).toString());
            ui->txtCommonName->setText(QueryLoadData.value(2).toString());
            ui->txtSpecies->setText(QueryLoadData.value(3).toString());
            ui->cmbStatus->setText(QueryLoadData.value(4).toString());
            ui->txtPrice->setText(QueryLoadData.value(5).toString());
            ui->txtDescription->setText(QueryLoadData.value(6).toString());
            ui->txtScientificName->setText(QueryLoadData.value(7).toString());
            ui->txtScientificName->setText(QueryLoadData.value(8).toString());




        }

    }

    QSqlDatabase::database().commit();
    DB_SQLITE3.close();
     Image.loadFromData(ImageDataFromDataBase, "JPG");
     ui->image_field->setPixmap(Image);
    foreach(QLineEdit *widget,this->findChildren<QLineEdit*>()){widget->clear();}

}

