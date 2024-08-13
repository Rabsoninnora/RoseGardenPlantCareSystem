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

//Read and process Image
void AddPlant::on_btnBrowse_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.png *.xpm *.jpg)"));

       //check if file_name is not empty
    if(!file_name.isEmpty()){
      //open prompt and display image
        QMessageBox::information(this, "......", file_name);
        QImage img(file_name);
        QPixmap pix = QPixmap::fromImage(img);

        //get lable dimensions
        int w = ui->load_image->width();
        int h = ui->load_image->height();
       //load image onto ui
        ui->load_image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));







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

    //posting data in the database in the addPlant Table/Relation
    db_RoseGarden.open();
    QSqlDatabase::database().transaction();
    QSqlQuery QueryInsertData(db_RoseGarden);
    QueryInsertData.prepare("insert into addplant(scientific_name, Genus, common_name, species, description, status, price, quantity) values('"+ scientific_name +"', '"+ Genus +"', '"+ common_name +"','"+ species +"','"+ description +"','"+ status +"', '"+ price +"', '"+ quantity +"')");
    QueryInsertData.exec();
    qDebug() <<" Last error : "<< QueryInsertData.lastError().text();
    QSqlDatabase::database().commit();
    db_RoseGarden.close();

    qDebug() << "Database closed  successfuly, Happy coding !";


    foreach (QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();

    }
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

