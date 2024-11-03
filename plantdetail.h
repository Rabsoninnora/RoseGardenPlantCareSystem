#ifndef PLANTDETAIL_H
#define PLANTDETAIL_H

#include <QDialog>

namespace Ui {
class PlantDetail;
}

class PlantDetail : public QDialog
{
    Q_OBJECT

public:
    explicit PlantDetail(QWidget *parent = nullptr);
    ~PlantDetail();

private:
    Ui::PlantDetail *ui;
};

#endif // PLANTDETAIL_H
