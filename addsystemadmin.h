#ifndef ADDSYSTEMADMIN_H
#define ADDSYSTEMADMIN_H
#include "mydb.h"
#include <QDialog>

namespace Ui {
class AddSystemAdmin;
}

class AddSystemAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit AddSystemAdmin(QWidget *parent = nullptr);
    ~AddSystemAdmin();

private slots:
    void on_ViewAccessDetail_clicked();

    void on_InsertAccessDetail_clicked();

    void on_DeleteAccessDetail_clicked();

private:
    Ui::AddSystemAdmin *ui;
    //creating the QSqlDatabase object
    QSqlDatabase db;
};

#endif // ADDSYSTEMADMIN_H
