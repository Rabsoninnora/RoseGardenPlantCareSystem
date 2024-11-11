#ifndef MAINWINDOWPLANTCARE_H
#define MAINWINDOWPLANTCARE_H
#include<QSqlDatabase>
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QSqlTableModel>
#include<QSqlResult>
#include<QDebug>
#include<QFile>
#include<QBuffer>
#include<QByteArray>
#include<QFileInfo>
#include<QSqlQueryModel>
#include <QMessageBox>
#include "mydb.h"
#include <QMainWindow>
#include "secdialog.h"
#include  "adminpanel.h"





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
    void on_pushButton_login_clicked();


    void on_pushButton_login_3_clicked();

    void on_btn_Admin_login_clicked();


private:
    Ui::MainWindowPlantCare *ui;
    //Creating an object for QSqlDatabase for database connecting

     /*
     creating an object for SecDialog
     and Admin_Dashboard
     */

    SecDialog *secDialog;

    AdminPanel *adminPanel;

    QSqlDatabase db;


};


#endif // MAINWINDOWPLANTCARE_H
