#ifndef MYDB_H
#define MYDB_H
/*
By Using the Singleton class, I ensure that there is only one
instance of the databse connection.
And it is easily accessible through out the application.
This approach helps manage the database connection more efficiently.
And prevents issues related to multiple connections.

*/

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlResult>
#include <QDebug>
#include <QFile>
#include <QBuffer>
#include <QByteArray>
#include <QFileInfo>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QObject>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintEngine>
#include <QDialog>



class MyDB
{
private:
    MyDB();
    static MyDB *instance;
    void init();
    QSqlDatabase db;
public:
    static MyDB* getInstance();
    static void ResetInstance();


    QSqlDatabase getDBInstance();

    ~MyDB();
};

#endif // MYDB_H
