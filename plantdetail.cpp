#include "plantdetail.h"
#include "ui_plantdetail.h"
#include <QMessageBox>

PlantDetail::PlantDetail(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlantDetail)
{
    ui->setupUi(this);
    this->showFullScreen();
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);






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
    QueryLoadData.prepare("SELECT * FROM addplant WHERE Plant_ID="+ ui->txtPlantID->text() + "");

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


void PlantDetail::on_btn_sell_plant_clicked()
{



        // Get the Plant ID from the UI
        QString Plant_ID = ui->txt_plant_ID->text();

        // Get the current quantity from the UI
        int currentQuantity = ui->txt_Quantity->text().toInt();

        // Get the quantity to sell from the line edit
        int quantityToSell = ui->lineEdit_quantity->text().toInt();

        // Validate the quantity to sell
        if (quantityToSell <= 0 || quantityToSell > currentQuantity) {
            QMessageBox::warning(this, "Invalid Quantity", "Please enter a valid quantity to sell.");
            return;
        }


        ////////


        // Update the quantity in the database

        QSqlQuery query(MyDB::getInstance()->getDBInstance());

        query.prepare("UPDATE addplant SET quantity = :quantity WHERE Plant_ID = :Plant_ID");

        query.bindValue(":quantity", currentQuantity - quantityToSell); // Update to the new quantity

        query.bindValue(":Plant_ID", Plant_ID);
        query.exec();

        QSqlDatabase::database().commit();
        QSqlDatabase::database().close();

        foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}

        if (!query.exec()) {
            QMessageBox::critical(this, "Database Error", "Failed to update quantity: " + query.lastError().text());
            return;
        }

        // Generate receipt
        double pricePerUnit = ui->txt_price->text().toDouble();
        double totalPrice = pricePerUnit * quantityToSell;
        QString receipt = QString("Rose Garden Nursery Receipt:\nPlant ID: %1\nQuantity Sold: %2\nTotal Price: ZMK%3")
                              .arg(Plant_ID)
                              .arg(quantityToSell)
                              .arg(totalPrice);


        // Display the receipt
        ui->textEdit_receipt->setText(receipt);

        // Refresh the quantity display
        ui->txt_Quantity->setText(QString::number(currentQuantity - quantityToSell));


}

