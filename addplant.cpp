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
       // Store image array to a file (optional)
        QString filename ="Home/RoseGardenPlantCareSystem/Files/imgArray.txt";
        QFile fileout(filename);
        if(fileout.open(QFile::ReadWrite |QFile::Text)){
            QTextStream out(&fileout);
            //loop through two dimension array and add elements in the file
            for(unsigned int i = 0; i < rows; i++){
                for(unsigned int j = 0; j < cols; j++){
                    out << imgArray[i][j];
                }
                //end line after each column, go to next row
                   out<< "  " <<Qt::endl;
            }

        }
        //update UI with information (lable text must be QString)
        ui->dms->setText(QString::fromStdString("W: " + std::to_string(cols) + " H: " + std::to_string(rows)));
        float pD =((float)numBlackPixels/(float)(cols*rows))*100;
        ui->pDark->setText(QString::fromStdString(std::to_string(pD)));

        //process image: find the number of blobs
        QVector<int> results = this->findProperties(imgArray, rows, cols);

        //update UI with results( results[0] = number of blobs, results[1]= max blob area)
        ui->nBlops->setText(QString::fromStdString(std::to_string(results[0])));
        ui->mBarea->setText(QString::fromStdString(std::to_string(results[1])));


    }
}

//method to find number of blobs in the image and area
//
QVector<int>AddPlant::findProperties(QVector<QVector<int>> &imgArray, unsigned int &rows, unsigned int &cols){
    int numIslands=0;
    int maxArea=0;
    int area=0;
    //explored
    QVector<QVector<int>>explored(rows, QVector<int>(cols,0));
    // loop thru
    for (unsigned int i = 0; i <rows; i++){
        for (unsigned int j = 0; j <cols; i++){

         //if a '1' is reached and not explored, begin bfs and add 1 to numIslands
            if(imgArray[i][j]==1 &&explored[i][j]==0){
             QVector<int>posn{(int)i,(int)j};//converting unsigned int to int
                area=this->bfSearch(posn,explored,rows,cols,imgArray);
             //update max area  if bigger
                if(area> maxArea){
                    maxArea=area;
                }
                numIslands+=1;
         }
        }

    }

    QVector<int>results{numIslands,maxArea};//create results vector
    return results;
}


  ///bfs function

int AddPlant::bfSearch(QVector <int>&posn, QVector<QVector<int>> &explored, unsigned int &rows, unsigned int &cols, QVector <QVector<int>> &imgArray){
  // potential moves up/down/left/right
    QVector<int>u{-1, 0};
    QVector<int>d{1, 0};
    QVector<int>l{0, -1};
    QVector<int>r{0, 1};
    int islandArea=0;
    //not explored queue (BFS)
    QQueue<QVector<int>> not_explored;
    not_explored.enqueue(posn);//add to front of queue
    while(!not_explored.isEmpty()){
        //find potential moves to explore ([[up],[down],[left],[right]]) - 2D Array
        QVector<QVector<int>> potential_moves{{posn[0]+u[0],posn[1]+u[1]},{posn[0]+d[0],posn[1]+d[1]},{posn[0]+l[0],posn[1]+l[1]},{posn[0]+r[0],posn[1]+r[1]}};

        //iterate thru, if it a valid move then append move to queue, else  continue
        for(QVector<int> move:potential_moves){


        }
    }
}
