#ifndef ADDPLANT_H
#define ADDPLANT_H
#include"databaseheader.h"

#include <QDialog>

namespace Ui {
class AddPlant;
}

class AddPlant : public QDialog
{
    Q_OBJECT

    //the widget ui is public
public:
    explicit AddPlant(QWidget *parent = nullptr);
    ~AddPlant();


//the fuctionality is private but the ui is public
private slots:


    void on_btnSave_clicked();
    void on_pushButton_btn_home_clicked();
    void on_btnReset_clicked();
    void on_btn_browse_image_clicked();

private:
    Ui::AddPlant *ui;
    //creating an object for SecDialog

    QSqlDatabase db_RoseGarden;
    QByteArray FinalDataToSave;
    QFileInfo FileInfo;
    QString ImageName;

     QByteArray imageData; // Adding this member variable to store image data
};

#endif // ADDPLANT_H
