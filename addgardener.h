#ifndef ADDGARDENER_H
#define ADDGARDENER_H

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

private:
    Ui::AddGardener *ui;
};

#endif // ADDGARDENER_H