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

private:
    Ui::AddGardener *ui;
};

#endif // ADDGARDENER_H
