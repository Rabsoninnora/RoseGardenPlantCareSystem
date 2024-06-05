#include "addgardener.h"
#include "ui_addgardener.h"
#include <QFileDialog> //For file opening
#include <QMessageBox> //pop up messages alerts infos and warning
#include <QPixmap> //
#include <QImage>  // Load Image
#include <QVector> // for arrays in the system code
#include <QQueue> // Queue data structures
#include <QPixmap>
#include <QLabel>
#include<QLineEdit>


AddGardener::AddGardener(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddGardener)
{
    ui->setupUi(this);
}

AddGardener::~AddGardener()
{
    delete ui;
}

void AddGardener::on_btnSave_clicked()
{
    QString Employee_id = ui->txtEmployeeID->text();
    QString National_id = ui->txtNationalID->text();
    QString Name = ui->txtName->text();
    QString Middle_name = ui->txtMiddleName->text();
    QString Last_name = ui->txtLastName->text();
    QString Job_title = ui->txtJobTitle->text();
    QString Description = ui->txtDescription->toPlainText();


//Check if the information can be passed // if I can get the information
    qDebug() << "EmployeeID :"
             <<Employee_id
             << "NationalID :"
             <<National_id
             << "Name :"
             <<Name
             << "MiddleName :"
             <<Middle_name
             <<"LastName :"
             <<Last_name
             <<"JobTile :"
             <<Job_title
             <<"Description :"
             <<Description;

    //I am able to get the information, but now it must be saved in the database
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");

    //Check if database file exists
    if(QFile::exists("/home/rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db"))
    {
        qDebug() <<" Databse File Exists ";

    } else {
        qDebug() <<" Database File Does not Exists";
        return;
    }



   // See if the database can be opened
    if(!database.open())
    {
        qDebug() << "Error: unable to open Database! ";
        return;
    } else
    {
        qDebug() << "Database opened successfuly ..!";
    }


/// Posting data in the database, the addgardener table/relation
    QSqlQuery query(database);
    query.prepare("insert into addgardener(Employee_id, National_id, Name, Middle_name, Last_name, Job_title, Description) values('"+ Employee_id +"', '"+ National_id +"', '"+ Name +"','"+ Middle_name +"','"+ Last_name +"','"+ Job_title +"', '"+ Description +"')");
    query.exec();
    qDebug() <<" Last error : "<< query.lastError().text();
    database.close();
}



void AddGardener::on_btnBrowse_2_clicked()
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

