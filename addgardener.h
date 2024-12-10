#ifndef ADDGARDENER_H
#define ADDGARDENER_H
#include "mydb.h"

#include <QDialog>

namespace Ui {
class AddGardener;
}

class AddGardener : public QDialog
{
    Q_OBJECT

public:
    explicit AddGardener(QWidget *parent = nullptr);
    ~AddGardener();

private slots:
    void on_btnSave_clicked();

    void on_btnReset_clicked();

    void on_btn_back_clicked();



private:
    Ui::AddGardener *ui;
      QSqlDatabase db;

};

#endif // ADDGARDENER_H
