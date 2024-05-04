#ifndef GARDENERDETAILS_H
#define GARDENERDETAILS_H

#include <QDialog>

namespace Ui {
class GardenerDetails;
}

class GardenerDetails : public QDialog
{
    Q_OBJECT

public:
    explicit GardenerDetails(QWidget *parent = nullptr);
    ~GardenerDetails();

private:
    Ui::GardenerDetails *ui;
};

#endif // GARDENERDETAILS_H
