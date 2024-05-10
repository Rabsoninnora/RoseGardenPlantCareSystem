#ifndef ADDPLANT_H
#define ADDPLANT_H

#include <QDialog>

namespace Ui {
class AddPlant;
}

class AddPlant : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlant(QWidget *parent = nullptr);
    ~AddPlant();

private slots:
    void on_btnBrowse_clicked();
    //find image properties, returns an array (QVector)
   // QVector<int> findProperties(QVector<QVector<int>> &imgArray, unsigned int &rows, unsigned int &cols);
    //breadth first search, returns max blob area
  //  int bfSearch(QVector);

private:
    Ui::AddPlant *ui;
};

#endif // ADDPLANT_H
