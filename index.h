#ifndef INDEX_H
#define INDEX_H
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
#include "databaseheader.h"
#include "adminpanel.h"

#include <QDialog>

namespace Ui {
class index;
}

class index : public QDialog
{
    Q_OBJECT

public:
    explicit index(QWidget *parent = nullptr);
    ~index();

private slots:
    void on_btn_login_Admin_clicked();

    void on_btn_Cancel_login_Admin_clicked();

private:
    Ui::index *ui;

    //Creating QSqlDatabase object

    QSqlDatabase db;

    //Creating an object for admin panel
    AdminPanel  *AdminDashboard;
};

#endif // INDEX_H
