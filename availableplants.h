#ifndef AVAILABLEPLANTS_H
#define AVAILABLEPLANTS_H
#include "databaseheader.h"

#include <QDialog>

namespace Ui {
class AvailablePlants;
}

class AvailablePlants : public QDialog
{
    Q_OBJECT

public:
    explicit AvailablePlants(QWidget *parent = nullptr);
    ~AvailablePlants();

private:
    Ui::AvailablePlants *ui;

    QSqlDatabase db;
};

#endif // AVAILABLEPLANTS_H
