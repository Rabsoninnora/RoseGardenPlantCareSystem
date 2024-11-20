#ifndef USERLOGIN_H
#define USERLOGIN_H
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
class UserLogin;
}

class UserLogin : public QDialog
{
    Q_OBJECT

public:
    explicit UserLogin(QWidget *parent = nullptr);
    ~UserLogin();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_login_3_clicked();

private:
    Ui::UserLogin *ui;




    SecDialog *secDialog;


    QSqlDatabase db;
};

#endif // USERLOGIN_H
