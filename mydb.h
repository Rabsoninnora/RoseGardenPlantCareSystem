#ifndef MYDB_H
#define MYDB_H
#include <QDebug>
#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QFile>
#include <QDebug>
#include <QSqlError>


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
