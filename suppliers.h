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

private slots:
    void on_btn_View_Supplier_clicked();

    void on_btn_Insert_Supplier_clicked();

    void on_btn_Update_Supplier_clicked();

    void on_btn_Delete_Supplier_clicked();



private:
    Ui::Suppliers *ui;
    //QSqlDatabase Object
        QSqlDatabase db;
};

#endif // SUPPLIERS_H
