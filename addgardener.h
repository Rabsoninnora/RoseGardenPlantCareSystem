#ifndef ADDGARDENER_H
#define ADDGARDENER_H
#include "databaseheader.h"

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

    void on_btnBrowse_2_clicked();

    void on_btn_home2_clicked();

    void on_btnReset_clicked();

private:
    Ui::AddGardener *ui;
      QSqlDatabase db;
};

#endif // ADDGARDENER_H
