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

    //get image_field dimentions
    int w=ui->image_field->width();
    int h=ui->image_field->height();



    QSqlQuery QueryLoadData( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    QueryLoadData.prepare("SELECT * FROM addplant WHERE Plant_ID="+ ui->txtPlantID->text() +"");
    if(QueryLoadData.exec())
    {


        while (QueryLoadData.next()) {
            ImageName = QueryLoadData.value("Image_Name").toString();
            ImageDataFromDataBase = QByteArray::fromBase64(QueryLoadData.value("Image_Data").toByteArray());

              ui->txt_Scientific_name->setText(QueryLoadData.value(1).toString());
              ui->txtGenus->setText(QueryLoadData.value(2).toString());
              ui->txt_Local_name->setText(QueryLoadData.value(3).toString());
              ui->species->setText(QueryLoadData.value(4).toString());
              ui->txt_Description->setText(QueryLoadData.value(5).toString());
              ui->txt_status->setText(QueryLoadData.value(6).toString());
              ui->txt_price->setText(QueryLoadData.value(7).toString());
              ui->txt_Quantity->setText(QueryLoadData.value(8).toString());

        }

    }

    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();
     Image.loadFromData(ImageDataFromDataBase, "JPG");
    //load image onto the UI
    ui->image_field->setPixmap(Image.scaled(w, h,Qt::KeepAspectRatio));
    foreach(QLineEdit *widget,this->findChildren<QLineEdit*>()){widget->clear();}

}

