#include "addplant.h"
#include "secdialog.h"
#include "ui_addplant.h"
#include <QFileDialog> //For file opening
#include <QMessageBox> //pop up messages alerts infos and warning
#include <QPixmap> //
#include <QImage>  // Load Image
#include <QVector> // for arrays in the system code
#include <QQueue> // Queue data structures
#include <QPixmap>
#include <QLabel>
#include<QLineEdit>
#include <QVBoxLayout>
#include <QByteArray>
#include "databaseheader.h"

AddPlant::AddPlant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPlant)
{
    ui->setupUi(this);



}


AddPlant::~AddPlant()
{
    delete ui;
}

void AddPlant::on_btn_browse_image_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images(*.png *.xpm *.jpg)"));
    if(!file_name.isEmpty()){
        //open prompt and display image
        QMessageBox::information(this, "......." ,file_name );
        QImage img(file_name);
        QPixmap pix = QPixmap::fromImage(img);

        //get image_field dimentions
        int w=ui->image_field->width();
        int h=ui->image_field->height();

        //load image onto the UI
        ui->image_field->setPixmap(pix.scaled(w, h,Qt::KeepAspectRatio));

    }

}


void AddPlant::on_btnSave_clicked()
{
    //Data received from the AddPlant form, passed to be posted in the database
    QString scientific_name = ui->txtScientificName->text();
    QString Genus = ui->txtGenus->text();
    QString common_name = ui->txtCommonName->text();
    QString species = ui->txtSpecies->text();
    QString description = ui->txtDescription->toPlainText();
    QString status = ui->cmbStatus->currentText();
    QString price = ui->txtPrice->text();
    QString quantity = ui->txtQuantity->text();



    /*

    db_RoseGarden.open();
    QSqlDatabase::database().transaction();
    QSqlQuery QueryInsertData(db_RoseGarden);
    QueryInsertData.prepare("insert into addplant(scientific_name, Genus, common_name, species, description, status, price, quantity, Image ) values('"+ scientific_name +"', '"+ Genus +"', '"+ common_name +"','"+ species +"','"+ description +"','"+ status +"', '"+ price +"', '"+ quantity +"')");
    QueryInsertData.exec();
    qDebug() <<" Last error : "<< QueryInsertData.lastError().text();
    QSqlDatabase::database().commit();
    db_RoseGarden.close();


    qDebug() << "Database closed  successfuly, Happy coding !";


   */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QString ImagePath = QFileDialog::getOpenFileName(this, tr("Select Image"), QCoreApplication::applicationDirPath(), tr("JPG Files(*.jpg)"));
    if (!ImagePath.isEmpty()) {
        QPixmap Image(ImagePath);
        QBuffer ImageBufferData(&imageData); // Use the member variable directly
        if (ImageBufferData.open(QIODevice::WriteOnly)) {
            Image.save(&ImageBufferData, "JPG");
        }
        imageData = ImageBufferData.buffer().toBase64(); // Convert to Base64
    }

    QFileInfo FileInfo(ImagePath);

    QString ImageName =FileInfo.fileName();
    db_RoseGarden.open();
    QSqlDatabase::database().transaction();
    QSqlQuery QueryInsertData(db_RoseGarden);
    QueryInsertData.prepare("INSERT INTO addplant(scientific_name, Genus, common_name, species, description, status, price, quantity, Image_Data, Image_Name) VALUES(:scientific_name,:Genus,:common_name,:species,:description,:status,:price,:quantity,:Image_Data,:Image_Name)");
    QueryInsertData.addBindValue(scientific_name);
    QueryInsertData.addBindValue(Genus);
    QueryInsertData.addBindValue(common_name);
    QueryInsertData.addBindValue(species);
    QueryInsertData.addBindValue(description);
    QueryInsertData.addBindValue(status);
    QueryInsertData.addBindValue(price);
    QueryInsertData.addBindValue(quantity);
    QueryInsertData.bindValue(":Image_Name", ImageName);
    QueryInsertData.addBindValue(imageData); // Use the stored image data

    QueryInsertData.exec();
    qDebug() << "Last error:" << QueryInsertData.lastError().text();
    QSqlDatabase::database().commit();
    db_RoseGarden.close();
    qDebug() << "Database closed successfully, Happy coding!";
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    foreach (QLineEdit *widget, this->findChildren<QLineEdit*>()) { widget->clear();}

    foreach(QPlainTextEdit *widget, this->findChildren<QPlainTextEdit*>()){widget->clear();}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






}



void AddPlant::on_pushButton_btn_home_clicked()
{
    QMessageBox::information(this, "Hi Rabson","Welcome back home");

}


void AddPlant::on_btnReset_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}

    foreach(QPlainTextEdit *widget,this->findChildren<QPlainTextEdit*>()){widget->clear();}
}









