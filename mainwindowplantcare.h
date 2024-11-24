#ifndef MAINWINDOWPLANTCARE_H
#define MAINWINDOWPLANTCARE_H

#include "adminlogin.h"
#include "userlogin.h"

#include <QMainWindow>






QT_BEGIN_NAMESPACE //Main namespace class decraration
namespace Ui {
class MainWindowPlantCare;
}
QT_END_NAMESPACE

// Main/Basse class of the Rose Garden Plant Care System
class MainWindowPlantCare : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowPlantCare(QWidget *parent = nullptr);
    ~MainWindowPlantCare();



private slots:


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindowPlantCare *ui;

    AdminLogin   *ptrAdminLogin;

    UserLogin    *ptrUserLogin;




};


#endif // MAINWINDOWPLANTCARE_H
