#ifndef GARDENERDETAILS_H
#define GARDENERDETAILS_H
#include "mydb.h"



#include <QDialog>

namespace Ui {
class GardenerDetails;
}

class GardenerDetails : public QDialog
{
    Q_OBJECT

public:
    explicit GardenerDetails(QWidget *parent = nullptr);
    ~GardenerDetails();

private slots:
    void on_ViewEmployeeRecord_clicked();

    void on_btn_Insert_Employee_clicked();

    void on_btn_Update_Employee_clicked();

    void on_btn_Delete_Employee_clicked();

    void on_btn_back_clicked();

private:
    Ui::GardenerDetails *ui;
    //QSqlDatabase object to be used in the gardenerdetails.cpp file
    QSqlDatabase db;
};

#endif // GARDENERDETAILS_H
