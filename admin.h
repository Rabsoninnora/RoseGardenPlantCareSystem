#ifndef ADMIN_H
#define ADMIN_H
#include"databaseheader.h"
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
#include <QMainWindow>
#include "adminpanel.h"

#include <QDialog>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_pushButton_login_clicked();

    void on_btn_Cancel_admin_login_clicked();

private:
    Ui::Admin *ui;

    AdminPanel *adminPanel;
     QSqlDatabase db;
};

#endif // ADMIN_H
