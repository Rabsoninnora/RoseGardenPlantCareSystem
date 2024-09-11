#ifndef SUPPLIERS_H
#define SUPPLIERS_H
#include"databaseheader.h"

#include <QDialog>

namespace Ui {
class Suppliers;
}

class Suppliers : public QDialog
{
    Q_OBJECT

public:
    explicit Suppliers(QWidget *parent = nullptr);
    ~Suppliers();

private:
    Ui::Suppliers *ui;
    //QSqlDatabase Object
     QSqlDatabase db;
};

#endif // SUPPLIERS_H
