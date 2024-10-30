#ifndef DATABASEHEADER_H
#define DATABASEHEADER_H

/*
By Using the Singleton class, I ensure that there is only one
instance of the databse connection.
And it is easily accessible through out the application.
This approach helps manage the database connection more efficiently.
And prevents issues related to multiple connections.

*/

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
#include <QTableWidget>
#include <QObject>
#include <QFileDialog>

class DatabaseManager {
public:
    static DatabaseManager& instance()
    {
        static DatabaseManager instance;
        return instance;
    }

    QSqlDatabase& database()
    {
        return db;
    }

    bool openDatabase(const QString& path)
    {
        if (db.isOpen()) {
            return true;
        }

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Project@rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");

        if (!db.open()) {
            qDebug() << "Error: Unable to open database:" << db.lastError().text();
            return false;
        }

        return true;
        /*

         First instance to open the database file, this file is opened and close according to the
         Application page you are on.

       */
        DatabaseManager::instance().openDatabase("C:/Project@rabson/RoseGardenPlantCareSystem/databases/RoseGardenPlantCareSystem.db");
    }

    void closeDatabase()
    {
        if (db.isOpen()) {
            db.close();
        }
    }

private:

     DatabaseManager() {}  // Private constructor
    ~DatabaseManager() { closeDatabase(); }  // Destructor to close the database


    // Delete copy constructor and assignment operator
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

 /*
  Creating a db object for the QSqlDatabase class
  I will use this object in any source file connecting to the database.

*/
    QSqlDatabase db;
};







#endif // DATABASEHEADER_H
