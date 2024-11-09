/*
School project:::For Rabson Innocent Phiri
Institution of learning::: Lusaka Business and Technical College
Developed for academic purposes
*/

#include "mydb.h"

MyDB* MyDB::instance = nullptr;

MyDB::MyDB()
{
    init();
}

void MyDB::init()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "Data");
    db.setDatabaseName("C:/Project@rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");

    if(QFile::exists("C:/Project@rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db"))
        qDebug() << "DB file exist";
    else
        qDebug() << "Hi Rabson sorry I can't find the DataBase file";

    if (!db.open())
        qDebug() << db.lastError().text();
    else
        qDebug() << "Hi Rabson Database loaded successfully happy coding!";

}

MyDB *MyDB::getInstance()
{
    qDebug() << "in MyDB::getInstance()";

    if(instance == nullptr)
        instance = new MyDB();

    return instance;

}

QSqlDatabase MyDB::getDBInstance()
{
    return db;
}

void MyDB::ResetInstance()
{
    delete instance;
    instance = nullptr;
}

MyDB::~MyDB()
{
    db.close();
}
