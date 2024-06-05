#include "addplant.h"
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

       //get image width/height, create empty binary matrix
        unsigned int cols = img.width();
        unsigned int rows =img.height();
        unsigned int numBlackPixels = 0;
        //created empty Vector/ which is a two dimension array
        QVector <QVector<int>> imgArray(rows,QVector<int>(cols, 0));

        //get pixel data, update matrix
        for(unsigned int i = 0; i < rows; i++){
            for(unsigned int j = 0; j < cols; j++){
                //img.pixel(x,y) where x = cols, y=rows (coordinates)
                QColor clrCurrent(img.pixel(j,i));
                int r = clrCurrent.red();
                int g = clrCurrent.green();
                int b =clrCurrent.blue();
                int a =clrCurrent.alpha();
                //if black, assign 1 to array
               //black: r = 0, g = 0, b = 0, a = 225
                if(r+g+b < 20 && a > 240){
                    imgArray[i][j] = 1;
                    numBlackPixels+=1;
                }
            }
        }

        //update ui with information(lable text must be QString)
        ui->dms->setText(QString::fromStdString("W: " +std::to_string(cols) + "H: " +std::to_string(rows)));
        float pD = ((float)numBlackPixels/(float)(cols*rows))*100;
        ui->pDark->setText(QString::fromStdString(std::to_string(pD)));


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
    QString quantity = ui->txtPrice->text();


    //check if the data can be passed/ if I can get this data
    qDebug()<<"scientific_name"
            <<scientific_name
            <<"Genus"
            <<Genus
            <<"common_name"
            <<common_name
            <<"species"
            <<species
            <<"description"
            <<description
            <<"status"
            <<status
            <<"price"
            <<price
            <<"quantity"
            <<quantity;
    //The data can be passed but now it must be posted inn the database
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");


    //checking if the database file exist
    if(QFile::exists("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db"))
    {
        qDebug()<< "Database File Exists ! ";
    }   else
    {
        qDebug() << "Database File Does Not Exists !";
        return;
    }



    //checking if the database can be opened

    if(!database.open())
    {
        qDebug() << "Error: Database Not Opened !";
        return;
    } else
    {
        qDebug() << "Database Succesfuly Opened !";
    }


    //posting data in the database in the addPlant Table/Relation
    QSqlQuery query(database);
    query.prepare("insert into addplant(scientific_name, Genus, common_name, species, description, status, price, quantity) values('"+ scientific_name +"', '"+ Genus +"', '"+ common_name +"','"+ species +"','"+ description +"','"+ status +"', '"+ price +"', '"+ quantity +"')");
    query.exec();
    qDebug() <<" Last error : "<< query.lastError().text();
    database.close();

}

