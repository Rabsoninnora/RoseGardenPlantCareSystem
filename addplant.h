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
    void on_btnBrowse_clicked();
    //find image properties, returns an array (QVector)
   // QVector<int> findProperties(QVector<QVector<int>> &imgArray, unsigned int &rows, unsigned int &cols);
    //breadth first search, returns max blob area
   // int bfSearch(QVector <int>&posn, QVector<QVector<int>> &explored, unsigned int &rows, unsigned int &cols, QVector <QVector<int>> &imgArray);

    void on_btnSave_clicked();

private:
    Ui::AddPlant *ui;
};

#endif // ADDPLANT_H
