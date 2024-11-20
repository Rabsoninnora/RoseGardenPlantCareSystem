#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H
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
#include "secdialog.h"
#include  "adminpanel.h"



#include <QDialog>

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

private slots:
    void on_btn_Admin_login_clicked();

    void on_btn_Admin_Cancel_clicked();

private:
    Ui::AdminLogin *ui;



    AdminPanel *adminPanel;

    QSqlDatabase db;

};

#endif // ADMINLOGIN_H
