#ifndef ADDUSER_H
#define ADDUSER_H
#include "mydb.h"
#include <QDialog>

namespace Ui {
class AddUser;
}

class AddUser : public QDialog
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = nullptr);
    ~AddUser();

private slots:
    void on_btn_View_User_clicked();

    void on_btn_Update_User_clicked();

    void on_btn_Delete_User_clicked();

    void on_btn_Insert_User_clicked();

    void on_btn_Reset_User_clicked();

    void on_btn_View_admin_clicked();

    void on_btn_Insert_admin_clicked();

private:
    Ui::AddUser *ui;
    //QSqlDatabase Object
    QSqlDatabase db;
};

#endif // ADDUSER_H
