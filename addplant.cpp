#include "addplant.h"
#include "ui_addplant.h"
#include <QFileDialog> //For file opening
#include <QMessageBox> //pop up messages alerts infos and warning
#include <QPixmap> //
#include <QImage>  // Load Image
#include <QVector> // for arrays in the system code
#include <QQueue> // Queue data structures
#include <QPixmap>

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

    if (!file_name.isEmpty()){
     //open prompt and display Image
        QMessageBox::information(this, "...", file_name);
        QImage img(file_name);
        QPixmap pix = QPixmap::fromImage(img);

     //Get Image dimentions
        int w = ui->load_Image->width();
        int h = ui->load_Image->height();
    //load Image onto the ui
    //    ui->load_Image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
   //Get Image width/height, create empty binary matrix
        unsigned int cols = img.width();
        unsigned int rows = img.height();
        unsigned int numBlackPixels = 0;
        QVector <QVector<int>> imgArray(rows, QVector<int>(cols, 0));
        //get pixel data, update matrix


  }
}

