#ifndef SPECIES_H
#define SPECIES_H
#include"databaseheader.h"

#include <QDialog>

namespace Ui {
class Species;
}

class Species : public QDialog
{
    Q_OBJECT

public:
    explicit Species(QWidget *parent = nullptr);
    ~Species();

private slots:
    void on_btnSearch_clicked();

private:
    Ui::Species *ui;
    QSqlQueryModel *model;

    //Creating a QSqlDatabase for database connectings

     QSqlDatabase db;
};

#endif // SPECIES_H
