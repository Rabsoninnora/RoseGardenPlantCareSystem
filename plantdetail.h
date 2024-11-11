#ifndef PLANTDETAIL_H
#define PLANTDETAIL_H
#include "mydb.h"

#include <QDialog>

namespace Ui {
class PlantDetail;
}

class PlantDetail : public QDialog
{
    Q_OBJECT

public:
    explicit PlantDetail(QWidget *parent = nullptr);
    ~PlantDetail();

private slots:
    void on_btnSearchPlant_clicked();

private:
    Ui::PlantDetail *ui;

   //Creating a QSqlDatabase for database connectings

    QSqlDatabase DB_SQLITE3;





};

#endif // PLANTDETAIL_H
